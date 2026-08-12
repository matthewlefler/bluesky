from dataclasses import dataclass
import xml.etree.ElementTree as ET

@dataclass
class platform:
    name: str
    protect: str

platforms: dict[str, platform] = dict()

def collect_platforms(root: ET.Element[str]) -> list[ET.Element[str]]:
    all_platforms = list(root.iter("platform"))

    for a_platform in all_platforms:
        name = a_platform.get("name")
        protect = a_platform.get("protect")

        if name is None or protect is None:
            continue

        platforms[name] = platform(name, protect)

    return all_platforms