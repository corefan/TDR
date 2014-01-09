#ifndef _H_GENERATOR
#define _H_GENERATOR

#include <stdio.h>

#include "platform/tlibc_platform.h"
#include "error/error_code_types.h"

#include "definition.h"
typedef struct _GENERATOR GENERATOR;
struct _GENERATOR
{
	FILE* fout;
	char document_name[TLIBC_MAX_FILE_PATH_LENGTH];

	TD_ERROR_CODE (*on_document_begin)(GENERATOR *self, const char *file_name);
	TD_ERROR_CODE (*on_document_end)(GENERATOR *self, const char *file_name);
	TD_ERROR_CODE (*on_definition)(GENERATOR *self, const ST_DEFINITION *definition);
};

void generator_init(GENERATOR *self);

TD_ERROR_CODE generator_open(GENERATOR *self, const char *primary_file, const char *suffix);

TD_ERROR_CODE generator_print(GENERATOR *self, const char* fmt, ...);

TD_ERROR_CODE generator_close(GENERATOR *self);

TD_ERROR_CODE generator_print_value(GENERATOR *self, const ST_VALUE *val);

TD_ERROR_CODE generator_print_type(GENERATOR *self, const ST_TYPE *type);

TD_ERROR_CODE generator_replace_extension(char *filename, tuint32 filename_length, const char *suffix);

//virtual functions
TD_ERROR_CODE generator_on_definition(GENERATOR *self, const ST_DEFINITION *definition);

TD_ERROR_CODE generator_on_document_begin(GENERATOR *self, const char *file_name);

TD_ERROR_CODE generator_on_document_end(GENERATOR *self, const char *file_name);

#endif
