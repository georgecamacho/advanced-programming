#include "GameComponent.h"

#include <_printf.h>

// instances instantiated here to avoid being overwritten each time constructor is called
int GameComponent::instances = 0;

GameComponent::GameComponent() {
    // each time constructor is called the instance is incremented and set to the id
    instances++;
    this->id = instances;
}

void GameComponent::Update(const tm* eventTime){
    // character array to store formatted time as "HH:MM:SS"
    char timeStr[9];
    strftime(timeStr, sizeof(timeStr), "%X", eventTime);
    printf("ID: %d Updated at %s \n", this->id, timeStr);
}
