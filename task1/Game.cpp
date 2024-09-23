#include "Game.h"

#include <unistd.h>

Game::Game(int maxComponents) {
    components = new GameComponent*[maxComponents];
    componentCount = 0;
}

Game::~Game(){
    // destructor implemented to delete compononents to prevent memory leak
    for (int i = 0; i < componentCount; i++) {

        delete components[i];
    }
    delete[] components;
}

void Game::Add(GameComponent* component) {
    components[componentCount] = component;
    componentCount++;
}

void Game::Run() {
    if (initialise) initialise();

    for (int invokedCount = 1; invokedCount <= 5; invokedCount++) {
        time_t currentTime = time(0);
        tm eventTime;
        gmtime_r(&currentTime, &eventTime);

        for (int i = 0; i < componentCount; i++) {
            components[i]->Update(&eventTime);
        }

        sleep(TICKS_1000MS);
    }

    if (terminate) terminate();
}

void Game::SetInitialise(FP initialise){
    this->initialise = initialise;
}

void Game::SetTerminate(FP terminate){
    this->terminate = terminate;
    
}
