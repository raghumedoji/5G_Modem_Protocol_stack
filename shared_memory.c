
#include "shared_memory.h"
#include <string.h>

/ Initialize shared memory
void init_shared_memory(SharedMemory* shm) {
    memset(shm->rx_buffer, 0, RX_BUFFER_SIZE);
    memset(shm->tx_buffer, 0, TX_BUFFER_SIZE);
    memset(shm->mac_pdu_buffer, 0, MAC_PDU_SIZE);
    memset(shm->pdsch_data_buffer, 0, PDSCH_DATA_SIZE);
    memset(shm->pusch_data_buffer, 0, PUSCH_DATA_SIZE);
    memset(shm->channel_estimation_buffer, 0, CHANNEL_ESTIMATION_SIZE);

    shm->rx_buffer_read_index = 0;
    shm->tx_buffer_write_index = 0;
    shm->mac_pdu_write_index = 0;
    shm->mac_pdu_read_index = 0;
    shm->pdsch_data_write_index = 0;
    shm->pdsch_data_read_index = 0;
    shm->pusch_data_write_index = 0;
    shm->pusch_data_read_index = 0;
    shm->channel_estimation_index = 0;
}

// Write data to RX buffer
void write_to_rx_buffer(SharedMemory* shm, const uint8_t* data, size_t size) {
    memcpy(shm->rx_buffer + shm->rx_buffer_read_index, data, size);
    shm->rx_buffer_read_index = (shm->rx_buffer_read_index + size) % RX_BUFFER_SIZE;
}

// Read data from RX buffer
void read_from_rx_buffer(SharedMemory* shm, uint8_t* data, size_t size) {
    memcpy(data, shm->rx_buffer + shm->rx_buffer_read_index, size);
    shm->rx_buffer_read_index = (shm->rx_buffer_read_index + size) % RX_BUFFER_SIZE;
}

// Write data to TX buffer
void write_to_tx_buffer(SharedMemory* shm, const uint8_t* data, size_t size) {
    memcpy(shm->tx_buffer + shm->tx_buffer_write_index, data, size);
    shm->tx_buffer_write_index = (shm->tx_buffer_write_index + size) % TX_BUFFER_SIZE;
}

// Read data from TX buffer
void read_from_tx_buffer(SharedMemory* shm, uint8_t* data, size_t size) {
    memcpy(data, shm->tx_buffer + shm->tx_buffer_write_index, size);
    shm->tx_buffer_write_index = (shm->tx_buffer_write_index + size) % TX_BUFFER_SIZE;
}

// Write MAC PDU
void write_mac_pdu(SharedMemory* shm, const uint8_t* pdu, size_t size) {
    memcpy(shm->mac_pdu_buffer + shm->mac_pdu_write_index, pdu, size);
    shm->mac_pdu_write_index = (shm->mac_pdu_write_index + size) % MAC_PDU_SIZE;
}

// Read MAC PDU
void read_mac_pdu(SharedMemory* shm, uint8_t* pdu, size_t size) {
    memcpy(pdu, shm->mac_pdu_buffer + shm->mac_pdu_read_index, size);
    shm->mac_pdu_read_index = (shm->mac_pdu_read_index + size) % MAC_PDU_SIZE;
}

// Write PDSCH data
void write_pdsch_data(SharedMemory* shm, const uint8_t* data, size_t size) {
    memcpy(shm->pdsch_data_buffer + shm->pdsch_data_write_index, data, size);
    shm->pdsch_data_write_index = (shm->pdsch_data_write_index + size) % PDSCH_DATA_SIZE;
}

// Read PDSCH data
void read_pdsch_data(SharedMemory* shm, uint8_t* data, size_t size) {
    memcpy(data, shm->pdsch_data_buffer + shm->pdsch_data_read_index, size);
    shm->pdsch_data_read_index = (shm->pdsch_data_read_index + size) % PDSCH_DATA_SIZE;
}

// Write PUSCH data
void write_pusch_data(SharedMemory* shm, const uint8_t* data, size_t size) {
    memcpy(shm->pusch_data_buffer + shm->pusch_data_write_index, data, size);
    shm->pusch_data_write_index = (shm->pusch_data_write_index + size) % PUSCH_DATA_SIZE;
}

// Read PUSCH data
void read_pusch_data(SharedMemory* shm, uint8_t* data, size_t size) {
    memcpy(data, shm->pusch_data_buffer + shm->pusch_data_read_index, size);
    shm->pusch_data_read_index = (shm->pusch_data_read_index + size) % PUSCH_DATA_SIZE;
}

// Write channel estimation data
void write_channel_estimation(SharedMemory* shm, const uint8_t* data, size_t size) {
    memcpy(shm->channel_estimation_buffer + shm->channel_estimation_index, data, size);
    shm->channel_estimation_index = (shm->channel_estimation_index + size) % CHANNEL_ESTIMATION_SIZE;
}

// Read channel estimation data
void read_channel_estimation(SharedMemory* shm, uint8_t* data, size_t size) {
    memcpy(data, shm->channel_estimation_buffer + shm->channel_estimation_index, size);
    shm->channel_estimation_index = (shm->channel_estimation_index + size) % CHANNEL_ESTIMATION_SIZE;
}
