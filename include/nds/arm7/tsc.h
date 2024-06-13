// SPDX-License-Identifier: Zlib
//
// Copyright (C) 2024 Adrian "asie" Siekierka

#ifndef LIBNDS_NDS_ARM7_TSC_H__
#define LIBNDS_NDS_ARM7_TSC_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ARM7
#error TSC is only available on the ARM7
#endif

/// @file nds/arm7/touch.h
///
/// @brief DS Touchscreen/Sound Controller control for ARM7

#include <nds/arm7/serial.h>

#define TSC_START               0x80
#define TSC_CHANNEL(n)          ((n) << 4)
#define TSC_CONVERT_12BIT       0x00 ///< Convert to 12-bit samples
#define TSC_CONVERT_8BIT        0x08 ///< Convert to 8-bit samples
#define TSC_MODE_DFR            0x00 ///< Differential Reference mode
#define TSC_MODE_SER            0x04 ///< Single-Ended Reference mode
#define TSC_POWER_AUTO          0x00 ///< Auto Power Down mode
#define TSC_POWER_ON            0x01 ///< Full Power mode

#define TSC_MEASURE_TEMP1       (TSC_START | TSC_CHANNEL(0) | TSC_CONVERT_12BIT | TSC_MODE_SER)
#define TSC_MEASURE_Y           (TSC_START | TSC_CHANNEL(1) | TSC_CONVERT_12BIT | TSC_MODE_DFR)
#define TSC_MEASURE_BATTERY     (TSC_START | TSC_CHANNEL(2) | TSC_CONVERT_12BIT | TSC_MODE_SER)
#define TSC_MEASURE_Z1          (TSC_START | TSC_CHANNEL(3) | TSC_CONVERT_12BIT | TSC_MODE_SER)
#define TSC_MEASURE_Z2          (TSC_START | TSC_CHANNEL(4) | TSC_CONVERT_12BIT | TSC_MODE_SER)
#define TSC_MEASURE_X           (TSC_START | TSC_CHANNEL(5) | TSC_CONVERT_12BIT | TSC_MODE_DFR)
#define TSC_MEASURE_AUX         (TSC_START | TSC_CHANNEL(6) | TSC_CONVERT_12BIT | TSC_MODE_SER)
#define TSC_MEASURE_TEMP2       (TSC_START | TSC_CHANNEL(7) | TSC_CONVERT_12BIT | TSC_MODE_SER)

/**
 * @brief Read a single 12-bit measurement from the NDS-mode TSC.
 * 
 * @param command Measurement command.
 * @return u16 Measured value, from 0 to 4095.
 */
u16 tscRead(u32 command);

/**
 * @brief Read multiple 12-bit measurements from the NDS-mode TSC.
 * 
 * @param command Measurement command.
 * @param buffer Output buffer.
 * @param count Number of measurements to read.
 */
void tscMeasure(u32 command, u16 *buffer, u32 count);

#ifdef __cplusplus
}
#endif

#endif // LIBNDS_NDS_ARM7_TSC_H__
