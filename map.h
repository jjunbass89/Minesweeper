#ifndef BOARD_H
#define BOARD_H

#include <vector>

struct Position {
  int x;
  int y;
};

struct MapParam {
  unsigned int sizeX;
  unsigned int sizeY;
  unsigned int mineCount;
};

enum class GameStatus {
  RUNNING,
  WIN,
  DEFEAT,
};

class Map {
 public:
  Map(const MapParam& param);
  void selectTile(const Position& pos);
  GameStatus getGameStatus();

 private:
  void initMap_(std::vector<std::vector<char>>& map, const MapParam& param);
  void addMineToBackMap_(const MapParam& param);
  void calcBackMapMineCount_();
  bool hasMine_(const int x, const int y);
  char intToNumChar_(const int in);

  void printFrontMap_();
  void printFrontMapXAxis_();
  void printFrontMapYAxisAndTiles_();

  void revealTile_(const Position& pos);
  void transverseTile_(const Position& pos);
  bool isOutOfMap_(const Position& pos);
  bool isDefeat_();
  bool isRunning_();

 private:
  std::vector<std::vector<char>> frontMap_;
  std::vector<std::vector<char>> backMap_;
  const char TILE_NONE = '.';
  const char TILE_MINE = 'm';
  const char TILE_ZERO = '0';
};

#endif