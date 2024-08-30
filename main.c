#include <stdio.h>
#include <pthread.h>
#include <sched.h>


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

void init_shared_memory(SharedMemory* shm);


// Function prototypes for each layer
void* phy_thread(void* arg);
void* mac_thread(void* arg);
void* rlc_thread(void* arg);
void* pdcp_thread(void* arg);
void* rrc_thread(void* arg);
void* nas_thread(void* arg);

// Thread attributes
pthread_attr_t attr;
pthread_attr_t core_attr;

// Thread identifiers
pthread_t phy_tid, mac_tid, rlc_tid, pdcp_tid, rrc_tid, nas_tid;

int main() {
    // Initialize thread attributes
    pthread_attr_init(&attr);

    // Create threads for each protocol layer
    pthread_create(&phy_tid, &attr, phy_thread, NULL);
    pthread_create(&mac_tid, &attr, mac_thread, NULL);
    pthread_create(&rlc_tid, &attr, rlc_thread, NULL);
    pthread_create(&pdcp_tid, &attr, pdcp_thread, NULL);
    pthread_create(&rrc_tid, &attr, rrc_thread, NULL);
    pthread_create(&nas_tid, &attr, nas_thread, NULL);

    // Wait for threads to complete
    pthread_join(phy_tid, NULL);
    pthread_join(mac_tid, NULL);
    pthread_join(rlc_tid, NULL);
    pthread_join(pdcp_tid, NULL);
    pthread_join(rrc_tid, NULL);
    pthread_join(nas_tid, NULL);

    // Cleanup
    pthread_attr_destroy(&attr);

    return 0;
}

// Function implementations for each thread
void* phy_thread(void* arg) {
    // Set CPU affinity to core 0
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    while (1) {
        // PHY processing logic
        printf("PHY thread running on core 0\n");
        sleep(1);
    }
    return NULL;
}

void* mac_thread(void* arg) {
    // Set CPU affinity to core 1
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(1, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    while (1) {
        // MAC processing logic
        printf("MAC thread running on core 1\n");
        sleep(1);
    }
    return NULL;
}

void* rlc_thread(void* arg) {
    // Set CPU affinity to core 1
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(1, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    while (1) {
        // MAC processing logic
        printf("MAC thread running on core 1\n");
        sleep(1);
    }
    return NULL;
}

void* pdcp_thread(void* arg) {
    // Set CPU affinity to core 1
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(1, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    while (1) {
        // MAC processing logic
        printf("MAC thread running on core 1\n");
        sleep(1);
    }
    return NULL;
}


void* nas_thread(void* arg) {
    // Set CPU affinity to core 1
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(1, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    while (1) {
        // MAC processing logic
        printf("MAC thread running on core 1\n");
        sleep(1);
    }
    return NULL;
}

void* rrc_thread(void* arg) {
    // Set CPU affinity to core 1
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(1, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    while (1) {
        // MAC processing logic
        printf("MAC thread running on core 1\n");
        sleep(1);
    }
    return NULL;
}

