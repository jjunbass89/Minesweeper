#include "map.h"
#include "converter.h"

#include <iostream>
#include <random>

void Map::initMap_(std::vector<std::vector<char>>& map, const MapParam& param) {
  map = std::vector<std::vector<char>>(param.sizeX);
  for (int x = 0; x < map.size(); x++) {
    map[x] = std::vector<char>(param.sizeY, TILE_NONE);
  }
}

void Map::addMineToBackMap_(const MapParam& param) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis;
  for (unsigned int i = 0; i < param.mineCount; i++) {
    int x, y;
    while (true) {
      x = dis(gen) % param.sizeX;
      y = dis(gen) % param.sizeY;
      if (backMap_[x][y] != TILE_MINE) {
        backMap_[x][y] = TILE_MINE;
        break;
      }
    }
  }
}

void Map::calcBackMapMineCount_() {
  for (int x = 0; x < backMap_.size(); x++) {
    for (int y = 0; y < backMap_[x].size(); y++) {
      if (backMap_[x][y] != TILE_MINE) {
        int mineCount = 0;
        if (hasMine_(x - 1, y - 1))
          mineCount++;
        if (hasMine_(x, y - 1))
          mineCount++;
        if (hasMine_(x + 1, y - 1))
          mineCount++;
        if (hasMine_(x - 1, y))
          mineCount++;
        if (hasMine_(x + 1, y))
          mineCount++;
        if (hasMine_(x - 1, y + 1))
          mineCount++;
        if (hasMine_(x, y + 1))
          mineCount++;
        if (hasMine_(x + 1, y + 1))
          mineCount++;

        char c = intToNumChar_(mineCount);
        backMap_[x][y] = c;
      }
    }
  }
}

char Map::intToNumChar_(const int in) {
  return '0' + in;
}

Map::Map(const MapParam& param) {
  initMap_(frontMap_, param);
  initMap_(backMap_, param);

  addMineToBackMap_(param);
  calcBackMapMineCount_();

  printFrontMap_();
}

void Map::printFrontMapXAxis_() {
  std::cout << std::endl << "   ";
  for (int i = 0; i < frontMap_.size(); i++) {
    std::cout << Converter::intToLowerChar(i);
  }
  std::cout << std::endl << std::endl;
}

void Map::printFrontMapYAxisAndTiles_() {
  for (int y = 0; y < frontMap_[0].size(); y++) {
    std::cout << Converter::intToLowerChar(y) << "  ";
    for (int x = 0; x < frontMap_.size(); x++) {
      std::cout << frontMap_[x][y];
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
}

void Map::printFrontMap_() {
  printFrontMapXAxis_();
  printFrontMapYAxisAndTiles_();
}

void Map::selectTile(const Position& pos) {
  const auto tileVal = backMap_[pos.x][pos.y];
  if (tileVal == TILE_ZERO) {
    transverseTile_(pos);
  } else {
    revealTile_(pos);
  }

  printFrontMap_();
}

void Map::revealTile_(const Position& pos) {
  frontMap_[pos.x][pos.y] = backMap_[pos.x][pos.y];
}

bool Map::isOutOfMap_(const Position& pos) {
  if (pos.x < 0 || pos.y < 0 || pos.x >= backMap_.size() ||
      pos.y >= backMap_[0].size()) {
    return true;
  }

  return false;
}

// // recursive function if minecount == 0
void Map::transverseTile_(const Position& pos) {
  if (isOutOfMap_(pos)) {
    return;
  }

  const auto frontVal = frontMap_[pos.x][pos.y];
  const auto backVal = backMap_[pos.x][pos.y];
  if (backVal == TILE_ZERO && frontVal == TILE_NONE) {
    revealTile_(pos);
    transverseTile_({pos.x - 1, pos.y - 1});
    transverseTile_({pos.x, pos.y - 1});
    transverseTile_({pos.x + 1, pos.y - 1});
    transverseTile_({pos.x - 1, pos.y});
    transverseTile_({pos.x + 1, pos.y});
    transverseTile_({pos.x - 1, pos.y + 1});
    transverseTile_({pos.x, pos.y + 1});
    transverseTile_({pos.x + 1, pos.y + 1});
  } else {
    revealTile_(pos);
  }
}

bool Map::hasMine_(const int x, const int y) {
  if (x >= 0 && x < backMap_.size() && y >= 0 && y < backMap_[x].size()) {
    if (backMap_[x][y] == 'm')
      return true;
  }
  return false;
}

GameStatus Map::getGameStatus() {
  if (isDefeat_()) {
    return GameStatus::DEFEAT;
  }
  if (isRunning_()) {
    return GameStatus::RUNNING;
  }

  return GameStatus::WIN;
}

bool Map::isDefeat_() {
  for (int x = 0; x < frontMap_.size(); x++) {
    for (int y = 0; y < frontMap_[x].size(); y++) {
      if (frontMap_[x][y] == TILE_MINE) {
        return true;
      }
    }
  }

  return false;
}

bool Map::isRunning_() {
  for (int x = 0; x < frontMap_.size(); x++) {
    for (int y = 0; y < frontMap_[x].size(); y++) {
      if (frontMap_[x][y] == '.') {
        if (backMap_[x][y] != TILE_MINE) {
          return true;
        }
      }
    }
  }

  return false;
}
