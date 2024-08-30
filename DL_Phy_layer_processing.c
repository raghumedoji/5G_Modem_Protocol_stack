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

