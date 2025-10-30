#include "GameController.h"


GameController::GameController(GameModel& model,GameView& gameView, MenuView& menuView,sf::RenderWindow &window)
    : model(model), gameView(gameView), menuView(menuView), window(window),
      inMenu(true),inLevelMenu(false),inLeaderBoard(false),inGameOver(false),inNumberOfPlayers(false),inEnterName(false)
{

    model.loadScores();
}

void GameController::run() {
    while (window.isOpen()) {
        if (inMenu) MainMenu();
        else if (inLevelMenu) LevelMenu();
        else if(inLeaderBoard) LeaderBoard();
        else if(inGameOver) GameOver();
        else if(inEnterName) EnterName();
        else if (inNumberOfPlayers) NumberOfPlayers();
        else Game();
    }
}

void GameController::EnterName()
{

    sf::Event event;
    menuView.drawEnterNameScreen(model.multiplayer);
    menuView.handleEvent(event);
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (menuView.isbackButtonPressed(event.mouseButton.x, event.mouseButton.y)) {model.setDifficulty(GameModel::EASY);
            inEnterName=false;
            inMenu=true;
        }

        if (menuView.isConfirmButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
            inNumberOfPlayers = false;
            inLevelMenu = true;
            model.setPlayer1Name(menuView.getPlayerName1());
            model.setPlayer2Name(menuView.getPlayerName2());
        }
    }
}

void GameController::NumberOfPlayers()
{
    menuView.draw_number_of_players_screen();
    sf::Event event;
    menuView.handleEvent(event);
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (menuView.isbackButtonPressed(event.mouseButton.x, event.mouseButton.y)) {model.setDifficulty(GameModel::EASY);
            inNumberOfPlayers=false;
            inMenu=true;
        }

        if (menuView.isOnePlayerButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
            inNumberOfPlayers = false;
            model.multiplayer = false;
            inEnterName=true;
        }

        if (menuView.isTwoPlayersButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
            inNumberOfPlayers = false;
            model.multiplayer = true;
            inEnterName=true;
        }
    }
}

void GameController::LevelMenu()
{
    menuView.draw_level();
    sf::Event event;
    menuView.handleEvent(event);
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (menuView.isbackButtonPressed(event.mouseButton.x, event.mouseButton.y)) {model.setDifficulty(GameModel::EASY);
            inLevelMenu=false;
            inNumberOfPlayers=false;
            inMenu=true;
            inEnterName=false;
        }

        if (menuView.isEasyButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
           model.setDifficulty(GameModel::EASY);
            inLevelMenu=false;
            inEnterName=false;

        }

        if (menuView.isMediumButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
            model.setDifficulty(GameModel::MEDIUM);
            inLevelMenu=false;
            inEnterName=false;
        }

        if (menuView.isHardButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
            model.setDifficulty(GameModel::HARD);
            inLevelMenu=false;
            inEnterName=false;
        }

        model.reset();
    }
}

void GameController::LeaderBoard()
{   menuView.drawScores(model.getScores());
    sf::Event event;
    menuView.handleEvent(event);

    while (window.pollEvent(event))
    {   if (menuView.isbackButtonPressed(event.mouseButton.x, event.mouseButton.y)) {model.setDifficulty(GameModel::EASY);
        inLeaderBoard=false;
        inMenu=true;
    }
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void GameController::GameOver()
{
    menuView.drawGameOverScreen(model.getScore1(),model.getScore2());
    sf::Event event;
    menuView.handleEvent(event);

    while (window.pollEvent(event))
    {   if (menuView.isbackButtonPressed(event.mouseButton.x, event.mouseButton.y)) {model.setDifficulty(GameModel::EASY);
        inGameOver=false;
        inMenu=true;
    }
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void GameController::MainMenu() {
    menuView.draw_start();
    sf::Event event;
    menuView.handleEvent(event);
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (menuView.isPlayButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
                    inMenu = false;
                    inNumberOfPlayers=true;
                }

                if (menuView.isLeaderBoardButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
                    inMenu = false;
                    inLeaderBoard=true;

                }
                // Проверяем нажатие кнопки Exit
                if (menuView.isExitButtonPressed(event.mouseButton.x, event.mouseButton.y)) {
                    window.close();
                }
            }
        }
    }
}

void GameController::Game()
{
    processInput(window);
    if (model.isGameOver()) {
        model.updateScores(model.getScore1());
        inGameOver = true;
    }
    model.update();
    gameView.updateScoreText();

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../images/grass.jpg"))
    {
        return;
    }
    sf::Sprite background(backgroundTexture);


    background.setTexture(backgroundTexture);

    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();


    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;


    background.setScale(scaleX, scaleY);
    window.clear(sf::Color::Black);
    window.draw(background);



    gameView.draw(window);
    window.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(model.calculateDelay()));
}

void GameController::processInput(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                model.is_running = false;
                inMenu = false;
            }

            // Обработка ввода первого игрока
            processPlayerInput(event, model.getSnake1(), sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D);

            // Обработка ввода второго игрока
            processPlayerInput(event, model.getSnake2(), sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right);
        }
    }
}

void GameController::processPlayerInput(sf::Event event, Snake& snake, sf::Keyboard::Key up, sf::Keyboard::Key down, sf::Keyboard::Key left, sf::Keyboard::Key right) {
    if (event.key.code == up && snake.getDirection() != 'D') snake.setDirection('U');
    if (event.key.code == down && snake.getDirection() != 'U') snake.setDirection('D');
    if (event.key.code == left && snake.getDirection() != 'R') snake.setDirection('L');
    if (event.key.code == right && snake.getDirection() != 'L') snake.setDirection('R');
}
