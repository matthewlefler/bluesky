#include <stdlib.h>
#include <stdio.h>

#include <vulkan/vulkan.h>

#include "logger.h"

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
    VkBaseOutStructure* previous_copied_struct = alloc_structure(basein_start);
    previous_copied_struct->sType = basein_start->sType;
    if(previous_copied_struct == NULL) {
        log_message(LOG_LEVEL_ERROR, "in copy_struct_chain -> init copied is null: %d", basein_start->sType);
    }
    void* return_struct = previous_copied_struct;

    // walk the structure chain,
    for(const VkBaseInStructure* current_struct = basein_start->pNext; current_struct != NULL; current_struct = current_struct->pNext) {
        current_copied_struct = alloc_structure(current_struct);
        current_copied_struct->sType = current_struct->sType;

        if(current_copied_struct == NULL) {
            log_message(LOG_LEVEL_ERROR, "copy_struct_chain: copied is null: %d", current_struct->sType);
        }

        if (current_struct == current_struct->pNext) {
            log_message(LOG_LEVEL_FATAL, "in copy_struct_chain -> structure chain to copy has infinite loop");
            exit(-1);
        }

        previous_copied_struct->pNext = current_copied_struct;
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

bool compare_VkPhysicalDeviceFeatures2_chain(VkPhysicalDeviceFeatures2* actual, VkPhysicalDeviceFeatures2* requirements) {
    const VkBaseInStructure* current_actual = (VkBaseInStructure*) actual;
    const VkBaseInStructure* current_requirements = (VkBaseInStructure*) requirements;
    
    // walk the structure chain, while both pointers are valid
    while(current_actual != NULL && current_requirements != NULL) {
        bool valid = compare_struct_extends_from_VkPhysicalDeviceFeatures2(current_actual, current_requirements);
        log_message(LOG_LEVEL_DEBUG, "\t compare_VkPhysicalDeviceFeatures2_chain: %s | %s", helper_print_VkStructureType(current_requirements), valid ? "true" : "false");
        if(!valid) {
            return false;
        }

        current_actual = current_actual->pNext;
        current_requirements = current_requirements->pNext;
    }

    if( // one structure chain is done while the other is not
        (current_actual == NULL && current_requirements != NULL) ||
        (current_actual != NULL && current_requirements == NULL)
    ) {
        return false;
    }

    return true;
}