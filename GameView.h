#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include "GameModel.h"
class GameView {
public:
    GameView(GameModel&model);
    void draw(sf::RenderWindow& window);
    void updateScoreText();
private:
    GameModel& model;
    sf::Font font;
    sf::Text scoreText1;
    sf::Text scoreText2;
};

#endif // GAMEVIEW_H
