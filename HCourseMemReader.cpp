// HCourseMemReader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	//inputs like ProcessID, Mem.
	DWORD inputID;
	DWORD inputMem;

	int intRead = 0;

	cout << "Input Process ID" << endl;
	cin >> inputID;
	cout << "Input Mem address" << endl;
	cin >> hex >> inputMem;

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, inputID); //Get handle to the process
	if (hProcess == NULL)
	{
		cout << "Something gone wrong. Try the magic again. Err = " << dec << GetLastError() << endl;
		getchar();
		return 1;
	}

	BOOL rpmReturn = ReadProcessMemory(hProcess, (LPCVOID)inputMem, &intRead, sizeof(int), NULL);
	if (rpmReturn == FALSE)
	{
			cout << "Something gone wrong. Try the magic again. Err = " << dec << GetLastError() << endl;
			getchar();
			return 1;
	}

	cout << "intRead = " << dec << intRead << endl;
	cout << "Press ENTER to quit.";
	getchar();

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
