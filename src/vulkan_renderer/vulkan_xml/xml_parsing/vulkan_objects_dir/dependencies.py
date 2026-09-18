from dataclasses import dataclass
from enum import Enum


class DependsOperation(Enum):
    OR = 0
    AND = 1
    NONE = -1

@dataclass
class Depends:
    sub_depends: list[Depends | str]
    operation: DependsOperation

def validate(depend: Depends) -> bool:
    raise NotImplemented

def parse_depend_string(depends: str) -> Depends | None:
    """
    parses a depends statments i.e. name1,(name2+name3),name4
    """
        
    # parens () for order
    # , means OR
    # + means AND
    #
    # i.e.
    # vk_name1,(vk_name2+vk_name3),vk_name4
    # means
    # vk_name1 or (both vk_name2 and vk_name3) or vk_name4
    OPEN_PAREN_CHAR = '('
    CLOSE_PAREN_CHAR = ')'
    OR_CHAR = ','
    AND_CHAR = '+'

    if(depends.isspace()):
        return None

    depends_name: str = ""
    stack: list[Depends] = list()
    current: Depends = Depends([], DependsOperation.NONE)
    for character in depends:
        if character == OR_CHAR:
            if current.operation == DependsOperation.AND:
                # error
                print(f"ERROR: depends contains AND \'{AND_CHAR}\' and OR \'{OR_CHAR}\' characters in the same sequence: \n\tin: {depends}")
                return None
            
            current.operation = DependsOperation.OR
            if not depends_name.isspace():
                current.sub_depends.append(depends_name)
            depends_name = ""
            
        elif character == AND_CHAR:
            if current.operation == DependsOperation.OR:
                # error
                print(f"ERROR: depends contains AND \'{AND_CHAR}\' and OR \'{OR_CHAR}\' characters in the same sequence\n\tin: {depends}")
                return None

            current.operation = DependsOperation.AND
            if not depends_name.isspace():
                current.sub_depends.append(depends_name)
            depends_name = ""
                
        elif character == OPEN_PAREN_CHAR:
            stack.append(current)
            current = Depends([], DependsOperation.NONE)
        elif character == CLOSE_PAREN_CHAR:
            if not depends_name.isspace():
                current.sub_depends.append(depends_name)
            depends_name = ""

            if current.operation == DependsOperation.NONE:
                print(f"ERROR: depends contains a sequence with no operation characters (\'{AND_CHAR}\',\'{OR_CHAR}\')\n\tin: {depends}")
                return None
            
            previous = stack.pop()
            previous.sub_depends.append(current)
            current = previous
        else:
            depends_name += character
    
    if current.operation == DependsOperation.NONE:
        print(f"ERROR: depends contains a sequence with no operation characters (\'{AND_CHAR}\',\'{OR_CHAR}\')\n\tin: {depends}")
        return None
    
    return current

def print_depends(depends: Depends, depth = 0) -> None:
    """
    recursively prints a depends statments
    """
    if depends is None:
        return
    TAB = "  "
    tabs = depth * TAB

    print(f"{tabs}(")
    for index,sub in enumerate(depends.sub_depends):
        if isinstance(sub, str):
            print(f"{(depth + 1) * TAB}{sub}")
        else:
            print_depends(sub, depth + 1)

        if index < len(depends.sub_depends) - 1:
            if depends.operation == DependsOperation.OR:
                print(f"{tabs}OR")
            elif depends.operation == DependsOperation.AND:
                print(f"{tabs}AND")
            elif depends.operation == DependsOperation.NONE:
                print(f"{tabs}NONE")
            else:
                print(f"{tabs}ERROR: unknown depends operation: {depends.operation}")
    print(f"{tabs})")
    