/*******************************************************************************
* File Name: cyfitter_cfg.h
* 
* PSoC Creator  3.3 SP1
*
* Description:
* This file provides basic startup and mux configration settings
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2015 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef CYFITTER_CFG_H
#define CYFITTER_CFG_H

#include "cytypes.h"

extern void cyfitter_cfg(void);


/* The CY_DMA_TD_PROTO_ENTRY structures are deprecated and will be removed in
 * a future version of PSoC Creator. These structures have been replaced by
 * entries in cyfitter.h, which can be accessed via ICyAPICustomize_v2. */
#if defined(__GNUC__) || defined(__ARMCC_VERSION)
#define CY_DEPRECATED __attribute__ ((deprecated))
#else
#define CY_DEPRECATED
#endif

struct CY_DMA_TD_PROTO_ENTRY
{
	uint8 offset;	/* offset of the first register in this TD */
	uint8 length;	/* length of the register block in this TD */
};

extern const struct CY_DMA_TD_PROTO_ENTRY CYCODE LCD_Seg_1_Com__DMA_TD_PROTO_BLOCK[1] CY_DEPRECATED;
#define LCD_Seg_1_Com__DMA_TD_PROTO_COUNT 1
extern const struct CY_DMA_TD_PROTO_ENTRY CYCODE LCD_Seg_1_Seg__DMA_TD_PROTO_BLOCK[1] CY_DEPRECATED;
#define LCD_Seg_1_Seg__DMA_TD_PROTO_COUNT 1

#undef CY_DEPRECATED

/* Analog Set/Unset methods */
extern void SetAnalogRoutingPumps(uint8 enabled);


#endif /* CYFITTER_CFG_H */

/*[]*/
