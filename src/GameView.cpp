#include "GameView.h"

GameView::GameView(GameModel& model) :model(model){
    if (!font.loadFromFile("../troika.otf")) {
 return;
    }
    scoreText1.setFont(font);
    scoreText1.setCharacterSize(34);
    scoreText1.setFillColor(sf::Color::White);
    scoreText1.setPosition(10, 10);

    scoreText2.setFont(font);
    scoreText2.setCharacterSize(34);
    scoreText2.setFillColor(sf::Color::White);
    scoreText2.setPosition(100, 10);


    updateScoreText();
}

void GameView::draw(sf::RenderWindow& window) {
    sf::Texture bodyTexture1;
    if (!bodyTexture1.loadFromFile("../images/snake_green_blob_32.png")) {

        return;
    }
    sf::Sprite bodySprite1(bodyTexture1);

    for (const auto& part : model.getSnake1().getBody()) {
        bodySprite1.setPosition(part.first * 20, part.second * 20);
        window.draw(bodySprite1);
    }

    sf::Texture headTexture1;
    if (!headTexture1.loadFromFile("../images/snake_green_head_32.png")) {

        return;
    }
    sf::Sprite headSprite1(headTexture1);
    auto headPart1 = model.getSnake1().getBody().front();
    headSprite1.setPosition(headPart1.first * 20, headPart1.second * 20);
    window.draw(headSprite1);


    if (model.multiplayer) {
        sf::Texture bodyTexture2;
        if (!bodyTexture2.loadFromFile("../images/snake_yellow_blob_32.png")) {

            return;
        }
        sf::Sprite bodySprite2(bodyTexture2);

        for (const auto& part : model.getSnake2().getBody()) {
            bodySprite2.setPosition(part.first * 20, part.second * 20);
            window.draw(bodySprite2);
        }

        sf::Texture headTexture2;
        if (!headTexture2.loadFromFile("../images/snake_yellow_head_32.png")) {

            return;
        }
        sf::Sprite headSprite2(headTexture2);
        auto headPart2 = model.getSnake2().getBody().front();
        headSprite2.setPosition(headPart2.first * 20, headPart2.second * 20);
        window.draw(headSprite2);


        scoreText2.setString(model.getPlayer2Name() + ": " + std::to_string(model.getScore2()));
        scoreText2.setPosition(1000, 10);
        window.draw(scoreText2);
    }

    sf::Texture foodTexture;
    if (!foodTexture.loadFromFile("../images/apple_alt_32.png")) {

        return;
    }
    sf::Sprite foodSprite(foodTexture);
    auto foodPosition = model.getFood().getPosition();
    foodSprite.setPosition(foodPosition.first * 20, foodPosition.second * 20);
    window.draw(foodSprite);

    window.draw(scoreText1);
}

void GameView::updateScoreText() {
    scoreText1.setString(model.getPlayer1Name() + ": " + std::to_string(model.getScore1()));
    if (model.multiplayer) {
        scoreText2.setString(model.getPlayer2Name() + ": " + std::to_string(model.getScore2()));
    }
}
