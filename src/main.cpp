//==============================================================================
///
/// @file
/// @brief Программа для робота Карела и стартовая функция
///
//==============================================================================


#include "karel.h"
bool shouldTurnRight;

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
    } else if (!shouldTurnRight) {
        TurnLeft();
        if (FrontIsClear()) {
            Move();
        } else {
            return;
        }
        TurnLeft();
        shouldTurnRight = true;
    } else {
        TurnLeft();
        TurnLeft();
        TurnLeft();
        if (FrontIsClear()) {
            Move();
        } else {
            return;
        }
        TurnLeft();
        TurnLeft();
        TurnLeft();
        shouldTurnRight = false;
    }
}
}


//==============================================================================
/// Стартовая функция
///
int main() {
    LoadWorld("worlds/CB_02.w");
    KarelProgram();
    Finish();
    return 0;
}
