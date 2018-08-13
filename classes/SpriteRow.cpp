#include "SpriteRow.h"
#include "windowBounds.h"

SpriteRow::SpriteRow(std::string _contents, unsigned int _leftOffset)
{
    contents = _contents;
    leftOffset = _leftOffset;
}

/*
Function: SpriteRow.draw
Parameters: Y Position, X Position
Purpose: Draw the sprite row in the curses window
*/
void SpriteRow::draw(const unsigned int yPos, const unsigned int xPos)
{
    for (int i = 0; i < contents.size(); i++)
        if (isInBounds(yPos, xPos)) mvaddch(yPos, xPos + leftOffset + i, contents[i]);
}

/*
Function: SpriteRow.clear
Parameters: Y Position, X Position
Purpose: Clear the sprite row from the curses window
*/
void SpriteRow::clear(const unsigned int yPos, const unsigned int xPos)
{
    for (int i = 0; i < contents.size(); i++)
        mvaddch(yPos, xPos + leftOffset + i, ' ');
}
