cmake_minimum_required(VERSION 3.25)
project(VulkanRenderer C)

# Set C standard to C23
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Compile flags for warnings and debugging
add_compile_options(-g -Wall -Wextra)

# xml based parsing
add_executable(vulkan_xml_parsing)
target_sources(vulkan_xml_parsing PRIVATE
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/parse.c
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_structs.c
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_type_structs.c
)

# Find System Dependencies
find_package(libXml2 REQUIRED)

# Include directories
target_include_directories(vulkan_xml_parsing PRIVATE
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing
    ${LIBXML2_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(vulkan_xml_parsing PRIVATE
    ${LIBXML2_LIBRARIES}
    m
)

# Set output directory matching your old 'build' setup
set_target_properties(vulkan_xml_parsing PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    OUTPUT_NAME "parse_xml"
)

add_custom_command(
  OUTPUT    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/bluesky_vulkan_xml_struct_copy.c
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/bluesky_vulkan_xml_struct_comparision_functions.c
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/bluesky_vulkan_xml_struct_comparision_vk_struct_type.c
  DEPENDS vulkan_xml_parsing
  COMMAND ./parse_xml ../src/vulkan_renderer/vulkan_xml/xml_parsing/vk.xml
)

# Define the executable target
add_executable(vulkan_main)

# source files
target_sources(vulkan_main PRIVATE
    ${CMAKE_SOURCE_DIR}/src/main.c

    ${CMAKE_SOURCE_DIR}/src/utilities/logger/logger.c

    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/extensions.c
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/layers.c
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/log_utilities.c
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/render.c
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/window.c

    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/devices/devices.c
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/devices/logical_devices.c
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/devices/physical_devices.c
    
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/vulkan_structure.c
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/bluesky_vulkan_xml_struct_copy.c
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/bluesky_vulkan_xml_struct_comparision_functions.c
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/bluesky_vulkan_xml_struct_comparision_vk_struct_type.c
)

# Find System Dependencies
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

# Include directories
target_include_directories(vulkan_main PRIVATE 
    ${CMAKE_SOURCE_DIR}/src
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
