#pragma once

class GameObject
{
    private:
        Sprite sprite;
        int xPos, yPos;
        double xVel, yVel;

    public:
        GameObject();

        // Drawing
        inline void draw() { sprite.draw(xPos, yPos); }
        inline void clear() { sprite.clear(xPos, yPos); }

        // Physics
        void move(const int xDistance, const int yDistance);
}
