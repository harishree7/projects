/*******************************************************************************
* File Name: RadioController.h
* Version 2.21
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

#if !defined(CY_SPIM_RadioController_H)
#define CY_SPIM_RadioController_H

#include "cyfitter.h"

/* PSoC3 ES2 or earlier*/
#define RadioController_PSOC3_ES2   ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_3A) && \
                     			      (CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2))
                     
/* PSoC5 ES1 or earlier */
#define RadioController_PSOC5_ES1   ((CYDEV_CHIP_MEMBER_USED == CYDEV_CHIP_MEMBER_5A) && \
                     		    	  (CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_5A_ES1))
	
#ifdef RadioController_TxInternalInterrupt__ES2_PATCH
	#if(RadioController_PSOC3_ES2 && RadioController_TxInternalInterrupt__ES2_PATCH)
		#include <intrins.h>
        #define RadioController_TX_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
	#endif /* End PSOC3_ES2 */
#endif /* RadioController_TxInternalInterrupt__ES2_PATCH */

#ifdef RadioController_RxInternalInterrupt__ES2_PATCH  
	#if(RadioController_PSOC3_ES2 && RadioController_RxInternalInterrupt__ES2_PATCH)
		#include <intrins.h>
        #define RadioController_RX_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
	#endif /* End PSOC3_ES2 */
#endif /* RadioController_RxInternalInterrupt__ES2_PATCH */


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define RadioController_DataWidth                  (8u)
#define RadioController_InternalClockUsed          (1u)
#define RadioController_InternalTxInterruptEnabled (0u)
#define RadioController_InternalRxInterruptEnabled (0u)
#define RadioController_ModeUseZero                (1u)
#define RadioController_BidirectionalMode          (0u)
#define RadioController_Mode                       (1u)

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects 
*/
#define RadioController_DATAWIDHT                (RadioController_DataWidth)
#define RadioController_InternalInterruptEnabled (0u)


/***************************************
*        Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct _RadioController_backupStruct
{
    uint8 enableState;
    uint8 cntrPeriod;
    
    #if(RadioController_PSOC3_ES2 || RadioController_PSOC5_ES1) /* PSoC3 ES2 or earlier, PSoC5 ES1 */
    
        uint8 saveSrTxIntMask;
        uint8 saveSrRxIntMask;
        
    #endif /* End RadioController_PSOC3_ES2 || RadioController_PSOC5_ES1 */

} RadioController_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  RadioController_Init(void) ;
void  RadioController_Enable(void) ;
void  RadioController_Start(void) ;
void  RadioController_Stop(void) ;
void  RadioController_EnableTxInt(void) ;
void  RadioController_EnableRxInt(void) ;
void  RadioController_DisableTxInt(void) ;
void  RadioController_DisableRxInt(void) ;
void  RadioController_SetTxInterruptMode(uint8 intSource) ;
void  RadioController_SetRxInterruptMode(uint8 intSource) ;
uint8 RadioController_ReadTxStatus(void) ;
uint8 RadioController_ReadRxStatus(void) ;
void  RadioController_WriteTxData(uint8 txData) ;
uint8 RadioController_ReadRxData(void) ;
uint8 RadioController_GetRxBufferSize(void) ;
uint8 RadioController_GetTxBufferSize(void) ;
void  RadioController_ClearRxBuffer(void) ;
void  RadioController_ClearTxBuffer(void) ;
void  RadioController_ClearFIFO(void) ;
void  RadioController_PutArray(uint8 *buffer, uint8 byteCount) ;
void  RadioController_Sleep(void) ;
void  RadioController_Wakeup(void) ;
void  RadioController_SaveConfig(void) ;
void  RadioController_RestoreConfig(void) ;

#if (RadioController_BidirectionalMode)

    void  RadioController_TxEnable(void) ;
    void  RadioController_TxDisable(void) ;

#endif /* RadioController_BidirectionalMode == 1u*/

CY_ISR_PROTO(RadioController_TX_ISR);
CY_ISR_PROTO(RadioController_RX_ISR);

/* Macros for getting software status of SPIM Statusi Register */
#define RadioController_GET_STATUS_TX(swTxSts) (uint8)(RadioController_TX_STATUS_REG | \
                                                       (swTxSts & RadioController_TX_STS_CLR_ON_RD_BYTES_MASK))
#define RadioController_GET_STATUS_RX(swRxSts) (uint8)(RadioController_RX_STATUS_REG | \
                                                       (swRxSts & RadioController_RX_STS_CLR_ON_RD_BYTES_MASK))                                                  

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects 
*/
#define RadioController_WriteByte (RadioController_WriteTxData)
#define RadioController_ReadByte  (RadioController_ReadRxData)
void  RadioController_SetInterruptMode(uint8 intSource) ;
uint8 RadioController_ReadStatus(void) ;
void  RadioController_EnableInt(void) ;
void  RadioController_DisableInt(void) ;


/***************************************
*           API Constants
***************************************/

#define RadioController_TX_ISR_NUMBER     (RadioController_TxInternalInterrupt__INTC_NUMBER)
#define RadioController_RX_ISR_NUMBER     (RadioController_RxInternalInterrupt__INTC_NUMBER)
#define RadioController_TX_ISR_PRIORITY   (RadioController_TxInternalInterrupt__INTC_PRIOR_NUM)
#define RadioController_RX_ISR_PRIORITY   (RadioController_RxInternalInterrupt__INTC_PRIOR_NUM)


/***************************************
*    Initial Parameter Constants
***************************************/
                                               
#define RadioController_INT_ON_SPI_DONE    (0u << RadioController_STS_SPI_DONE_SHIFT)
#define RadioController_INT_ON_TX_EMPTY    (0u << RadioController_STS_TX_FIFO_EMPTY_SHIFT)
#define RadioController_INT_ON_TX_NOT_FULL (0u << RadioController_STS_TX_FIFO_NOT_FULL_SHIFT)
#define RadioController_INT_ON_BYTE_COMP   (0u << RadioController_STS_BYTE_COMPLETE_SHIFT)
#define RadioController_INT_ON_SPI_IDLE    (0u << RadioController_STS_SPI_IDLE_SHIFT)

#define RadioController_TX_INIT_INTERRUPTS_MASK  (RadioController_INT_ON_SPI_DONE | \
                                            RadioController_INT_ON_TX_EMPTY | RadioController_INT_ON_TX_NOT_FULL | \
                                            RadioController_INT_ON_BYTE_COMP | RadioController_INT_ON_SPI_IDLE)
            
#define RadioController_INT_ON_RX_FULL      (0u << RadioController_STS_RX_FIFO_FULL_SHIFT)
#define RadioController_INT_ON_RX_NOT_EMPTY (0u << RadioController_STS_RX_FIFO_NOT_EMPTY_SHIFT)
#define RadioController_INT_ON_RX_OVER      (0u << RadioController_STS_RX_FIFO_OVERRUN_SHIFT)

#define RadioController_RX_INIT_INTERRUPTS_MASK  (RadioController_INT_ON_RX_FULL | \
                                            RadioController_INT_ON_RX_NOT_EMPTY | RadioController_INT_ON_RX_OVER)
                                               
#define RadioController_BITCTR_INIT           ( (RadioController_DataWidth << 1u) - 1u)

#define RadioController_TXBUFFERSIZE          (4u)
#define RadioController_RXBUFFERSIZE          (4u)

/* Following definitions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects 
*/
#define RadioController_INIT_INTERRUPTS_MASK  (RadioController_INT_ON_SPI_DONE | RadioController_INT_ON_TX_EMPTY | \
                                            RadioController_INT_ON_TX_NOT_FULL | RadioController_INT_ON_RX_FULL | \
                                            RadioController_INT_ON_RX_NOT_EMPTY | RadioController_INT_ON_RX_OVER | \
                                            RadioController_INT_ON_BYTE_COMP)


/***************************************
*             Registers
***************************************/

#define RadioController_TXDATA_REG         (* (reg8 *) \
        RadioController_BSPIM_sR8_Dp_u0__F0_REG)
#define RadioController_TXDATA_PTR         (  (reg8 *) \
        RadioController_BSPIM_sR8_Dp_u0__F0_REG)
#define RadioController_RXDATA_REG         (* (reg8 *) \
        RadioController_BSPIM_sR8_Dp_u0__F1_REG)
#define RadioController_RXDATA_PTR         (  (reg8 *) \
        RadioController_BSPIM_sR8_Dp_u0__F1_REG)

#define RadioController_AUX_CONTROL_DP0_REG (* (reg8 *) \
        RadioController_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG)
#define RadioController_AUX_CONTROL_DP0_PTR (  (reg8 *) \
        RadioController_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG)        

#if (RadioController_DataWidth > 8u)

    #define RadioController_AUX_CONTROL_DP1_REG  (* (reg8 *) \
            RadioController_BSPIM_sR8_Dp_u1__DP_AUX_CTL_REG)
    #define RadioController_AUX_CONTROL_DP1_PTR  (  (reg8 *) \
            RadioController_BSPIM_sR8_Dp_u1__DP_AUX_CTL_REG)
#endif /* RadioController_DataWidth > 8u */

#define RadioController_COUNTER_PERIOD_REG  (* (reg8 *)  RadioController_BSPIM_BitCounter__PERIOD_REG)
#define RadioController_COUNTER_PERIOD_PTR  (  (reg8 *)  RadioController_BSPIM_BitCounter__PERIOD_REG)
#define RadioController_COUNTER_CONTROL_REG (* (reg8 *)  RadioController_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)
#define RadioController_COUNTER_CONTROL_PTR (  (reg8 *)  RadioController_BSPIM_BitCounter__CONTROL_AUX_CTL_REG)

#define RadioController_TX_STATUS_REG       (* (reg8 *)  RadioController_BSPIM_TxStsReg__STATUS_REG)
#define RadioController_TX_STATUS_PTR       (  (reg8 *)  RadioController_BSPIM_TxStsReg__STATUS_REG)
#define RadioController_RX_STATUS_REG       (* (reg8 *)  RadioController_BSPIM_RxStsReg__STATUS_REG)
#define RadioController_RX_STATUS_PTR       (  (reg8 *)  RadioController_BSPIM_RxStsReg__STATUS_REG)

#define RadioController_CONTROL_REG         (* (reg8 *)  \
        RadioController_BSPIM_BidirMode_SyncCtl_CtrlReg__CONTROL_REG)
#define RadioController_CONTROL_PTR         (  (reg8 *)  \
        RadioController_BSPIM_BidirMode_SyncCtl_CtrlReg__CONTROL_REG)
        
#define RadioController_TX_STATUS_MASK_REG  (* (reg8 *)  RadioController_BSPIM_TxStsReg__MASK_REG)
#define RadioController_TX_STATUS_MASK_PTR  (  (reg8 *)  RadioController_BSPIM_TxStsReg__MASK_REG)
#define RadioController_RX_STATUS_MASK_REG  (* (reg8 *)  RadioController_BSPIM_RxStsReg__MASK_REG)
#define RadioController_RX_STATUS_MASK_PTR  (  (reg8 *)  RadioController_BSPIM_RxStsReg__MASK_REG)

#define RadioController_TX_STATUS_ACTL_REG  (* (reg8 *)  RadioController_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define RadioController_TX_STATUS_ACTL_PTR  (  (reg8 *)  RadioController_BSPIM_TxStsReg__STATUS_AUX_CTL_REG)
#define RadioController_RX_STATUS_ACTL_REG  (* (reg8 *)  RadioController_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)
#define RadioController_RX_STATUS_ACTL_PTR  (  (reg8 *)  RadioController_BSPIM_RxStsReg__STATUS_AUX_CTL_REG)

/* Obsolete register names. Not to be used in new designs */
#define RadioController_TXDATA                 (RadioController_TXDATA_REG)
#define RadioController_RXDATA                 (RadioController_RXDATA_REG)
#define RadioController_AUX_CONTROLDP0         (RadioController_AUX_CONTROL_DP0_REG)
#define RadioController_TXBUFFERREAD           (RadioController_txBufferRead)
#define RadioController_TXBUFFERWRITE          (RadioController_txBufferWrite)
#define RadioController_RXBUFFERREAD           (RadioController_rxBufferRead)
#define RadioController_RXBUFFERWRITE          (RadioController_rxBufferWrite)

#if(RadioController_DataWidth > 8u)    
    #define RadioController_AUX_CONTROLDP1     (RadioController_AUX_CONTROL_DP1_REG)    
#endif /* RadioController_DataWidth > 8u */
    
#define RadioController_COUNTER_PERIOD         (RadioController_COUNTER_PERIOD_REG)
#define RadioController_COUNTER_CONTROL        (RadioController_COUNTER_CONTROL_REG)
#define RadioController_STATUS                 (RadioController_TX_STATUS_REG)
#define RadioController_CONTROL                (RadioController_CONTROL_REG)
#define RadioController_STATUS_MASK            (RadioController_TX_STATUS_MASK_REG)
#define RadioController_STATUS_ACTL            (RadioController_TX_STATUS_ACTL_REG)


/***************************************
*       Register Constants 
***************************************/

/* Status Register Definitions */
#define RadioController_STS_SPI_DONE_SHIFT          (0x00u)
#define RadioController_STS_TX_FIFO_EMPTY_SHIFT     (0x01u)
#define RadioController_STS_TX_FIFO_NOT_FULL_SHIFT  (0x02u)
#define RadioController_STS_BYTE_COMPLETE_SHIFT     (0x03u)
#define RadioController_STS_SPI_IDLE_SHIFT          (0x04u)
#define RadioController_STS_RX_FIFO_FULL_SHIFT      (0x04u)
#define RadioController_STS_RX_FIFO_NOT_EMPTY_SHIFT (0x05u)
#define RadioController_STS_RX_FIFO_OVERRUN_SHIFT   (0x06u)

#define RadioController_STS_SPI_DONE                (0x01u << RadioController_STS_SPI_DONE_SHIFT)        
#define RadioController_STS_TX_FIFO_EMPTY           (0x01u << RadioController_STS_TX_FIFO_EMPTY_SHIFT)    
#define RadioController_STS_TX_FIFO_NOT_FULL        (0x01u << RadioController_STS_TX_FIFO_NOT_FULL_SHIFT)    
#define RadioController_STS_SPI_IDLE                (0x01u << RadioController_STS_SPI_IDLE_SHIFT)
#define RadioController_STS_RX_FIFO_FULL            (0x01u << RadioController_STS_RX_FIFO_FULL_SHIFT)    
#define RadioController_STS_RX_FIFO_NOT_EMPTY       (0x01u << RadioController_STS_RX_FIFO_NOT_EMPTY_SHIFT)    
#define RadioController_STS_RX_FIFO_OVERRUN         (0x01u << RadioController_STS_RX_FIFO_OVERRUN_SHIFT)  
#define RadioController_STS_BYTE_COMPLETE           (0x01u << RadioController_STS_BYTE_COMPLETE_SHIFT)

#define RadioController_TX_STS_CLR_ON_RD_BYTES_MASK (0x09u)
#define RadioController_RX_STS_CLR_ON_RD_BYTES_MASK (0x40u)

/* StatusI Register Interrupt Enable Control Bits */
/* As defined by the Register map for the AUX Control Register */
#define RadioController_INT_ENABLE                  (0x10u)
#define RadioController_FIFO_CLR                    (0x03u)
                                                                 
/* Bit Counter (7-bit) Control Register Bit Definitions */
/* As defined by the Register map for the AUX Control Register */
#define RadioController_CNTR_ENABLE                 (0x20u)   
                                                                  
/* Bi-Directional mode control bit */
#define RadioController_CTRL_TX_SIGNAL_EN           (0x01u)

/* Datapath Auxillary Control Register definitions */
#define RadioController_AUX_CTRL_FIFO0_CLR          (0x01u)
#define RadioController_AUX_CTRL_FIFO1_CLR          (0x02u)
#define RadioController_AUX_CTRL_FIFO0_LVL          (0x04u)
#define RadioController_AUX_CTRL_FIFO1_LVL          (0x08u)
#define RadioController_STATUS_ACTL_INT_EN_MASK     (0x10u)

#endif  /* CY_SPIM_RadioController_H */


/* [] END OF FILE */
