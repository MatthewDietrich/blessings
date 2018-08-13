#include "Sprite.h"
#include <cstdio>

/*
Function: Sprite.load
Parameters: filename (char*)
Return: void
Purpose: Load a file containing a sprite
*/
void Sprite::load(const char* filename)
{
    FILE* fp = fopen(filename);
    std::string tempString;
    char c;
    unsigned int offset = 0;
    bool firstCharFlag;

    if (fp == NULL)
        spriteRows.push_back(SpriteRow(std::string("SPRITE_ERR"), 0));

    else
    {
        do
        {
            c = fgetc(fp);

            if (c == '\n')
                spriteRows.push_back(SpriteRow(tempString, offset));

            else if (firstCharFlag == false and c == ' ')
                offset++

            else
            {
                tempString.push_back(c);
                firstCharFlag = true;
            }
        }
    }

    return;
}

void Sprite::draw(const int yPos, const int xPos)
{
    for (int i = 0; i < spriteRows.size(); i++)
        spriteRows[i].draw(yPos, xPos);
}

void Sprite::clear(const int yPos, const int xPos)
{
    for (int i = 0; i < spriteRows.size(); i++)
        spriteRows[i].draw(yPos, xPos);
}
