#pragma once


#define ID_MAXSIZE			32				// ������������ ���������� ������� � ��������������
#define TI_MAXSIZE			4096			// ������������ ���������� ��-�� � ������� ��������������� 
#define TI_INT_DEFAULT		0x00000000		// �������� �� ��������� ��� ���� integer 
#define TI_STR_DEFAULT		0x00			// �������� �� ��������� ��� ���� string 
#define TI_LOG_DEFAULT		0
#define TI_NULLIDX			0xffffffff		// ��� �������� ������� ���������������
#define TI_STR_MAXSIZE		255
#define TI_ARRAY_MAXSIZE	10

namespace IT
{
	enum IDDATATYPE { INT = 1, STR = 2, LOG = 3};				// ���� ������ ���������������: integer, string
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, PF = 5, A = 6};	// ���� ���������������: ����������, �������, ��������, �������, �������� �������, ������

	struct Entry		// ������ ������� ���������������
	{
		int				idxLT;
		char			parrent_block_name[ID_MAXSIZE];	// ��� ������������� �����
		char			id[ID_MAXSIZE];					// ������������� (������������� ��������� �� ID_MAXSIZE)
		IDDATATYPE		iddatatype;						// ��� ������
		IDTYPE			idtype;							// ��� ��������������

		union
		{
			struct
			{
				int value;
				int array_size;
				int parm_count;
			}vint;						// �������� integer
			struct
			{
				char len;						// ��������� �������� � string
				char str[TI_STR_MAXSIZE - 1];	// ������� string
			} vstr[TI_STR_MAXSIZE];				// �������� string
			bool vlogic;
		} value;								// �������� ��������������
	};

	struct IdTable // ��������� ������� ���������������
	{
		int maxsize;				// ������� ������� ��������������� < TI_MAXSIZE
		int current_size;			// ������� ������ ������� ��������������� < maxsize
		Entry* table;				// ������ ����� ������� ���������������
	};

	IdTable Create(int size);
	void Add(IdTable& idtable, Entry entry);
	Entry GetEntry(IdTable& idtable, int n);
	int IsId(IdTable& idtable, char id[ID_MAXSIZE]);
	void Delete(IdTable& idtable);
	void PrintIdTable(IdTable& idtable);
};