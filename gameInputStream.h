#ifndef GAME_INPUT_STREAM_H
#define GAME_INPUT_STREAM_H

#include <string>

template <typename T>
class GameInputStream {
   public:
    T getValidInput();
    void setMinInput(const T min);
    void setMaxInput(const T max);
    void setMessage(const std::string& message);

   private:
    T showMessageAndGetValidInput_(const std::string& message);
    bool isValidInput_(const T input);
    std::string getAdditionalMessage_();
    std::string convertToStr_(const T in);

   private:
    T minInput_;
    T maxInput_;
    std::string message_;
};

#endif