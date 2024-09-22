#include <iostream>
#include "Game.h"
#include "DrawableGameComponent.h"

using namespace std;

// standalone functions: initialise and terminateGame
void initialise() {
    cout << "Initialising Game..." << endl;
}

// terminateGame used as function name due to conflict with terminate function in std library 
// Alternate option: remove std namespace & add std::cout, std::endl
void terminateGame() {
    cout << "Terminating game..." << endl;
}

int main() {
    // seed - collosal number of seconds that have passed since 1970, only needs to be done once
    srand(time(NULL));

    // dynamic instance of Game created with 2 components: game component and drawable game component
    Game* game = new Game(2);

    game->SetInitialise(initialise);
    game->SetTerminate(terminateGame);

    game->Add(new GameComponent());
    game->Add(new DrawableGameComponent(0, 0));

    game->Run();
    
    delete game;

    return 0;
}
