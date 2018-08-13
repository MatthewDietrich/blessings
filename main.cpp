//#include "GameWindow.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream> //debugging

void getTerminalSize(unsigned int *termWidth, unsigned int *termHeight);

int main()
{
    unsigned int termWidth, termHeight;
    getTerminalSize(&termWidth, &termHeight);
    std::cout << termWidth << " " << termHeight << std::endl;
    return 0;
}

void getTerminalSize(unsigned int *termWidth, unsigned int *termHeight)
{
    const char* TERMSIZE_TEMP_FILENAME = "__TERMSIZE.temp.txt";
    char termWidthStr[50], termHeightStr[50];

    std::string terminalCommand = "printf \"cols\nlines\" | tput -S > ";
    terminalCommand += TERMSIZE_TEMP_FILENAME;
    system(terminalCommand.c_str());

    std::ifstream termSizeFile (TERMSIZE_TEMP_FILENAME);
    termSizeFile.getline(termWidthStr, 50);
    termSizeFile.getline(termHeightStr, 50);
    *termWidth = atoi(termWidthStr);
    *termHeight = atoi(termHeightStr);

    terminalCommand = "rm ";
    terminalCommand += TERMSIZE_TEMP_FILENAME;
    system(terminalCommand.c_str());
}
