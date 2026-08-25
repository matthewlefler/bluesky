cmake_minimum_required(VERSION 3.25)
project(VulkanRenderer C)

# Set C standard to C23
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Compile flags for warnings and debugging
add_compile_options(-g -Wall -Wextra)

# Define the executable target
add_executable(vulkan_main)

# source files
target_sources(vulkan_main PRIVATE
    src/main.c

    src/utilities/logger/logger.c

    src/vulkan_renderer/extensions.c
    src/vulkan_renderer/layers.c
    src/vulkan_renderer/log_utilities.c
    src/vulkan_renderer/render.c
    src/vulkan_renderer/window.c

    src/vulkan_renderer/devices/devices.c
    src/vulkan_renderer/devices/logical_devices.c
    src/vulkan_renderer/devices/physical_devices.c
    
    src/vulkan_renderer/vulkan_xml/vulkan_structure.c
    src/vulkan_renderer/vulkan_xml/bluesky_vulkan_xml_struct_copy.c
    src/vulkan_renderer/vulkan_xml/bluesky_vulkan_xml_struct_comparision_functions.c
    src/vulkan_renderer/vulkan_xml/bluesky_vulkan_xml_struct_comparision_vk_struct_type.c
)

# Find System Dependencies
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

# Include directories
target_include_directories(vulkan_main PRIVATE 
    src
)

# Link libraries
target_link_libraries(vulkan_main PRIVATE 
    Vulkan::Vulkan 
    glfw
    m
)

# Set output directory matching your old 'build' setup
set_target_properties(vulkan_main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    OUTPUT_NAME "main"
)