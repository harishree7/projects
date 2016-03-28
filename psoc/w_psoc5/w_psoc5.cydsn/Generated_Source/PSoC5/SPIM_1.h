/*******************************************************************************
* File Name: SPIM_1.h
* Version 2.10
*
* Description:
*  Contains the function prototypes, constants and register definition
*  of the SPI Master Component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIM_SPIM_1_H)
#define CY_SPIM_SPIM_1_H

#include "cyfitter.h"

/* PSoC3 ES2 or earlier*/
#define SPIM_1_PSOC3_ES2   ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_3A) && \
                     			      (CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2))
                     
/* PSoC5 ES1 or earlier */
#define SPIM_1_PSOC5_ES1   ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_5A) && \
                     		    	  (CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_5A_ES1))
	
#ifdef SPIM_1_TxInternalInterrupt__ES2_PATCH
	#if(SPIM_1_PSOC3_ES2 && SPIM_1_TxInternalInterrupt__ES2_PATCH)
		#include <intrins.h>
        #define SPIM_1_TX_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
	#endif /* End PSOC3_ES2 */
#endif /* SPIM_1_TxInternalInterrupt__ES2_PATCH */

#ifdef SPIM_1_RxInternalInterrupt__ES2_PATCH  
	#if(SPIM_1_PSOC3_ES2 && SPIM_1_RxInternalInterrupt__ES2_PATCH)
		#include <intrins.h>
        #define SPIM_1_RX_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
	#endif /* End PSOC3_ES2 */
#endif /* SPIM_1_RxInternalInterrupt__ES2_PATCH */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define SPIM_1_DataWidth                  (8u)
#define SPIM_1_InternalClockUsed          (1u)
#define SPIM_1_InternalTxInterruptEnabled (0u)
#define SPIM_1_InternalRxInterruptEnabled (0u)
#define SPIM_1_ModeUseZero                (1u)
#define SPIM_1_BidirectionalMode          (0u)
#define SPIM_1_Mode                       (1u)

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects 
*/
#define SPIM_1_DATAWIDHT                (SPIM_1_DataWidth)
#define SPIM_1_InternalInterruptEnabled (0u)


/***************************************
*        Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct _SPIM_1_backupStruct
{
    uint8 enableState;
    uint8 cntrPeriod;
    
    #if(SPIM_1_PSOC3_ES2 || SPIM_1_PSOC5_ES1) /* PSoC3 ES2 or earlier, PSoC5 ES1 */
    
        uint8 saveSrTxIntMask;
        uint8 saveSrRxIntMask;
        
    #endif /* End SPIM_1_PSOC3_ES2 || SPIM_1_PSOC5_ES1 */

} SPIM_1_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  SPIM_1_Init(void);
void  SPIM_1_Enable(void) ;
void  SPIM_1_Start(void);
void  SPIM_1_Stop(void) ;
void  SPIM_1_EnableTxInt(void) ;
void  SPIM_1_EnableRxInt(void) ;
void  SPIM_1_DisableTxInt(void) ;
void  SPIM_1_DisableRxInt(void) ;
void  SPIM_1_SetTxInterruptMode(uint8 intSource) ;
void  SPIM_1_SetRxInterruptMode(uint8 intSource) ;
uint8 SPIM_1_ReadTxStatus(void);
uint8 SPIM_1_ReadRxStatus(void);
void  SPIM_1_WriteTxData(uint8 txData);
uint8 SPIM_1_ReadRxData(void);
uint8 SPIM_1_GetRxBufferSize(void) ;
uint8 SPIM_1_GetTxBufferSize(void) ;
void  SPIM_1_ClearRxBuffer(void);
void  SPIM_1_ClearTxBuffer(void);
void  SPIM_1_ClearFIFO(void) ;
void  SPIM_1_PutArray(uint8 *buffer, uint8 byteCount);
void  SPIM_1_Sleep(void);
void  SPIM_1_Wakeup(void);
void  SPIM_1_SaveConfig(void);
void  SPIM_1_RestoreConfig(void) ;

#if (SPIM_1_BidirectionalMode)

    void  SPIM_1_TxEnable(void) ;
    void  SPIM_1_TxDisable(void) ;

#endif /* SPIM_1_BidirectionalMode == 1u*/

CY_ISR_PROTO(SPIM_1_TX_ISR);
CY_ISR_PROTO(SPIM_1_RX_ISR);

/* Macros for getting software status of SPIM Statusi Register */
#define SPIM_1_GET_STATUS_TX(swTxSts) (uint8)(SPIM_1_TX_STATUS_REG | \
                                                       (swTxSts & SPIM_1_TX_STS_CLR_ON_RD_BYTES_MASK))
#define SPIM_1_GET_STATUS_RX(swRxSts) (uint8)(SPIM_1_RX_STATUS_REG | \
                                                       (swRxSts & SPIM_1_RX_STS_CLR_ON_RD_BYTES_MASK))                                                  

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects 
*/
#define SPIM_1_WriteByte (SPIM_1_WriteTxData)
#define SPIM_1_ReadByte  (SPIM_1_ReadRxData)
void  SPIM_1_SetInterruptMode(uint8 intSource) ;
uint8 SPIM_1_ReadStatus(void);
void  SPIM_1_EnableInt(void) ;
void  SPIM_1_DisableInt(void) ;


/***************************************
*           API Constants
***************************************/

#define SPIM_1_TX_ISR_NUMBER     (SPIM_1_TxInternalInterrupt__INTC_NUMBER)
#define SPIM_1_RX_ISR_NUMBER     (SPIM_1_RxInternalInterrupt__INTC_NUMBER)
#define SPIM_1_TX_ISR_PRIORITY   (SPIM_1_TxInternalInterrupt__INTC_PRIOR_NUM)
#define SPIM_1_RX_ISR_PRIORITY   (SPIM_1_RxInternalInterrupt__INTC_PRIOR_NUM)


/***************************************
*    Initial Parameter Constants
***************************************/
                                               
#define SPIM_1_INT_ON_SPI_DONE    (0u << SPIM_1_STS_SPI_DONE_SHIFT)
#define SPIM_1_INT_ON_TX_EMPTY    (0u << SPIM_1_STS_TX_FIFO_EMPTY_SHIFT)
#define SPIM_1_INT_ON_TX_NOT_FULL (0u << SPIM_1_STS_TX_FIFO_NOT_FULL_SHIFT)
#define SPIM_1_INT_ON_BYTE_COMP   (0u << SPIM_1_STS_BYTE_COMPLETE_SHIFT)
#define SPIM_1_INT_ON_SPI_IDLE    (0u << SPIM_1_STS_SPI_IDLE_SHIFT)

#define SPIM_1_TX_INIT_INTERRUPTS_MASK  (SPIM_1_INT_ON_SPI_DONE | \
                                            SPIM_1_INT_ON_TX_EMPTY | SPIM_1_INT_ON_TX_NOT_FULL | \
                                            SPIM_1_INT_ON_BYTE_COMP | SPIM_1_INT_ON_SPI_IDLE)
            
#define SPIM_1_INT_ON_RX_FULL      (0u << SPIM_1_STS_RX_FIFO_FULL_SHIFT)
#define SPIM_1_INT_ON_RX_NOT_EMPTY (0u << SPIM_1_STS_RX_FIFO_NOT_EMPTY_SHIFT)
#define SPIM_1_INT_ON_RX_OVER      (0u << SPIM_1_STS_RX_FIFO_OVERRUN_SHIFT)

#define SPIM_1_RX_INIT_INTERRUPTS_MASK  (SPIM_1_INT_ON_RX_FULL | \
                                            SPIM_1_INT_ON_RX_NOT_EMPTY | SPIM_1_INT_ON_RX_OVER)
                                               
#define SPIM_1_BITCTR_INIT           ( (SPIM_1_DataWidth << 1u) - 1u)

#define SPIM_1_TXBUFFERSIZE          (4u)
#define SPIM_1_RXBUFFERSIZE          (4u)

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects 
*/
#define SPIM_1_INIT_INTERRUPTS_MASK  (SPIM_1_INT_ON_SPI_DONE | SPIM_1_INT_ON_TX_EMPTY | \
                                            SPIM_1_INT_ON_TX_NOT_FULL | SPIM_1_INT_ON_RX_FULL | \
                                            SPIM_1_INT_ON_RX_NOT_EMPTY | SPIM_1_INT_ON_RX_OVER | \
                                            SPIM_1_INT_ON_BYTE_COMP)


/***************************************
*             Registers
***************************************/

#define SPIM_1_TXDATA_REG         (* (reg8 *) \
        SPIM_1_BSPIM_sR8_Dp_u0__F0_REG)
#define SPIM_1_TXDATA_PTR         (  (reg8 *) \
        SPIM_1_BSPIM_sR8_Dp_u0__F0_REG)
#define SPIM_1_RXDATA_REG         (* (reg8 *) \
        SPIM_1_BSPIM_sR8_Dp_u0__F1_REG)
#define SPIM_1_RXDATA_PTR         (  (reg8 *) \
        SPIM_1_BSPIM_sR8_Dp_u0__F1_REG)

#define SPIM_1_AUX_CONTROL_DP0_REG (* (reg8 *) \
        SPIM_1_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG)
#define SPIM_1_AUX_CONTROL_DP0_PTR (  (reg8 *) \
        SPIM_1_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG)        

#if (SPIM_1_DataWidth > 8u)

    #define SPIM_1_AUX_CONTROL_DP1_REG  (* (reg8 *) \
            SPIM_1_BSPIM_sR8_Dp_u1__DP_AUX_CTL_REG)
    #define SPIM_1_AUX_CONTROL_DP1_PTR  (  (reg8 *) \
            SPIM_1_BSPIM_sR8_Dp_u1__DP_AUX_CTL_REG)
#endif /* SPIM_1_DataWidth > 8u */

#define SPIM_1_COUNTER_PERIOD_REG  (* (reg8 *)  SPIM_1_BSPIM_BitCounter__PERIOD_REG)
#define SPIM_1_COUNTER_PERIOD_PTR  (  (reg8 *)  SPIM_1_BSPIM_BitCounter__PERIOD_REG)
#define SPIM_1_COUNTER_CONTROL_REG (* (reg8 *)  SPIM_1_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)
#define SPIM_1_COUNTER_CONTROL_PTR (  (reg8 *)  SPIM_1_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)

#define SPIM_1_TX_STATUS_REG       (* (reg8 *)  SPIM_1_BSPIM_TxStsReg__STATUS_REG)
#define SPIM_1_TX_STATUS_PTR       (  (reg8 *)  SPIM_1_BSPIM_TxStsReg__STATUS_REG)
#define SPIM_1_RX_STATUS_REG       (* (reg8 *)  SPIM_1_BSPIM_RxStsReg__STATUS_REG)
#define SPIM_1_RX_STATUS_PTR       (  (reg8 *)  SPIM_1_BSPIM_RxStsReg__STATUS_REG)

#define SPIM_1_CONTROL_REG         (* (reg8 *)  \
        SPIM_1_BSPIM_BidirMode_AsyncCtl_CtrlReg__CONTROL_REG)
#define SPIM_1_CONTROL_PTR         (  (reg8 *)  \
        SPIM_1_BSPIM_BidirMode_AsyncCtl_CtrlReg__CONTROL_REG)
        
#define SPIM_1_TX_STATUS_MASK_REG  (* (reg8 *)  SPIM_1_BSPIM_TxStsReg__MASK_REG)
#define SPIM_1_TX_STATUS_MASK_PTR  (  (reg8 *)  SPIM_1_BSPIM_TxStsReg__MASK_REG)
#define SPIM_1_RX_STATUS_MASK_REG  (* (reg8 *)  SPIM_1_BSPIM_RxStsReg__MASK_REG)
#define SPIM_1_RX_STATUS_MASK_PTR  (  (reg8 *)  SPIM_1_BSPIM_RxStsReg__MASK_REG)

#define SPIM_1_TX_STATUS_ACTL_REG  (* (reg8 *)  SPIM_1_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define SPIM_1_TX_STATUS_ACTL_PTR  (  (reg8 *)  SPIM_1_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define SPIM_1_RX_STATUS_ACTL_REG  (* (reg8 *)  SPIM_1_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)
#define SPIM_1_RX_STATUS_ACTL_PTR  (  (reg8 *)  SPIM_1_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)

/* Obsolete register names. Not to be used in new designs */
#define SPIM_1_TXDATA                 (SPIM_1_TXDATA_REG)
#define SPIM_1_RXDATA                 (SPIM_1_RXDATA_REG)
#define SPIM_1_AUX_CONTROLDP0         (SPIM_1_AUX_CONTROL_DP0_REG)
#define SPIM_1_TXBUFFERREAD           (SPIM_1_txBufferRead)
#define SPIM_1_TXBUFFERWRITE          (SPIM_1_txBufferWrite)
#define SPIM_1_RXBUFFERREAD           (SPIM_1_rxBufferRead)
#define SPIM_1_RXBUFFERWRITE          (SPIM_1_rxBufferWrite)

#if(SPIM_1_DataWidth > 8u)    
    #define SPIM_1_AUX_CONTROLDP1     (SPIM_1_AUX_CONTROL_DP1_REG)    
#endif /* SPIM_1_DataWidth > 8u */
    
#define SPIM_1_COUNTER_PERIOD         (SPIM_1_COUNTER_PERIOD_REG)
#define SPIM_1_COUNTER_CONTROL        (SPIM_1_COUNTER_CONTROL_REG)
#define SPIM_1_STATUS                 (SPIM_1_TX_STATUS_REG)
#define SPIM_1_CONTROL                (SPIM_1_CONTROL_REG)
#define SPIM_1_STATUS_MASK            (SPIM_1_TX_STATUS_MASK_REG)
#define SPIM_1_STATUS_ACTL            (SPIM_1_TX_STATUS_ACTL_REG)


/***************************************
*       Register Constants 
***************************************/

/* Status Register Definitions */
#define SPIM_1_STS_SPI_DONE_SHIFT          (0x00u)
#define SPIM_1_STS_TX_FIFO_EMPTY_SHIFT     (0x01u)
#define SPIM_1_STS_TX_FIFO_NOT_FULL_SHIFT  (0x02u)
#define SPIM_1_STS_BYTE_COMPLETE_SHIFT     (0x03u)
#define SPIM_1_STS_SPI_IDLE_SHIFT          (0x04u)
#define SPIM_1_STS_RX_FIFO_FULL_SHIFT      (0x04u)
#define SPIM_1_STS_RX_FIFO_NOT_EMPTY_SHIFT (0x05u)
#define SPIM_1_STS_RX_FIFO_OVERRUN_SHIFT   (0x06u)

#define SPIM_1_STS_SPI_DONE                (0x01u << SPIM_1_STS_SPI_DONE_SHIFT)        
#define SPIM_1_STS_TX_FIFO_EMPTY           (0x01u << SPIM_1_STS_TX_FIFO_EMPTY_SHIFT)    
#define SPIM_1_STS_TX_FIFO_NOT_FULL        (0x01u << SPIM_1_STS_TX_FIFO_NOT_FULL_SHIFT)    
#define SPIM_1_STS_SPI_IDLE                (0x01u << SPIM_1_STS_SPI_IDLE_SHIFT)
#define SPIM_1_STS_RX_FIFO_FULL            (0x01u << SPIM_1_STS_RX_FIFO_FULL_SHIFT)    
#define SPIM_1_STS_RX_FIFO_NOT_EMPTY       (0x01u << SPIM_1_STS_RX_FIFO_NOT_EMPTY_SHIFT)    
#define SPIM_1_STS_RX_FIFO_OVERRUN         (0x01u << SPIM_1_STS_RX_FIFO_OVERRUN_SHIFT)  
#define SPIM_1_STS_BYTE_COMPLETE           (0x01u << SPIM_1_STS_BYTE_COMPLETE_SHIFT)

#define SPIM_1_TX_STS_CLR_ON_RD_BYTES_MASK (0x09u)
#define SPIM_1_RX_STS_CLR_ON_RD_BYTES_MASK (0x40u)

/* StatusI Register Interrupt Enable Control Bits */
/* As defined by the Register map for the AUX Control Register */
#define SPIM_1_INT_ENABLE                  (0x10u)
#define SPIM_1_FIFO_CLR                    (0x03u)
                                                                 
/* Bit Counter (7-bit) Control Register Bit Definitions */
/* As defined by the Register map for the AUX Control Register */
#define SPIM_1_CNTR_ENABLE                 (0x20u)   
                                                                  
/* Bi-Directional mode control bit */
#define SPIM_1_CTRL_TX_SIGNAL_EN           (0x01u)

/* Datapath Auxillary Control Register definitions */
#define SPIM_1_AUX_CTRL_FIFO0_CLR          (0x01u)
#define SPIM_1_AUX_CTRL_FIFO1_CLR          (0x02u)
#define SPIM_1_AUX_CTRL_FIFO0_LVL          (0x04u)
#define SPIM_1_AUX_CTRL_FIFO1_LVL          (0x08u)
#define SPIM_1_STATUS_ACTL_INT_EN_MASK     (0x10u)

#endif  /* CY_SPIM_SPIM_1_H */


/* [] END OF FILE */
