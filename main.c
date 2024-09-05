#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <shared_memory.h>
#include <phy.h>
#include <mac.h>
#include <rlc.h>
#include <pdcp.h>
#include <rrc.h>
#include "nas.h"
#include "global_variables.h"

// Functions for each layer 
void* phy_thread(void* arg);
void* mac_thread(void* arg);
void* rlc_thread(void* arg);
void* pdcp_thread(void* arg);
void* rrc_thread(void* arg);
void* nas_thread(void* arg);

//GLobal Shared mem variable
SharedMemory shared_memory;

// Thread attributes 
pthread_attr_t attr;

// Thread IDS
pthread_t phy_tid, mac_tid, rlc_tid, pdcp_tid, rrc_tid, nas_tid;

// Function call, Core assignments //Assuming 6 Cores one each for(PHY, MAC, RRC, RLC, PDCP, NAS)
void* phy_thread(void* arg) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    while (1) {
        phy_layer_processing();
        printf("PHY thread running on core 0\n");
        sleep(1);
    }
    return NULL;
}

void* mac_thread(void* arg) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(1, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    while (1) {
        mac_layer_processing();
        printf("MAC thread running on core 1\n");
        sleep(1);
    }
    return NULL;
}

void* rlc_thread(void* arg) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(2, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    while (1) {
        rlc_layer_processing();
        printf("RLC thread running on core 2\n");
        sleep(1);
    }
    return NULL;
}

void* pdcp_thread(void* arg) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(3, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    while (1) {
        pdcp_layer_processing();
        printf("PDCP thread running on core 3\n");
        sleep(1);
    }
    return NULL;
}

void* rrc_thread(void* arg) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(4, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    while (1) {
        rrc_layer_processing();
        printf("RRC thread running on core 4\n");
        sleep(1);
    }
    return NULL;
}

void* nas_thread(void* arg) {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(5, &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    while (1) {
        nas_layer_processing();
        printf("NAS thread running on core 5\n");
        sleep(1);
    }
    return NULL;
}

int main() {
    // Initialize shared memory and global variables
    init_shared_memory(&shared_memory);
    pthread_attr_init(&attr);

    // Create threads for each protocol layer
    if (pthread_create(&phy_tid, &attr, phy_thread, NULL) != 0) {
        perror("Failed to create PHY thread");
        return 1;
    }
    if (pthread_create(&mac_tid, &attr, mac_thread, NULL) != 0) {
        perror("Failed to create MAC thread");
        return 1;
    }
    if (pthread_create(&rlc_tid, &attr, rlc_thread, NULL) != 0) {
        perror("Failed to create RLC thread");
        return 1;
    }
    if (pthread_create(&pdcp_tid, &attr, pdcp_thread, NULL) != 0) {
        perror("Failed to create PDCP thread");
        return 1;
    }
    if (pthread_create(&rrc_tid, &attr, rrc_thread, NULL) != 0) {
        perror("Failed to create RRC thread");
        return 1;
    }
    if (pthread_create(&nas_tid, &attr, nas_thread, NULL) != 0) {
        perror("Failed to create NAS thread");
        return 1;
    }

    // Wait for threads to complete
    pthread_join(phy_tid, NULL);
    pthread_join(mac_tid, NULL);
    pthread_join(rlc_tid, NULL);
    pthread_join(pdcp_tid, NULL);
    pthread_join(rrc_tid, NULL);
    pthread_join(nas_tid, NULL);

    // Update global slot and system frame number
    update_slot_sfn();

    // Cleanup
    pthread_attr_destroy(&attr);

    return 0;
}
