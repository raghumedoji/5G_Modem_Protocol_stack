#include "rlc.h"
#include "rrc.h"
#include "pdcp.h"
#include "mac.h"
#include "phy.h"
#include "nas.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shared_memory.h"
#include "rlc_dl.h"

// Global Shared Memory
extern SharedMemory shared_memory;

// Function prototypes for DL RLC layer
void rlc_receive_pdu(SharedMemory* shm);
void rlc_reassembly(SharedMemory* shm);
void rlc_error_detection(SharedMemory* shm);
void rlc_retransmission(SharedMemory* shm);
void rlc_reordering(SharedMemory* shm);
void rlc_delivery_to_upper_layer(SharedMemory* shm);

// Function implementations

// Function to receive RLC PDUs from the MAC layer
void rlc_receive_pdu(SharedMemory* shm) {
    // Retrieve RLC PDU from the shared memory (MAC to RLC buffer)
    // The PDU could be a data PDU or a control PDU
    printf("Receiving RLC PDU...\n");

    // Example: Retrieve RLC PDU and store it in the RLC buffer
    memcpy(shm->rlc_dl_buffer, shm->mac_rlc_dl_buffer, shm->mac_rlc_dl_buffer_size);
}

// Function to reassemble RLC SDUs from the received PDUs
void rlc_reassembly(SharedMemory* shm) {
    // Reassemble RLC SDUs from the received RLC PDUs
    // Handle segmentation, reassembly, and reordering
    printf("Reassembling RLC SDU...\n");

    // Example reassembly logic
    // Assume shm->rlc_dl_buffer contains the received RLC PDUs
    // Reassemble these into RLC SDUs stored in shm->rlc_sdu_reassembly_buffer
}

// Function for error detection in the received RLC PDUs
void rlc_error_detection(SharedMemory* shm) {
    // Detect errors in the received RLC PDUs
    // Perform CRC checks, sequence number validation, etc.
    printf("Detecting errors in RLC PDU...\n");

    // Example error detection logic
    // Perform CRC checks or sequence number validation on shm->rlc_dl_buffer
}

// Function to handle RLC retransmission based on ACK/NACK feedback
void rlc_retransmission(SharedMemory* shm) {
    // Handle retransmission of RLC PDUs based on ACK/NACK feedback
    // Manage retransmission buffers and timers
    printf("Handling RLC retransmission...\n");

    // Example: Handle retransmissions by managing shm->rlc_retransmission_buffer
}

// Function for reordering received RLC PDUs to ensure in-sequence delivery
void rlc_reordering(SharedMemory* shm) {
    // Reorder received RLC PDUs based on sequence numbers
    // Ensure in-sequence delivery of RLC SDUs to upper layers
    printf("Reordering RLC PDUs...\n");

    // Example reordering logic based on sequence numbers in shm->rlc_dl_buffer
}

// Function to deliver reassembled RLC SDUs to the PDCP layer
void rlc_delivery_to_pdcp_layer(SharedMemory* shm) {
    // Deliver the reassembled RLC SDUs to the PDCP layer
    // Copy the reassembled SDUs to the shared memory buffer for PDCP
    printf("Delivering RLC SDU to PDCP...\n");

    // Example: Copy data from shm->rlc_sdu_reassembly_buffer to shm->rlc_pdcp_dl_buffer
}

// Main DL RLC processing function
void* dl_rlc_processing() {
    while (1) {
        
        rlc_receive_pdu(&shared_memory);            // Step 1: Receive RLC PDU from MAC layer
        rlc_error_detection(&shared_memory);        // Step 2: Error detection in RLC PDU
        rlc_reordering(&shared_memory);             // Step 3: Reordering RLC PDUs
        rlc_reassembly(&shared_memory);             // Step 4: Reassemble RLC SDUs
        rlc_retransmission(&shared_memory);         // Step 5: Handle retransmission
        rlc_delivery_to_pdcp_layer(&shared_memory);// Step 6: Deliver RLC SDUs to PDCP layer

        // Sleep or wait for the next processing cycle
        sleep(1); // Adjust as necessary for timing requirements
    }
    return NULL;
}

