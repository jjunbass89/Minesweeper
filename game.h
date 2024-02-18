#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "GameUI.h"
#include <memory>

class Game {
   public:
    Game();
    void getValidPositionFromUIAndUpdateMap();
    GameStatus getStatus();
    void showEndMessage(GameStatus status);

   private:
    MapParam getValidMapSizeAndMinCount_();
    Position getValidPositionFromUI_();    

   private:
    std::unique_ptr<GameUI> gameUI_;
    std::unique_ptr<Map> map_;
};

#endif