/*******************************************************************************
* 	Register address and control bit definitions for the CYRF7936 device
********************************************************************************
*	This file's contents were copied from a PSoC 1 header file for the
*	CYFISPI user module (CYFISPI_Regs.h). Radio SPI commands were also
*	added here for convenience as well as some user-defined parameters.
*******************************************************************************/

#define	 READ_ONE_BYTE	0x00
#define  WRITE_ONE_BYTE	0x80
#define  BURST_READ		0x40
#define  BURST_WRITE	0xC0

#define CHANNEL_ADR                                       0x00
#define CHANNEL_RST                                       0x48
#define CHANNEL_MSK                                       0x7F

#define CHANNEL_MAX                                       0x62
#define CHANNEL_MIN                                       0x00
#define CHANNEL_2P498_GHZ                                 0x62
#define CHANNEL_2P4_GHZ                                   0x00

// -------------------------------
// User-added parameter definitions
// -------------------------------
#define DEF_PR_SEQ_MSB									  0x33
#define DEF_PR_SEQ_LSB									  0x33
#define DEF_32_THOLD									  0x05
#define DEF_64_THOLD									  0x0E
#define SOP_TSH											  0x04
#define ANALOG_CTRL_ADR									  0x39
#define ANALOG_CTRL_RST									  0x00
#define ALL_SLOW										  0x01

// -------------------------------
// TX Length register
// -------------------------------
#define TX_LENGTH_ADR                                     0x01
#define TX_LENGTH_RST                                     0x00
#define TX_LENGTH_MSK                                     0xFF


// -------------------------------
// TX Control register
// -------------------------------
#define TX_CTRL_ADR                                       0x02
#define TX_CTRL_RST                                       0x03

// See TX_IRQ for remaining bit position definitions

// TX_CTRL bit masks
#define TX_GO                                             0x80
#define TX_CLR                                            0x40


// -------------------------------
// TX Configuration register
// -------------------------------
#define TX_CFG_ADR                                        0x03
#define TX_CFG_RST                                        0x05

// separate bit field masks
#define TX_DATCODE_LEN_MSK                                0x20
#define TX_DATMODE_MSK                                    0x18
#define PA_VAL_MSK                                        0x07

// DATCODE_LEN register masks
#define DATCODE_LEN_64                                    0x20
#define DATCODE_LEN_32                                    0x00

// DATMODE register masks
#define DATMODE_1MBPS                                     0x00
#define DATMODE_8DR                                       0x08
#define DATMODE_DDR                                       0x10
#define DATMODE_SDR                                       0x18

// PA_SET register masks
#define PA_N30_DBM                                        0x00
#define PA_N25_DBM                                        0x01
#define PA_N20_DBM                                        0x02
#define PA_N15_DBM                                        0x03
#define PA_N10_DBM                                        0x04
#define PA_N5_DBM                                         0x05
#define PA_0_DBM                                          0x06
#define PA_4_DBM                                          0x07


// -------------------------------
// TX IRQ Status register
// -------------------------------
#define TX_IRQ_STATUS_ADR                                 0x04

// TX_IRQ bit masks
#define XS_IRQ                                            0x80
#define LV_IRQ                                            0x40
#define TXB15_IRQ                                         0x20
#define TXB8_IRQ                                          0x10
#define TXB0_IRQ                                          0x08
#define TXBERR_IRQ                                        0x04
#define TXC_IRQ                                           0x02
#define TXE_IRQ                                           0x01


// -------------------------------
// RX Control register
// -------------------------------
#define RX_CTRL_ADR                                       0x05
#define RX_CTRL_RST                                       0x07

// See RX_IRQ register for bit positions definitions also used for this register

// RX_CTRL bit masks
#define RX_GO                                             0x80


// -------------------------------
// RX Configuration register
// -------------------------------
#define RX_CFG_ADR                                        0x06
#define RX_CFG_RST                                        0x92

#define AUTO_AGC_EN                                       0x80
#define LNA_EN                                            0x40
#define ATT_EN                                            0x20
#define HI                                                0x10
#define LO                                                0x00
#define FASTTURN_EN                                       0x08
#define RXOW_EN                                           0x02
#define VLD_EN                                            0x01


// -------------------------------
// RX IRQ register
// -------------------------------
#define RX_IRQ_STATUS_ADR                                 0x07
// There is no default value for this register.

// RX_IRQ bit masks
#define RXOW_IRQ                                          0x80
#define SOFDET_IRQ                                        0x40
#define RXB16_IRQ                                         0x20
#define RXB8_IRQ                                          0x10
#define RXB1_IRQ                                          0x08
#define RXBERR_IRQ                                        0x04
#define RXC_IRQ                                           0x02
#define RXE_IRQ                                           0x01


// -------------------------------
// RX Status register
// -------------------------------
#define RX_STATUS_ADR                                     0x08
// There is no default value for this register.

// single flag bits & multi-bit-field masks
#define RX_ACK                                            0x80
#define RX_PKTERR                                         0x40
#define RX_EOPERR                                         0x20
#define RX_CRC0                                           0x10
#define RX_BAD_CRC                                        0x08
#define RX_DATCODE_LEN                                    0x04
#define RX_DATMODE_MSK                                    0x03


// -------------------------------
// RX Count register
// -------------------------------
#define RX_COUNT_ADR                                      0x09
#define RX_COUNT_RST                                      0x00
#define RX_COUNT_MSK                                      0xFF


// -------------------------------
// RX Length Field register
// -------------------------------
#define RX_LENGTH_ADR                                     0x0A
#define RX_LENGTH_RST                                     0x00
#define RX_LENGTH_MSK                                     0xFF


// -------------------------------
// Power Control register
// -------------------------------
#define PWR_CTRL_ADR                                      0x0B
#define PWR_CTRL_RST                                      0xA0

// single flag bits & multi-bit-field masks
#define PMU_EN                                            0x80
#define LV_IRQ_EN                                         0x40
#define PMU_SEN                                           0x20
#define PFET_OFF                                          0x10
#define LV_IRQ_TH_MSK                                     0x0C
#define PMU_OUTV_MSK                                      0x03

// LV_IRQ_TH values
#define LV_IRQ_TH_1P8_V                                   0x0C
#define LV_IRQ_TH_2P0_V                                   0x08
#define LV_IRQ_TH_2P2_V                                   0x04
#define LV_IRQ_TH_PMU_OUTV                                0x00

// PMU_OUTV values
#define PMU_OUTV_2P4                                      0x03
#define PMU_OUTV_2P5                                      0x02
#define PMU_OUTV_2P6                                      0x01
#define PMU_OUTV_2P7                                      0x00


// -------------------------------
// Crystal Control register
// -------------------------------
#define XTAL_CTRL_ADR                                     0x0C
#define XTAL_CTRL_RST                                     0x04

// single flag bits & multi-bit-field masks
#define XOUT_FNC_MSK                                      0xC0
#define XS_IRQ_EN                                         0x20
#define XOUT_FREQ_MSK                                     0x07

// XOUT_FNC values
#define XOUT_FNC_XOUT_FREQ                                0x00
#define XOUT_FNC_PA_N                                     0x40
#define XOUT_FNC_RAD_STREAM                               0x80
#define XOUT_FNC_GPIO                                     0xC0

// XOUT_FREQ values
#define XOUT_FREQ_12MHZ                                   0x00
#define XOUT_FREQ_6MHZ                                    0x01
#define XOUT_FREQ_3MHZ                                    0x02
#define XOUT_FREQ_1P5MHZ                                  0x03
#define XOUT_FREQ_P75MHZ                                  0x04


// -------------------------------
// I/O Configuration register
// -------------------------------
#define IO_CFG_ADR                                        0x0D
#define IO_CFG_RST                                        0x00
#define IO_CFG_MSK                                        0xFF

// single flag bits & multi-bit-field masks
#define IRQ_OD                                            0x80
#define IRQ_POL                                           0x40
#define MISO_OD                                           0x20
#define XOUT_OD                                           0x10
#define PACTL_OD                                          0x08
#define PACTL_GPIO                                        0x04
#define SPI_3_PIN                                         0x02
#define IRQ_GPIO                                          0x01


// -------------------------------
// GPIO Control register
// -------------------------------
#define GPIO_CTRL_ADR                                     0x0E
#define GPIO_CTRL_RST                                     0x00
#define GPIO_CTRL_MSK                                     0xF0

// single flag bits & multi-bit-field masks
#define XOUT_OP                                           0x80
#define MISO_OP                                           0x40
#define PACTL_OP                                          0x20
#define IRQ_OP                                            0x10
#define XOUT_IP                                           0x08
#define MISO_IP                                           0x04
#define PACTL_IP                                          0x02
#define IRQ_IP                                            0x01


// -------------------------------
// Transaction Configuration register
// -------------------------------
#define XACT_CFG_ADR                                      0x0F
#define XACT_CFG_RST                                      0x80

// single flag bits & multi-bit-field masks
#define ACK_EN                                            0x80
#define FRC_END_STATE                                     0x20
#define END_STATE_MSK                                     0x1C
#define ACK_TO_MSK                                        0x03

// END_STATE field values
#define END_STATE_SLEEP                                   0x00
#define END_STATE_IDLE                                    0x04
#define END_STATE_TXSYNTH                                 0x08
#define END_STATE_RXSYNTH                                 0x0C
#define END_STATE_RX                                      0x10

// ACK_TO field values
#define ACK_TO_4X                                         0x00
#define ACK_TO_8X                                         0x01
#define ACK_TO_12X                                        0x02
#define ACK_TO_15X                                        0x03


// -------------------------------
// Framing Configuration register
// -------------------------------
#define FRAMING_CFG_ADR                                   0x10
#define FRAMING_CFG_RST                                   0xA5

// single flag bits & multi-bit-field masks
#define SOP_EN                                            0x80
#define SOP_LEN                                           0x40
#define LEN_EN                                            0x20
#define SOP_THRESH_MSK                                    0x1F

// -------------------------------
// Data Threshold 32 register
// -------------------------------
#define DATA32_THOLD_ADR                                  0x11
#define DAT32_THRESH_RST                                  0x04
#define DAT32_THRESH_MSK                                  0x0F

// -------------------------------
// Data Threshold 64 register
// -------------------------------
#define DATA64_THOLD_ADR                                  0x12
#define DAT64_THRESH_RST                                  0x0A
#define DAT64_THRESH_MSK                                  0x1F

// -------------------------------
// RSSI register
// -------------------------------
#define RSSI_ADR                                          0x13
#define RSSI_RST                                          0x20

// single flag bits & multi-bit-field masks
#define SOP_RSSI                                          0x80
#define LNA_STATE                                         0x20
#define RSSI_LVL_MSK                                      0x1F


// -------------------------------
// EOP Control register
// -------------------------------
#define EOP_CTRL_ADR                                      0x14
#define EOP_CTRL_RST                                      0xA4

// single flag bits & multi-bit-field masks
#define HINT_EN                                           0x80
#define HINT_EOP_MSK                                      0x70
#define EOP_MSK                                           0x0F


// -------------------------------
// CRC Seed registers
// -------------------------------
#define CRC_SEED_LSB_ADR                                  0x15
#define CRC_SEED_MSB_ADR                                  0x16
#define CRC_SEED_LSB_RST                                  0x00
#define CRC_SEED_MSB_RST                                  0x00

// CRC related values
// USB CRC-16
#define CRC_POLY_MSB                                      0x80
#define CRC_POLY_LSB                                      0x05
#define CRC_RESI_MSB                                      0x80
#define CRC_RESI_LSB                                      0x0D


// -------------------------------
// TX CRC Calculated registers
// -------------------------------
#define TX_CRC_LSB_ADR                                    0x17
#define TX_CRC_MSB_ADR                                    0x18


// -------------------------------
// RX CRC Field registers
// -------------------------------
#define RX_CRC_LSB_ADR                                    0x19
#define RX_CRC_MSB_ADR                                    0x1A
#define RX_CRC_LSB_RST                                    0xFF
#define RX_CRC_MSB_RST                                    0xFF


// -------------------------------
// Synth Offset registers
// -------------------------------
#define TX_OFFSET_LSB_ADR                                 0x1B
#define TX_OFFSET_MSB_ADR                                 0x1C
#define TX_OFFSET_LSB_RST                                 0x00
#define TX_OFFSET_MSB_RST                                 0x00

// single flag bits & multi-bit-field masks
#define STRIM_MSB_MSK                                     0x0F
#define STRIM_LSB_MSK                                     0xFF


// -------------------------------
// Mode Override register
// -------------------------------
#define MODE_OVERRIDE_ADR                                 0x1D
#define MODE_OVERRIDE_RST                                 0x00

#define FRC_AWAKE                                         0x03
#define FRC_AWAKE_OFF_1                                   0x01
#define FRC_AWAKE_OFF_2                                   0x00

// single flag bits & multi-bit-field masks
#define DIS_AUTO_SEN                                      0x80
#define SEN_TXRXB                                         0x40
#define FRC_SEN                                           0x20
#define FRC_AWAKE_MSK                                     0x18
#define MODE_OVRD_FRC_AWAKE                               0x18
#define MODE_OVRD_FRC_AWAKE_OFF_1                         0x08
#define MODE_OVRD_FRC_AWAKE_OFF_2                         0x00
#define RST                                               0x01
#define FRC_PA                                            0x02


// -------------------------------
// RX Override register
// -------------------------------
#define RX_OVERRIDE_ADR                                   0x1E
#define RX_OVERRIDE_RST                                   0x00

// single flag bits & multi-bit-field masks
#define ACK_RX                                            0x80
#define EXTEND_RX_TX                                      0x40
#define MAN_RXACK                                         0x20
#define FRC_RXDR                                          0x10
#define DIS_CRC0                                          0x08
#define DIS_RXCRC                                         0x04
#define ACE                                               0x02


// -------------------------------
// TX Override register
// -------------------------------
#define TX_OVERRIDE_ADR                                   0x1F
#define TX_OVERRIDE_RST                                   0x00

// single flag bits & multi-bit-field masks
#define ACK_TX_SEN                                        0x80
#define FRC_PREAMBLE                                      0x40
#define DIS_TX_RETRANS                                    0x20
#define MAN_TXACK                                         0x10
#define OVRRD_ACK                                         0x08
#define DIS_TXCRC                                         0x04
#define CO                                                0x02
#define TXINV                                             0x01


//------------------------------------------------------------------------------
//      File Function Detail
//------------------------------------------------------------------------------

// -------------------------------
// TX Buffer - 16 bytes
// -------------------------------
#define TX_BUFFER_ADR                                     0x20


// -------------------------------
// RX Buffer - 16 bytes
// -------------------------------
#define RX_BUFFER_ADR                                     0x21


// -------------------------------
// Framing Code - 8 bytes
// -------------------------------
#define SOP_CODE_ADR                                      0x22

// CODESTORE_REG_SOF_RST        64'h17_ff_9e_21_36_90_c7_82
#define CODESTORE_BYTE7_SOF_RST                           0x17
#define CODESTORE_BYTE6_SOF_RST                           0xFF
#define CODESTORE_BYTE5_SOF_RST                           0x9E
#define CODESTORE_BYTE4_SOF_RST                           0x21
#define CODESTORE_BYTE3_SOF_RST                           0x36
#define CODESTORE_BYTE2_SOF_RST                           0x90
#define CODESTORE_BYTE1_SOF_RST                           0xC7
#define CODESTORE_BYTE0_SOF_RST                           0x82


// -------------------------------
// Data Code - 16 bytes
// -------------------------------
#define DATA_CODE_ADR                                     0x23

// CODESTORE_REG_DCODE0_RST            64'h01_2B_F1_DB_01_32_BE_6F
#define CODESTORE_BYTE7_DCODE0_RST                        0x01
#define CODESTORE_BYTE6_DCODE0_RST                        0x2B
#define CODESTORE_BYTE5_DCODE0_RST                        0xF1
#define CODESTORE_BYTE4_DCODE0_RST                        0xDB
#define CODESTORE_BYTE3_DCODE0_RST                        0x01
#define CODESTORE_BYTE2_DCODE0_RST                        0x32
#define CODESTORE_BYTE1_DCODE0_RST                        0xBE
#define CODESTORE_BYTE0_DCODE0_RST                        0x6F

// CODESTORE_REG_DCODE1_RST            64'h02_F9_93_97_02_FA_5C_E3
#define CODESTORE_BYTE7_DCODE1_RST                        0x02
#define CODESTORE_BYTE6_DCODE1_RST                        0xF9
#define CODESTORE_BYTE5_DCODE1_RST                        0x93
#define CODESTORE_BYTE4_DCODE1_RST                        0x97
#define CODESTORE_BYTE3_DCODE1_RST                        0x02
#define CODESTORE_BYTE2_DCODE1_RST                        0xFA
#define CODESTORE_BYTE1_DCODE1_RST                        0x5C
#define CODESTORE_BYTE0_DCODE1_RST                        0xE3


// -------------------------------
// Preamble - 3 bytes
// -------------------------------
#define PREAMBLE_ADR                                      0x24

#define PREAMBLE_CODE_MSB_RST                             0x33
#define PREAMBLE_CODE_LSB_RST                             0x33
#define PREAMBLE_LEN_RST                                  0x02


// -------------------------------
// Laser Fuses - 8 bytes (2 hidden)
// -------------------------------
#define MFG_ID_ADR                                        0x25


// -------------------------------
// XTAL Startup Delay
// -------------------------------
#define XTAL_CFG_ADR                                      0x26
#define XTAL_CFG_RST                                      0x00

// -------------------------------
// Clock Override
// -------------------------------
#define CLK_OVERRIDE_ADR                                  0x27
#define CLK_OVERRIDE_RST                                  0x00

#define RXF                                               0x02


// -------------------------------
// Clock Enable
// -------------------------------
#define CLK_EN_ADR                                        0x28
#define CLK_EN_RST                                        0x00

#define RXF                                               0x02


// -------------------------------
// Receiver Abort
// -------------------------------
#define RX_ABORT_ADR                                      0x29
#define RX_ABORT_RST                                      0x00

#define ABORT_EN                                          0x20


// -------------------------------
// Auto Calibration Time
// -------------------------------
#define AUTO_CAL_TIME_ADR                                 0x32
#define AUTO_CAL_TIME_RST                                 0x0C

#define AUTO_CAL_TIME_MAX                                 0x3C


// -------------------------------
// Auto Calibration Offset
// -------------------------------
#define AUTO_CAL_OFFSET_ADR                               0x35
#define AUTO_CAL_OFFSET_RST                               0x00

#define AUTO_CAL_OFFSET_MINUS_4                           0x14

//[] END OF FILE
