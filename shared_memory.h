typedef struct {
    int phy_data_ready;
    char phy_to_mac_buffer[1024];
    
    int mac_data_ready;
    char mac_to_rlc_buffer[1024];
    
    int rlc_data_ready;
    char rlc_to_pdcp_buffer[1024];
    
    int pdcp_data_ready;
    char pdcp_to_rrc_buffer[1024];
    
    int rrc_data_ready;
    char rrc_to_nas_buffer[1024];

    pthread_mutex_t phy_mac_mutex;
    pthread_mutex_t mac_rlc_mutex;
    pthread_mutex_t rlc_pdcp_mutex;
    pthread_mutex_t pdcp_rrc_mutex;
    pthread_mutex_t rrc_nas_mutex;

} SharedMemory;

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
