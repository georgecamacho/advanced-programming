#pragma once

#include <ctime>

class GameComponent {
    private:
        int id;
        // static added to retain its value between function calls
        // this variable is shared among all instances of this class
        static int instances;
    public:
        GameComponent(void);
        // virtual added so compiler knows that this function can be overridden in DrawableGameComponent class
        virtual void Update(const tm* eventTime);
};
