#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Constants
#define PREAMBLE_TRANSMISSION 1
#define PREAMBLE_RECEIVED 2
#define MSG1 3
#define MSG2 4
#define MAX_RETRANSMISSIONS 3

int rar_timer 60

// Enumeration for RACH state
typedef enum {
    RACH_IDLE,
    RACH_MSG1_SENT,
    RACH_MSG2_RECEIVED,
} RachState;

// Structure for RACH procedure
typedef struct {
    RachState state;
    int preambleIndex;
    int raRnti;
    int retransmissions;
} RachProcedure;

// Function to send Msg1 (preamble transmission)
void sendMsg1(RachProcedure* rach) {
    // Simulate sending the preamble (Msg1)
    printf("Sending Msg1 with preamble index: %d\n", rach->preambleIndex);
    
    // Update RACH state
    rach->state = RACH_MSG1_SENT;
}

// Function to process Msg2 (RAR reception)
bool processMsg2(RachProcedure* rach, int receivedRaRnti) {
    if (receivedRaRnti == rach->raRnti) {
        printf("Msg2 received with matching RA-RNTI: %d\n", receivedRaRnti);
        
        // Update RACH state
        rach->state = RACH_MSG2_RECEIVED;
        return true;
    } else {
        printf("Msg2 received with non-matching RA-RNTI: %d\n", receivedRaRnti);
        return false;
    }
}

// Function to handle the RACH procedure
void handleRachProcedure(RachProcedure* rach) {
    // Initialize the RACH procedure
    rach->state = RACH_IDLE;
    rach->preambleIndex = 1; // Example preamble index
    rach->raRnti = 100; // Example RA-RNTI
    rach->retransmissions = 0;

    while (rach->retransmissions < MAX_RETRANSMISSIONS) {
        // Send Msg1
        sendMsg1(rach);
        sleep(rar_timer);

        // Simulate receiving Msg2 with RA-RNTI (for demonstration)
        int receivedRaRnti = 100; // Placeholder value

        if (processMsg2(rach, receivedRaRnti)) {
            printf("RACH procedure successful.\n");
            break;
        } else {
            rach->retransmissions++;
            printf("Retransmission attempt %d.\n", rach->retransmissions);
        }
    }

    if (rach->retransmissions == MAX_RETRANSMISSIONS) {
        printf("RACH procedure failed after maximum retransmissions.\n");
    }
}

// Main function
int main() {
    // Initialize the RACH procedure
    RachProcedure rach;
    handleRachProcedure(&rach);

    return 0;
}
