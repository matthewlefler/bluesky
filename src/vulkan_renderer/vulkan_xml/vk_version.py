VULKAN_VERSION_MAJOR = 1
VULKAN_VERSION_MINOR = 4
VULKAN_VERSION = (VULKAN_VERSION_MAJOR << 4) + VULKAN_VERSION_MINOR

def parse_VK_VERSION(version: str) -> int:
    version = version.removeprefix("VK_VERSION_")
    major = int(version[0])
    minor = int(version[2])

    return (major << 4) + minor