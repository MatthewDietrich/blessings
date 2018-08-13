#include "GameWindow.h"

inline void fillVertical(const unsigned int horizontalPosition, const char fillChar);
inline void fillHorizontal(const unsigned int, verticalPosition, const char fillChar);
inline void fillCorners(const char fillChar);

GameWindow::GameWindow(unsigned int width, unsigned int height, unsigned int leftOffset = 0, unsigned int topOffset = 0)
{
    top = topOffset;
    right = leftOffset + width - 1;
    bottom = topOffset + height - 1;
    left = leftOffset;
}

void GameWindow::drawBorders()
{
    fillVertical(left, '|');
    fillVertical(right, '|');
    fillHorizontal(top, '-');
    fillHorizontal(bottom, '-');
    fillCorners('+');
}

inline bool isInBounds(const int xPos, const int yPos)
{
    return (
        xPos > left     &&
        xPos < right    &&
        yPos > top      &&
        yPos < bottom
    );
}

inline void fillVertical(const unsigned int horizontalPosition, const char fillChar)
{
    for (int i = top; i <= bottom) mvaddch(i, horizontalPosition, fillChar);
    return;
}

inline void fillHorizontal(const unsigned int, verticalPosition, const char fillChar)
{
    for (int i = left; i <= right; i++) mvaddch(verticalPosition, i, fillChar);
}

inline void fillCorners(const char fillChar)
{
    mvaddch(top, left, fillChar);
    mvaddch(top, right, fillChar);
    mvaddch(bottom, right, fillChar);
    mvaddch(bottom, left, fillChar);
}
