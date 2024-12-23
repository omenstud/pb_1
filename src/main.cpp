//==============================================================================
///
/// @file
/// @brief Программа для робота Карела и стартовая функция
///
//==============================================================================

#include "karel.h"

void turnRight() {
  TurnLeft();
  TurnLeft();
  TurnLeft();
}

void goToFinish() {
  if (BeepersPresent()) {
    return;
  }

  TurnLeft();
  if (FrontIsClear()) {
    Move();
  } else {
    turnRight();
    if (FrontIsClear()) {
      Move();
    } else {
      turnRight();
    }
  }

  goToFinish();
}

//==============================================================================
/// Программа для робота Карела
///
void KarelProgram() {
  /// @todo Добавить программу для Карела
  goToFinish();
}

//==============================================================================
/// Стартовая функция
///
int main() {
  LoadWorld("worlds/Maze_01.w");
  KarelProgram();
  Finish();
  return 0;
}
