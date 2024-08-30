#include "rlc.h"
#include "rrc.h"
#include "pdcp.h"
#include "mac.h"
#include "phy.h"
#include "nas.h"


void rlc_layer_processing()
{
    dl_pdcp_processing();    
    ul_pdcp_processing();
}

