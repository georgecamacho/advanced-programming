#pragma once
#include "GameComponent.h"

class DrawableGameComponent : public GameComponent {
    private:
        int x;
        int y;
        // enum used for Direction so options are limited and the user can't enter a random string that is unaccounted for
        enum Direction {Up, Down, Left, Right};
        static const char* directionStr[];
        void ChangeDirection();
        void Draw();
    
    public:
        const int SCREEN_HEIGHT = 20;
        const int SCREEN_WIDTH = 80;
        Direction direction;
        DrawableGameComponent(int x, int y);
        void Update(const tm* eventTime);
};
