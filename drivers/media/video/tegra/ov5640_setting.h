/*
 * ov5640.h - OV5640 sensor setting
 *
 * Copyright (c) 2011, NVIDIA, All Rights Reserved.
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2. This program is licensed "as is" without any warranty of any
 * kind, whether express or implied.
 */

#ifndef __OV5640_SETTING_H__
#define __OV5640_SETTING_H__

#define OV5640_REG_SRM_GROUP_ACCESS    0x3212
#define OV5640_SRM_GROUP_LAUNCH_ENABLE 0x80
#define OV5640_SRM_GROUP_LAUNCH        0x20
#define OV5640_SRM_GROUP_END_HOLD      0x10

struct ov5640_reg {
	u8 op;
	u16 addr;
	u8 val;
};

enum {
	OV5640_WRITE_REG,
	OV5640_WRITE_REG_MASK,
	OV5640_DATA_MASK,
	OV5640_WAIT_MS,
	OV5640_TABLE_END,
};

static struct ov5640_reg mode_initial[] = {
	{OV5640_WRITE_REG, 0x3103, 0x11},
	{OV5640_WRITE_REG, 0x3008, 0x82},
	{OV5640_WAIT_MS,        0,   10},  // 10ms delay after software reset
	{OV5640_WRITE_REG, 0x3003, 0x03},
	{OV5640_WRITE_REG, 0x3103, 0x03},
	{OV5640_WRITE_REG, 0x3017, 0x00},
	{OV5640_WRITE_REG, 0x3018, 0x00},
	{OV5640_WRITE_REG, 0x3037, 0x13},
	{OV5640_WRITE_REG, 0x3108, 0x01},
	{OV5640_WRITE_REG, 0x3630, 0x2E},
	{OV5640_WRITE_REG, 0x3632, 0xE2},
	{OV5640_WRITE_REG, 0x3633, 0x23},
	{OV5640_WRITE_REG, 0x3621, 0xE0},
	{OV5640_WRITE_REG, 0x3704, 0xA0},
	{OV5640_WRITE_REG, 0x3703, 0x5A},
	{OV5640_WRITE_REG, 0x3715, 0x78},
	{OV5640_WRITE_REG, 0x3717, 0x01},
	{OV5640_WRITE_REG, 0x370B, 0x60},
	{OV5640_WRITE_REG, 0x3705, 0x1A},
	{OV5640_WRITE_REG, 0x3905, 0x02},
	{OV5640_WRITE_REG, 0x3906, 0x10},
	{OV5640_WRITE_REG, 0x3901, 0x0A},
	{OV5640_WRITE_REG, 0x3731, 0x12},
	{OV5640_WRITE_REG, 0x3600, 0x08},
	{OV5640_WRITE_REG, 0x3601, 0x33},
	{OV5640_WRITE_REG, 0x302D, 0x60},
	{OV5640_WRITE_REG, 0x3620, 0x52},
	{OV5640_WRITE_REG, 0x371B, 0x20},
	{OV5640_WRITE_REG, 0x471C, 0x50},
	{OV5640_WRITE_REG, 0x3A13, 0x43},
	{OV5640_WRITE_REG, 0x3635, 0x1C},
	{OV5640_WRITE_REG, 0x3634, 0x40},
	{OV5640_WRITE_REG, 0x3622, 0x01},
	{OV5640_WRITE_REG, 0x3C01, 0x34},
	{OV5640_WRITE_REG, 0x3C04, 0x28},
	{OV5640_WRITE_REG, 0x3C05, 0x98},
	{OV5640_WRITE_REG, 0x3C06, 0x00},
	{OV5640_WRITE_REG, 0x3C07, 0x08},
	{OV5640_WRITE_REG, 0x3C08, 0x00},
	{OV5640_WRITE_REG, 0x3C09, 0x1C},
	{OV5640_WRITE_REG, 0x3C0A, 0x9C},
	{OV5640_WRITE_REG, 0x3C0B, 0x40},

	// TIMING
	{OV5640_WRITE_REG, 0x3820, 0x40},
	{OV5640_WRITE_REG, 0x3821, 0x07},
	{OV5640_WRITE_REG, 0x3814, 0x31},
	{OV5640_WRITE_REG, 0x3815, 0x31},
	{OV5640_WRITE_REG, 0x3800, 0x00},
	{OV5640_WRITE_REG, 0x3801, 0x00},
	{OV5640_WRITE_REG, 0x3802, 0x00},
	{OV5640_WRITE_REG, 0x3803, 0x04},
	{OV5640_WRITE_REG, 0x3804, 0x0A},
	{OV5640_WRITE_REG, 0x3805, 0x3F},
	{OV5640_WRITE_REG, 0x3806, 0x07},
	{OV5640_WRITE_REG, 0x3807, 0x9B},
	{OV5640_WRITE_REG, 0x3808, 0x05},
	{OV5640_WRITE_REG, 0x3809, 0x00},
	{OV5640_WRITE_REG, 0x380A, 0x03},
	{OV5640_WRITE_REG, 0x380B, 0xC0},
	{OV5640_WRITE_REG, 0x380C, 0x07},
	{OV5640_WRITE_REG, 0x380D, 0x68},
	{OV5640_WRITE_REG, 0x380E, 0x03},
	{OV5640_WRITE_REG, 0x380F, 0xD8},
	{OV5640_WRITE_REG, 0x3810, 0x00},
	{OV5640_WRITE_REG, 0x3811, 0x10},
	{OV5640_WRITE_REG, 0x3812, 0x00},
	{OV5640_WRITE_REG, 0x3813, 0x06},

	// AEC band width
	{OV5640_WRITE_REG, 0x3A08, 0x01},
	{OV5640_WRITE_REG, 0x3A09, 0x27},
	{OV5640_WRITE_REG, 0x3A0A, 0x00},
	{OV5640_WRITE_REG, 0x3A0B, 0xF6},
	{OV5640_WRITE_REG, 0x3A0E, 0x03},
	{OV5640_WRITE_REG, 0x3A0D, 0x04},

	// BLC
	{OV5640_WRITE_REG, 0x4001, 0x02},
	{OV5640_WRITE_REG, 0x4004, 0x02},

	// SYSTEM
	{OV5640_WRITE_REG, 0x3000, 0x00},
	{OV5640_WRITE_REG, 0x3002, 0x1C},
	{OV5640_WRITE_REG, 0x3004, 0xFF},
	{OV5640_WRITE_REG, 0x3006, 0xC3},
	{OV5640_WRITE_REG, 0x300E, 0x45},
	{OV5640_WRITE_REG, 0x302E, 0x08},

	// FORMAT
	{OV5640_WRITE_REG, 0x4300, 0x32},
	{OV5640_WRITE_REG, 0x501F, 0x00},

	// ISP
	{OV5640_WRITE_REG, 0x5000, 0xA7},

	// GAMMA
	{OV5640_WRITE_REG, 0x5480, 0x01},
	{OV5640_WRITE_REG, 0x5025, 0x00},

	// AWB
	{OV5640_WRITE_REG, 0x5180, 0xFF},
	{OV5640_WRITE_REG, 0x5181, 0xF2},
	{OV5640_WRITE_REG, 0x5182, 0x11},
	{OV5640_WRITE_REG, 0x5183, 0x14},
	{OV5640_WRITE_REG, 0x5184, 0x25},
	{OV5640_WRITE_REG, 0x5185, 0x24},
	{OV5640_WRITE_REG, 0x5186, 0x0E},
	{OV5640_WRITE_REG, 0x5187, 0x0D},
	{OV5640_WRITE_REG, 0x5188, 0x0E},
	{OV5640_WRITE_REG, 0x5189, 0x7D},
	{OV5640_WRITE_REG, 0x518A, 0x7D},
	{OV5640_WRITE_REG, 0x518B, 0x88},
	{OV5640_WRITE_REG, 0x518C, 0x40},
	{OV5640_WRITE_REG, 0x518D, 0x41},
	{OV5640_WRITE_REG, 0x518E, 0x38},
	{OV5640_WRITE_REG, 0x518F, 0x6D},
	{OV5640_WRITE_REG, 0x5190, 0x6B},
	{OV5640_WRITE_REG, 0x5191, 0xF8},
	{OV5640_WRITE_REG, 0x5192, 0x04},
	{OV5640_WRITE_REG, 0x5193, 0x70},
	{OV5640_WRITE_REG, 0x5194, 0xF0},
	{OV5640_WRITE_REG, 0x5195, 0xF0},
	{OV5640_WRITE_REG, 0x5196, 0x03},
	{OV5640_WRITE_REG, 0x5197, 0x01},
	{OV5640_WRITE_REG, 0x5198, 0x04},
	{OV5640_WRITE_REG, 0x5199, 0x6D},
	{OV5640_WRITE_REG, 0x519A, 0x04},
	{OV5640_WRITE_REG, 0x519B, 0x00},
	{OV5640_WRITE_REG, 0x519C, 0x07},
	{OV5640_WRITE_REG, 0x519D, 0x80},
	{OV5640_WRITE_REG, 0x519E, 0x38},

	// GAMMA
	{OV5640_WRITE_REG, 0x5481, 0x04},
	{OV5640_WRITE_REG, 0x5482, 0x14},
	{OV5640_WRITE_REG, 0x5483, 0x28},
	{OV5640_WRITE_REG, 0x5484, 0x51},
	{OV5640_WRITE_REG, 0x5485, 0x65},
	{OV5640_WRITE_REG, 0x5486, 0x71},
	{OV5640_WRITE_REG, 0x5487, 0x7D},
	{OV5640_WRITE_REG, 0x5488, 0x87},
	{OV5640_WRITE_REG, 0x5489, 0x91},
	{OV5640_WRITE_REG, 0x548A, 0x9A},
	{OV5640_WRITE_REG, 0x548B, 0xAA},
	{OV5640_WRITE_REG, 0x548C, 0xB8},
	{OV5640_WRITE_REG, 0x548D, 0xCD},
	{OV5640_WRITE_REG, 0x548E, 0xDD},
	{OV5640_WRITE_REG, 0x548F, 0xEA},
	{OV5640_WRITE_REG, 0x5490, 0x1D},

	// CMX
	{OV5640_WRITE_REG, 0x5381, 0x1C},
	{OV5640_WRITE_REG, 0x5382, 0x5A},
	{OV5640_WRITE_REG, 0x5383, 0x06},
	{OV5640_WRITE_REG, 0x5384, 0x09},
	{OV5640_WRITE_REG, 0x5385, 0x77},
	{OV5640_WRITE_REG, 0x5386, 0x83},
	{OV5640_WRITE_REG, 0x5387, 0x75},
	{OV5640_WRITE_REG, 0x5388, 0x66},
	{OV5640_WRITE_REG, 0x5389, 0x0F},
	{OV5640_WRITE_REG, 0x538B, 0x98},
	{OV5640_WRITE_REG, 0x538A, 0x01},

	// CIP
	{OV5640_WRITE_REG, 0x5300, 0x08},
	{OV5640_WRITE_REG, 0x5301, 0x30},
	{OV5640_WRITE_REG, 0x5302, 0x18},
	{OV5640_WRITE_REG, 0x5303, 0x00},
	{OV5640_WRITE_REG, 0x5304, 0x08},
	{OV5640_WRITE_REG, 0x5305, 0x30},
	{OV5640_WRITE_REG, 0x5306, 0x08},
	{OV5640_WRITE_REG, 0x5307, 0x40},
	{OV5640_WRITE_REG, 0x5309, 0x08},
	{OV5640_WRITE_REG, 0x530A, 0x30},
	{OV5640_WRITE_REG, 0x530B, 0x04},
	{OV5640_WRITE_REG, 0x530C, 0x06},

	// SDE
	{OV5640_WRITE_REG, 0x5580, 0x02},
	{OV5640_WRITE_REG, 0x5588, 0x01},
	{OV5640_WRITE_REG, 0x5583, 0x40},
	{OV5640_WRITE_REG, 0x5584, 0x30},
	{OV5640_WRITE_REG, 0x5589, 0x38},
	{OV5640_WRITE_REG, 0x558A, 0x00},
	{OV5640_WRITE_REG, 0x558B, 0x78},

	// LSC
	{OV5640_WRITE_REG, 0x5800, 0x30},
	{OV5640_WRITE_REG, 0x5801, 0x1B},
	{OV5640_WRITE_REG, 0x5802, 0x15},
	{OV5640_WRITE_REG, 0x5803, 0x15},
	{OV5640_WRITE_REG, 0x5804, 0x1A},
	{OV5640_WRITE_REG, 0x5805, 0x38},
	{OV5640_WRITE_REG, 0x5806, 0x11},
	{OV5640_WRITE_REG, 0x5807, 0x09},
	{OV5640_WRITE_REG, 0x5808, 0x06},
	{OV5640_WRITE_REG, 0x5809, 0x06},
	{OV5640_WRITE_REG, 0x580A, 0x0A},
	{OV5640_WRITE_REG, 0x580B, 0x0F},
	{OV5640_WRITE_REG, 0x580C, 0x0B},
	{OV5640_WRITE_REG, 0x580D, 0x03},
	{OV5640_WRITE_REG, 0x580E, 0x00},
	{OV5640_WRITE_REG, 0x580F, 0x00},
	{OV5640_WRITE_REG, 0x5810, 0x04},
	{OV5640_WRITE_REG, 0x5811, 0x0C},
	{OV5640_WRITE_REG, 0x5812, 0x0B},
	{OV5640_WRITE_REG, 0x5813, 0x04},
	{OV5640_WRITE_REG, 0x5814, 0x00},
	{OV5640_WRITE_REG, 0x5815, 0x00},
	{OV5640_WRITE_REG, 0x5816, 0x05},
	{OV5640_WRITE_REG, 0x5817, 0x0C},
	{OV5640_WRITE_REG, 0x5818, 0x11},
	{OV5640_WRITE_REG, 0x5819, 0x0A},
	{OV5640_WRITE_REG, 0x581A, 0x07},
	{OV5640_WRITE_REG, 0x581B, 0x07},
	{OV5640_WRITE_REG, 0x581C, 0x0B},
	{OV5640_WRITE_REG, 0x581D, 0x11},
	{OV5640_WRITE_REG, 0x581E, 0x3E},
	{OV5640_WRITE_REG, 0x581F, 0x1D},
	{OV5640_WRITE_REG, 0x5820, 0x17},
	{OV5640_WRITE_REG, 0x5821, 0x17},
	{OV5640_WRITE_REG, 0x5822, 0x1F},
	{OV5640_WRITE_REG, 0x5823, 0x3F},
	{OV5640_WRITE_REG, 0x5824, 0x65},
	{OV5640_WRITE_REG, 0x5825, 0x21},
	{OV5640_WRITE_REG, 0x5826, 0x23},
	{OV5640_WRITE_REG, 0x5827, 0x21},
	{OV5640_WRITE_REG, 0x5828, 0x23},
	{OV5640_WRITE_REG, 0x5829, 0x23},
	{OV5640_WRITE_REG, 0x582A, 0x21},
	{OV5640_WRITE_REG, 0x582B, 0x21},
	{OV5640_WRITE_REG, 0x582C, 0x21},
	{OV5640_WRITE_REG, 0x582D, 0x03},
	{OV5640_WRITE_REG, 0x582E, 0x23},
	{OV5640_WRITE_REG, 0x582F, 0x21},
	{OV5640_WRITE_REG, 0x5830, 0x41},
	{OV5640_WRITE_REG, 0x5831, 0x41},
	{OV5640_WRITE_REG, 0x5832, 0x01},
	{OV5640_WRITE_REG, 0x5833, 0x23},
	{OV5640_WRITE_REG, 0x5834, 0x21},
	{OV5640_WRITE_REG, 0x5835, 0x21},
	{OV5640_WRITE_REG, 0x5836, 0x21},
	{OV5640_WRITE_REG, 0x5837, 0x03},
	{OV5640_WRITE_REG, 0x5838, 0x43},
	{OV5640_WRITE_REG, 0x5839, 0x23},
	{OV5640_WRITE_REG, 0x583A, 0x23},
	{OV5640_WRITE_REG, 0x583B, 0x23},
	{OV5640_WRITE_REG, 0x583C, 0x43},
	{OV5640_WRITE_REG, 0x583D, 0xCF},

	// AEC
	{OV5640_WRITE_REG, 0x3A00, 0x7C},
	// night mode
	{OV5640_WRITE_REG, 0x3A02, 0x07},
	{OV5640_WRITE_REG, 0x3A03, 0xB0},
	{OV5640_WRITE_REG, 0x3A14, 0x07},
	{OV5640_WRITE_REG, 0x3A15, 0xB0},
	{OV5640_WRITE_REG, 0x3A17, 0x02},
	// stable range
	{OV5640_WRITE_REG, 0x3A0F, 0x2C},
	{OV5640_WRITE_REG, 0x3A10, 0x27},
	{OV5640_WRITE_REG, 0x3A1B, 0x2C},
	{OV5640_WRITE_REG, 0x3A1E, 0x27},
	{OV5640_WRITE_REG, 0x3A11, 0x61},
	{OV5640_WRITE_REG, 0x3A1F, 0x10},
	// gain ceiling
	{OV5640_WRITE_REG, 0x3A18, 0x00},
	{OV5640_WRITE_REG, 0x3A19, 0x7F},

	// AVG window weight
	{OV5640_WRITE_REG, 0x5688, 0x62},
	{OV5640_WRITE_REG, 0x5689, 0x26},
	{OV5640_WRITE_REG, 0x568A, 0xE6},
	{OV5640_WRITE_REG, 0x568B, 0x6E},
	{OV5640_WRITE_REG, 0x568C, 0xEA},
	{OV5640_WRITE_REG, 0x568D, 0xAE},
	{OV5640_WRITE_REG, 0x568E, 0xA6},
	{OV5640_WRITE_REG, 0x568F, 0x6A},

	{OV5640_WRITE_REG, 0x3034, 0x18},
	{OV5640_WRITE_REG, 0x3503, 0x00},
	{OV5640_WRITE_REG, 0x3036, 0x70},

	{OV5640_WRITE_REG, 0x3618, 0x00},
	{OV5640_WRITE_REG, 0x3612, 0x29},
	{OV5640_WRITE_REG, 0x3708, 0x62},
	{OV5640_WRITE_REG, 0x3709, 0x52},
	{OV5640_WRITE_REG, 0x370C, 0x03},
	{OV5640_WRITE_REG, 0x5001, 0xA3},
	{OV5640_WRITE_REG, 0x3035, 0x21},

	{OV5640_WRITE_REG, 0x4713, 0x02},
	{OV5640_WRITE_REG, 0x4407, 0x0C},
	{OV5640_WRITE_REG, 0x460B, 0x35},
	{OV5640_WRITE_REG, 0x460C, 0x20},
	{OV5640_WRITE_REG, 0x3824, 0x01},
	{OV5640_WRITE_REG, 0x4800, 0x34},
	{OV5640_WRITE_REG, 0x4837, 0x10},
	{OV5640_WRITE_REG, 0x3003, 0x01},
	{OV5640_WRITE_REG, 0x4003, 0x82},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg mode_1280x960[] = {
	{OV5640_WRITE_REG, 0x4201, 0x01},  // stop after 1 frame, workaround for take green picture
	{OV5640_WRITE_REG, 0x3036, 0x70},
	{OV5640_WRITE_REG, 0x3C07, 0x08},
	{OV5640_WRITE_REG, 0x3820, 0x40},
	{OV5640_WRITE_REG, 0x3821, 0x07},
	{OV5640_WRITE_REG, 0x3814, 0x31},
	{OV5640_WRITE_REG, 0x3815, 0x31},
	{OV5640_WRITE_REG, 0x3800, 0x00},
	{OV5640_WRITE_REG, 0x3801, 0x00},
	{OV5640_WRITE_REG, 0x3802, 0x00},
	{OV5640_WRITE_REG, 0x3803, 0x04},
	{OV5640_WRITE_REG, 0x3804, 0x0A},
	{OV5640_WRITE_REG, 0x3805, 0x3F},
	{OV5640_WRITE_REG, 0x3806, 0x07},
	{OV5640_WRITE_REG, 0x3807, 0x9B},
	{OV5640_WRITE_REG, 0x3808, 0x05},
	{OV5640_WRITE_REG, 0x3809, 0x00},
	{OV5640_WRITE_REG, 0x380A, 0x03},
	{OV5640_WRITE_REG, 0x380B, 0xC0},
	{OV5640_WRITE_REG, 0x380C, 0x07},
	{OV5640_WRITE_REG, 0x380D, 0x68},
	{OV5640_WRITE_REG, 0x380E, 0x03},
	{OV5640_WRITE_REG, 0x380F, 0xD8},
	{OV5640_WRITE_REG, 0x3813, 0x06},
	{OV5640_WRITE_REG, 0x3618, 0x00},
	{OV5640_WRITE_REG, 0x3612, 0x29},
	{OV5640_WRITE_REG, 0x3708, 0x62},
	{OV5640_WRITE_REG, 0x3709, 0x52},
	{OV5640_WRITE_REG, 0x370C, 0x03},
	{OV5640_WRITE_REG, 0x3A0E, 0x03},
	{OV5640_WRITE_REG, 0x3A0D, 0x04},
	{OV5640_WRITE_REG, 0x4004, 0x02},
	{OV5640_WRITE_REG, 0x5001, 0xA3},
	{OV5640_WRITE_REG, 0x3008, 0x02},
	{OV5640_WRITE_REG, 0x3035, 0x21},
	{OV5640_WRITE_REG, 0x3002, 0x1C},
	{OV5640_WRITE_REG, 0x3006, 0xC3},
	{OV5640_WRITE_REG, 0x4713, 0x02},
	{OV5640_WRITE_REG, 0x4407, 0x0C},
	{OV5640_WRITE_REG, 0x460B, 0x35},
	{OV5640_WRITE_REG, 0x460C, 0x20},
	{OV5640_WRITE_REG, 0x3824, 0x01},
	{OV5640_WRITE_REG, 0x3003, 0x03},
	{OV5640_WRITE_REG, 0x3003, 0x01},
	{OV5640_WRITE_REG, 0x4003, 0x82},

	// group write for AEC in case of unstable exposure after capture
	{OV5640_WRITE_REG, 0x3004, 0xDF},  // disable MCU clock
	{OV5640_WRITE_REG, 0x3212, 0x00},  // group access
	{OV5640_WRITE_REG, 0x3503, 0x00},
	{OV5640_WRITE_REG, 0x3004, 0xFF},  // enable MCU clock here in case group write failed
	{OV5640_WRITE_REG, 0x3022, 0x12},  // relaunch focus zone after MCU clock on in case AF failed
	{OV5640_WRITE_REG, 0x3212, 0x10},  // group hold end
	{OV5640_WRITE_REG, 0x3212, 0xA0},  // group launch enable and group launch

	{OV5640_WRITE_REG, 0x4201, 0x00},  // start after 1 frame, workaround for take green picture
	{OV5640_WRITE_REG, 0x4202, 0x01},  // start after 1 frame, workaround for take green picture

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg mode_2592x1944[] = {
	{OV5640_WRITE_REG, 0x4201, 0x01},  // stop after 1 frame, workaround for take green picture
	{OV5640_WRITE_REG, 0x3003, 0x03},
	{OV5640_WRITE_REG, 0x3503, 0x07},
	{OV5640_WRITE_REG, 0x3036, 0x54},
	{OV5640_WRITE_REG, 0x3C07, 0x07},
	{OV5640_WRITE_REG, 0x3820, 0x40},
	{OV5640_WRITE_REG, 0x3821, 0x06},
	{OV5640_WRITE_REG, 0x3814, 0x11},
	{OV5640_WRITE_REG, 0x3815, 0x11},
	{OV5640_WRITE_REG, 0x3800, 0x00},
	{OV5640_WRITE_REG, 0x3801, 0x00},
	{OV5640_WRITE_REG, 0x3802, 0x00},
	{OV5640_WRITE_REG, 0x3803, 0x00},
	{OV5640_WRITE_REG, 0x3804, 0x0A},
	{OV5640_WRITE_REG, 0x3805, 0x3F},
	{OV5640_WRITE_REG, 0x3806, 0x07},
	{OV5640_WRITE_REG, 0x3807, 0x9F},
	{OV5640_WRITE_REG, 0x3808, 0x0A},
	{OV5640_WRITE_REG, 0x3809, 0x20},
	{OV5640_WRITE_REG, 0x380A, 0x07},
	{OV5640_WRITE_REG, 0x380B, 0x98},
	{OV5640_WRITE_REG, 0x380C, 0x0B},
	{OV5640_WRITE_REG, 0x380D, 0x20},
	{OV5640_WRITE_REG, 0x380E, 0x07},
	{OV5640_WRITE_REG, 0x380F, 0xB0},
	{OV5640_WRITE_REG, 0x3813, 0x04},
	{OV5640_WRITE_REG, 0x3618, 0x04},
	{OV5640_WRITE_REG, 0x3612, 0x2B},
	{OV5640_WRITE_REG, 0x3708, 0x21},
	{OV5640_WRITE_REG, 0x3709, 0x12},
	{OV5640_WRITE_REG, 0x370C, 0x00},
	{OV5640_WRITE_REG, 0x3A0E, 0x03},
	{OV5640_WRITE_REG, 0x3A0D, 0x04},
	{OV5640_WRITE_REG, 0x4004, 0x06},
	{OV5640_WRITE_REG, 0x5001, 0x83},
	{OV5640_WRITE_REG, 0x3008, 0x02},
	{OV5640_WRITE_REG, 0x3035, 0x11},
	{OV5640_WRITE_REG, 0x3002, 0x1C},
	{OV5640_WRITE_REG, 0x3006, 0xC3},
	{OV5640_WRITE_REG, 0x4713, 0x02},
	{OV5640_WRITE_REG, 0x4407, 0x0C},
	{OV5640_WRITE_REG, 0x460B, 0x35},
	{OV5640_WRITE_REG, 0x460C, 0x20},
	{OV5640_WRITE_REG, 0x3824, 0x01},
	{OV5640_WRITE_REG, 0x4003, 0x82},
	{OV5640_WRITE_REG, 0x3003, 0x01},
	{OV5640_WRITE_REG, 0x4201, 0x00},  // start after 1 frame, workaround for take green picture
	{OV5640_WRITE_REG, 0x4202, 0x01},  // start after 1 frame, workaround for take green picture

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg mode_1920x1080[] = {
	{OV5640_WRITE_REG, 0x4201, 0x01},  // stop after 1 frame, workaround for take green picture
	{OV5640_WRITE_REG, 0x3035, 0x11},
	{OV5640_WRITE_REG, 0x3036, 0x54},
	{OV5640_WRITE_REG, 0x3C07, 0x07},
	{OV5640_WRITE_REG, 0x3820, 0x40},
	{OV5640_WRITE_REG, 0x3821, 0x06},
	{OV5640_WRITE_REG, 0x3814, 0x11},
	{OV5640_WRITE_REG, 0x3815, 0x11},
	{OV5640_WRITE_REG, 0x3800, 0x01},
	{OV5640_WRITE_REG, 0x3801, 0x50},
	{OV5640_WRITE_REG, 0x3802, 0x01},
	{OV5640_WRITE_REG, 0x3803, 0xB2},
	{OV5640_WRITE_REG, 0x3804, 0x08},
	{OV5640_WRITE_REG, 0x3805, 0xEF},
	{OV5640_WRITE_REG, 0x3806, 0x05},
	{OV5640_WRITE_REG, 0x3807, 0xF2},
	{OV5640_WRITE_REG, 0x3808, 0x07},
	{OV5640_WRITE_REG, 0x3809, 0x80},
	{OV5640_WRITE_REG, 0x380A, 0x04},
	{OV5640_WRITE_REG, 0x380B, 0x38},
	{OV5640_WRITE_REG, 0x380C, 0x09},
	{OV5640_WRITE_REG, 0x380D, 0xC4},
	{OV5640_WRITE_REG, 0x380E, 0x04},
	{OV5640_WRITE_REG, 0x380F, 0x60},
	{OV5640_WRITE_REG, 0x3813, 0x04},
	{OV5640_WRITE_REG, 0x3618, 0x04},
	{OV5640_WRITE_REG, 0x3612, 0x2B},
	{OV5640_WRITE_REG, 0x3708, 0x62},
	{OV5640_WRITE_REG, 0x3709, 0x12},
	{OV5640_WRITE_REG, 0x370C, 0x00},
	{OV5640_WRITE_REG, 0x4004, 0x06},
	{OV5640_WRITE_REG, 0x4713, 0x02},
	{OV5640_WRITE_REG, 0x4407, 0x04},
	{OV5640_WRITE_REG, 0x460B, 0x37},
	{OV5640_WRITE_REG, 0x460C, 0x20},
	{OV5640_WRITE_REG, 0x3824, 0x04},
	{OV5640_WRITE_REG, 0x5001, 0x83},
	{OV5640_WRITE_REG, 0x3008, 0x02},
	{OV5640_WRITE_REG, 0x3002, 0x1C},
	{OV5640_WRITE_REG, 0x3006, 0xC3},
	{OV5640_WRITE_REG, 0x4003, 0x82},
	{OV5640_WRITE_REG, 0x4201, 0x00},  // start after 1 frame, workaround for take green picture
	{OV5640_WRITE_REG, 0x4202, 0x01},  // start after 1 frame, workaround for take green picture

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static u8 af_firmware_code[] = {
#include "ov5640_af_firmware_code.h"
};

enum {
	OV5640_MODE_1280x960,
	OV5640_MODE_2592x1944,
	OV5640_MODE_1920x1080,
};

static struct ov5640_reg *mode_table[] = {
	[OV5640_MODE_1280x960]  = mode_1280x960,
	[OV5640_MODE_2592x1944] = mode_2592x1944,
	[OV5640_MODE_1920x1080] = mode_1920x1080,
};

#define OV5640_AF_CMD_MAIN   0x3022
#define OV5640_AF_CMD_ACK    0x3023
#define OV5640_AF_CMD_PARA0  0x3024
#define OV5640_AF_CMD_PARA1  0x3025
#define OV5640_AF_CMD_PARA2  0x3026
#define OV5640_AF_CMD_PARA3  0x3027
#define OV5640_AF_CMD_PARA4  0x3028
#define OV5640_AF_FW_STATUS  0x3029

#define OV5640_FW_S_FIRWARE   0x7F
#define OV5640_FW_S_STARTUP   0x7E
#define OV5640_FW_S_IDLE      0x70
#define OV5640_FW_S_FOCUSING  0x00
#define OV5640_FW_S_FOCUSED   0x10

#define OV5640_TRIG_AUTO_FOCUS       0x03
#define OV5640_RELEASE_FOCUS         0x08
#define OV5640_RELAUNCH_FOCUS_ZONES  0x12

static struct ov5640_reg WhiteBalance_Auto[] = {
	{OV5640_WRITE_REG, 0x3406, 0x00},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg WhiteBalance_Incandescent[] = {
	{OV5640_WRITE_REG, 0x3406, 0x01},
	{OV5640_WRITE_REG, 0x3400, 0x04},
	{OV5640_WRITE_REG, 0x3401, 0x9D},
	{OV5640_WRITE_REG, 0x3402, 0x04},
	{OV5640_WRITE_REG, 0x3403, 0x00},
	{OV5640_WRITE_REG, 0x3404, 0x09},
	{OV5640_WRITE_REG, 0x3405, 0xA6},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg WhiteBalance_Fluorescent[] = {
	{OV5640_WRITE_REG, 0x3406, 0x01},
	{OV5640_WRITE_REG, 0x3400, 0x05},
	{OV5640_WRITE_REG, 0x3401, 0x48},
	{OV5640_WRITE_REG, 0x3402, 0x04},
	{OV5640_WRITE_REG, 0x3403, 0x00},
	{OV5640_WRITE_REG, 0x3404, 0x07},
	{OV5640_WRITE_REG, 0x3405, 0xCF},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg WhiteBalance_Daylight[] = {
	{OV5640_WRITE_REG, 0x3406, 0x01},
	{OV5640_WRITE_REG, 0x3400, 0x06},
	{OV5640_WRITE_REG, 0x3401, 0x1C},
	{OV5640_WRITE_REG, 0x3402, 0x04},
	{OV5640_WRITE_REG, 0x3403, 0x00},
	{OV5640_WRITE_REG, 0x3404, 0x04},
	{OV5640_WRITE_REG, 0x3405, 0xF3},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg WhiteBalance_CloudyDaylight[] = {
	{OV5640_WRITE_REG, 0x3406, 0x01},
	{OV5640_WRITE_REG, 0x3400, 0x07},
	{OV5640_WRITE_REG, 0x3401, 0x48},
	{OV5640_WRITE_REG, 0x3402, 0x04},
	{OV5640_WRITE_REG, 0x3403, 0x00},
	{OV5640_WRITE_REG, 0x3404, 0x04},
	{OV5640_WRITE_REG, 0x3405, 0xD3},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg ColorEffect_Aqua[] = {
	{OV5640_WRITE_REG_MASK, 0x5580, 0x18},
	{OV5640_DATA_MASK,      0, 0x58},
	{OV5640_WRITE_REG, 0x5583, 0xA0},
	{OV5640_WRITE_REG, 0x5584, 0x40},
	{OV5640_WRITE_REG_MASK, 0x5003, 0x00},
	{OV5640_DATA_MASK,      0, 0x01},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg ColorEffect_Mono[] = {
	{OV5640_WRITE_REG_MASK, 0x5580, 0x18},
	{OV5640_DATA_MASK,      0, 0x58},
	{OV5640_WRITE_REG, 0x5583, 0x80},
	{OV5640_WRITE_REG, 0x5584, 0x80},
	{OV5640_WRITE_REG_MASK, 0x5003, 0x00},
	{OV5640_DATA_MASK,      0, 0x01},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg ColorEffect_Negative[] = {
	{OV5640_WRITE_REG_MASK, 0x5580, 0x40},
	{OV5640_DATA_MASK,      0, 0x58},
	{OV5640_WRITE_REG_MASK, 0x5003, 0x00},
	{OV5640_DATA_MASK,      0, 0x01},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg ColorEffect_None[] = {
	{OV5640_WRITE_REG_MASK, 0x5580, 0x00},
	{OV5640_DATA_MASK,      0, 0x58},
	{OV5640_WRITE_REG, 0x5583, 0x40},
	{OV5640_WRITE_REG, 0x5584, 0x30},
	{OV5640_WRITE_REG_MASK, 0x5003, 0x00},
	{OV5640_DATA_MASK,      0, 0x01},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg ColorEffect_Sepia[] = {
	{OV5640_WRITE_REG_MASK, 0x5580, 0x18},
	{OV5640_DATA_MASK,      0, 0x58},
	{OV5640_WRITE_REG, 0x5583, 0x40},
	{OV5640_WRITE_REG, 0x5584, 0xA0},
	{OV5640_WRITE_REG_MASK, 0x5003, 0x00},
	{OV5640_DATA_MASK,      0, 0x01},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg ColorEffect_Solarize[] = {
	{OV5640_WRITE_REG_MASK, 0x5580, 0x00},
	{OV5640_DATA_MASK,      0, 0x58},
	{OV5640_WRITE_REG, 0x5583, 0x40},
	{OV5640_WRITE_REG, 0x5584, 0x40},
	{OV5640_WRITE_REG_MASK, 0x5003, 0x01},
	{OV5640_DATA_MASK,      0, 0x01},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg Exposure_Minus_Two[] = {
	// -1.3EV
	{OV5640_WRITE_REG, 0x3A0F, 0x12},
	{OV5640_WRITE_REG, 0x3A10, 0x0C},
	{OV5640_WRITE_REG, 0x3A1B, 0x12},
	{OV5640_WRITE_REG, 0x3A1E, 0x0C},
	{OV5640_WRITE_REG, 0x3A11, 0x30},
	{OV5640_WRITE_REG, 0x3A1F, 0x10},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg Exposure_Minus_One[] = {
	// -0.7EV
	{OV5640_WRITE_REG, 0x3A0F, 0x20},
	{OV5640_WRITE_REG, 0x3A10, 0x1A},
	{OV5640_WRITE_REG, 0x3A1B, 0x20},
	{OV5640_WRITE_REG, 0x3A1E, 0x1A},
	{OV5640_WRITE_REG, 0x3A11, 0x51},
	{OV5640_WRITE_REG, 0x3A1F, 0x10},

	{OV5640_TABLE_END, 0x0000, 0x00},
};


static struct ov5640_reg Exposure_Zero[] = {
	// default
	{OV5640_WRITE_REG, 0x3A0F, 0x2C},
	{OV5640_WRITE_REG, 0x3A10, 0x27},
	{OV5640_WRITE_REG, 0x3A1B, 0x2C},
	{OV5640_WRITE_REG, 0x3A1E, 0x27},
	{OV5640_WRITE_REG, 0x3A11, 0x61},
	{OV5640_WRITE_REG, 0x3A1F, 0x10},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg Exposure_Plus_One[] = {
	// +0.7EV
	{OV5640_WRITE_REG, 0x3A0F, 0x3A},
	{OV5640_WRITE_REG, 0x3A10, 0x34},
	{OV5640_WRITE_REG, 0x3A1B, 0x3A},
	{OV5640_WRITE_REG, 0x3A1E, 0x34},
	{OV5640_WRITE_REG, 0x3A11, 0x80},
	{OV5640_WRITE_REG, 0x3A1F, 0x20},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

static struct ov5640_reg Exposure_Plus_Two[] = {
	// +1.3EV
	{OV5640_WRITE_REG, 0x3A0F, 0x48},
	{OV5640_WRITE_REG, 0x3A10, 0x42},
	{OV5640_WRITE_REG, 0x3A1B, 0x48},
	{OV5640_WRITE_REG, 0x3A1E, 0x42},
	{OV5640_WRITE_REG, 0x3A11, 0x91},
	{OV5640_WRITE_REG, 0x3A1F, 0x20},

	{OV5640_TABLE_END, 0x0000, 0x00},
};

#endif  // __OV5640_SETTING_H__
