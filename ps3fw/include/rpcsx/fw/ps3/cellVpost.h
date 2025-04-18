#pragma once

#ifdef _MSC_VER
#pragma warning(push, 0)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wold-style-cast"
#endif
extern "C"
{
#include "libswscale/swscale.h"
}
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif

// Error Codes
enum CellVpostError : u32
{
	CELL_VPOST_ERROR_Q_ARG_CFG_NULL = 0x80610410,
	CELL_VPOST_ERROR_Q_ARG_CFG_INVALID = 0x80610411,
	CELL_VPOST_ERROR_Q_ARG_ATTR_NULL = 0x80610412,
	CELL_VPOST_ERROR_O_ARG_CFG_NULL = 0x80610440,
	CELL_VPOST_ERROR_O_ARG_CFG_INVALID = 0x80610441,
	CELL_VPOST_ERROR_O_ARG_RSRC_NULL = 0x80610442,
	CELL_VPOST_ERROR_O_ARG_RSRC_INVALID = 0x80610443,
	CELL_VPOST_ERROR_O_ARG_HDL_NULL = 0x80610444,
	CELL_VPOST_ERROR_O_FATAL_QUERY_FAIL = 0x80610460,
	CELL_VPOST_ERROR_O_FATAL_CREATEMON_FAIL = 0x80610461,
	CELL_VPOST_ERROR_O_FATAL_INITSPURS_FAIL = 0x80610462,
	CELL_VPOST_ERROR_C_ARG_HDL_NULL = 0x80610470,
	CELL_VPOST_ERROR_C_ARG_HDL_INVALID = 0x80610471,
	CELL_VPOST_ERROR_C_FATAL_LOCKMON_FAIL = 0x80610490,
	CELL_VPOST_ERROR_C_FATAL_UNLOCKMON_FAIL = 0x80610491,
	CELL_VPOST_ERROR_C_FATAL_DESTROYMON_FAIL = 0x80610492,
	CELL_VPOST_ERROR_C_FATAL_FINSPURS_FAIL = 0x80610463,
	CELL_VPOST_ERROR_E_ARG_HDL_NULL = 0x806104a0,
	CELL_VPOST_ERROR_E_ARG_HDL_INVALID = 0x806104a1,
	CELL_VPOST_ERROR_E_ARG_INPICBUF_NULL = 0x806104a2,
	CELL_VPOST_ERROR_E_ARG_INPICBUF_INVALID = 0x806104a3,
	CELL_VPOST_ERROR_E_ARG_CTRL_NULL = 0x806104a4,
	CELL_VPOST_ERROR_E_ARG_CTRL_INVALID = 0x806104a5,
	CELL_VPOST_ERROR_E_ARG_OUTPICBUF_NULL = 0x806104a6,
	CELL_VPOST_ERROR_E_ARG_OUTPICBUF_INVALID = 0x806104a7,
	CELL_VPOST_ERROR_E_ARG_PICINFO_NULL = 0x806104a8,
	CELL_VPOST_ERROR_E_FATAL_LOCKMON_FAIL = 0x806104c0,
	CELL_VPOST_ERROR_E_FATAL_UNLOCKMON_FAIL = 0x806104c1,
	CELL_VPOST_ENT_ERROR_Q_ARG_ATTR_NULL = 0x80618110,
	CELL_VPOST_ENT_ERROR_O_ARG_RSRC_NULL = 0x80618140,
	CELL_VPOST_ENT_ERROR_O_ARG_RSRC_INVALID = 0x80618141,
	CELL_VPOST_ENT_ERROR_O_ARG_HDL_NULL = 0x80618142,
	CELL_VPOST_ENT_ERROR_O_FATAL_QUERY_FAIL = 0x80618160,
	CELL_VPOST_ENT_ERROR_O_FATAL_CSPUCORE_FAIL = 0x80618161,
	CELL_VPOST_ENT_ERROR_C_ARG_HDL_NULL = 0x80618170,
	CELL_VPOST_ENT_ERROR_C_ARG_HDL_INVALID = 0x80618171,
	CELL_VPOST_ENT_ERROR_C_FATAL_SNDCMD_FAIL = 0x80618190,
	CELL_VPOST_ENT_ERROR_C_FATAL_RCVRES_FAIL = 0x80618191,
	CELL_VPOST_ENT_ERROR_C_FATAL_DSPUCORE_FAIL = 0x80618192,
	CELL_VPOST_ENT_ERROR_E_ARG_HDL_NULL = 0x806181a0,
	CELL_VPOST_ENT_ERROR_E_ARG_HDL_INVALID = 0x806181a1,
	CELL_VPOST_ENT_ERROR_E_ARG_INPICBUF_NULL = 0x806181a2,
	CELL_VPOST_ENT_ERROR_E_ARG_INPICBUF_INVALID = 0x806181a3,
	CELL_VPOST_ENT_ERROR_E_ARG_INPICINFO_NULL = 0x806181a4,
	CELL_VPOST_ENT_ERROR_E_ARG_INPICINFO_INVALID = 0x806181a5,
	CELL_VPOST_ENT_ERROR_E_ARG_CTRL_NULL = 0x806181a6,
	CELL_VPOST_ENT_ERROR_E_ARG_CTRL_INVALID = 0x806181a7,
	CELL_VPOST_ENT_ERROR_E_ARG_COMB_INVALID = 0x806181a8,
	CELL_VPOST_ENT_ERROR_E_ARG_OUTPICBUF_NULL = 0x806181a9,
	CELL_VPOST_ENT_ERROR_E_ARG_OUTPICBUF_INVALID = 0x806181aa,
	CELL_VPOST_ENT_ERROR_E_ARG_OUTPICINFO_NULL = 0x806181ab,
	CELL_VPOST_ENT_ERROR_E_FATAL_SNDCMD_FAIL = 0x806181c0,
	CELL_VPOST_ENT_ERROR_E_FATAL_RCVRES_FAIL = 0x806181c1,
	CELL_VPOST_ENT_ERROR_E_FATAL_SPUCORE_FAIL = 0x806181c2,
	CELL_VPOST_IPC_ERROR_Q_ARG_ATTR_NULL = 0x80618210,
	CELL_VPOST_IPC_ERROR_O_ARG_RSRC_NULL = 0x80618240,
	CELL_VPOST_IPC_ERROR_O_ARG_RSRC_INVALID = 0x80618241,
	CELL_VPOST_IPC_ERROR_O_ARG_HDL_NULL = 0x80618242,
	CELL_VPOST_IPC_ERROR_O_FATAL_QUERY_FAIL = 0x80618260,
	CELL_VPOST_IPC_ERROR_O_FATAL_CSPUCORE_FAIL = 0x80618261,
	CELL_VPOST_IPC_ERROR_C_ARG_HDL_NULL = 0x80618270,
	CELL_VPOST_IPC_ERROR_C_ARG_HDL_INVALID = 0x80618271,
	CELL_VPOST_IPC_ERROR_C_FATAL_SNDCMD_FAIL = 0x80618290,
	CELL_VPOST_IPC_ERROR_C_FATAL_RCVRES_FAIL = 0x80618291,
	CELL_VPOST_IPC_ERROR_C_FATAL_DSPUCORE_FAIL = 0x80618292,
	CELL_VPOST_IPC_ERROR_E_ARG_HDL_NULL = 0x806182a0,
	CELL_VPOST_IPC_ERROR_E_ARG_HDL_INVALID = 0x806182a1,
	CELL_VPOST_IPC_ERROR_E_ARG_INPICBUF_NULL = 0x806182a2,
	CELL_VPOST_IPC_ERROR_E_ARG_INPICBUF_INVALID = 0x806182a3,
	CELL_VPOST_IPC_ERROR_E_ARG_INPICINFO_NULL = 0x806182a4,
	CELL_VPOST_IPC_ERROR_E_ARG_INPICINFO_INVALID = 0x806182a5,
	CELL_VPOST_IPC_ERROR_E_ARG_CTRL_NULL = 0x806182a6,
	CELL_VPOST_IPC_ERROR_E_ARG_CTRL_INVALID = 0x806182a7,
	CELL_VPOST_IPC_ERROR_E_ARG_COMB_INVALID = 0x806182a8,
	CELL_VPOST_IPC_ERROR_E_ARG_OUTPICBUF_NULL = 0x806182a9,
	CELL_VPOST_IPC_ERROR_E_ARG_OUTPICBUF_INVALID = 0x806182aa,
	CELL_VPOST_IPC_ERROR_E_ARG_OUTPICINFO_NULL = 0x806182ab,
	CELL_VPOST_IPC_ERROR_E_FATAL_SNDCMD_FAIL = 0x806182c0,
	CELL_VPOST_IPC_ERROR_E_FATAL_RCVRES_FAIL = 0x806182c1,
	CELL_VPOST_IPC_ERROR_E_FATAL_SPUCORE_FAIL = 0x806182c2,
	CELL_VPOST_VSC_ERROR_Q_ARG_ATTR_NULL = 0x80618310,
	CELL_VPOST_VSC_ERROR_O_ARG_RSRC_NULL = 0x80618340,
	CELL_VPOST_VSC_ERROR_O_ARG_RSRC_INVALID = 0x80618341,
	CELL_VPOST_VSC_ERROR_O_ARG_HDL_NULL = 0x80618342,
	CELL_VPOST_VSC_ERROR_O_FATAL_QUERY_FAIL = 0x80618360,
	CELL_VPOST_VSC_ERROR_O_FATAL_CSPUCORE_FAIL = 0x80618361,
	CELL_VPOST_VSC_ERROR_C_ARG_HDL_NULL = 0x80618370,
	CELL_VPOST_VSC_ERROR_C_ARG_HDL_INVALID = 0x80618371,
	CELL_VPOST_VSC_ERROR_C_FATAL_SNDCMD_FAIL = 0x80618390,
	CELL_VPOST_VSC_ERROR_C_FATAL_RCVRES_FAIL = 0x80618391,
	CELL_VPOST_VSC_ERROR_C_FATAL_DSPUCORE_FAIL = 0x80618392,
	CELL_VPOST_VSC_ERROR_E_ARG_HDL_NULL = 0x806183a0,
	CELL_VPOST_VSC_ERROR_E_ARG_HDL_INVALID = 0x806183a1,
	CELL_VPOST_VSC_ERROR_E_ARG_INPICBUF_NULL = 0x806183a2,
	CELL_VPOST_VSC_ERROR_E_ARG_INPICBUF_INVALID = 0x806183a3,
	CELL_VPOST_VSC_ERROR_E_ARG_INPICINFO_NULL = 0x806183a4,
	CELL_VPOST_VSC_ERROR_E_ARG_INPICINFO_INVALID = 0x806183a5,
	CELL_VPOST_VSC_ERROR_E_ARG_CTRL_NULL = 0x806183a6,
	CELL_VPOST_VSC_ERROR_E_ARG_CTRL_INVALID = 0x806183a7,
	CELL_VPOST_VSC_ERROR_E_ARG_COMB_INVALID = 0x806183a8,
	CELL_VPOST_VSC_ERROR_E_ARG_OUTPICBUF_NULL = 0x806183a9,
	CELL_VPOST_VSC_ERROR_E_ARG_OUTPICBUF_INVALID = 0x806183aa,
	CELL_VPOST_VSC_ERROR_E_ARG_OUTPICINFO_NULL = 0x806183ab,
	CELL_VPOST_VSC_ERROR_E_FATAL_SNDCMD_FAIL = 0x806183c0,
	CELL_VPOST_VSC_ERROR_E_FATAL_RCVRES_FAIL = 0x806183c1,
	CELL_VPOST_VSC_ERROR_E_FATAL_SPUCORE_FAIL = 0x806183c2,
	CELL_VPOST_CSC_ERROR_Q_ARG_ATTR_NULL = 0x80618410,
	CELL_VPOST_CSC_ERROR_O_ARG_RSRC_NULL = 0x80618440,
	CELL_VPOST_CSC_ERROR_O_ARG_RSRC_INVALID = 0x80618441,
	CELL_VPOST_CSC_ERROR_O_ARG_HDL_NULL = 0x80618442,
	CELL_VPOST_CSC_ERROR_O_FATAL_QUERY_FAIL = 0x80618460,
	CELL_VPOST_CSC_ERROR_O_FATAL_CSPUCORE_FAIL = 0x80618461,
	CELL_VPOST_CSC_ERROR_C_ARG_HDL_NULL = 0x80618470,
	CELL_VPOST_CSC_ERROR_C_ARG_HDL_INVALID = 0x80618471,
	CELL_VPOST_CSC_ERROR_C_FATAL_SNDCMD_FAIL = 0x80618490,
	CELL_VPOST_CSC_ERROR_C_FATAL_RCVRES_FAIL = 0x80618491,
	CELL_VPOST_CSC_ERROR_C_FATAL_DSPUCORE_FAIL = 0x80618492,
	CELL_VPOST_CSC_ERROR_E_ARG_HDL_NULL = 0x806184a0,
	CELL_VPOST_CSC_ERROR_E_ARG_HDL_INVALID = 0x806184a1,
	CELL_VPOST_CSC_ERROR_E_ARG_INPICBUF_NULL = 0x806184a2,
	CELL_VPOST_CSC_ERROR_E_ARG_INPICBUF_INVALID = 0x806184a3,
	CELL_VPOST_CSC_ERROR_E_ARG_INPICINFO_NULL = 0x806184a4,
	CELL_VPOST_CSC_ERROR_E_ARG_INPICINFO_INVALID = 0x806184a5,
	CELL_VPOST_CSC_ERROR_E_ARG_CTRL_NULL = 0x806184a6,
	CELL_VPOST_CSC_ERROR_E_ARG_CTRL_INVALID = 0x806184a7,
	CELL_VPOST_CSC_ERROR_E_ARG_COMB_INVALID = 0x806184a8,
	CELL_VPOST_CSC_ERROR_E_ARG_OUTPICBUF_NULL = 0x806184a9,
	CELL_VPOST_CSC_ERROR_E_ARG_OUTPICBUF_INVALID = 0x806184aa,
	CELL_VPOST_CSC_ERROR_E_ARG_OUTPICINFO_NULL = 0x806184ab,
	CELL_VPOST_CSC_ERROR_E_FATAL_SNDCMD_FAIL = 0x806184c0,
	CELL_VPOST_CSC_ERROR_E_FATAL_RCVRES_FAIL = 0x806184c1,
	CELL_VPOST_CSC_ERROR_E_FATAL_SPUCORE_FAIL = 0x806184c2,
};

enum CellVpostPictureDepth : s32
{
	CELL_VPOST_PIC_DEPTH_8,
};

enum CellVpostPictureFormatIn : s32
{
	CELL_VPOST_PIC_FMT_IN_YUV420_PLANAR,
};

enum CellVpostPictureFormatOut : s32
{
	CELL_VPOST_PIC_FMT_OUT_RGBA_ILV,
	CELL_VPOST_PIC_FMT_OUT_YUV420_PLANAR,
};

enum CellVpostPictureStructure : s32
{
	CELL_VPOST_PIC_STRUCT_PFRM,
	CELL_VPOST_PIC_STRUCT_IFRM,
	CELL_VPOST_PIC_STRUCT_ITOP,
	CELL_VPOST_PIC_STRUCT_IBTM,
};

enum CellVpostExecType : s32
{
	CELL_VPOST_EXEC_TYPE_PFRM_PFRM,
	CELL_VPOST_EXEC_TYPE_PTOP_ITOP,
	CELL_VPOST_EXEC_TYPE_PBTM_IBTM,
	CELL_VPOST_EXEC_TYPE_ITOP_PFRM,
	CELL_VPOST_EXEC_TYPE_IBTM_PFRM,
	CELL_VPOST_EXEC_TYPE_IFRM_IFRM,
	CELL_VPOST_EXEC_TYPE_ITOP_ITOP,
	CELL_VPOST_EXEC_TYPE_IBTM_IBTM,
};

enum CellVpostChromaPositionType : s32
{
	CELL_VPOST_CHROMA_POS_TYPE_A,
	CELL_VPOST_CHROMA_POS_TYPE_B,
};

enum CellVpostScanType : s32
{
	CELL_VPOST_SCAN_TYPE_P,
	CELL_VPOST_SCAN_TYPE_I,
};

enum CellVpostQuantRange : s32
{
	CELL_VPOST_QUANT_RANGE_FULL,
	CELL_VPOST_QUANT_RANGE_BROADCAST,
};

enum CellVpostColorMatrix : s32
{
	CELL_VPOST_COLOR_MATRIX_BT601,
	CELL_VPOST_COLOR_MATRIX_BT709,
};

enum CellVpostScalerType : s32
{
	CELL_VPOST_SCALER_TYPE_BILINEAR,
	CELL_VPOST_SCALER_TYPE_LINEAR_SHARP,
	CELL_VPOST_SCALER_TYPE_2X4TAP,
	CELL_VPOST_SCALER_TYPE_8X4TAP,
};

enum CellVpostIpcType : s32
{
	CELL_VPOST_IPC_TYPE_DOUBLING,
	CELL_VPOST_IPC_TYPE_LINEAR,
	CELL_VPOST_IPC_TYPE_MAVG,
};

struct CellVpostCfgParam
{
	be_t<u32> inMaxWidth;
	be_t<u32> inMaxHeight;
	be_t<s32> inDepth;  // CellVpostPictureDepth
	be_t<s32> inPicFmt; // CellVpostPictureFormatIn

	be_t<u32> outMaxWidth;
	be_t<u32> outMaxHeight;
	be_t<s32> outDepth;  // CellVpostPictureDepth
	be_t<s32> outPicFmt; // CellVpostPictureFormatOut

	be_t<u32> reserved1;
	be_t<u32> reserved2;
};

struct CellVpostAttr
{
	be_t<u32> memSize;
	u8 delay;
	be_t<u32> vpostVerUpper;
	be_t<u32> vpostVerLower;
};

struct CellVpostResource
{
	be_t<u32> memAddr;
	be_t<u32> memSize;
	be_t<s32> ppuThreadPriority;
	be_t<u32> ppuThreadStackSize;
	be_t<s32> spuThreadPriority;
	be_t<u32> numOfSpus;
};

struct CellVpostResourceEx
{
	be_t<u32> memAddr;
	be_t<u32> memSize;
	be_t<u32> spurs_addr;
	u8 priority[8];
	be_t<u32> maxContention;
};

struct CellVpostWindow
{
	be_t<u32> x;
	be_t<u32> y;
	be_t<u32> width;
	be_t<u32> height;
};

struct CellVpostCtrlParam
{
	be_t<s32> execType; // CellVpostExecType

	be_t<s32> scalerType; // CellVpostScalerType
	be_t<s32> ipcType;    // CellVpostIpcType

	be_t<u32> inWidth;
	be_t<u32> inHeight;
	be_t<s32> inChromaPosType; // CellVpostChromaPositionType
	be_t<s32> inQuantRange;    // CellVpostQuantRange
	be_t<s32> inColorMatrix;   // CellVpostColorMatrix
	CellVpostWindow inWindow;

	be_t<u32> outWidth;
	be_t<u32> outHeight;
	CellVpostWindow outWindow;
	u8 outAlpha;

	be_t<u64> userData;

	be_t<u32> reserved1;
	be_t<u32> reserved2;
};

struct CellVpostPictureInfo
{
	be_t<u32> inWidth;
	be_t<u32> inHeight;
	be_t<s32> inDepth;         // CellVpostPictureDepth
	be_t<s32> inScanType;      // CellVpostScanType
	be_t<s32> inPicFmt;        // CellVpostPictureFormatIn
	be_t<s32> inChromaPosType; // CellVpostChromaPositionType
	be_t<s32> inPicStruct;     // CellVpostPictureStructure
	be_t<s32> inQuantRange;    // CellVpostQuantRange
	be_t<s32> inColorMatrix;   // CellVpostColorMatrix

	be_t<u32> outWidth;
	be_t<u32> outHeight;
	be_t<s32> outDepth;         // CellVpostPictureDepth
	be_t<s32> outScanType;      // CellVpostScanType
	be_t<s32> outPicFmt;        // CellVpostPictureFormatOut
	be_t<s32> outChromaPosType; // CellVpostChromaPositionType
	be_t<s32> outPicStruct;     // CellVpostPictureStructure
	be_t<s32> outQuantRange;    // CellVpostQuantRange
	be_t<s32> outColorMatrix;   // CellVpostColorMatrix

	be_t<u64> userData;

	be_t<u32> reserved1;
	be_t<u32> reserved2;
};

class VpostInstance
{
public:
	static const u32 id_base = 1;
	static const u32 id_step = 1;
	static const u32 id_count = 1023;
	SAVESTATE_INIT_POS(23);

	const bool to_rgba;

	SwsContext* sws{};

	VpostInstance(bool rgba)
		: to_rgba(rgba)
	{
	}

	~VpostInstance()
	{
		sws_freeContext(sws);
	}
};
