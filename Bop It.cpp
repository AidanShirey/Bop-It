// Bop It.cpp : Reads out the commands for the McDonald's Bop It! happy meal toy.
// Author : Aidan Shirey


#include "stdafx.h"
#include <sapi.h>
#include <string>
#include "time.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	const WORD colors[] =
	{
		0xF, 0xC, 0xE, 0xB, 0xA
	};
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD index = 0;
	string commands[5] = { "Bop it", "Spin it", "Twist it", "Pull it", "Switch it" };
	srand(time(NULL));
	ISpVoice * pVoice = NULL;
	if (FAILED(CoInitialize(NULL)))
		return false;
	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	if (SUCCEEDED(hr))
	{
		while (true) 
		{
			int play = rand() % 5;
			int playswitch = play + 1;
			switch (playswitch)
			{
			case 1: {
				index = 0;
				SetConsoleTextAttribute(hstdout, colors[index]);
				cout << commands[play] << endl;
				hr = pVoice->Speak(L"Bop it", 0, NULL);
				break;
			}
			case 2: {
				index = 1;
				SetConsoleTextAttribute(hstdout, colors[index]);
				cout << commands[play] << endl;
				hr = pVoice->Speak(L"Spin it", 0, NULL);
				break;
			}
			case 3: {
				index = 2;
				SetConsoleTextAttribute(hstdout, colors[index]);
				cout << commands[play] << endl;
				hr = pVoice->Speak(L"Twist it", 0, NULL);
				break; 
			}
			case 4: {
				index = 3;
				SetConsoleTextAttribute(hstdout, colors[index]);
				cout << commands[play] << endl;
				hr = pVoice->Speak(L"Pull it", 0, NULL);
				break; 
			}
			case 5: {
				index = 4;
				SetConsoleTextAttribute(hstdout, colors[index]);
				cout << commands[play] << endl;
				hr = pVoice->Speak(L"Switch it", 0, NULL);
				break; 
			}
			}
		}
		
		pVoice->Release();
		pVoice = NULL;
	}

	CoUninitialize();
	return true;
}

