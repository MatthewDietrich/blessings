#pragma once

class SpriteRow
{
    private:
        std::string contents;
        unsigned int leftOffset;

    public:
        SpriteRow(std::string _contents, unsigned int leftOffset);
        draw(const unsigned int yPos, const unsigned int xPos);
        clear(const unsigned int yPos, const unsigned int xPos);
}
