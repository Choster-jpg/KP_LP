#pragma once
#include <fstream>

#define IN_MAX_LEN_TEXT 1024*1024
#define IN_CODE_ENDL '\n'
#define IN_SEPARATOR '|'

// i(b)+((c+o+n)b+)*b*r;

#define IN_CODE_TABLE {\
	IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::T,    IN::T, IN::T,    IN::A, IN::F,    IN::F, IN::F,    IN::F, IN::F, \
	IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::T, IN::T, \
\
	IN::A, IN::T,    IN::F, IN::F,    IN::A, IN::A,    IN::T, IN::A,    IN::A, IN::A,    IN::A, IN::A,    IN::A, IN::A,    IN::A, IN::A, \
	IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::A,    IN::A, IN::A,    IN::A, IN::F, \
\
	IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T, \
	IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::F, IN::A,    IN::A, IN::A,    IN::F, IN::F, \
\
	IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T, \
	IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::T,    IN::T, IN::A,    IN::A, IN::A,    IN::F, IN::F, \
\
\
	IN::T, IN::T,    IN::T, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F, \
	IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::T,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F, \
\
	IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F, \
	IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F, \
\
	IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::T,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F, \
	IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::T, \
\
	IN::F, IN::T,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::T, IN::F,    IN::F, IN::F,    IN::T, IN::F,    IN::F, IN::F, \
	IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::T,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F,    IN::F, IN::F  \
					}

namespace In
{
	struct IN
	{
		enum { T = 1024, F = 2048, I = 4096, A = 8192 };
		int size;
		int file_size;
		int lines;
		int ignor;
		unsigned char* text;
		int code[256];
	};

	IN getIn(wchar_t infile[], wchar_t outfile[]);
}

