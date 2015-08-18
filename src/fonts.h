#ifndef FONTS_H
#define FONTS_H

#include "SystemFont5x7.h"
#include "Font3x5.h"
#include "Arial14.h"
#include "Arial_bold_14.h"
#include "Corsiva_12.h"
#include "Verdana_digits_24.h"
#include "fixednums7x15.h"
#include "fixednums8x16.h"

// Font Indices
#define FONT_LENGTH             0
#define FONT_FIXED_WIDTH        2
#define FONT_HEIGHT             3
#define FONT_FIRST_CHAR         4
#define FONT_CHAR_COUNT         5
#define FONT_WIDTH_TABLE        6

typedef struct {
	unsigned char *name;
	unsigned char *data;
} font_info;

static font_info fonts_table[] = {
	{"System5x7", System5x7},
	{"Fixed3x5", Font3x5},
	{"FixedDigits7x15", fixednums7x15},
	{"FixedDigits8x16", fixednums8x16},
	{"Arial14", Arial_14},
	{"ArialBold14", Arial_bold_14},
	{"Corsiva12", Corsiva_12},
	{"VerdanaDigits24", Verdana_digits_24},
	{NULL, NULL}
};

#endif // FONTS_H
