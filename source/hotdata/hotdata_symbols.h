#ifndef _H_HOTDATA_SYMBOLS
#define _H_HOTDATA_SYMBOLS

#include "syntactic_node.h"

typedef enum _HOTDATA_SYMBOLS_TYPE
{
	EN_HST_VALUE = 0,
	EN_HST_TYPE = 1,
	EN_HST_PARAMETER = 2,
}HOTDATA_SYMBOLS_TYPE;

typedef union _HOTDATA_SYMBOLS_BODY
{
	ST_VALUE val;
	ST_TYPE type;
	ST_Parameter para;
}HOTDATA_SYMBOLS_BODY;

typedef struct _HOTDATA_SYMBOLS
{
	HOTDATA_SYMBOLS_TYPE type;
	HOTDATA_SYMBOLS_BODY body;
}HOTDATA_SYMBOLS;

#endif //_H_HOTDATA_SYMBOLS