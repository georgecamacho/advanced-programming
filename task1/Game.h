#pragma once
#include "GameComponent.h"

// Tpye definition FP for a function that returns void and no parameters
typedef void (*FP)();

class Game {
    private:
        const int TICKS_1000MS = 1;
        int componentCount;
        GameComponent** components;
        FP initialise;
        FP terminate;
    
    public:
        Game(int maxComponents);
        void Add(GameComponent*);
        void Run();
        void SetInitialise(FP initialise);
        void SetTerminate(FP terminate);
        


};
