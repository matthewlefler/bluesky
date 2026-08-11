import xml.etree.ElementTree as ET

def debug_print_tree(element: ET.Element[str], last: list[bool] = [], level: int = 0) -> None:
    # │ ├ └ ─
    last_len = len(last)
    for index,boolean in enumerate(last):
        if(index == last_len-1):
            if boolean == True:
                print("└───", end="")
            else:
                print("├───", end="")
        else:
            if boolean == True:
                print("    ", end="")
            else:
                print("│   ", end="")

    tag = element.tag or ""
    text = element.text or ""
    tail = element.tail or ""
    attrib = element.attrib
    if not tag.isspace():
        print(f"{tag}:", end="")
    else:
        print(f"None:", end="")
    if not text.isspace():
        print(f" {text}", end="")
    if not tail.isspace():
        print(f" | {tail}", end="")
    if not len(attrib) <= 0:
        print(f" | {attrib}", end="")
    print("")


    sub_element_len = len(element)
    for index,sub_element in enumerate(element):
        if sub_element_len-1 == index:
            debug_print_tree(sub_element, last + [True], level + 1)
        else:
            debug_print_tree(sub_element, last + [False], level + 1)