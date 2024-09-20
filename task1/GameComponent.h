#pragma once
#include <ctime>

class GameComponent {
    private:
        int id;
        int instances;
    public:
        GameComponent(void);
        void Update(const tm*);
};
