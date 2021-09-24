#pragma warning(disable : 4996)
#include <iostream>
#include <time.h>

// TODO: Это пример библиотечной функции.
extern "C"
{
	void __stdcall concat1(char* dest, char* par1)
	{
		int k = 0;
		for (int i = 0; par1[i] != '\0'; i++)
			dest[k++] = par1[i];

		dest[k] = '\0';
	}

	void __stdcall concat2(char* destination, char* left_operand, char* right_operand)
	{
		int k = 0;
		for (int i = 0; right_operand[i] != '\0'; i++)
			destination[k++] = right_operand[i];

		for (int i = 0; left_operand[i] != '\0'; i++)
			destination[k++] = left_operand[i];

		destination[k] = '\0';
	}

	void __stdcall print(char* value)
	{
		std::cout << value << "\n";
	}

	void __stdcall printint(int value)
	{
		std::cout << value << "\n";
	}

	void __stdcall isvisokosni(int value)
	{
		if (value % 4 == 0 || (value % 100 == 0 && value % 400 == 0))
		{
			std::cout << "god_visokosnii\n";
		}
		else
		{
			std::cout << "god_ne_visokosnii\n";
		}
	}

	void __stdcall printcurrentdate()
	{
		time_t now = time(0);
		tm date;
		localtime_s(&date, &now);
		char buf[228];
		strftime(buf, sizeof(buf), "%c", &date);
		std::cout << buf << std::endl;
	}
}