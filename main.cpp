#include <iostream>
#include <cstdio>
#include <windows.h>  //For music
#include <MMsystem.h> //For music
#include <string>     
#include <fstream>
#include <thread>

// To use this function make sure u add "winmm.lib" (with quotes) into the 
// additional dependencies of the linker (at least in Visual Studio)
// if u are using another IDE or it doesn't work u cant comment it to disable it.

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
	std::thread t(playMusic); // Music

	for (int index{0}; index < 6560; ++index) // Video
	{
		printFrame(index);
		Sleep(25);
	}
	
	

	return 0;
}
