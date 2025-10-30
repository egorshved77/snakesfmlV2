#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "Snake.h"
#include "Food.h"
#include <algorithm>
#include <fstream>

class GameModel {
public:
    enum Difficulty { EASY, MEDIUM, HARD };

    GameModel(int width, int height, Difficulty level);

    void update();
    void reset();
    bool isGameOver() const;
    int getScore1() const;
    int getScore2() const;
    int getWidth() const;
    int getHeight() const;
    int calculateDelay() const;
    void initSinglePlayer();
    void initMultiplayer();
    Snake& getSnake1();
    Snake& getSnake2();
    Food getFood() const;

    bool is_running;
    bool multiplayer;
    void setDifficulty(Difficulty level);

    void setPlayer1Name(const std::string& playerName);
    void setPlayer2Name(const std::string& playerName);

    const std::string& getPlayer1Name() const;
    const std::string& getPlayer2Name() const;

    void loadScores(); // Загрузка рекордов из файла
    void saveScores(); // Сохранение рекордов в файл
    void updateScores(int newScore); // Обновление списка рекордов

    const std::vector<std::pair<std::string, int>>& getScores() const; // Получение списка рекордов

private:
    std::vector<std::pair<std::string, int>> scores; // Пары (имя игрока, счёт)
    std::string player1Name;
    std::string player2Name;
    Snake snake1;
    Snake snake2;
    Food food;
    int base_delay;
    int score1;
    int score2;
    int width;
    int height;//
};

#endif // GAMEMODEL_H
