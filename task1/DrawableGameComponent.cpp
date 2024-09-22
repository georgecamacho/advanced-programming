#include "DrawableGameComponent.h"
#include <algorithm>

using namespace std;

const char* DrawableGameComponent::directionStr[] = {"Up", "Down", "Left", "Right"};

DrawableGameComponent::DrawableGameComponent(int x, int y): GameComponent() {
    this->x = x;
    this->y = y;
    this->direction = Right;
}

void DrawableGameComponent::ChangeDirection() {
    Direction updatedDirection;
    // continues the loop until a different direction - to the current one - is selected
    do {
        updatedDirection = Direction(rand() % 4);
    }
    while (updatedDirection == direction);
    direction = updatedDirection;
}

void DrawableGameComponent::Draw() {
    printf("%s : X: %d, Y: %d \n", directionStr[direction], x, y);
}

void DrawableGameComponent::Update(const tm* eventTime) {
    GameComponent::Update(eventTime);
    switch(direction) {
        case Up:
            y = min(SCREEN_HEIGHT, y + 1);
            break;
        case Down:
            y = max(0, y - 1);
            break;
        case Left: 
            x = max(0, x - 1);
            break;
        case Right:
            x = min(SCREEN_WIDTH, x + 1);
            break;
        
    }

    Draw();
    ChangeDirection();
}
