#include "rlc.h"
#include "rrc.h"
#include "pdcp.h"
#include "mac.h"
#include "phy.h"
#include "nas.h"


void mac_layer_processing()
{
    dl_mac_processing();    
    ul_mac_processing();
}
