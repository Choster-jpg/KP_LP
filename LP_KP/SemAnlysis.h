#pragma once
#include "Parm.h"
#include "Log.h"
#include "In.h"
#include "FST.h"
#include "LT.h"
#include "IT.h"
#include "MFST.h"
#include "GBR.h"
#include "Analysis.h"
#include "PolishNotation.h"
#include "GenerateToAssembler.h"
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <cwchar>

void SemAnalysis(LT::LexTable& lextable, IT::IdTable& idtable);