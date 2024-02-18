#ifndef GAMEUI_H
#define GAMEUI_H

#include "GameInputStream.h"

#include <memory>
#include <string>

class GameUI {
 public:
  unsigned int getValidXSize();
  unsigned int getValidYSize();
  unsigned int getValidMineCount(const unsigned int sizeX,
                                 const unsigned int sizeY);
  void generatePosInputStream(const unsigned int sizeX,
                              const unsigned int sizeY);
  unsigned int getValidX();
  unsigned int getValidY();

 private:
  std::unique_ptr<GameInputStream<unsigned int>> generateXSizeInputStream_();
  std::unique_ptr<GameInputStream<unsigned int>> generateYSizeInputStream_();
  std::unique_ptr<GameInputStream<unsigned int>> generateMineCountInputStream_(
      const unsigned int sizeX, const unsigned int sizeY);
  void generateXInputStream_(const unsigned int size);
  void generateYInputStream_(const unsigned int size);

  unsigned int getMaxMineCount_(const unsigned int sizeX,
                                const unsigned int sizeY);

 private:
  std::unique_ptr<GameInputStream<char>> xInputStream_;
  std::unique_ptr<GameInputStream<char>> yInputStream_;

  const unsigned int MIN_MAP_SIDE_SIZE = 3;
  const unsigned int MAX_MAP_SIDE_SIZE = 26;
  const unsigned int MIN_MINE_COUNT = 1;
};

#endif