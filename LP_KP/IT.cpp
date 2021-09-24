#include "IT.h"
#include "Error.h"
#include <string.h>
#include <fstream>
#include <iomanip>

using namespace std;

namespace IT
{
	IdTable Create(int size)
	{
		IdTable idtable;
		idtable.maxsize = size;
		idtable.current_size = 0;
		idtable.table = new Entry[TI_MAXSIZE];
		return idtable;
	}

	Entry GetEntry(IdTable& idtable, int n)
	{
		if (n < idtable.maxsize && n >= 0)
			return idtable.table[n];
		else
			throw ERROR_THROW(123)
	}

	void Delete(IdTable& idtable)
	{
		delete idtable.table;
		idtable.table = nullptr;
	}

	void Add(IdTable& idtable, Entry entry)
	{
		if (strlen(entry.id) > ID_MAXSIZE)
			throw ERROR_THROW(136);

		if (idtable.current_size < idtable.maxsize)
		{
			idtable.table[idtable.current_size] = entry;

			if (entry.iddatatype == IT::IDDATATYPE::INT)
				idtable.table[idtable.current_size].value.vint.value = TI_INT_DEFAULT;

			if (entry.iddatatype == IT::IDDATATYPE::STR)
			{
				idtable.table[idtable.current_size].value.vstr->str[0] = TI_STR_DEFAULT;
				idtable.table[idtable.current_size].value.vstr->len = 0;
			}

			if (entry.iddatatype == IT::IDDATATYPE::LOG)
				idtable.table[idtable.current_size].value.vlogic = TI_LOG_DEFAULT;

			idtable.current_size++;
		}
		else
			throw ERROR_THROW(125);
	}

	int IsId(IdTable& idtable, char id[ID_MAXSIZE])
	{
		for (int i = 0; i < idtable.current_size; i++)
		{
			if (strcmp(idtable.table[i].id, id) == 0)
				return i;
		}
		return TI_NULLIDX;
	}

	void PrintIdTable(IdTable& idtable)
	{
		ofstream fout("idTable.txt");

		if (fout.is_open())
		{
			fout << "Литералы: \n\n";

			for (int i = 0; i < idtable.current_size; i++)
			{
				if (idtable.table[i].idtype == IT::IDTYPE::L)
				{
					if (idtable.table[i].iddatatype == INT)
					{
						fout << "integer" << setw(40 - 7) << idtable.table[i].value.vint.value << endl;
					}
					else if(idtable.table[i].iddatatype == IDDATATYPE::STR)
					{
						fout << "string" << setw(40 - 6) << idtable.table[i].value.vstr->str << "\t\t" << (int)idtable.table[i].value.vstr->len << std::endl;
					}
					else
					{
						fout << "logic" << setw(40 - 5) << idtable.table[i].value.vlogic << std::endl;
					}
				}
			}
			fout << "\n\n\n";

			fout << "Функции: \n\n";

			for (int i = 0; i < idtable.current_size; i++)
			{
				if (idtable.table[i].idtype == IT::IDTYPE::F)
				{
					if (idtable.table[i].iddatatype == IDDATATYPE::INT)
					{
						fout << idtable.table[i].id << setw(40 - strlen(idtable.table[i].id)) << "integer" << endl;
					}
					else if (idtable.table[i].iddatatype == IDDATATYPE::STR)
					{
						fout << idtable.table[i].id << setw(40 - strlen(idtable.table[i].id)) << "string" << std::endl;
					}
					else
					{
						fout << idtable.table[i].id << setw(40 - strlen(idtable.table[i].id)) << "logic" << std::endl;
					}
				}


			}
			fout << "\n\n\n";

			fout << "Переменные: \n\n";

			for (int i = 0; i < idtable.current_size; i++)
			{
				if (idtable.table[i].idtype == IT::IDTYPE::V)
				{
					if (idtable.table[i].iddatatype == IDDATATYPE::INT)
					{
						fout << idtable.table[i].parrent_block_name << setw(40 - strlen(idtable.table[i].parrent_block_name)) << idtable.table[i].id << setw(40 - strlen(idtable.table[i].id)) << "integer\tV" << setw(10) << idtable.table[i].value.vint. value << endl;
					}
					else if(idtable.table[i].iddatatype == IDDATATYPE::STR)
					{
						fout << idtable.table[i].parrent_block_name << setw(40 - strlen(idtable.table[i].parrent_block_name)) << idtable.table[i].id << setw(40 - strlen(idtable.table[i].id))  << "string\tV" << setw(10) << idtable.table[i].value.vstr->str << setw(10) << idtable.table[i].value.vstr->len <<  endl;
					}
					else
					{
						fout << idtable.table[i].parrent_block_name << setw(40 - strlen(idtable.table[i].parrent_block_name)) << idtable.table[i].id << setw(40 - strlen(idtable.table[i].id))  << "logic\tV" << setw(10) << idtable.table[i].value.vlogic << endl;
					}
				}

				if (idtable.table[i].idtype == IT::IDTYPE::P)
				{
					if (idtable.table[i].iddatatype == IDDATATYPE::INT)
					{
						fout << idtable.table[i].parrent_block_name << setw(40  - strlen(idtable.table[i].parrent_block_name)) << idtable.table[i].id << setw(40 - strlen(idtable.table[i].id))  << "integer\tP" << setw(10) << idtable.table[i].value.vint.value << endl;
					}
					else if (idtable.table[i].iddatatype == IDDATATYPE::STR)
					{
						fout << idtable.table[i].parrent_block_name << setw(40  - strlen(idtable.table[i].parrent_block_name)) << idtable.table[i].id << setw(40 - strlen(idtable.table[i].id))  << "string\tP" << setw(10) << idtable.table[i].value.vstr->str << setw(10) << idtable.table[i].value.vstr->len << endl;
					}
					else
					{
						fout << idtable.table[i].parrent_block_name << setw(40  - strlen(idtable.table[i].parrent_block_name)) << idtable.table[i].id << setw(40 - strlen(idtable.table[i].id))  << "logic\tP" << setw(10) << idtable.table[i].value.vlogic << endl;
					}
				}

				if (idtable.table[i].idtype == IT::IDTYPE::A)
				{
					if (idtable.table[i].iddatatype == IDDATATYPE::INT)
					{
						fout << idtable.table[i].parrent_block_name << setw(40 - strlen(idtable.table[i].parrent_block_name)) << idtable.table[i].id << setw(40 - 7) << "integer\tA"  << endl;
					}
					else if (idtable.table[i].iddatatype == IDDATATYPE::STR)
					{
						fout << idtable.table[i].parrent_block_name << setw(40 - strlen(idtable.table[i].parrent_block_name)) << idtable.table[i].id << setw(40 - 6) << "string\tA"  << endl;
					}
					else
					{
						fout << idtable.table[i].parrent_block_name << setw(40 - strlen(idtable.table[i].parrent_block_name)) << idtable.table[i].id << setw(40 - 6) << "logic\tA"  << endl;
					}
				}
			}
			fout << "\n\n\n";
		}
		else
			throw ERROR_THROW(127);
		fout.close();
	}
}

