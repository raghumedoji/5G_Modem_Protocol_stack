// Buffer sizes
#define RX_BUFFER_SIZE 8192
#define TX_BUFFER_SIZE 8192
#define MAC_PDU_SIZE 1024
#define PDSCH_DATA_SIZE 2048
#define PUSCH_DATA_SIZE 2048
#define CHANNEL_ESTIMATION_SIZE 512

// Struct for PHY to MAC shared memory
typedef struct {
    uint8_t rx_buffer[RX_BUFFER_SIZE];          // Buffer for raw RX data
    uint8_t tx_buffer[TX_BUFFER_SIZE];          // Buffer for TX data
    uint8_t mac_pdu_buffer[MAC_PDU_SIZE];       // Buffer for MAC PDUs
    uint8_t pdsch_data_buffer[PDSCH_DATA_SIZE]; // Buffer for PDSCH data
    uint8_t pusch_data_buffer[PUSCH_DATA_SIZE]; // Buffer for PUSCH data
    uint8_t channel_estimation_buffer[CHANNEL_ESTIMATION_SIZE]; // Buffer for channel estimation

    // Indices for read and write operations
    uint32_t rx_buffer_read_index;
    uint32_t tx_buffer_write_index;
    uint32_t mac_pdu_write_index;
    uint32_t mac_pdu_read_index;
    uint32_t pdsch_data_write_index;
    uint32_t pdsch_data_read_index;
    uint32_t pusch_data_write_index;
    uint32_t pusch_data_read_index;
    uint32_t channel_estimation_index;
} SharedMemory;

// Function prototypes
void init_shared_memory(SharedMemory* shm);
void write_to_rx_buffer(SharedMemory* shm, const uint8_t* data, size_t size);
void read_from_rx_buffer(SharedMemory* shm, uint8_t* data, size_t size);
void write_to_tx_buffer(SharedMemory* shm, const uint8_t* data, size_t size);
void read_from_tx_buffer(SharedMemory* shm, uint8_t* data, size_t size);
void write_mac_pdu(SharedMemory* shm, const uint8_t* pdu, size_t size);
void read_mac_pdu(SharedMemory* shm, uint8_t* pdu, size_t size);
void write_pdsch_data(SharedMemory* shm, const uint8_t* data, size_t size);
void read_pdsch_data(SharedMemory* shm, uint8_t* data, size_t size);
void write_pusch_data(SharedMemory* shm, const uint8_t* data, size_t size);
void read_pusch_data(SharedMemory* shm, uint8_t* data, size_t size);
void write_channel_estimation(SharedMemory* shm, const uint8_t* data, size_t size);
void read_channel_estimation(SharedMemory* shm, uint8_t* data, size_t size);



// Initialize shared memory and synchronization mechanisms
void init_shared_memory(SharedMemory* shm) {
    memset(shm, 0, sizeof(SharedMemory));

    // Initialize mutexes
    pthread_mutex_init(&shm->phy_mac_mutex, NULL);
    pthread_mutex_init(&shm->mac_rlc_mutex, NULL);
    pthread_mutex_init(&shm->rlc_pdcp_mutex, NULL);
    pthread_mutex_init(&shm->pdcp_rrc_mutex, NULL);
    pthread_mutex_init(&shm->rrc_nas_mutex, NULL);
}

void init_shared_memory(SharedMemory* shm);
