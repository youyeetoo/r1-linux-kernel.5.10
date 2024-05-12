#include "diagnosis.h"
u32 diagnosis_TX_Hang_HAXIDMA_PCIE(struct mac_ax_adapter *adapter)
{
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	u32 reg1, cnt = 0;
	struct mac_ax_intf_ops *ops = adapter_to_intf_ops(adapter);

#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_HAXI_INIT_CFG1);
		if ((reg1 & 0x28080) != 0x8080) {
			PLTFM_MSG_ERR("Reg: R_AX_HAXI_INIT_CFG1 => %x, " \
				      "HAXIDMA Setting Error\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_HAXI_DMA_STOP1);
		if ((reg1 & 0xFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_HAXI_DMA_STOP1 => %x, " \
				      "HAXIDMA Stop\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_ACH0_PAGE_INFO_V1);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH0_PAGE_INFO_V1 => %x, " \
				      "Used page for ACH0, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(R_AX_ACH0_PAGE_INFO);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH0_PAGE_INFO => %x, " \
				      "Used page for ACH0, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_ACH1_PAGE_INFO_V1);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH1_PAGE_INFO_V1 => %x, " \
				      "Used page for ACH1, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(R_AX_ACH1_PAGE_INFO);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH1_PAGE_INFO => %x, " \
				      "Used page for ACH1, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_ACH2_PAGE_INFO_V1);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH2_PAGE_INFO_V1 => %x, " \
				      "Used page for ACH2, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(R_AX_ACH2_PAGE_INFO);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH2_PAGE_INFO => %x, " \
				      "Used page for ACH2, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_ACH3_PAGE_INFO_V1);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH3_PAGE_INFO_V1 => %x, " \
				      "Used page for ACH3, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(R_AX_ACH3_PAGE_INFO);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH3_PAGE_INFO => %x, " \
				      "Used page for ACH3, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_ACH4_PAGE_INFO_V1);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH4_PAGE_INFO_V1 => %x, " \
				      "Used page for ACH4, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(R_AX_ACH4_PAGE_INFO);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH4_PAGE_INFO => %x, " \
				      "Used page for ACH4, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_ACH5_PAGE_INFO_V1);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH5_PAGE_INFO_V1 => %x, " \
				      "Used page for ACH5, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(R_AX_ACH5_PAGE_INFO);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH5_PAGE_INFO => %x, " \
				      "Used page for ACH5, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_ACH6_PAGE_INFO_V1);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH6_PAGE_INFO_V1 => %x, " \
				      "Used page for ACH6, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(R_AX_ACH6_PAGE_INFO);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH6_PAGE_INFO => %x, " \
				      "Used page for ACH6, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_ACH7_PAGE_INFO_V1);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH7_PAGE_INFO_V1 => %x, " \
				      "Used page for ACH7, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(R_AX_ACH7_PAGE_INFO);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_ACH7_PAGE_INFO => %x, " \
				      "Used page for ACH7, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_CH8_PAGE_INFO_V1);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_CH8_PAGE_INFO_V1 => %x, " \
				      "Used page for ACH8, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(R_AX_CH8_PAGE_INFO);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_CH8_PAGE_INFO => %x, " \
				      "Used page for ACH8, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_CH9_PAGE_INFO_V1);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_CH9_PAGE_INFO_V1 => %x, " \
				      "Used page for ACH9, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(R_AX_CH9_PAGE_INFO);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_CH9_PAGE_INFO => %x, " \
				      "Used page for ACH9, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_CH10_PAGE_INFO_V1);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_CH10_PAGE_INFO_V1 => %x, " \
				      "Used page for ACH10, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(R_AX_CH10_PAGE_INFO);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_CH10_PAGE_INFO => %x, " \
				      "Used page for ACH10, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_CH11_PAGE_INFO_V1);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_CH11_PAGE_INFO_V1 => %x, " \
				      "Used page for ACH11, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(R_AX_CH11_PAGE_INFO);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_CH11_PAGE_INFO => %x, " \
				      "Used page for ACH11, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_CH12_PAGE_INFO_V1);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_CH12_PAGE_INFO_V1 => %x, " \
				      "Used page for ACH12, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(R_AX_CH12_PAGE_INFO);
		if ((reg1 & 0x1FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_CH12_PAGE_INFO => %x, " \
				      "Used page for ACH12, no TX for consumption.\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_DBG_ERR_FLAG_V1);
		if ((reg1 & 0x18) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_DBG_ERR_FLAG_V1 => %x, " \
				      "PCIE TRX Stuck event!\n", reg1);
			cnt += 1;
		}
	}
#endif
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB))
		return cnt;
#endif
	return MACSUCCESS;
}

u32 diagnosis_TX_Hang_DMAC_Common(struct mac_ax_adapter *adapter)
{
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	u32 reg1, cnt = 0;
	struct mac_ax_intf_ops *ops = adapter_to_intf_ops(adapter);

#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(0x8400);
		if ((reg1 & 0xFFFF0000) != 0xFFFF0000) {
			PLTFM_MSG_ERR("Reg: 0x8400 => %x, " \
				      "DMAC function enable setting error\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT)) {
		reg1 = MAC_REG_R32(0x8404);
		if ((reg1 & 0xFFFF0000) != 0xFFFF0000) {
			PLTFM_MSG_ERR("Reg: 0x8404 => %x, " \
				      "DMAC Clock enable setting error\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(0x8400);
		if ((reg1 & 0xFFFF4000) != 0xFFFF4000) {
			PLTFM_MSG_ERR("Reg: 0x8400 => %x, " \
				      "DMAC function enable setting error\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(0x8404);
		if ((reg1 & 0xF9F0000) != 0xF9F0000) {
			PLTFM_MSG_ERR("Reg: 0x8404 => %x, " \
				      "DMAC Clock enable setting error\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_DMAC_ERR_ISR);
		if ((reg1 & 0x7FFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_DMAC_ERR_ISR => %x, " \
				      "DMAC Error Indication\n", reg1);
			cnt += 1;
		}
	}
#endif
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E))
		return cnt;
#endif
	return MACSUCCESS;
}

u32 diagnosis_TX_Hang_DMAC_Dispatcher(struct mac_ax_adapter *adapter)
{
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	u32 reg1, cnt = 0;
	struct mac_ax_intf_ops *ops = adapter_to_intf_ops(adapter);

#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_DMAC_MACID_DROP_0);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_DMAC_MACID_DROP_0 => %x, " \
				      "DMAC MACID_DROP_0 has been setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_DMAC_MACID_DROP_1);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_DMAC_MACID_DROP_1 => %x, " \
				      "DMAC MACID_DROP_1 has been setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_DMAC_MACID_DROP_2);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_DMAC_MACID_DROP_2 => %x, " \
				      "DMAC MACID_DROP_2 has been setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_DMAC_MACID_DROP_3);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_DMAC_MACID_DROP_3 => %x, " \
				      "DMAC MACID_DROP_3 has been setted\n", reg1);
			cnt += 1;
		}
	}
#endif
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E))
		return cnt;
#endif
	return MACSUCCESS;
}

u32 diagnosis_TX_Hang_DMAC_STA_scheduler(struct mac_ax_adapter *adapter)
{
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	u32 reg1, cnt = 0;
	struct mac_ax_intf_ops *ops = adapter_to_intf_ops(adapter);

#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_SS_MACID_PAUSE_0);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_SS_MACID_PAUSE_0 => %x, " \
				      "MACID PAUSE 0 has beed setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_SS_MACID_PAUSE_1);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_SS_MACID_PAUSE_1 => %x, " \
				      "MACID PAUSE 1 has beed setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_SS_MACID_PAUSE_2);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_SS_MACID_PAUSE_2 => %x, " \
				      "MACID PAUSE 2 has beed setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_SS_MACID_PAUSE_3);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_SS_MACID_PAUSE_3 => %x, " \
				      "MACID PAUSE 3 has beed setted\n", reg1);
			cnt += 1;
		}
	}
#endif
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E))
		return cnt;
#endif
	return MACSUCCESS;
}

u32 diagnosis_TX_Hang_CMAC_Common(struct mac_ax_adapter *adapter)
{
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	u32 reg1, cnt = 0;
	struct mac_ax_intf_ops *ops = adapter_to_intf_ops(adapter);

#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(0xC000);
		if ((reg1 & 0xF000003F) != 0xF000003F) {
			PLTFM_MSG_ERR("Reg: 0xC000 => %x, " \
				      "CMAC function enable setting error\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(0xC004);
		if ((reg1 & 0x4000003F) != 0x4000003F) {
			PLTFM_MSG_ERR("Reg: 0xC004 => %x, " \
				      "CMAC Clock enable setting error\n", reg1);
			cnt += 1;
		}
	}
#endif
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E))
		return cnt;
#endif
	return MACSUCCESS;
}

u32 diagnosis_TX_Hang_CMAC_SCH(struct mac_ax_adapter *adapter)
{
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	u32 reg1, cnt = 0;
	struct mac_ax_intf_ops *ops = adapter_to_intf_ops(adapter);

#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_CMAC_MACID_DROP_0);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_CMAC_MACID_DROP_0 => %x, " \
				      "CMAC MACID_DROP_0 has been setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_CMAC_MACID_DROP_1);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_CMAC_MACID_DROP_1 => %x, " \
				      "CMAC MACID_DROP_1 has been setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_CMAC_MACID_DROP_2);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_CMAC_MACID_DROP_2 => %x, " \
				      "CMAC MACID_DROP_2 has been setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_CMAC_MACID_DROP_3);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_CMAC_MACID_DROP_3 => %x, " \
				      "CMAC MACID_DROP_3 has been setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_MBSSID_DROP_0);
		if ((reg1 & 0x1FFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_MBSSID_DROP_0 => %x, " \
				      "MBSSID_DROP has been setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_MACID_SLEEP_0);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_MACID_SLEEP_0 => %x, " \
				      "MACID_SLEEP_0 has been setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_MACID_SLEEP_1);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_MACID_SLEEP_1 => %x, " \
				      "MACID_SLEEP_1 has been setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_MACID_SLEEP_2);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_MACID_SLEEP_2 => %x, " \
				      "MACID_SLEEP_2 has been setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_MACID_SLEEP_3);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_MACID_SLEEP_3 => %x, " \
				      "MACID_SLEEP_3 has been setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_CTN_TXEN);
		if ((reg1 & 0xFFFF) != 0xFFFF) {
			PLTFM_MSG_ERR("Reg: R_AX_CTN_TXEN => %x, " \
				      "Contension TXEN setting error\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_CTN_DRV_TXEN);
		if ((reg1 & 0xFFFF) != 0xFFFF) {
			PLTFM_MSG_ERR("Reg: R_AX_CTN_DRV_TXEN => %x, " \
				      "Contension DRV TXEN setting error\n", reg1);
			cnt += 1;
		}
	}
#endif
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E))
		return cnt;
#endif
	return MACSUCCESS;
}

u32 diagnosis_TX_Hang_CMAC_PTCL(struct mac_ax_adapter *adapter)
{
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	u32 reg1, cnt = 0;
	struct mac_ax_intf_ops *ops = adapter_to_intf_ops(adapter);

#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(0xC600);
		if ((reg1 & 0x3) != 0x3) {
			PLTFM_MSG_ERR("Reg: 0xC600 => %x, " \
				      "HW mode TX setting error\n", reg1);
			cnt += 1;
		}
	}
#endif
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E))
		return cnt;
#endif
	return MACSUCCESS;
}

u32 diagnosis_TX_Hang_CMAC_TMAC(struct mac_ax_adapter *adapter)
{
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	u32 reg1, reg2, cnt = 0;
	struct mac_ax_intf_ops *ops = adapter_to_intf_ops(adapter);

#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		MAC_REG_W32(R_AX_TX_PPDU_CNT, 2);
		reg1 = MAC_REG_R32(R_AX_TX_PPDU_CNT);
		PLTFM_DELAY_MS(DIAGNOSIS_DELAY);
		reg2 = MAC_REG_R32(R_AX_TX_PPDU_CNT);
		if ((reg2 & 0xFFFF0000) <= (reg1 & 0xFFFF0000)) {
			PLTFM_MSG_ERR("Reg: B0 TX_PPDU_CNT[2 OFDM] => %x, " \
				      "OFDM counter should be incremantal " \
				      "Otherwise Response TX may stuck\n", reg1);
			cnt += 1;
		}
	}
#endif
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E))
		return cnt;
#endif
	return MACSUCCESS;
}

u32 diagnosis_TX_Hang_CMAC_TRXPTCL(struct mac_ax_adapter *adapter)
{
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	u32 reg1, cnt = 0;
	struct mac_ax_intf_ops *ops = adapter_to_intf_ops(adapter);

#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_MAC_LOOPBACK);
		if ((reg1 & 0x1) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_MAC_LOOPBACK => %x, " \
				      "MAC LB mode setted\n", reg1);
			cnt += 1;
		}
	}
#endif
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E))
		return cnt;
#endif
	return MACSUCCESS;
}

u32 diagnosis_TX_Hang_CMAC_RMAC(struct mac_ax_adapter *adapter)
{
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	u32 reg1, reg2, cnt = 0;
	struct mac_ax_intf_ops *ops = adapter_to_intf_ops(adapter);

#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		MAC_REG_W32(R_AX_RX_DBG_CNT_SEL, 0);
		reg1 = MAC_REG_R32(R_AX_RX_DBG_CNT_SEL);
		PLTFM_DELAY_MS(DIAGNOSIS_DELAY);
		reg2 = MAC_REG_R32(R_AX_RX_DBG_CNT_SEL);
		if ((reg2 & 0xFFFF0000) <= (reg1 & 0xFFFF0000)) {
			PLTFM_MSG_ERR("Reg: B0 RX_CNT[0 OFDM_OK] => %x, " \
				      "OFDM counter should be incremantal " \
				      "RX might be stuck\n", reg1);
			cnt += 1;
		}
	}
#endif
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E))
		return cnt;
#endif
	return MACSUCCESS;
}

u32 diagnosis_RX_Hang_HAXIDMA_PCIE(struct mac_ax_adapter *adapter)
{
#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	u32 reg1, cnt = 0;
	struct mac_ax_intf_ops *ops = adapter_to_intf_ops(adapter);

#if (MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB)) {
		reg1 = MAC_REG_R32(R_AX_DBG_ERR_FLAG_V1);
		if ((reg1 & 0x18) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_DBG_ERR_FLAG_V1 => %x, " \
				      "PCIE TRX Stuck event!\n", reg1);
			cnt += 1;
		}
	}
#endif
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB))
		return cnt;
#endif
	return MACSUCCESS;
}

u32 diagnosis_RX_Hang_DMAC_STA_scheduler(struct mac_ax_adapter *adapter)
{
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	u32 reg1, cnt = 0;
	struct mac_ax_intf_ops *ops = adapter_to_intf_ops(adapter);

#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_SS_MACID_PAUSE_0);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_SS_MACID_PAUSE_0 => %x, " \
				      "MACID PAUSE 0 has beed setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_SS_MACID_PAUSE_1);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_SS_MACID_PAUSE_1 => %x, " \
				      "MACID PAUSE 1 has beed setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_SS_MACID_PAUSE_2);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_SS_MACID_PAUSE_2 => %x, " \
				      "MACID PAUSE 2 has beed setted\n", reg1);
			cnt += 1;
		}
	}
#endif
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_SS_MACID_PAUSE_3);
		if ((reg1 & 0xFFFFFFFF) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_SS_MACID_PAUSE_3 => %x, " \
				      "MACID PAUSE 3 has beed setted\n", reg1);
			cnt += 1;
		}
	}
#endif
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E))
		return cnt;
#endif
	return MACSUCCESS;
}

u32 diagnosis_RX_Hang_CMAC_TRXPTCL(struct mac_ax_adapter *adapter)
{
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	u32 reg1, cnt = 0;
	struct mac_ax_intf_ops *ops = adapter_to_intf_ops(adapter);

#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		reg1 = MAC_REG_R32(R_AX_MAC_LOOPBACK);
		if ((reg1 & 0x1) != 0) {
			PLTFM_MSG_ERR("Reg: R_AX_MAC_LOOPBACK => %x, " \
				      "MAC LB mode setted\n", reg1);
			cnt += 1;
		}
	}
#endif
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E))
		return cnt;
#endif
	return MACSUCCESS;
}

u32 diagnosis_RX_Hang_CMAC_RMAC(struct mac_ax_adapter *adapter)
{
#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	u32 reg1, reg2, cnt = 0;
	struct mac_ax_intf_ops *ops = adapter_to_intf_ops(adapter);

#if (MAC_AX_8852A_SUPPORT || \
MAC_AX_8852B_SUPPORT || \
MAC_AX_8851B_SUPPORT || \
MAC_AX_8852BT_SUPPORT || \
MAC_AX_8852C_SUPPORT || \
MAC_AX_8852D_SUPPORT || \
MAC_AX_8192XB_SUPPORT || \
MAC_AX_8851E_SUPPORT)
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E)) {
		MAC_REG_W32(R_AX_RX_DBG_CNT_SEL, 0);
		reg1 = MAC_REG_R32(R_AX_RX_DBG_CNT_SEL);
		PLTFM_DELAY_MS(DIAGNOSIS_DELAY);
		reg2 = MAC_REG_R32(R_AX_RX_DBG_CNT_SEL);
		if ((reg2 & 0xFFFF0000) <= (reg1 & 0xFFFF0000)) {
			PLTFM_MSG_ERR("Reg: B0 RX_CNT[0 OFDM_OK] => %x, " \
				      "OFDM counter should be incremantal " \
				      "RX might be stuck\n", reg1);
			cnt += 1;
		}
	}
#endif
	if (is_chip_id(adapter, MAC_AX_CHIP_ID_8852A) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851B) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852BT) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852C) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8852D) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8192XB) ||
	    is_chip_id(adapter, MAC_AX_CHIP_ID_8851E))
		return cnt;
#endif
	return MACSUCCESS;
}

u32 diagnosis_TX_Hang(struct mac_ax_adapter *adapter)
{
	u32 cnt = 0;

#if MAC_AX_PCIE_SUPPORT
	cnt += diagnosis_TX_Hang_HAXIDMA_PCIE(adapter);
#endif
	cnt += diagnosis_TX_Hang_DMAC_Common(adapter);
	cnt += diagnosis_TX_Hang_DMAC_Dispatcher(adapter);
	cnt += diagnosis_TX_Hang_DMAC_STA_scheduler(adapter);
	cnt += diagnosis_TX_Hang_CMAC_Common(adapter);
	cnt += diagnosis_TX_Hang_CMAC_SCH(adapter);
	cnt += diagnosis_TX_Hang_CMAC_PTCL(adapter);
	cnt += diagnosis_TX_Hang_CMAC_TMAC(adapter);
	cnt += diagnosis_TX_Hang_CMAC_TRXPTCL(adapter);
	cnt += diagnosis_TX_Hang_CMAC_RMAC(adapter);
	if (cnt > 0) {
		PLTFM_MSG_ERR("################################\n");
		PLTFM_MSG_ERR("####TX_Hang Error counter:%d####\n", cnt);
		PLTFM_MSG_ERR("################################\n\n");
	}

	return cnt;
}

u32 diagnosis_RX_Hang(struct mac_ax_adapter *adapter)
{
	u32 cnt = 0;

#if MAC_AX_PCIE_SUPPORT
	cnt += diagnosis_RX_Hang_HAXIDMA_PCIE(adapter);
#endif
	cnt += diagnosis_RX_Hang_DMAC_STA_scheduler(adapter);
	cnt += diagnosis_RX_Hang_CMAC_TRXPTCL(adapter);
	cnt += diagnosis_RX_Hang_CMAC_RMAC(adapter);
	if (cnt > 0) {
		PLTFM_MSG_ERR("################################\n");
		PLTFM_MSG_ERR("####RX_Hang Error counter:%d####\n", cnt);
		PLTFM_MSG_ERR("################################\n\n");
	}

	return cnt;
}

