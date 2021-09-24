#pragma once
#include "LT.h"
#include "IT.h"

	#define STANDART_BEGIN    ".586							; ������� ������ (��������� Pentium)\n"						\
					   << ".model flat, stdcall			; ������ ������, ���������� � �������\n"					\
					   << "includelib kernel32.lib			; ������������: ����������� � kernel32\n"				\
					   << "includelib libucrt.lib			; ��� UCRT - universal C Run-Time library\n\n"			\
					   << "ExitProcess PROTO: DWORD		; �������� ������� ��� ���������� �������� Windows\n\n"		\

#define STANDART_LIB	  ";-----------Standart functions-----------\n"					\
					   << "includelib D:\\����\\��\\KP\\StandartLibrary\\Debug\\StandartLibrary.lib\n"	\
					   << "concat1 PROTO : DWORD, : DWORD\n"							\
					   << "concat2 PROTO : DWORD, : DWORD, : DWORD\n"					\
					   << "print PROTO : DWORD\n"										\
					   << "printint PROTO : DWORD\n"									\
					   << "isvisokosni PROTO : DWORD\n"								\
					   << "printcurrentdate PROTO\n"									\
					   << ";----------------------------------------\n\n";	

#define STACK(value) ".stack " << value << "\n\n";

#define LITERALS_BEGIN ";---------------Literals---------------\n"\
								<< ".const\n\n";

#define LITERALS_END	 ";--------------------------------------------\n";

#define VARIABLES_BEGIN "\n\n;----------------Variables-------------------\n.data\n\n";

#define VARIABLES_END	 ";--------------------------------------------\n";

#define FUNCTIONS_BEGIN "\n;----------------Functions-------------------\n\n"\
						<< ".code\n\n";

#define FUNCTIONS_END	"\n;----------------------------------------------\n";




	void generation(LT::LexTable& LexTable, IT::IdTable& IdTable);

