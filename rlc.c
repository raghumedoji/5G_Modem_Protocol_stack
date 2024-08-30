#include "rlc.h"
#include "rrc.h"
#include "pdcp.h"
#include "mac.h"
#include "phy.h"
#include "nas.h"


void rlc_layer_processing()
{
    dl_rlc_processing();    
    ul_rlc_processing();
}
