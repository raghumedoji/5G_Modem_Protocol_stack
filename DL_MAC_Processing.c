

#include "rlc.h"
#include "rrc.h"
#include "pdcp.h"
#include "mac.h"
#include "phy.h"
#include "nas.h"



#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include "shared_memory.h"

// Global Shared Memory
extern SharedMemory shared_memory;

// Function prototypes
void schedule_dlsch();
void process_dlsch_data(SharedMemory* shm);
void handle_dl_harq(SharedMemory* shm);
void report_dl_buffer_status(SharedMemory* shm);
void transmit_dlsch_data(SharedMemory* shm);
void assemble_dlsch_pdu(SharedMemory* shm);
void allocate_dl_resources();
void handle_dl_control_info();
void decode_dlsch_data(SharedMemory* shm);
void synchronize_dl_processing();

// Function implementations
void schedule_dlsch() {
    // Retrieve scheduling information from higher layers
    // Assign resources to UEs
    // Update MAC PDU buffer with scheduled data
    printf("Scheduling downlink resources...\n");
}

void process_dlsch_data(SharedMemory* shm) {
    // Read data from MAC PDU buffer
    // Decode the data as per MAC layer protocol
    // Store the decoded data in the appropriate buffer
    // Pass the data to higher layers (RLC/PDCP)
    printf("Processing downlink data...\n");
}

void handle_dl_harq(SharedMemory* shm) {
    // Check HARQ status and process ACK/NACK feedback
    // Manage HARQ buffers and queues
    // Handle retransmissions and update scheduling
    printf("Handling downlink HARQ...\n");
}

void report_dl_buffer_status(SharedMemory* shm) {
    // Gather buffer status information from lower layers
    // Format the report as per protocol requirements
    // Send the report to the higher layer (e.g., RRC)
    printf("Reporting downlink buffer status...\n");
}

void transmit_dlsch_data(SharedMemory* shm) {
    // Format the data into MAC PDU format
    // Update MAC PDU buffer with data
    // Send the MAC PDU to PHY layer for transmission
    printf("Transmitting downlink data...\n");
}

void assemble_dlsch_pdu(SharedMemory* shm) {
    // Retrieve data from higher layers
    // Add MAC header and control information
    // Assemble the MAC PDU
    // Store the assembled PDU in the MAC PDU buffer
    printf("Assembling downlink MAC PDU...\n");
}

void allocate_dl_resources() {
    // Determine resource requirements for each UE
    // Allocate resources as per scheduling decisions
    // Update resource allocation status
    printf("Allocating downlink resources...\n");
}

void handle_dl_control_info() {
    // Retrieve DCI from higher layers
    // Apply DCI to DL scheduling and HARQ processes
    // Update scheduling and HARQ states based on DCI
    printf("Handling downlink control information...\n");
}

void decode_dlsch_data(SharedMemory* shm) {
    // Read data from PHY layer
    // Perform decoding and CRC checks
    // Handle error correction
    // Store decoded data in appropriate buffers
    printf("Decoding downlink data...\n");
}

void synchronize_dl_processing() {
    // Retrieve current system frame number and slot information
    // Synchronize DL processing tasks accordingly
    // Update timing and synchronization status
    printf("Synchronizing downlink processing...\n");
}

// Example of a function to simulate the processing loop
void* dl_mac_processing() {
    while (1) {
        synchronize_dl_processing();
        
        //Decode DCI
        handle_dl_control_info();

        process_dlsch_data(&shared_memory);
        handle_dl_harq(&shared_memory);

        //send decoded data to Upper layer RLC
        send_pdsch_to_upper_layers(&shared_memory);

        // Sleep or wait for next processing cycle
        sleep(1); // Adjust as necessary
    }
    return NULL;
}
