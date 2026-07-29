#include <vulkan/vulkan.h>

#include "vulkan_xml.h"

void set_pNext(void* structure, void* addr) {
    *((VkStructureType*) structure) + 1 = addr;
}

void* get_pNext(void* structure) {
    return (((VkStructureType*) structure) + 1);
}
VkStructureType get_sType(void* structure) {
    return *(VkStructureType*) structure;
}

void* copy_struct_chain(void* start) {
    void* current_copied_struct = NULL;
    void* previous_copied_struct = copy_structure(start);
    void* current_struct = get_pNext(start);

    void* return_struct = previous_copied_struct;
    
    // walk the structure chain,
    while(current_struct != NULL) {
        current_copied_struct = copy_structure(current_struct);
        set_pNext(previous_copied_struct, current_copied_struct);

        current_struct = get_pNext(current_struct);
        previous_copied_struct = current_copied_struct;
    }

    return return_struct;
}

void free_struct_chain(void* start) {
    void* current = start;
    void* prev = NULL;

    while(current != NULL) {
        prev = current;
        current = get_pNext(current);

        free(prev);
    }
}

bool compare_struct_chain(void* actual, void* requirements) {
    void* current_actual = actual;
    void* current_requirements = requirements;
    
    // walk the structure chain,
    while(current_actual != NULL && current_requirements != NULL) {
        if(!compare_structure(current_actual, current_requirements)) {
            return false;
        }

        current_actual = get_pNext(current_actual);
        current_requirements = get_pNext(current_requirements);
    }

    if( // one structure chain is done while the other is not
        (current_actual == NULL && current_requirements != NULL) ||
        (current_actual != NULL && current_requirements == NULL)
    ) {
        return false;
    }

    return true;
}