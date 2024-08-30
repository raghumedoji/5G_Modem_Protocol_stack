
#include "rlc.h"
#include "rrc.h"
#include "pdcp.h"
#include "mac.h"
#include "phy.h"
#include "nas.h"


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

