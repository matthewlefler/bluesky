cmake_minimum_required(VERSION 3.25)
project(VulkanRenderer C)

# Set C standard to C23
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Compile flags for warnings and debugging
add_compile_options(-g -Wall -Wextra)

# xml based parsing
add_custom_target(xml_parsing
    python ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/parse.py ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing_output ../src/vulkan_renderer/vulkan_xml/xml_parsing/vk.xml

    SOURCES ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/parse.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_object.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/dependencies.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/extensions.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/features.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/platforms.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/vulkan_objects.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/vulkan_objects_types_dir/basetypes.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/vulkan_objects_types_dir/bitmasks.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/vulkan_objects_types_dir/defines.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/vulkan_objects_types_dir/enumerations.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/vulkan_objects_types_dir/function_pointers.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/vulkan_objects_types_dir/handles.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/vulkan_objects_types_dir/includes.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/vulkan_objects_types_dir/structures.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/vulkan_objects_types_dir/types.py
            ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing/vulkan_objects_dir/vulkan_objects_types_dir/unions.py

    BYPRODUCTS  ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing_output/bluesky_vulkan_xml_struct_copy.c
                ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing_output/bluesky_vulkan_xml_struct_compare.c
                ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing_output/bluesky_vulkan_xml_struct_compare_functions.c
)

# Define the executable target
add_executable(vulkan_main)
add_dependencies(vulkan_main xml_parsing)

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
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing_output/bluesky_vulkan_xml_struct_copy.c
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing_output/bluesky_vulkan_xml_struct_compare.c
    ${CMAKE_SOURCE_DIR}/src/vulkan_renderer/vulkan_xml/xml_parsing_output/bluesky_vulkan_xml_struct_compare_functions.c
)

# Find System Dependencies
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

# Include directories
target_include_directories(vulkan_main PRIVATE 
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/utilities/logger
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
