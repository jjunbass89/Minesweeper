#include "GameUI.h"
#include "Converter.h"

#include <iostream>

std::unique_ptr<GameInputStream<unsigned int>>
GameUI::generateXSizeInputStream_() {
  auto inputStream = std::make_unique<GameInputStream<unsigned int>>();
  inputStream->setMinInput(MIN_MAP_SIDE_SIZE);
  inputStream->setMaxInput(MAX_MAP_SIDE_SIZE);
  inputStream->setMessage("Map 의 X 축 크기");
  return std::move(inputStream);
}

std::unique_ptr<GameInputStream<unsigned int>>
GameUI::generateYSizeInputStream_() {
  auto inputStream = std::make_unique<GameInputStream<unsigned int>>();
  inputStream->setMinInput(MIN_MAP_SIDE_SIZE);
  inputStream->setMaxInput(MAX_MAP_SIDE_SIZE);
  inputStream->setMessage("Map 의 Y 축 크기");
  return std::move(inputStream);
}

unsigned int GameUI::getMaxMineCount_(const unsigned int sizeX,
                                      const unsigned int sizeY) {
  return (sizeX * sizeY) - 1;
}

std::unique_ptr<GameInputStream<unsigned int>>
GameUI::generateMineCountInputStream_(const unsigned int sizeX,
                                      const unsigned int sizeY) {
  const auto maxMineCount = getMaxMineCount_(sizeX, sizeY);

  auto inputStream = std::make_unique<GameInputStream<unsigned int>>();
  inputStream->setMinInput(MIN_MINE_COUNT);
  inputStream->setMaxInput(maxMineCount);
  inputStream->setMessage("전체 지뢰의 수");
  return std::move(inputStream);
}

void GameUI::generatePosInputStream(const unsigned int sizeX,
                                    const unsigned int sizeY) {
  generateXInputStream_(sizeX);
  generateYInputStream_(sizeY);
}

void GameUI::generateXInputStream_(const unsigned int size) {
  const auto maxVal = size - 1;
  const auto maxPosChar = Converter::intToLowerChar(maxVal);

  xInputStream_ = std::make_unique<GameInputStream<char>>();
  xInputStream_->setMinInput(Converter::MIN_POS_CHAR);
  xInputStream_->setMaxInput(maxPosChar);
  xInputStream_->setMessage("열의 좌표");
}

void GameUI::generateYInputStream_(const unsigned int size) {
  const auto maxVal = size - 1;
  const auto maxPosChar = Converter::intToLowerChar(maxVal);

  yInputStream_ = std::make_unique<GameInputStream<char>>();
  yInputStream_->setMinInput(Converter::MIN_POS_CHAR);
  yInputStream_->setMaxInput(maxPosChar);
  yInputStream_->setMessage("행의 좌표");
}

unsigned int GameUI::getValidXSize() {
  auto inputStream = generateXSizeInputStream_();
  return inputStream->getValidInput();
}

unsigned int GameUI::getValidYSize() {
  auto inputStream = generateYSizeInputStream_();
  return inputStream->getValidInput();
}

unsigned int GameUI::getValidMineCount(const unsigned int sizeX,
                                       const unsigned int sizeY) {

  auto inputStream = generateMineCountInputStream_(sizeX, sizeY);
  return inputStream->getValidInput();
}

unsigned int GameUI::getValidX() {
  const auto input = xInputStream_->getValidInput();

  const auto x = Converter::lowerCharToInt(input);
  return x;
}

unsigned int GameUI::getValidY() {
  const auto input = yInputStream_->getValidInput();

  const auto y = Converter::lowerCharToInt(input);
  return y;
}