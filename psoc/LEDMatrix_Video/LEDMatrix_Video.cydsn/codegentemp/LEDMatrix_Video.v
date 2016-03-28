// ======================================================================
// LEDMatrix_Video.v generated from TopDesign.cysch
// 03/04/2016 at 11:51
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_TMA4 2
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 3
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PANTHER 5
`define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1
`define CYDEV_CHIP_REV_PANTHER_ES1 1
`define CYDEV_CHIP_REV_PANTHER_ES0 0
`define CYDEV_CHIP_DIE_EXPECT 4
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 4
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_MEMBER_4G 2
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 3
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 4
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 5
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 6
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 7
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 8
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 9
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 10
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 11
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4F 12
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4M 13
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 14
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 15
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4C 16
`define CYDEV_CHIP_REVISION_4C_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_MEMBER_5B 17
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 18
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 17
`define CYDEV_CHIP_REVISION_USED 0
// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: bSegLCD_v3_40
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bSegLCD_v3_40"
`include "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bSegLCD_v3_40\bSegLCD_v3_40.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bSegLCD_v3_40"
`include "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bSegLCD_v3_40\bSegLCD_v3_40.v"
`endif

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// SegLCD_v3_40(AdvancedDPSettings=false, BiasType=0, BiasVoltage=63, ClockFrequency=27520, CustomCharsList={{0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x3E, 0x1C, 0x1C, 0x08, 0x08}, {0x08, 0x08, 0x18, 0x1C, 0x3E}, {0x02, 0x06, 0x08, 0x10, 0x20}, {0x00, 0x4F, 0x00, 0x4F, 0x00}, {0x06, 0x0F, 0x7F, 0x01, 0x7F}, {0x48, 0x56, 0x55, 0x35, 0x09}, {0x0C, 0x0C, 0x0C, 0x0C, 0x0C}, {0x10, 0x38, 0x54, 0x10, 0x1F}, {0x04, 0x02, 0x7F, 0x02, 0x04}, {0x10, 0x20, 0x7F, 0x20, 0x10}, {0x7F, 0x3E, 0x1C, 0x08, 0x7F}, {0x7F, 0x08, 0x1C, 0x3E, 0x7F}, {0x7F, 0x08, 0x2A, 0x1C, 0x08}, {0x08, 0x1C, 0x2A, 0x08, 0x7F}, {0x02, 0x0E, 0x3E, 0x0E, 0x02}, {0x20, 0x38, 0x3E, 0x38, 0x20}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x00, 0x00, 0x4F, 0x00, 0x00}, {0x00, 0x07, 0x00, 0x07, 0x00}, {0x14, 0x7F, 0x14, 0x7F, 0x14}, {0x24, 0x2A, 0x7F, 0x2A, 0x12}, {0x23, 0x13, 0x08, 0x64, 0x62}, {0x36, 0x49, 0x55, 0x22, 0x50}, {0x00, 0x05, 0x03, 0x00, 0x00}, {0x00, 0x1C, 0x22, 0x41, 0x00}, {0x00, 0x41, 0x22, 0x1C, 0x00}, {0x14, 0x08, 0x3E, 0x08, 0x14}, {0x08, 0x08, 0x3E, 0x08, 0x08}, {0x00, 0x50, 0x30, 0x00, 0x00}, {0x08, 0x08, 0x08, 0x08, 0x08}, {0x00, 0x60, 0x60, 0x00, 0x00}, {0x20, 0x10, 0x08, 0x04, 0x02}, {0x3E, 0x51, 0x49, 0x45, 0x3E}, {0x00, 0x42, 0x7F, 0x40, 0x00}, {0x42, 0x61, 0x51, 0x49, 0x46}, {0x21, 0x41, 0x45, 0x4B, 0x31}, {0x18, 0x14, 0x12, 0x7F, 0x10}, {0x27, 0x45, 0x45, 0x45, 0x39}, {0x3C, 0x4A, 0x49, 0x49, 0x30}, {0x01, 0x71, 0x09, 0x05, 0x03}, {0x36, 0x49, 0x49, 0x49, 0x36}, {0x06, 0x49, 0x49, 0x29, 0x1E}, {0x00, 0x36, 0x36, 0x00, 0x00}, {0x00, 0x56, 0x36, 0x00, 0x00}, {0x08, 0x14, 0x22, 0x41, 0x00}, {0x14, 0x14, 0x14, 0x14, 0x14}, {0x00, 0x41, 0x22, 0x14, 0x08}, {0x02, 0x01, 0x51, 0x09, 0x06}, {0x32, 0x49, 0x79, 0x41, 0x3E}, {0x7E, 0x11, 0x11, 0x11, 0x7E}, {0x7F, 0x49, 0x49, 0x49, 0x36}, {0x3E, 0x41, 0x41, 0x41, 0x22}, {0x7F, 0x41, 0x41, 0x22, 0x1C}, {0x7F, 0x49, 0x49, 0x49, 0x41}, {0x7F, 0x09, 0x09, 0x09, 0x01}, {0x3E, 0x41, 0x49, 0x49, 0x3A}, {0x7F, 0x08, 0x08, 0x08, 0x7F}, {0x00, 0x41, 0x7F, 0x41, 0x00}, {0x20, 0x40, 0x41, 0x3F, 0x01}, {0x7F, 0x08, 0x14, 0x22, 0x41}, {0x7F, 0x40, 0x40, 0x40, 0x40}, {0x7F, 0x02, 0x0C, 0x02, 0x7F}, {0x7F, 0x04, 0x08, 0x10, 0x7F}, {0x3E, 0x41, 0x41, 0x41, 0x3E}, {0x7F, 0x09, 0x09, 0x09, 0x06}, {0x3E, 0x41, 0x51, 0x21, 0x5E}, {0x7F, 0x09, 0x19, 0x29, 0x46}, {0x46, 0x49, 0x49, 0x49, 0x31}, {0x01, 0x01, 0x7F, 0x01, 0x01}, {0x3F, 0x40, 0x40, 0x40, 0x3F}, {0x1F, 0x20, 0x40, 0x20, 0x1F}, {0x3F, 0x40, 0x38, 0x40, 0x3F}, {0x63, 0x14, 0x08, 0x14, 0x63}, {0x07, 0x08, 0x70, 0x08, 0x07}, {0x61, 0x51, 0x49, 0x45, 0x43}, {0x00, 0x7F, 0x41, 0x41, 0x00}, {0x15, 0x16, 0x7C, 0x16, 0x15}, {0x00, 0x41, 0x41, 0x7F, 0x00}, {0x04, 0x02, 0x01, 0x02, 0x04}, {0x40, 0x40, 0x40, 0x40, 0x40}, {0x00, 0x01, 0x02, 0x04, 0x00}, {0x20, 0x54, 0x54, 0x54, 0x78}, {0x7F, 0x48, 0x44, 0x44, 0x38}, {0x38, 0x44, 0x44, 0x44, 0x40}, {0x38, 0x44, 0x44, 0x48, 0x7F}, {0x38, 0x54, 0x54, 0x54, 0x18}, {0x08, 0x7E, 0x09, 0x01, 0x02}, {0x0C, 0x52, 0x52, 0x52, 0x3E}, {0x7F, 0x08, 0x04, 0x04, 0x78}, {0x00, 0x44, 0x7D, 0x40, 0x00}, {0x20, 0x40, 0x40, 0x3D, 0x00}, {0x7F, 0x10, 0x28, 0x44, 0x00}, {0x00, 0x41, 0x7F, 0x40, 0x00}, {0x7C, 0x04, 0x18, 0x04, 0x78}, {0x7C, 0x08, 0x04, 0x04, 0x78}, {0x38, 0x44, 0x44, 0x44, 0x38}, {0x7C, 0x14, 0x14, 0x14, 0x08}, {0x08, 0x14, 0x14, 0x18, 0x7C}, {0x7C, 0x08, 0x04, 0x04, 0x08}, {0x48, 0x54, 0x54, 0x54, 0x20}, {0x04, 0x3F, 0x44, 0x40, 0x20}, {0x3C, 0x40, 0x40, 0x20, 0x7C}, {0x1C, 0x20, 0x40, 0x20, 0x1C}, {0x3C, 0x40, 0x30, 0x40, 0x3C}, {0x44, 0x28, 0x10, 0x28, 0x44}, {0x0C, 0x50, 0x50, 0x50, 0x3C}, {0x44, 0x64, 0x54, 0x4C, 0x44}, {0x00, 0x08, 0x36, 0x41, 0x00}, {0x00, 0x00, 0x7F, 0x00, 0x00}, {0x00, 0x41, 0x36, 0x08, 0x00}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x08, 0x08, 0x2A, 0x1C, 0x08}, {0x44, 0x44, 0x5F, 0x44, 0x44}, {0x22, 0x14, 0x08, 0x14, 0x22}, {0x1C, 0x3E, 0x3E, 0x3E, 0x1C}, {0x7F, 0x41, 0x41, 0x41, 0x7F}, {0x7F, 0x5B, 0x41, 0x5F, 0x7F}, {0x7F, 0x4D, 0x55, 0x59, 0x7F}, {0x1D, 0x15, 0x17, 0x00, 0x00}, {0x15, 0x15, 0x1F, 0x00, 0x00}, {0x17, 0x08, 0x74, 0x56, 0x5D}, {0x17, 0x08, 0x24, 0x32, 0x79}, {0x35, 0x1F, 0x28, 0x34, 0x7A}, {0x08, 0x14, 0x2A, 0x14, 0x22}, {0x22, 0x14, 0x2A, 0x14, 0x08}, {0x08, 0x04, 0x08, 0x10, 0x08}, {0x14, 0x0A, 0x14, 0x28, 0x14}, {0x2A, 0x55, 0x2A, 0x55, 0x2A}, {0x24, 0x3B, 0x2A, 0x7E, 0x2A}, {0x40, 0x3F, 0x15, 0x15, 0x7F}, {0x46, 0x20, 0x1F, 0x20, 0x46}, {0x24, 0x14, 0x7F, 0x18, 0x24}, {0x24, 0x14, 0x7F, 0x14, 0x24}, {0x44, 0x6A, 0x79, 0x6A, 0x44}, {0x40, 0x44, 0x7F, 0x44, 0x40}, {0x7F, 0x49, 0x49, 0x49, 0x7F}, {0x02, 0x4C, 0x30, 0x0C, 0x02}, {0x04, 0x04, 0x3C, 0x04, 0x44}, {0x49, 0x55, 0x7F, 0x55, 0x49}, {0x3A, 0x45, 0x45, 0x45, 0x39}, {0x40, 0x3E, 0x10, 0x10, 0x1E}, {0x08, 0x54, 0x3E, 0x15, 0x08}, {0x7F, 0x7F, 0x7F, 0x7F, 0x7F}, {0x55, 0x2A, 0x55, 0x2A, 0x55}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0x70, 0x50, 0x70, 0x00, 0x00}, {0x00, 0x00, 0x0F, 0x01, 0x01}, {0x40, 0x40, 0x70, 0x00, 0x00}, {0x10, 0x20, 0x40, 0x00, 0x00}, {0x00, 0x18, 0x18, 0x00, 0x00}, {0x0A, 0x0A, 0x4A, 0x2A, 0x1E}, {0x04, 0x44, 0x34, 0x14, 0x0C}, {0x20, 0x10, 0x78, 0x04, 0x00}, {0x18, 0x08, 0x4C, 0x48, 0x38}, {0x48, 0x48, 0x78, 0x48, 0x48}, {0x48, 0x28, 0x18, 0x78, 0x08}, {0x08, 0x7C, 0x08, 0x28, 0x18}, {0x40, 0x48, 0x48, 0x78, 0x40}, {0x54, 0x54, 0x54, 0x7C, 0x00}, {0x18, 0x00, 0x58, 0x40, 0x38}, {0x08, 0x08, 0x08, 0x08, 0x08}, {0x01, 0x41, 0x3D, 0x09, 0x07}, {0x10, 0x08, 0x78, 0x02, 0x01}, {0x06, 0x02, 0x43, 0x22, 0x1E}, {0x42, 0x42, 0x7E, 0x42, 0x42}, {0x22, 0x12, 0x0A, 0x7F, 0x02}, {0x42, 0x3F, 0x02, 0x42, 0x3E}, {0x0A, 0x0A, 0x7F, 0x0A, 0x0A}, {0x08, 0x46, 0x42, 0x22, 0x1E}, {0x04, 0x03, 0x42, 0x3E, 0x02}, {0x42, 0x42, 0x42, 0x42, 0x7E}, {0x02, 0x4F, 0x22, 0x1F, 0x02}, {0x4A, 0x4A, 0x40, 0x20, 0x1C}, {0x42, 0x22, 0x12, 0x2A, 0x46}, {0x02, 0x3F, 0x42, 0x4A, 0x46}, {0x06, 0x48, 0x40, 0x20, 0x1E}, {0x08, 0x46, 0x4A, 0x32, 0x1E}, {0x0A, 0x4A, 0x3E, 0x09, 0x08}, {0x0E, 0x00, 0x4E, 0x20, 0x1E}, {0x04, 0x45, 0x3D, 0x05, 0x04}, {0x00, 0x7F, 0x08, 0x10, 0x00}, {0x44, 0x24, 0x1F, 0x04, 0x04}, {0x40, 0x42, 0x42, 0x42, 0x40}, {0x42, 0x2A, 0x12, 0x2A, 0x06}, {0x22, 0x12, 0x7A, 0x16, 0x22}, {0x00, 0x40, 0x20, 0x1F, 0x00}, {0x78, 0x00, 0x02, 0x04, 0x78}, {0x3F, 0x44, 0x44, 0x44, 0x44}, {0x02, 0x42, 0x42, 0x22, 0x1E}, {0x04, 0x02, 0x04, 0x08, 0x30}, {0x32, 0x02, 0x7F, 0x02, 0x32}, {0x02, 0x12, 0x22, 0x52, 0x0E}, {0x00, 0x2A, 0x2A, 0x2A, 0x40}, {0x38, 0x24, 0x22, 0x20, 0x1E}, {0x40, 0x28, 0x10, 0x28, 0x06}, {0x0A, 0x3E, 0x4A, 0x4A, 0x4A}, {0x04, 0x7F, 0x04, 0x14, 0x0C}, {0x40, 0x42, 0x42, 0x7E, 0x40}, {0x4A, 0x4A, 0x4A, 0x4A, 0x7E}, {0x04, 0x05, 0x45, 0x15, 0x1C}, {0x0F, 0x40, 0x20, 0x1F, 0x00}, {0x7C, 0x00, 0x7E, 0x40, 0x30}, {0x7E, 0x40, 0x20, 0x10, 0x08}, {0x7E, 0x7E, 0x7E, 0x7E, 0x7E}, {0x0E, 0x02, 0x42, 0x22, 0x1E}, {0x42, 0x42, 0x40, 0x20, 0x18}, {0x02, 0x04, 0x01, 0x02, 0x00}, {0x07, 0x05, 0x07, 0x00, 0x00}, {0x38, 0x44, 0x48, 0x30, 0x4C}, {0x20, 0x55, 0x55, 0x55, 0x38}, {0xFE, 0x15, 0x15, 0x15, 0x0A}, {0x28, 0x54, 0x54, 0x44, 0x20}, {0xFF, 0x10, 0x10, 0x08, 0x1F}, {0x38, 0x44, 0x4C, 0x54, 0x24}, {0xFC, 0x12, 0x11, 0x11, 0x0E}, {0x0E, 0xA1, 0xA1, 0xA1, 0x7F}, {0x20, 0x40, 0x3C, 0x04, 0x04}, {0x04, 0x04, 0x00, 0x0E, 0x00}, {0x40, 0x80, 0x81, 0x7F, 0x00}, {0x0A, 0x04, 0x0A, 0x00, 0x00}, {0x18, 0x24, 0x7E, 0x24, 0x10}, {0x14, 0x7F, 0x54, 0x40, 0x40}, {0x7C, 0x0A, 0x05, 0x05, 0x78}, {0x38, 0x45, 0x45, 0x45, 0x38}, {0xFF, 0x12, 0x11, 0x11, 0x0E}, {0x0E, 0x11, 0x11, 0x12, 0xFF}, {0x3C, 0x4A, 0x4A, 0x4A, 0x3C}, {0x30, 0x28, 0x10, 0x28, 0x18}, {0x58, 0x64, 0x04, 0x64, 0x58}, {0x3C, 0x41, 0x40, 0x21, 0x7C}, {0x63, 0x55, 0x4A, 0x41, 0x41}, {0x44, 0x3C, 0x04, 0x7C, 0x44}, {0x45, 0x29, 0x11, 0x29, 0x45}, {0x0F, 0x90, 0x90, 0x90, 0x7F}, {0x14, 0x14, 0x7C, 0x14, 0x12}, {0x44, 0x3C, 0x14, 0x14, 0x74}, {0x7C, 0x14, 0x1C, 0x14, 0x7C}, {0x10, 0x10, 0x54, 0x10, 0x10}, {0x00, 0x00, 0x00, 0x00, 0x00}, {0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};, CustomStep=1, FrameRate=10, Gang=false, GlassSize=10, Helpers=<?xml version="1.0" encoding="utf-16"?> <ArrayOfAnyType xmlns:CustomizerVersion="CyComponentLibrary_21ad3f60981bcfd3b7b04d4bd0325112bba9a9512eef82f5c5844933688040e7, Version=0.0.0.0, Culture=neutral, PublicKeyToken=null">   <anyType d2p1:type="HelperInfo" xmlns:d2p1="http://www.w3.org/2001/XMLSchema-instance">     <Name>Empty</Name>     <Color>0</Color>     <GlobalHelperIndex>0</GlobalHelperIndex>     <HelpSegInfoArray>       <HelperSegmentInfo Name="PIX0" Com="0" Seg="0" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX1" Com="1" Seg="0" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX2" Com="2" Seg="0" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX3" Com="3" Seg="0" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX4" Com="4" Seg="0" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX5" Com="0" Seg="1" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX6" Com="1" Seg="1" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX7" Com="2" Seg="1" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX8" Com="3" Seg="1" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX9" Com="4" Seg="1" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX10" Com="0" Seg="2" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX11" Com="1" Seg="2" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX12" Com="2" Seg="2" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX13" Com="3" Seg="2" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX14" Com="4" Seg="2" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX15" Com="0" Seg="3" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX16" Com="1" Seg="3" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX17" Com="2" Seg="3" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX18" Com="3" Seg="3" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX19" Com="4" Seg="3" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX20" Com="0" Seg="4" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX21" Com="1" Seg="4" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX22" Com="2" Seg="4" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX23" Com="3" Seg="4" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX24" Com="4" Seg="4" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX25" Com="0" Seg="5" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX26" Com="1" Seg="5" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX27" Com="2" Seg="5" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX28" Com="3" Seg="5" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX29" Com="4" Seg="5" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX30" Com="0" Seg="6" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX31" Com="1" Seg="6" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX32" Com="2" Seg="6" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX33" Com="3" Seg="6" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>       <HelperSegmentInfo Name="PIX34" Com="4" Seg="6" Display="-1" Digit="-1" Helper="Empty" RelPos="-1">         <GlobalDigitNum>-1</GlobalDigitNum>       </HelperSegmentInfo>     </HelpSegInfoArray>     <Kind>Empty</Kind>     <MaxSymbolsCount>0</MaxSymbolsCount>     <SegmentCount>0</SegmentCount>     <DisplayNum>-1</DisplayNum>     <SymbolsCount>0</SymbolsCount>   </anyType> </ArrayOfAnyType>, HiDriveStrength=5, HiDriveTime=1, LowDriveStrength=7, LowDriveTime=253, Mode=0, NumCommonLines=5, NumSegmentLines=7, Supply=1, TimerPeriod=15, UseCustomStep=false, WaveformType=0, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=SegLCD_v3_40, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=LCD_Seg_1, CY_INSTANCE_SHORT_NAME=LCD_Seg_1, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=40, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 SP1, INSTANCE_NAME=LCD_Seg_1, )
module SegLCD_v3_40_0 ;


          wire  Net_260;
          wire  Net_259;
          wire  Net_256;
          wire  Net_255;
    electrical [4:0] Net_250;
          wire  Net_249;
          wire  Net_248;
          wire  Net_247;
          wire  Net_246;
          wire  Net_96;
          wire  Net_98;
          wire  Net_82;
          wire  Net_80;
          wire  Net_78;
          wire  Net_1186;
          wire  Net_1163;
          wire  Net_971;
          wire  Net_1049;
          wire  Net_1199;
          wire  Net_1173;
          wire  Net_979;
          wire  Net_1159;
          wire  Net_1045;
          wire  Net_988;


	cy_clock_v1_0
		#(.id("0ef9c90b-ecf8-423d-897f-f67baddc030c/ad4f26d7-8ffe-4f37-9ed6-0ec327663a75"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("36337209302.3256"),
		  .is_direct(0),
		  .is_digital(1))
		Int_Clock
		 (.clock_out(Net_78));



	cy_dma_v1_0
		#(.drq_type(2'b10))
		Lcd_Dma
		 (.drq(Net_1186),
		  .trq(1'b0),
		  .nrq(Net_1163));


	wire [0:0] tmpOE__Com_net;

	cy_psoc3_port_v1_0
		#(.width(5),
		  .siorefwidth(3),
		  .id("0ef9c90b-ecf8-423d-897f-f67baddc030c/6f17f0bc-12e3-40a0-ae3e-f94a2342eb38"),
		  .pin_aliases(",,,,"),
		  .access_mode("LCD"),
		  .layout_mode("NONCONTIGUOUS"),
		  .port_mode("OUTPUT"),
		  .intr_mode(10'b0000000000),
		  .drive_mode(15'b000000000000000),
		  .lcd_com_seg(5'b00000),
		  .lcd_sw_drive(0),
		  .por_state(0),
		  .port_alias_required(1),
		  .port_alias_group("SegLcdPort"))
		Com
		 (.oe(tmpOE__Com_net),
		  .y(5'b0));

	assign tmpOE__Com_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? 1'b1 : 1'b0;

	wire [0:0] tmpOE__Seg_net;

	cy_psoc3_port_v1_0
		#(.width(7),
		  .siorefwidth(4),
		  .id("0ef9c90b-ecf8-423d-897f-f67baddc030c/96a95f9b-4cc2-4a8a-8732-76c138ffddc7"),
		  .pin_aliases(",,,,,,"),
		  .access_mode("LCD"),
		  .layout_mode("NONCONTIGUOUS"),
		  .port_mode("OUTPUT"),
		  .intr_mode(14'b00000000000000),
		  .drive_mode(21'b000000000000000000000),
		  .lcd_com_seg(7'b1111111),
		  .lcd_sw_drive(0),
		  .por_state(0),
		  .port_alias_required(1),
		  .port_alias_group("SegLcdPort"))
		Seg
		 (.oe(tmpOE__Seg_net),
		  .y(7'b0));

	assign tmpOE__Seg_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? 1'b1 : 1'b0;


	cy_dma_v1_0
		#(.drq_type(2'b10))
		Frame_Dma
		 (.drq(Net_1173),
		  .trq(1'b0),
		  .nrq(Net_249));


    cy_psoc3_lcd_v2_0 LCD (
        .mode_1(Net_1045),
        .mode_2(Net_979),
        .drive_en(Net_1159),
        .data_clk(Net_1173),
        .frame(Net_1199),
        .int_clr(Net_1049),
        .lp_ack_udb(Net_971),
        .bias(Net_250[4:0]),
        .interrupt(Net_988));


	cy_isr_v1_0
		#(.int_type(2'b10))
		TD_DoneInt
		 (.int_signal(Net_1163));


	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_1186 = Net_1199;

    bSegLCD_v3_40 bLCDDSD (
        .clock(Net_78),
        .mode_1(Net_1045),
        .drive(Net_1159),
        .data_clk(Net_1173),
        .frame(Net_1199),
        .lcd_int(Net_988),
        .clr_int(Net_1049),
        .lp_ack(Net_971),
        .mode_2(Net_979));
    defparam bLCDDSD.PowerMode = 0;


	cy_isr_v1_0
		#(.int_type(2'b10))
		Wakeup
		 (.int_signal(Net_988));



	cy_clock_v1_0
		#(.id("0ef9c90b-ecf8-423d-897f-f67baddc030c/4787bcd5-a12a-45e9-9857-f3f481676345"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		MasterClock
		 (.clock_out(Net_82));



    assign Net_256 = Net_82 | Net_80;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_80));


	cy_clock_v1_0
		#(.id("0ef9c90b-ecf8-423d-897f-f67baddc030c/9b3e2c72-352e-42bd-bfb8-d649d75acc26"),
		  .source_clock_id("315365C3-2E3E-4f04-84A2-BB564A173261"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		MasterClock_2
		 (.clock_out(Net_96));



    assign Net_260 = Net_96 | Net_98;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_98));



endmodule

// top
module top ;


    SegLCD_v3_40_0 LCD_Seg_1 ();



endmodule

