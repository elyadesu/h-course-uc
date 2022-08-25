// HCourseMemReader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;

BOOL bProcMagic(DWORD dID, uintptr_t dMem, int iType)
{
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dID); //Get handle to the process
	if (hProcess == NULL)
	{
		cout << "Something gone wrong. Try the magic again. Err = " << dec << GetLastError() << endl;
		getchar();
		return 1;
	}
	switch (iType)
	{
	case 1: //bool
	{
		bool boolRead;
		BOOL rpmReturn = ReadProcessMemory(hProcess, (LPCVOID)dMem, &boolRead, sizeof(bool), NULL);
		if (rpmReturn == FALSE)
		{
			cout << "Something gone wrong. Try the magic again. Err = " << dec << GetLastError() << endl;
			getchar();
			return 1;
		}
		cout << "boolRead = " << boolRead << endl;
		break;
	}
	case 2: //int
	{
		int intRead;
		BOOL rpmReturn = ReadProcessMemory(hProcess, (LPCVOID)dMem, &intRead, sizeof(int), NULL);
		if (rpmReturn == FALSE)
		{
			cout << "Something gone wrong. Try the magic again. Err = " << dec << GetLastError() << endl;
			getchar();
			return 1;
		}
		cout << "intRead = " << dec << intRead << endl;
		break;
	}
	case 3: //char
	{
		char charRead;
		BOOL rpmReturn = ReadProcessMemory(hProcess, (LPCVOID)dMem, &charRead, sizeof(char), NULL);
		if (rpmReturn == FALSE)
		{
			cout << "Something gone wrong. Try the magic again. Err = " << dec << GetLastError() << endl;
			getchar();
			return 1;
		}
		cout << "charRead = " << charRead << endl;
		break;
	}
	case 4: //string 
	{
		string strRead; //Really problems with strings reading. Need to fix
		BOOL rpmReturn = ReadProcessMemory(hProcess, (LPCVOID)dMem, &strRead, sizeof(string), NULL);
		if (rpmReturn == FALSE)
		{
			cout << "Something gone wrong. Try the magic again. Err = " << dec << GetLastError() << endl;
			getchar();
			return 1;
		}
		cout << "strRead = " << strRead << endl; //smth wrong with buffer.
		break;
	}
	case 5: //intpointer(x86)
	{
		int* pointerRead;
		BOOL rpmReturn = ReadProcessMemory(hProcess, (LPCVOID)dMem, &pointerRead, sizeof(4), NULL);
		if (rpmReturn == FALSE)
		{
			cout << "Something gone wrong. Try the magic again. Err = " << dec << GetLastError() << endl;
			getchar();
			return 1;
		}
		cout << "pointerRead = " << pointerRead << endl;
		break;
	}
	case 6: //inpointer(x64)
	{
		int* pointerRead;
		BOOL rpmReturn = ReadProcessMemory(hProcess, (LPCVOID)dMem, &pointerRead, sizeof(8), NULL);
		if (rpmReturn == FALSE)
		{
			cout << "Something gone wrong. Try the magic again. Err = " << dec << GetLastError() << endl;
			getchar();
			return 1;
		}
		cout << "pointerRead = " << pointerRead << endl;
		break;
	}
	}
	CloseHandle(hProcess);

};

int main()
{
	//inputs like ProcessID, Mem.
	DWORD inputID;
	uintptr_t inputMem = 0x0;
	int inputType;

	cout << "Input Process ID" << endl << flush;
	cin >> inputID;
	cout << "Input Mem address" << endl << flush;
	cin >> hex >> inputMem;
	do
	{
		cout << "Input type of the variable 1-bool 2-int 3-char 4-string(broken) 5-intpointer(x86) 6-intpointer(x64)" << endl << flush;
		cin >> dec >> inputType;
	} while (inputType < 0 && inputType > 7);
	
	bProcMagic(inputID, inputMem, inputType);
	cout << "Press ENTER to quit.";
	system("pause > nul");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
