#include "GameInputStream.h"

#include <iostream>

template <typename T>
T GameInputStream<T>::getValidInput() {
    std::string message = message_ + getAdditionalMessage_();
    return showMessageAndGetValidInput_(message);
}

template <typename T>
void GameInputStream<T>::setMinInput(const T min) {
    minInput_ = min;
}

template <typename T>
void GameInputStream<T>::setMaxInput(const T max) {
    maxInput_ = max;
}

template <typename T>
void GameInputStream<T>::setMessage(const std::string& message) {
    message_ = message;
}

template <typename T>
T GameInputStream<T>::showMessageAndGetValidInput_(const std::string& message) {
    T result = {};
    while (true) {
        std::cout << message;
        std::cin >> result;
        if (isValidInput_(result))
            break;

        std::cin.clear();
        std::cin.ignore();
    }

    return result;
}

template <typename T>
bool GameInputStream<T>::isValidInput_(const T input) {
    if (input < minInput_ || input > maxInput_) {
        return false;
    }

    return true;
}

template <>
bool GameInputStream<char>::isValidInput_(const char input) {
    const auto lowerChar = std::tolower(input);
    if (lowerChar < minInput_ || lowerChar > maxInput_) {
        return false;
    }

    return true;
}

template <typename T>
std::string GameInputStream<T>::convertToStr_(const T in) {
    return std::to_string(in);
}

template <>
std::string GameInputStream<char>::convertToStr_(const char in) {
    std::string ret;
    ret += in;
    return ret;
}

template <typename T>
std::string GameInputStream<T>::getAdditionalMessage_() {
    const auto strMinUnserInputInt = convertToStr_(minInput_);
    const auto strMaxUnserInputInt = convertToStr_(maxInput_);
    return "를 입력하고 엔터를 누르세요. (" + strMinUnserInputInt + " 이상, " +
           strMaxUnserInputInt + " 이하) : ";
}

template class GameInputStream<unsigned int>;
template class GameInputStream<char>;