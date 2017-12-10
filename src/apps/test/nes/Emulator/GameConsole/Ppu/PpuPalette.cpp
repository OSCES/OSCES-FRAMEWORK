/*
    NES Emulator Project
    Created by Igor Belorus
    06/11/2012
*/

#include "PpuPalette.h"


static const RgbPixel_t PpuPalette[] =
{
/*0x00*/ { 124, 124, 124},
/*0x01*/ {   0,   0, 252},
/*0x02*/ {   0,   0, 188},
/*0x03*/ {  68,  40, 188},
/*0x04*/ { 148,   0, 132},
/*0x05*/ { 168,   0,  32},
/*0x06*/ { 168,  16,   0},
/*0x07*/ { 136,  20,   0},
/*0x08*/ {  80,  48,   0},
/*0x09*/ {   0, 120,   0},
/*0x0A*/ {   0, 104,   0},
/*0x0B*/ {   0,  88,   0},
/*0x0C*/ {   0,  64,  88},
/*0x0D*/ {   0,   0,   0},
/*0x0E*/ {   0,   0,   0},
/*0x0F*/ {   0,   0,   0},
/*0x10*/ { 188, 188, 188},
/*0x11*/ {   0, 120, 248},
/*0x12*/ {   0,  88, 248},
/*0x13*/ { 104,  68, 252},
/*0x14*/ { 216,   0, 204},
/*0x15*/ { 228,   0,  88},
/*0x00*/ { 248,  56,   0},
/*0x00*/ { 228,  92,  16},
/*0x00*/ { 172, 124,   0},
/*0x00*/ {   0, 184,   0},
/*0x00*/ {   0, 168,   0},
/*0x00*/ {   0, 168,  68},
/*0x00*/ {   0, 136, 136},
/*0x00*/ {   0,   0,   0},
/*0x00*/ {   0,   0,   0},
/*0x00*/ {   0,   0,   0},
/*0x00*/ { 248, 248, 248},
/*0x00*/ {  60, 188, 252},
/*0x00*/ { 104, 136, 252},
/*0x00*/ { 152, 120, 248},
/*0x00*/ { 248, 120, 248},
/*0x00*/ { 248,  88, 152},
/*0x00*/ { 248, 120,  88},
/*0x00*/ { 252, 160,  68},
/*0x00*/ { 248, 184,   0},
/*0x00*/ { 184, 248,  24},
/*0x00*/ {  88, 216,  84},
/*0x00*/ {  88, 248, 152},
/*0x00*/ {   0, 232, 216},
/*0x00*/ { 120, 120, 120},
/*0x00*/ {   0,   0,   0},
/*0x00*/ {   0,   0,   0},
/*0x00*/ { 252, 252, 252},
/*0x00*/ { 164, 228, 252},
/*0x00*/ { 184, 184, 248},
/*0x00*/ { 216, 184, 248},
/*0x00*/ { 248, 184, 248},
/*0x00*/ { 248, 164, 192},
/*0x00*/ { 240, 208, 176},
/*0x00*/ { 252, 224, 168},
/*0x00*/ { 248, 216, 120},
/*0x00*/ { 216, 248, 120},
/*0x00*/ { 184, 248, 184},
/*0x00*/ { 184, 248, 216},
/*0x00*/ {   0, 252, 252},
/*0x00*/ { 248, 216, 248},
/*0x00*/ {   0,   0,   0},
/*0x00*/ {   0,   0,   0},
};

static const uint32_t PpuPaletteRGBA[] =
{
2088532992,
64512,
48128,
1143520256,
2483061760,
2818580480,
2819620864,
2283012096,
1345323008,
7864320,
6815744,
5767168,
4216832,
0,
0,
0,
3166485504,
7927808,
5830656,
1749351424,
3623930880,
3825227776,
4164419584,
3831238656,
2893807616,
12058624,
11010048,
11027456,
8947712,
0,
0,
0,
4177065984,
1019018240,
1753807872,
2558064640,
4168677376,
4166555648,
4168636416,
4238361600,
4172808192,
3103266816,
1490572288,
1492686848,
15259648,
2021160960,
0,
0,
4244438016,
2766470144,
3099129856,
3636000768,
4172871680,
4171546624,
4040208384,
4242581504,
4174936064,
3640162304,
3103307776,
3103315968,
16579584,
4174968832,
0,
0
};



static const uint8_t PpuPalette322[] = 
{
91,
192,
128,
138,
132,
5,
5,
4,
10,
24,
24,
16,
80,
0,
0,
0,
173,
216,
208,
211,
198,
71,
15,
23,
29,
40,
40,
104,
160,
0,
0,
0,
255,
233,
227,
220,
223,
151,
95,
111,
47,
61,
114,
186,
248,
91,
0,
0,
255,
253,
237,
238,
239,
239,
183,
191,
119,
126,
189,
253,
248,
247,
0,
0
};

RgbPixel_t* GetPalettePixel( uint8_t color )
{
    return const_cast< RgbPixel_t* >( &PpuPalette[ color ] );
}

uint8_t GetPalettePixel332( uint8_t color )
{
	return PpuPalette322[ color ];
}

uint32_t GetPalettePixel8888( uint8_t color )
{
	uint32_t pixel = *( uint32_t* )&PpuPalette[ color ];
	return pixel;
}

uint32_t* GetPalettePixel8888()
{
	return ( uint32_t* )PpuPalette;
}

uint8_t* GetPalettePixel332()
{
    return ( uint8_t* )PpuPalette322;
}

uint32_t* GetPalettePixelRGBA()
{
	return ( uint32_t* )PpuPaletteRGBA;
}