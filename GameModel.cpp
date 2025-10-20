#include "GameModel.h"

GameModel::GameModel(int width, int height, Difficulty level)
    : width(width), height(height), snake1(width / 2 - 1, height / 2 - 1), snake2(width / 2 + 1, height / 2 - 1), food(width, height, snake1) {
    is_running = true;
    multiplayer = false;
    setDifficulty(level);
}

void GameModel::initSinglePlayer() {
    multiplayer = false;
    snake1 = Snake(width / 2 - 1, height / 2 - 1);
    food.generate_new_position(width, height, snake1);
}

void GameModel::initMultiplayer() {
    multiplayer = true;
    snake1 = Snake(width / 2 - 1, height / 2 - 1);
    snake2 = Snake(width / 2 + 1, height / 2 - 1);
    food.generate_new_position(width, height, snake1);
}

void GameModel::saveScores() {
    std::ofstream file("../scores.txt");
    for (const auto& score : scores) {
        file << score.first << " " << score.second << std::endl;
    }
    file.close();
}

void GameModel::updateScores(int newScore) {
    if (multiplayer) {
        scores.push_back({player1Name, newScore});
        scores.push_back({player2Name, newScore});
    } else {
        scores.push_back({player1Name, newScore});
    }
    std::sort(scores.begin(), scores.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Сортировка по убыванию счёта
    });

    if (scores.size() > 10) {
        scores.resize(10); // Ограничение до 10 лучших результатов
    }
    saveScores(); // Сохранение в файл после обновления
}

void GameModel::loadScores() {
    std::ifstream file("../scores.txt");
    scores.clear();
    std::string name;
    int score;
    while (file >> name >> score) {
        scores.push_back({name, score});
    }
    file.close();
}

const std::vector<std::pair<std::string, int>>& GameModel::getScores() const {
    return scores;
}
void GameModel::setDifficulty(Difficulty level) {
    switch (level) {
    case EASY:
        base_delay = 300; // 300 milliseconds for easy level
        break;
    case MEDIUM:
        base_delay = 200; // 200 milliseconds for medium level
        break;
    case HARD:
        base_delay = 100; // 100 milliseconds for hard level
        break;
    default:
        base_delay = 200; // Default to medium level
        break;
    }
}

void GameModel::update() {
    snake1.move();
    if (multiplayer) {
        snake2.move();
    }

    if (snake1.getBody()[0] == food.getPosition()) {
        snake1.grow();
        score1 += 10;
        food.generate_new_position(width, height, snake1);
    }

    if (multiplayer && snake2.getBody()[0] == food.getPosition()) {
        snake2.grow();
        score2 += 10;
        food.generate_new_position(width, height, snake2);
    }

    if (snake1.check_collision(width, height) || (multiplayer && snake2.check_collision(width, height))) {
        is_running = false;
    }
}

void GameModel::reset() {
    if (multiplayer) {
        initMultiplayer();
    } else {
        initSinglePlayer();
    }
    is_running = true;
    score1 = 0;
    score2 = 0;
}

int GameModel::calculateDelay() const {
    int score = getScore1();
    int delay = base_delay - (score / 10) * 10;
    if (delay < 40) {
        delay = 40;
    }
    return delay;
}

bool GameModel::isGameOver() const {
    return !is_running;
}

int GameModel::getScore1() const {
    return score1;
}

int GameModel::getScore2() const {
    return score2;
}

int GameModel::getHeight() const {
    return height;
}

int GameModel::getWidth() const {
    return width;
}

Food GameModel::getFood() const {
    return food;
}

Snake& GameModel::getSnake1() {
    return snake1;
}

Snake& GameModel::getSnake2() {
    return snake2;
}
void GameModel::setPlayer1Name(const std::string& playerName) {
    this->player1Name = playerName;
}

void GameModel::setPlayer2Name(const std::string& playerName) {
    this->player2Name = playerName;
}

const std::string& GameModel::getPlayer1Name() const {
    return player1Name;
}

const std::string& GameModel::getPlayer2Name() const {
    return player2Name;
}