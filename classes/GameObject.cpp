#include "GameObject.h"
#include <cmath>

GameObject::GameObject()
{

}

void GameObject::move(const int xDistance, const int yDistance)
{
    xPos += xDistance;
    yPos += yDistance;
}
