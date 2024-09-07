Design!
Assuming 6 cores and each core is assigned to one thread(PHY, MAC, RLC, PDCP, NAS, RRC)

MAC Layer Functions

RRC layer functions

RRC Connection Establishment - Procedure to establish an RRC connection between the UE (User Equipment) and the network.

RRC Connection Re-establishment - Re-establishes the RRC connection when a failure in the current connection occurs due to radio link failure, handover failure, or security issues.

RRC Connection Release - Releases the established RRC connection and moves the UE to an idle or inactive state.

RRC Connection Reconfiguration - Used to modify RRC parameters, including reconfigurations related to DRB (Data Radio Bearer), SRB (Signaling Radio Bearer), and measurement configuration.

RRC Inactive State Transition - Manages transitions between RRC Connected and RRC Inactive states (e.g., release to RRC inactive).

RRC Handover - Manages handover from one cell to another, either intra-frequency or inter-frequency.

Paging - The network uses paging to notify the UE of incoming data while in idle or inactive state.

Security Mode Command - Establishes the security settings, including integrity protection and ciphering, by configuring algorithms and keys.

Measurement Reporting
UE reports measurements such as signal quality for handover and cell reselection decisions.

RRC Suspend/Resume - Manages RRC connection suspend/resume procedures, used in cases such as moving to/from RRC Inactive state.

System Information Acquisition -Involves acquiring and updating system information, including MIB, SIB1, and other system information blocks.

Cell Reselection - Procedure to select a new serving cell while in RRC_IDLE or RRC_INACTIVE state.

UE Capability Transfer - UE reports its capabilities, such as supported frequency bands, transmission modes, etc., to the network.

RRC Connection Re-establishment Reject - Rejects an RRC Connection Re-establishment request from the UE.


RRC Reconfiguration with Mobility - Initiates handover when mobility events trigger a need to change the serving cell.


RRC Resume Reject - Rejects an RRC Resume request from the UE.


RRC Failure Information Reporting - UE reports failure information to the network, such as radio link failure.

RRC Connection Re-establishment Request - The UE requests re-establishment of an RRC connection due to a failure scenario.

RRC Reconfiguration Complete - The UE informs the network that the reconfiguration is complete and successfully applied.
