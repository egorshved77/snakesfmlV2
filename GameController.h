#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "GameModel.h"
#include "GameView.h"
#include "MenuView.h"
#include <iostream>
#include <thread>
#include <chrono>

class GameController {
public:
    GameController(GameModel& model, GameView& gameView, MenuView& menuView,sf::RenderWindow &window);
    void run();

private:
    void MainMenu();
    void LevelMenu();
    void Game();
    void LeaderBoard();
    void NumberOfPlayers();
    void EnterName();
    void GameOver();
    void processInput(sf::RenderWindow& window);
    void processPlayerInput(sf::Event event, Snake& snake, sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key left, sf::Keyboard::Key right);

    GameModel& model;
    GameView& gameView;
    MenuView& menuView;
    sf::RenderWindow& window;
    bool inMenu;
    bool inLevelMenu;
    bool gameFinished = false;
    bool inLeaderBoard;
    bool inGameOver;
    bool inNumberOfPlayers;
    bool inEnterName;

};

#endif // GAMECONTROLLER_H
