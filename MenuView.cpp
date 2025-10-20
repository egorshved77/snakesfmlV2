#include "MenuView.h"

MenuView::MenuView(sf::RenderWindow& window) : window(window)
{
    if (!font.loadFromFile("../troika.otf"))
    {
  return;
    }

    titleText.setFont(font);
    titleText.setString("SNAKE");
    titleText.setCharacterSize(50);
    titleText.setFillColor(sf::Color::White);
    sf::FloatRect titleBounds = titleText.getLocalBounds();
    titleText.setOrigin(titleBounds.left + titleBounds.width / 2.0f, titleBounds.top + titleBounds.height / 2.0f);
    titleText.setPosition(window.getSize().x / 2.0f, 100);

    inputText.setFont(font);
    inputText.setCharacterSize(24);
    inputText.setFillColor(sf::Color::Green);
    inputText.setPosition(100.f, 100.f);



    developed.setFont(font);
    developed.setString("developed by Yahor Shved");
    developed.setCharacterSize(30);
    developed.setFillColor(sf::Color::White);
    developed.setPosition(830, 760);

    NumberoflayersText.setFont(font);
    NumberoflayersText.setString("Choose number of players");
    NumberoflayersText.setCharacterSize(60);
    NumberoflayersText.setFillColor(sf::Color::Black);
    sf::FloatRect choosenumber = NumberoflayersText.getLocalBounds();
    NumberoflayersText.setOrigin(choosenumber.left + choosenumber.width / 2.0f, choosenumber.top + choosenumber.height / 2.0f);
    NumberoflayersText.setPosition(window.getSize().x / 2.0f, 120);



    levelchangeText.setFont(font);
    levelchangeText.setString("Select level");
    levelchangeText.setCharacterSize(60);
    levelchangeText.setFillColor(sf::Color(41,159,64));
    sf::FloatRect levelBounds = levelchangeText.getLocalBounds();
    levelchangeText.setOrigin(levelBounds.left + levelBounds.width / 2.0f, levelBounds.top + levelBounds.height / 2.0f);
    levelchangeText.setPosition(window.getSize().x / 2.0f, 100);


    playButton.setFont(font);
    playButton.setString("Play");
    playButton.setCharacterSize(40);
    playButton.setFillColor(sf::Color::White);
    playButton.setPosition(100, 200);

    leaderboardButton.setFont(font);
    leaderboardButton.setString("Leaderboard");
    leaderboardButton.setCharacterSize(40);
    leaderboardButton.setFillColor(sf::Color::White);
    leaderboardButton.setPosition(100, 250);


    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setCharacterSize(40);
    exitButton.setFillColor(sf::Color::White);
    exitButton.setPosition(100, 300);

    easyButton.setFont(font);
    easyButton.setString("Easy");
    easyButton.setCharacterSize(60);
    easyButton.setFillColor(sf::Color::Black);
    easyButton.setPosition(500, 250);

    mediumButton.setFont(font);
    mediumButton.setString("Medium");
    mediumButton.setCharacterSize(60);
    mediumButton.setFillColor(sf::Color(41,159,64));
    mediumButton.setPosition(500, 350);

    hardButton.setFont(font);
    hardButton.setString("Hard");
    hardButton.setCharacterSize(60);
    hardButton.setFillColor(sf::Color(41,159,64));
    hardButton.setPosition(500, 450);


    backButton.setFont(font);
    backButton.setString("Back");
    backButton.setCharacterSize(40);
    backButton.setFillColor(sf::Color::White);
    backButton.setPosition(20, 20);


    scoreText.setFont(font);
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(sf::Color::White);

    gameOverText.setFont(font);
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("Game Over");
    sf::FloatRect textBounds = gameOverText.getLocalBounds();
    gameOverText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    gameOverText.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

    finalScoreText.setFont(font);
    finalScoreText.setCharacterSize(24);
    finalScoreText.setFillColor(sf::Color::White);
    finalScoreText.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f + 50);

    OnePlayer.setFont(font);
    OnePlayer.setString("1 Player");
    OnePlayer.setCharacterSize(60);
    OnePlayer.setFillColor(sf::Color::Black);
    OnePlayer.setPosition(500, 280);

    TwoPLayers.setFont(font);
    TwoPLayers.setString("2 Players");
    TwoPLayers.setCharacterSize(60);
    TwoPLayers.setFillColor(sf::Color::Black);
    TwoPLayers.setPosition(500, 400);



    nameInputField.setSize(sf::Vector2f(300, 40));
    nameInputField.setFillColor(sf::Color::White);
    nameInputField.setPosition(250, 140);

    confirmButton.setSize(sf::Vector2f(100, 40));
    confirmButton.setFillColor(sf::Color::Green);
    confirmButton.setPosition(350, 200);



    confirmButtonText.setFont(font);
    confirmButtonText.setCharacterSize(18);
    confirmButtonText.setFillColor(sf::Color::White);
    confirmButtonText.setString("Confirm");
    confirmButtonText.setPosition(confirmButton.getPosition().x + 10, confirmButton.getPosition().y + 10);


}


void MenuView::draw_start()
{   sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../images/background.jpg"))
    {
        return;
    }
    window.clear(sf::Color::Black);
    sf::Sprite background(backgroundTexture);

    background.setTexture(backgroundTexture);

    // Получаем размеры окна и текстуры
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();

    // Рассчитываем коэффициенты масштабирования
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    // Устанавливаем масштаб для спрайта
    background.setScale(scaleX, scaleY);
    window.draw(background);
    window.draw(player1Text);
    window.draw(player2Text);
    window.draw(titleText);
    window.draw(developed);
    window.draw(playButton);
    window.draw(leaderboardButton);
    window.draw(exitButton);
    window.display();
}

void MenuView::draw_number_of_players_screen()
{   sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../images/multiplayer.jpg"))
    {
        return;
    }
    window.clear(sf::Color::Black);
    sf::Sprite background(backgroundTexture);

    background.setTexture(backgroundTexture);

    // Получаем размеры окна и текстуры
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();

    // Рассчитываем коэффициенты масштабирования
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    // Устанавливаем масштаб для спрайта
    background.setScale(scaleX, scaleY);
    window.draw(background);
    window.draw(NumberoflayersText);
    window.draw(OnePlayer);
    window.draw(TwoPLayers);
    window.draw(backButton);
    window.display();
}



void MenuView::draw_level()
{

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../images/changelevel.jpg"))
    {
        return;
    }
    sf::Sprite background(backgroundTexture);
    window.clear(sf::Color::Black);

    background.setTexture(backgroundTexture);

    // Получаем размеры окна и текстуры
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();

    // Рассчитываем коэффициенты масштабирования
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    // Устанавливаем масштаб для спрайта
    background.setScale(scaleX, scaleY);

    window.draw(background);
    window.draw(levelchangeText);
    window.draw(easyButton);
    window.draw(mediumButton);
    window.draw(hardButton);
    window.draw(backButton);
    window.display();
}


void MenuView::drawGameOverScreen(int score1,int score2) {
    window.clear(sf::Color::Black);
    window.draw(backButton);
    window.draw(gameOverText);

    finalScoreText.setString(getPlayerName1()+" "+std::to_string(score1)+"\nPlayer2:"+std::to_string(score2));
    sf::FloatRect textBounds = finalScoreText.getLocalBounds();
    finalScoreText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    finalScoreText.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f + 50);

    window.draw(finalScoreText);

    window.display();
}

void MenuView::drawScores(const std::vector<std::pair<std::string, int>>& scores)
{ sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../images/leaderboard.jpg"))
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

    float yPos = 100.0f;
    int i=0;
    for (const auto& score : scores) {
        scoreText.setString(std::to_string(i + 1) + ". " +score.first + "  " + std::to_string(score.second));
        scoreText.setPosition(100.0f, yPos);
        window.draw(scoreText);
        yPos += 30.0f; // Adjust vertical spacing as needed
        i++;
    }
    window.draw(backButton);
    window.display();
}

bool MenuView::isPlayButtonPressed(int x, int y) const
{
    return playButton.getGlobalBounds().contains(x, y);
}

bool MenuView::isbackButtonPressed(int x, int y) const
{
    return backButton.getGlobalBounds().contains(x, y);
}

bool MenuView::isExitButtonPressed(int x, int y) const
{
    return exitButton.getGlobalBounds().contains(x, y);
}

bool MenuView::isMediumButtonPressed(int x, int y) const
{
    return mediumButton.getGlobalBounds().contains(x, y);
}

bool MenuView::isHardButtonPressed(int x, int y) const
{
    return hardButton.getGlobalBounds().contains(x, y);
}

bool MenuView::isEasyButtonPressed(int x, int y) const
{
    return easyButton.getGlobalBounds().contains(x, y);
}

bool MenuView::isLeaderBoardButtonPressed(int x, int y) const
{
    return leaderboardButton.getGlobalBounds().contains(x, y);
}

bool MenuView::isOnePlayerButtonPressed(int x, int y) const
{
    return OnePlayer.getGlobalBounds().contains(x, y);
}

bool MenuView::isTwoPlayersButtonPressed(int x, int y) const
{
    return TwoPLayers.getGlobalBounds().contains(x, y);
}

bool MenuView::isConfirmButtonPressed(int x, int y) const{
    return confirmButton.getGlobalBounds().contains(x, y);
}

void MenuView::updateButtonColor(sf::Text& button, bool isHovered)
{
    if (isHovered)
    {
        button.setFillColor(sf::Color::Yellow);
    }
    else
    {
        button.setFillColor(sf::Color::White);
    }
}

void MenuView::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved)
    {
        int mouseX = event.mouseMove.x;
        int mouseY = event.mouseMove.y;
        updateButtonColor(playButton, isPlayButtonPressed(mouseX, mouseY));
        updateButtonColor(exitButton, isExitButtonPressed(mouseX, mouseY));
        updateButtonColor(easyButton, isEasyButtonPressed(mouseX, mouseY));
        updateButtonColor(mediumButton, isMediumButtonPressed(mouseX, mouseY));
        updateButtonColor(hardButton, isHardButtonPressed(mouseX, mouseY));
        updateButtonColor(leaderboardButton, isLeaderBoardButtonPressed(mouseX, mouseY));
        updateButtonColor(backButton, isbackButtonPressed(mouseX, mouseY));
        updateButtonColor(OnePlayer, isOnePlayerButtonPressed(mouseX, mouseY));
        updateButtonColor(TwoPLayers, isTwoPlayersButtonPressed(mouseX, mouseY));
    }
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128 && std::isprint(static_cast<char>(event.text.unicode))&& event.text.unicode != '\b') {
            playerName += static_cast<char>(event.text.unicode);
        }
    }    else if (event.text.unicode == '\b' && !playerName.empty()) // Handle backspace
    {
        playerName.pop_back();

    }

}

void MenuView::drawEnterNameScreen(bool multiplayer) {

    sf::Text enterNameText;
    sf::Text playerNameText;
    enterNameText.setFont(font);
    enterNameText.setCharacterSize(24);
    enterNameText.setFillColor(sf::Color::White);
    enterNameText.setString("Enter your name:");
    enterNameText.setPosition(100, 100);


    playerNameText.setFont(font);
    playerNameText.setCharacterSize(24);
    playerNameText.setFillColor(sf::Color::White);
    playerNameText.setPosition(100, 150);


    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../images/leaderboard.jpg"))
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
    if(multiplayer)
    {
        window.clear(sf::Color::Black);
        window.draw(background);

        // Отрисовка кнопок и текстовых полей
        window.draw(backButton);
        window.draw(enterNameText);
        window.draw(confirmButton);
        window.draw(confirmButtonText);
        window.draw(inputText);

        playerNameText.setString("Player name: " + playerName);
        window.draw(playerNameText);

        window.display();
    }

    else if(!multiplayer)
    {

        window.clear(sf::Color::Black);
        window.draw(background);

        // Отрисовка кнопок и текстовых полей
        window.draw(backButton);
        window.draw(enterNameText);
        window.draw(confirmButton);
        window.draw(confirmButtonText);
        window.draw(inputText);

        playerNameText.setString("Player name: " + playerName);
        window.draw(playerNameText);

        window.display();

    }
}

std::string MenuView::getPlayerName1() {
    return playerName;
}

std::string MenuView::getPlayerName2() {
    return playerName;
}



