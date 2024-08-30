#include <stdio.h>
#include "rlc.h"
#include "rrc.h"
#include "pdcp.h"
#include "mac.h"
#include "phy.h"
#include "nas.h"

// Constants
#define NUM_SYMBOLS_PER_SLOT 14
#define NUM_SLOTS 10
#define NUM_SYSTEM_FRAMES 1024


extern int current_slot;
extern int system_frame_number;

// Function prototypes
void dl_phy_layer_processing();
void channel_estimation();
void demodulation();
void synchronization();
void channel_decoding();




void channel_estimation() {
    // Simulate channel estimation
    printf("Performing channel estimation...\n");
    // Actual channel estimation code would go here
    // e.g., using reference signals and pilot symbols
}

void demodulation() {
    // Simulate demodulation
    printf("Performing demodulation...\n");
    // Actual demodulation code would go here
    // e.g., QPSK, 16QAM, 64QAM demodulation
}

void synchronization() {
    // Simulate synchronization
    printf("Performing synchronization...\n");
    // Actual synchronization code would go here
    // e.g., time and frequency synchronization
}

void channel_decoding() {
    // Simulate channel decoding
    printf("Performing channel decoding...\n");
    // Actual channel decoding code would go here
    // e.g., Turbo decoding, LDPC decoding
}



void channel_estimation_ul() {
    // Simulate channel estimation for UL
    printf("Performing UL channel estimation...\n");
    // Actual channel estimation code would go here
    // e.g., using reference signals and pilot symbols
}

void demodulation_ul() {
    // Simulate demodulation for UL
    printf("Performing UL demodulation...\n");
    // Actual demodulation code would go here
    // e.g., QPSK, 16QAM, 64QAM demodulation
}

void synchronization_ul() {
    // Simulate synchronization for UL
    printf("Performing UL synchronization...\n");
    // Actual synchronization code would go here
    // e.g., time and frequency synchronization
}

void channel_encoding_ul() {
    // Simulate channel encoding for UL
    printf("Performing UL channel encoding...\n");
    // Actual channel encoding code would go here
    // e.g., Turbo encoding, LDPC encoding
}





void dl_phy_layer_processing() {
    printf("Starting DL PHY layer processing...\n");

    // Channel Estimation
    channel_estimation();

    // Demodulation
    demodulation();

    // DCI Decoding 
    channel_decoding();

    //Decode PDSCH
    decode_pdsch();

    //Copy to shared memory
    copy_phy_to_mac();

    printf("DL PHY layer processing completed.\n");
}


void ul_phy_layer_processing() {
    printf("Starting UL PHY layer processing...\n");

     //Channel Estimation
    channel_estimation_ul();
    
    // Process data from MAC layer(PDSCH PDU)
    mac_layer_processing_ul();
    
    //crc_addition

    add_crc_ul();
    
    // Channel Encoding (LDPC, Polar codes)
    channel_encoding_ul();
    
    // modulation
    modulation_ul();

    //layer mapping

    layer_mapping();

    //precoding
    precoding();

    //RE element mapper
    re_element_mapper();

    //OFDM modulation

    ofdm_modulation();

    // 3. Synchronization
    synchronization_ul();



    printf("UL PHY layer processing completed.\n");
}


void phy_layer_processing()
{
    dl_phy_layer_processing();
    ul_phy_layer_processing();
}
