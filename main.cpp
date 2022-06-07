#include <iostream>
#include <cstdio>
#include <windows.h>
#include <MMsystem.h>
#include <string>
#include <fstream>
#include <thread>

void playMusic()
{
	const wchar_t* soundToPlay = L"./res/BA.wav";
	PlaySound(soundToPlay, NULL, SND_FILENAME | SND_LOOP);
}

std::string getFrame(int frame)
{
	std::string currentFrame{};
	char buffer[35];
	sprintf_s(buffer, "./res/BA%d%s", frame, ".txt");

	std::string stringBuffer = buffer;
	return stringBuffer;
}

void printFrame(int frame)
{
	std::string currentLine{};
	std::string stringBuffer = getFrame(frame);
	std::ifstream frameBuffer (stringBuffer);

	while (getline(frameBuffer, currentLine))
	{
		std::cout << currentLine << '\n';
	}

	
	
}

int main()
{
	std::thread t(playMusic);

	for (int index{0}; index < 6560; ++index)
	{
		printFrame(index);
		Sleep(25);
	}
	
	

	return 0;
}