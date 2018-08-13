#pragma once

class GameWindow
{
    private:
        unsigned int _width;
        unsigned int _height;
        unsigned int top, right, bottom, left;

    public:
        GameWindow(unsigned int width, unsigned int height, unsigned int leftOffset, unsigned int topOffset);

        void drawBorders();
        void drawObjects();
        inline bool isInBounds(const int xPos, const int yPos);

        ~GameWindow();
}
