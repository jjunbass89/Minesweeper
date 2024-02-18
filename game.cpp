#include <iostream>

#include "game.h"

using namespace std;

Game::Game() {
  const auto MapParam = getValidMapSizeAndMinCount_();
  gameUI_->generatePosInputStream(MapParam.sizeX, MapParam.sizeY);

  map_ = std::make_unique<Map>(MapParam);
}

MapParam Game::getValidMapSizeAndMinCount_() {
  MapParam out;

  gameUI_ = std::make_unique<GameUI>();
  out.sizeX = gameUI_->getValidXSize();
  out.sizeY = gameUI_->getValidYSize();
  out.mineCount = gameUI_->getValidMineCount(out.sizeX, out.sizeY);
  return out;
}

void Game::getValidPositionFromUIAndUpdateMap() {
  const auto pos = getValidPositionFromUI_();
  map_->selectTile(pos);
}

Position Game::getValidPositionFromUI_() {
  Position pos;
  pos.y = gameUI_->getValidY();
  pos.x = gameUI_->getValidX();

  return pos;
}

GameStatus Game::getStatus() {
  return map_->getGameStatus();
}

void Game::showEndMessage(GameStatus status) {
  if (status == GameStatus::WIN) {
    std::cout << "½Â¸®." << std::endl;
  } else {
    std::cout << "ÆÐ¹è." << std::endl;
  }
}
