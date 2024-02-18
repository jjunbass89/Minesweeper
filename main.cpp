#include <iostream>
#include <string>
#include "game.h"

using namespace std;

int main() {
  Game game;
  while (true) {
    game.getValidPositionFromUIAndUpdateMap();
    const auto status = game.getStatus();
    if (status != GameStatus::RUNNING) {
      game.showEndMessage(status);
      break;
    }
  }
  return 0;
}