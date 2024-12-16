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
    int counter = 0;

    while (BeepersPresent()) {
        PickBeeper();
        counter++;
    }

    for (int i = 0; i < counter * 2; i++) {
        PutBeeper();
    }

    if (FrontIsClear()) {
        Move();
    } else if (shouldTurnRight) {
        turnRight();
        
        if (FrontIsClear()) {
            Move();
        } else {
            Finish();
        }

        turnRight();
        shouldTurnRight = false;
    } else {
        TurnLeft();

        if (FrontIsClear()) {
            Move();
        } else {
            Finish();
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
    LoadWorld("worlds/Double_beepers_02.w");
    KarelProgram();
    Finish();
    return 0;
}
