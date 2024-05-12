#include "../type.h"
#include "../mac_def.h"
#define DIAGNOSIS_DELAY 100
u32 diagnosis_TX_Hang_HAXIDMA_PCIE(struct mac_ax_adapter *adapter);
u32 diagnosis_TX_Hang_DMAC_Common(struct mac_ax_adapter *adapter);
u32 diagnosis_TX_Hang_DMAC_Dispatcher(struct mac_ax_adapter *adapter);
u32 diagnosis_TX_Hang_DMAC_STA_scheduler(struct mac_ax_adapter *adapter);
u32 diagnosis_TX_Hang_CMAC_Common(struct mac_ax_adapter *adapter);
u32 diagnosis_TX_Hang_CMAC_SCH(struct mac_ax_adapter *adapter);
u32 diagnosis_TX_Hang_CMAC_PTCL(struct mac_ax_adapter *adapter);
u32 diagnosis_TX_Hang_CMAC_TMAC(struct mac_ax_adapter *adapter);
u32 diagnosis_TX_Hang_CMAC_TRXPTCL(struct mac_ax_adapter *adapter);
u32 diagnosis_TX_Hang_CMAC_RMAC(struct mac_ax_adapter *adapter);
u32 diagnosis_RX_Hang_HAXIDMA_PCIE(struct mac_ax_adapter *adapter);
u32 diagnosis_RX_Hang_DMAC_STA_scheduler(struct mac_ax_adapter *adapter);
u32 diagnosis_RX_Hang_CMAC_TRXPTCL(struct mac_ax_adapter *adapter);
u32 diagnosis_RX_Hang_CMAC_RMAC(struct mac_ax_adapter *adapter);
u32 diagnosis_TX_Hang(struct mac_ax_adapter *adapter);
u32 diagnosis_RX_Hang(struct mac_ax_adapter *adapter);
