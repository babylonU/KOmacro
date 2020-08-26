#include "stdafx.h" // i am writing on VİsualStudio.For in. Maybe not.
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <locale>

using namespace std;

int karakter_basla = 0;
unsigned char karakter_bitir;
int a = 0;
int sec = 0;

void sendKeyDown(unsigned char EnterKey)
{
	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = EnterKey;
	input.ki.dwFlags = 0;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;

	SendInput(1, &input, sizeof(INPUT));
}

void sendKeyUp(unsigned char EnterKey)
{
	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = EnterKey;
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;

	SendInput(1, &input, sizeof(INPUT));
}
void Bitir() {
	system("Cls");
	cout << "Çıkış için 2 i tuşlayınız.";
	while (karakter_bitir != ' ') {
		karakter_bitir = _getch();
		if (karakter_bitir == '2') {
			break;
		}
	}
}

void Timer() {
// ALT + TaB ekledim fakat nedense progtam tuş atamalarını beraber basınca görmüyor.
	sendKeyDown(VK_MENU);
	sendKeyDown(VK_TAB);
	sendKeyUp(VK_TAB);
	sendKeyUp(VK_MENU);
	Sleep(100);
	cout << "Çalışma durumu...";
		for (int x = 1; x <= 600; x++) {
			++sec;
			Sleep(1000);
			sendKeyDown(0x5A);
			sendKeyDown(0x32);
			sendKeyUp(0x32);
			sendKeyUp(0x5A);
			if (sec == 12) {
				sendKeyDown(0x34);
				sendKeyUp(0x34);
				continue;
			}
			if (sec == 55) {
				sendKeyDown(0x31);
				sendKeyUp(0x31);
				continue;	
			}
			if (sec == 120) {
				sendKeyDown(0x39);
				sendKeyUp(0x39);
				sec = 0;
				continue;
			// Wolf zamanı.
			}
		}
	}
// Bir zamanlayıcı 10 dakika boyunca for döngüsünü döngürecek, her 12,55,120 saniyelerde bir şart koşacak son şartta da değişken değerini 0layıp geri dönecek. 

void LastCheck() {
	Timer();
	sendKeyDown(VK_RETURN);
	sendKeyUp(VK_RETURN);
	sendKeyDown(VK_OEM_2);
	sendKeyUp(VK_OEM_2);
	sendKeyDown(0x54);
	sendKeyUp(0x54);
	sendKeyDown(0x4F);
	sendKeyUp(0x4F);
	sendKeyDown(0x57);
	sendKeyUp(0x57);
	sendKeyDown(0x4E);
	sendKeyUp(0x4E);
	sendKeyDown(VK_RETURN);
	sendKeyUp(VK_RETURN);
	// /town yazısı.
	Bitir();
}
int main() {
	MAİN:
	setlocale(LC_ALL, "Turkish");
	Sleep(5000);
	cout << "Başlamak için SHİFT tuşuna basmanız gerekmektedir.";
	if (GetAsyncKeyState (VK_SHIFT)) {
		system("Cls");
		LastCheck();
	}
	else {
		goto MAİN;
	}
	return 0;
}
