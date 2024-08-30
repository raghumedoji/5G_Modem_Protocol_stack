#include "global_variables.h"
#include <stdio.h>
#include <unistd.h>

// Initialize global variables
int current_slot = 0;
int system_frame_number = 0;


// Function to update the global slot and frame number
void update_slot_sfn() {
    current_slot = (current_slot + 1) % 10; // 10 slots per frame
    if (current_slot == 0) {
        system_frame_number = (system_frame_number + 1) % 1025; // 0-1024 frame numbers
    }
} 
