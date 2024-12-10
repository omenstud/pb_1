//==============================================================================
///
/// @file
/// @brief Программа для робота Карела и стартовая функция
///
//==============================================================================


#include "karel.h"
bool shouldTurnRight;

void turnRight() {
    TurnLeft();
    TurnLeft();
    TurnLeft();
}

//==============================================================================
/// Программа для робота Карела
///
void KarelProgram() {
/// @todo Добавить программу для Карела
while (true) {
    while (BeepersPresent()) {
        PickBeeper();
    }

    if (FrontIsClear()) {
        Move();
    } else if (shouldTurnRight) {
        turnRight();
        
        if (FrontIsClear()) {
            Move();
        } else {
            return;
        }

        turnRight();
        shouldTurnRight = false;
    } else {
        TurnLeft();

        if (FrontIsClear()) {
            Move();
        } else {
            return;
        }

        TurnLeft();
        shouldTurnRight = true;
    }
}
}


//==============================================================================
/// Стартовая функция
///
int main() {
    LoadWorld("worlds/CB_03.w");
    KarelProgram();
    Finish();
    return 0;
}
