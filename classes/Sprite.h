#include <cstdio>
#include <vector>
#include <string>
#include <ncurses>

#pragma once

class Sprite
{
    private:
        std::vector<SpriteRow> spriteRows;

    public:
        Sprite();
        load(const char* filename);
        draw(const unsigned int yPos, const unsigned int xPos);
        clear(const unsigned int yPos, const unsigned int xPos);
}
