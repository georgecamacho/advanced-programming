#include <iostream>
#include "Game.h"
#include "DrawableGameComponent.h"

using namespace std;

// standalone functions: initialise and terminateGame
void initialise() {
    cout << "Initialising Game..." << endl;
}

// terminateGame used as function name instead of terminate as the std library already has a terminate function, which conflicts
// Other option would be to add std in front of cout & endl
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

    return 0;
}
