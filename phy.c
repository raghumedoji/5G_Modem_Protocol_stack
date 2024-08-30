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




void phy_layer_processing()
{
    dl_phy_layer_processing();
    ul_phy_layer_processing();
}
