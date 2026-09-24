import xml.etree.ElementTree as ET

def remove_all_tags(root: ET.Element[str], tag_name: str) -> None:
    for parent in root.iter():
        for child in list(parent):
            if child.tag == tag_name:
                parent.remove(child)