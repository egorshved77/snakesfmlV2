#ifndef MENUVIEW_H
#define MENUVIEW_H
#include "GameModel.h"
#include <SFML/Graphics.hpp>

class MenuView
{
public:

    MenuView(sf::RenderWindow& window);

    void draw_start();
    void draw_level();
    void draw_number_of_players_screen();
    void drawGameOverScreen(int score1,int score2);

    void handleEvent(const sf::Event& event);

    bool isPlayButtonPressed(int x, int y) const;
    bool isExitButtonPressed(int x, int y) const;


    void drawScores(const std::vector<std::pair<std::string, int>>& scores);

    bool isMediumButtonPressed(int mouseX, int mouseY) const;
    bool isHardButtonPressed(int mouseX, int mouseY) const;
    bool isEasyButtonPressed(int mouseX, int mouseY) const;
    bool isLeaderBoardButtonPressed(int x, int y) const;
    bool isbackButtonPressed(int x, int y) const;
    bool isOnePlayerButtonPressed(int mouseX, int mouseY) const;
    bool isTwoPlayersButtonPressed(int mouseX, int mouseY) const;

    void drawEnterNameScreen(bool multiplayer);
    std::string getPlayerName1();
    std::string getPlayerName2();


    bool isConfirmButtonPressed(int x, int y) const;
private:
    sf::Text confirmButtonText;
    sf::Text titleText;
    sf::Text developed;
    sf::Text NumberoflayersText;
    sf::Text levelchangeText;
    sf::Text scoreText;
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text playButton;
    sf::Text leaderboardButton;
    sf::Text exitButton;
    sf::Text easyButton;
    sf::Text mediumButton;
    sf::Text hardButton;
    sf::Text backButton;
    sf::Text gameOverText;
    sf::Text finalScoreText;

    sf::Text OnePlayer;
    sf::Text TwoPLayers;

    sf::Text player1Text;
    sf::Text player2Text;

    sf::Text playerNamePrompt;
    sf::Text inputText;
    std::string playerNameInput;
    bool inputActive;

    std::string playerName;
    sf::RectangleShape nameInputField;
    sf::RectangleShape confirmButton;
    bool isEnteringName;



    void updateButtonColor(sf::Text& button, bool isHovered);
};

#endif // MENUVIEW_H
