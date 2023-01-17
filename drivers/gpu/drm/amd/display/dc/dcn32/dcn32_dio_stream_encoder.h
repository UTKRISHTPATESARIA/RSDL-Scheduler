/*
 * Copyright 2021 - Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */

#ifndef __DC_DIO_STREAM_ENCODER_DCN32_H__
#define __DC_DIO_STREAM_ENCODER_DCN32_H__

#include "dcn30/dcn30_vpg.h"
#include "dcn30/dcn30_afmt.h"
#include "stream_encoder.h"
#include "dcn20/dcn20_stream_encoder.h"

#define SE_DCN32_REG_LIST(id)\
	SRI(AFMT_CNTL, DIG, id), \
	SRI(DIG_FE_CNTL, DIG, id), \
	SRI(HDMI_CONTROL, DIG, id), \
	SRI(HDMI_DB_CONTROL, DIG, id), \
	SRI(HDMI_GC, DIG, id), \
	SRI(HDMI_GENERIC_PACKET_CONTROL0, DIG, id), \
	SRI(HDMI_GENERIC_PACKET_CONTROL1, DIG, id), \
	SRI(HDMI_GENERIC_PACKET_CONTROL2, DIG, id), \
	SRI(HDMI_GENERIC_PACKET_CONTROL3, DIG, id), \
	SRI(HDMI_GENERIC_PACKET_CONTROL4, DIG, id), \
	SRI(HDMI_GENERIC_PACKET_CONTROL5, DIG, id), \
	SRI(HDMI_GENERIC_PACKET_CONTROL6, DIG, id), \
	SRI(HDMI_GENERIC_PACKET_CONTROL7, DIG, id), \
	SRI(HDMI_GENERIC_PACKET_CONTROL8, DIG, id), \
	SRI(HDMI_GENERIC_PACKET_CONTROL9, DIG, id), \
	SRI(HDMI_GENERIC_PACKET_CONTROL10, DIG, id), \
	SRI(HDMI_INFOFRAME_CONTROL0, DIG, id), \
	SRI(HDMI_INFOFRAME_CONTROL1, DIG, id), \
	SRI(HDMI_VBI_PACKET_CONTROL, DIG, id), \
	SRI(HDMI_AUDIO_PACKET_CONTROL, DIG, id),\
	SRI(HDMI_ACR_PACKET_CONTROL, DIG, id),\
	SRI(HDMI_ACR_32_0, DIG, id),\
	SRI(HDMI_ACR_32_1, DIG, id),\
	SRI(HDMI_ACR_44_0, DIG, id),\
	SRI(HDMI_ACR_44_1, DIG, id),\
	SRI(HDMI_ACR_48_0, DIG, id),\
	SRI(HDMI_ACR_48_1, DIG, id),\
	SRI(DP_DB_CNTL, DP, id), \
	SRI(DP_MSA_MISC, DP, id), \
	SRI(DP_MSA_VBID_MISC, DP, id), \
	SRI(DP_MSA_COLORIMETRY, DP, id), \
	SRI(DP_MSA_TIMING_PARAM1, DP, id), \
	SRI(DP_MSA_TIMING_PARAM2, DP, id), \
	SRI(DP_MSA_TIMING_PARAM3, DP, id), \
	SRI(DP_MSA_TIMING_PARAM4, DP, id), \
	SRI(DP_MSE_RATE_CNTL, DP, id), \
	SRI(DP_MSE_RATE_UPDATE, DP, id), \
	SRI(DP_PIXEL_FORMAT, DP, id), \
	SRI(DP_SEC_CNTL, DP, id), \
	SRI(DP_SEC_CNTL2, DP, id), \
	SRI(DP_SEC_CNTL6, DP, id), \
	SRI(DP_STEER_FIFO, DP, id), \
	SRI(DP_VID_M, DP, id), \
	SRI(DP_VID_N, DP, id), \
	SRI(DP_VID_STREAM_CNTL, DP, id), \
	SRI(DP_VID_TIMING, DP, id), \
	SRI(DP_SEC_AUD_N, DP, id), \
	SRI(DP_SEC_TIMESTAMP, DP, id), \
	SRI(DP_DSC_CNTL, DP, id), \
	SRI(DP_SEC_METADATA_TRANSMISSION, DP, id), \
	SRI(HDMI_METADATA_PACKET_CONTROL, DIG, id), \
	SRI(DP_SEC_FRAMING4, DP, id), \
	SRI(DP_GSP11_CNTL, DP, id), \
	SRI(DME_CONTROL, DME, id),\
	SRI(DP_SEC_METADATA_TRANSMISSION, DP, id), \
	SRI(HDMI_METADATA_PACKET_CONTROL, DIG, id), \
	SRI(DIG_FE_CNTL, DIG, id), \
	SRI(DIG_CLOCK_PATTERN, DIG, id), \
	SRI(DIG_FIFO_CTRL0, DIG, id)


#define SE_COMMON_MASK_SH_LIST_DCN32_BASE(mask_sh)\
	SE_SF(DP0_DP_PIXEL_FORMAT, DP_PIXEL_ENCODING, mask_sh),\
	SE_SF(DP0_DP_PIXEL_FORMAT, DP_COMPONENT_DEPTH, mask_sh),\
	SE_SF(DP0_DP_PIXEL_FORMAT, DP_PIXEL_PER_CYCLE_PROCESSING_MODE, mask_sh),\
	SE_SF(DIG0_HDMI_CONTROL, HDMI_PACKET_GEN_VERSION, mask_sh),\
	SE_SF(DIG0_HDMI_CONTROL, HDMI_KEEPOUT_MODE, mask_sh),\
	SE_SF(DIG0_HDMI_CONTROL, HDMI_DEEP_COLOR_ENABLE, mask_sh),\
	SE_SF(DIG0_HDMI_CONTROL, HDMI_DEEP_COLOR_DEPTH, mask_sh),\
	SE_SF(DIG0_HDMI_CONTROL, HDMI_DATA_SCRAMBLE_EN, mask_sh),\
	SE_SF(DIG0_HDMI_CONTROL, HDMI_NO_EXTRA_NULL_PACKET_FILLED, mask_sh),\
	SE_SF(DIG0_HDMI_VBI_PACKET_CONTROL, HDMI_GC_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_VBI_PACKET_CONTROL, HDMI_GC_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_VBI_PACKET_CONTROL, HDMI_NULL_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_INFOFRAME_CONTROL0, HDMI_AUDIO_INFO_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_INFOFRAME_CONTROL1, HDMI_AUDIO_INFO_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GC, HDMI_GC_AVMUTE, mask_sh),\
	SE_SF(DP0_DP_MSE_RATE_CNTL, DP_MSE_RATE_X, mask_sh),\
	SE_SF(DP0_DP_MSE_RATE_CNTL, DP_MSE_RATE_Y, mask_sh),\
	SE_SF(DP0_DP_MSE_RATE_UPDATE, DP_MSE_RATE_UPDATE_PENDING, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP0_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_STREAM_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP1_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP2_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP3_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_MPG_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL1, DP_SEC_GSP5_LINE_REFERENCE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL2, DP_SEC_GSP4_SEND, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL2, DP_SEC_GSP4_SEND_PENDING, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL4, DP_SEC_GSP4_LINE_NUM, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL5, DP_SEC_GSP5_LINE_NUM, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL2, DP_SEC_GSP4_SEND_ANY_LINE, mask_sh),\
	SE_SF(DP0_DP_VID_STREAM_CNTL, DP_VID_STREAM_DIS_DEFER, mask_sh),\
	SE_SF(DP0_DP_VID_STREAM_CNTL, DP_VID_STREAM_ENABLE, mask_sh),\
	SE_SF(DP0_DP_VID_STREAM_CNTL, DP_VID_STREAM_STATUS, mask_sh),\
	SE_SF(DP0_DP_STEER_FIFO, DP_STEER_FIFO_RESET, mask_sh),\
	SE_SF(DP0_DP_VID_TIMING, DP_VID_M_N_GEN_EN, mask_sh),\
	SE_SF(DP0_DP_VID_N, DP_VID_N, mask_sh),\
	SE_SF(DP0_DP_VID_M, DP_VID_M, mask_sh),\
	SE_SF(DIG0_HDMI_AUDIO_PACKET_CONTROL, HDMI_AUDIO_DELAY_EN, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_PACKET_CONTROL, HDMI_ACR_AUTO_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_PACKET_CONTROL, HDMI_ACR_SOURCE, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_PACKET_CONTROL, HDMI_ACR_AUDIO_PRIORITY, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_32_0, HDMI_ACR_CTS_32, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_32_1, HDMI_ACR_N_32, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_44_0, HDMI_ACR_CTS_44, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_44_1, HDMI_ACR_N_44, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_48_0, HDMI_ACR_CTS_48, mask_sh),\
	SE_SF(DIG0_HDMI_ACR_48_1, HDMI_ACR_N_48, mask_sh),\
	SE_SF(DP0_DP_SEC_AUD_N, DP_SEC_AUD_N, mask_sh),\
	SE_SF(DP0_DP_SEC_TIMESTAMP, DP_SEC_TIMESTAMP_MODE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_ASP_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_ATP_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_AIP_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_ACM_ENABLE, mask_sh),\
	SE_SF(DIG0_AFMT_CNTL, AFMT_AUDIO_CLOCK_EN, mask_sh),\
	SE_SF(DIG0_HDMI_CONTROL, HDMI_CLOCK_CHANNEL_RATE, mask_sh),\
	SE_SF(DIG0_DIG_FE_CNTL, TMDS_PIXEL_ENCODING, mask_sh),\
	SE_SF(DIG0_DIG_FE_CNTL, TMDS_COLOR_FORMAT, mask_sh),\
	SE_SF(DIG0_DIG_FE_CNTL, DIG_STEREOSYNC_SELECT, mask_sh),\
	SE_SF(DIG0_DIG_FE_CNTL, DIG_STEREOSYNC_GATE_EN, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP4_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP5_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP6_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL, DP_SEC_GSP7_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL2, DP_SEC_GSP7_SEND, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL6, DP_SEC_GSP7_LINE_NUM, mask_sh),\
	SE_SF(DP0_DP_SEC_CNTL2, DP_SEC_GSP11_PPS, mask_sh),\
	SE_SF(DP0_DP_GSP11_CNTL, DP_SEC_GSP11_ENABLE, mask_sh),\
	SE_SF(DP0_DP_GSP11_CNTL, DP_SEC_GSP11_LINE_NUM, mask_sh),\
	SE_SF(DP0_DP_DB_CNTL, DP_DB_DISABLE, mask_sh),\
	SE_SF(DP0_DP_MSA_COLORIMETRY, DP_MSA_MISC0, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM1, DP_MSA_HTOTAL, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM1, DP_MSA_VTOTAL, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM2, DP_MSA_HSTART, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM2, DP_MSA_VSTART, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM3, DP_MSA_HSYNCWIDTH, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM3, DP_MSA_HSYNCPOLARITY, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM3, DP_MSA_VSYNCWIDTH, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM3, DP_MSA_VSYNCPOLARITY, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM4, DP_MSA_HWIDTH, mask_sh),\
	SE_SF(DP0_DP_MSA_TIMING_PARAM4, DP_MSA_VHEIGHT, mask_sh),\
	SE_SF(DIG0_HDMI_DB_CONTROL, HDMI_DB_DISABLE, mask_sh),\
	SE_SF(DP0_DP_VID_TIMING, DP_VID_N_MUL, mask_sh),\
	SE_SF(DIG0_DIG_FE_CNTL, DIG_SOURCE_SELECT, mask_sh), \
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC0_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC0_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC1_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC1_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC2_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC2_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC3_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC3_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC4_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC4_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC5_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC5_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC6_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC6_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC7_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL0, HDMI_GENERIC7_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL6, HDMI_GENERIC8_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL6, HDMI_GENERIC8_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL6, HDMI_GENERIC9_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL6, HDMI_GENERIC9_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL6, HDMI_GENERIC10_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL6, HDMI_GENERIC10_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL6, HDMI_GENERIC11_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL6, HDMI_GENERIC11_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL6, HDMI_GENERIC12_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL6, HDMI_GENERIC12_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL6, HDMI_GENERIC13_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL6, HDMI_GENERIC13_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL6, HDMI_GENERIC14_CONT, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL6, HDMI_GENERIC14_SEND, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL1, HDMI_GENERIC0_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL1, HDMI_GENERIC1_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL2, HDMI_GENERIC2_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL2, HDMI_GENERIC3_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL3, HDMI_GENERIC4_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL3, HDMI_GENERIC5_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL4, HDMI_GENERIC6_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL4, HDMI_GENERIC7_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL7, HDMI_GENERIC8_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL7, HDMI_GENERIC9_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL8, HDMI_GENERIC10_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL8, HDMI_GENERIC11_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL9, HDMI_GENERIC12_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL9, HDMI_GENERIC13_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_GENERIC_PACKET_CONTROL10, HDMI_GENERIC14_LINE, mask_sh),\
	SE_SF(DP0_DP_DSC_CNTL, DP_DSC_MODE, mask_sh),\
	SE_SF(DP0_DP_MSA_VBID_MISC, DP_VBID6_LINE_REFERENCE, mask_sh),\
	SE_SF(DP0_DP_MSA_VBID_MISC, DP_VBID6_LINE_NUM, mask_sh),\
	SE_SF(DME0_DME_CONTROL, METADATA_ENGINE_EN, mask_sh),\
	SE_SF(DME0_DME_CONTROL, METADATA_HUBP_REQUESTOR_ID, mask_sh),\
	SE_SF(DME0_DME_CONTROL, METADATA_STREAM_TYPE, mask_sh),\
	SE_SF(DP0_DP_SEC_METADATA_TRANSMISSION, DP_SEC_METADATA_PACKET_ENABLE, mask_sh),\
	SE_SF(DP0_DP_SEC_METADATA_TRANSMISSION, DP_SEC_METADATA_PACKET_LINE_REFERENCE, mask_sh),\
	SE_SF(DP0_DP_SEC_METADATA_TRANSMISSION, DP_SEC_METADATA_PACKET_LINE, mask_sh),\
	SE_SF(DIG0_HDMI_METADATA_PACKET_CONTROL, HDMI_METADATA_PACKET_ENABLE, mask_sh),\
	SE_SF(DIG0_HDMI_METADATA_PACKET_CONTROL, HDMI_METADATA_PACKET_LINE_REFERENCE, mask_sh),\
	SE_SF(DIG0_HDMI_METADATA_PACKET_CONTROL, HDMI_METADATA_PACKET_LINE, mask_sh),\
	SE_SF(DIG0_DIG_FE_CNTL, DOLBY_VISION_EN, mask_sh),\
	SE_SF(DIG0_DIG_FE_CNTL, DIG_SYMCLK_FE_ON, mask_sh),\
	SE_SF(DP0_DP_SEC_FRAMING4, DP_SST_SDP_SPLITTING, mask_sh),\
	SE_SF(DIG0_DIG_CLOCK_PATTERN, DIG_CLOCK_PATTERN, mask_sh),\
	SE_SF(DIG0_DIG_FIFO_CTRL0, DIG_FIFO_READ_START_LEVEL, mask_sh),\
	SE_SF(DIG0_DIG_FIFO_CTRL0, DIG_FIFO_ENABLE, mask_sh),\
	SE_SF(DIG0_DIG_FIFO_CTRL0, DIG_FIFO_RESET, mask_sh),\
	SE_SF(DIG0_DIG_FIFO_CTRL0, DIG_FIFO_RESET_DONE, mask_sh),\
	SE_SF(DIG0_DIG_FIFO_CTRL0, DIG_FIFO_OUTPUT_PIXEL_MODE, mask_sh)

#if defined(CONFIG_DRM_AMD_DC_HDCP)
#define SE_COMMON_MASK_SH_LIST_DCN32(mask_sh)\
	SE_COMMON_MASK_SH_LIST_DCN32_BASE(mask_sh),\
	SE_SF(DIG0_HDMI_VBI_PACKET_CONTROL, HDMI_ACP_SEND, mask_sh)
#else
#define SE_COMMON_MASK_SH_LIST_DCN32(mask_sh)\
	SE_COMMON_MASK_SH_LIST_DCN32_BASE(mask_sh)
#endif

void dcn32_dio_stream_encoder_construct(
	struct dcn10_stream_encoder *enc1,
	struct dc_context *ctx,
	struct dc_bios *bp,
	enum engine_id eng_id,
	struct vpg *vpg,
	struct afmt *afmt,
	const struct dcn10_stream_enc_registers *regs,
	const struct dcn10_stream_encoder_shift *se_shift,
	const struct dcn10_stream_encoder_mask *se_mask);

#endif /* __DC_DIO_STREAM_ENCODER_DCN32_H__ */
