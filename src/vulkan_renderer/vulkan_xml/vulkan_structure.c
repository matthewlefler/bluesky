#include <stdlib.h>

#include <vulkan/vulkan.h>

#include "../../utilities/logger/logger.h"

#include "vulkan_structure.h"
#include "vulkan_xml.h"

void set_pNext(void* structure, void* addr) {
    ((VkBaseOutStructure*) structure)->pNext = addr;
}

void* get_pNext(void* structure) {
    return ((VkBaseOutStructure*) structure)->pNext;
}

VkStructureType get_sType(void* structure) {
    return *((VkStructureType*) structure);
}

void* copy_struct_chain(void* start) {
    if(start == NULL) {
        return NULL;
    }

    VkBaseInStructure* basein_start = (VkBaseInStructure*) start;

    VkBaseOutStructure* current_copied_struct = NULL;
    VkBaseOutStructure* previous_copied_struct = copy_struct_extends_from_vk_struct(basein_start);
    if(previous_copied_struct == NULL) {
        log_message(LOG_LEVEL_ERROR, "init copied is null: %d", basein_start->sType);
    }
    const VkBaseInStructure* current_struct = basein_start->pNext;

    void* return_struct = previous_copied_struct;
    
    // walk the structure chain,
    while(current_struct != NULL) {
        current_copied_struct = copy_struct_extends_from_vk_struct(current_struct);
        if(current_copied_struct == NULL) {
            log_message(LOG_LEVEL_ERROR, "copied is null: %d", current_struct->sType);
        }

        previous_copied_struct->pNext = current_copied_struct;

        current_struct = basein_start->pNext;
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
    
    // walk the structure chain, while both pointers are valid
    while(current_actual != NULL && current_requirements != NULL) {
        if(!compare_struct_extends_from_vk_struct(current_actual, current_requirements)) {
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