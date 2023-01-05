#include "../include/gameOverMenu.hpp"

using namespace std;
using namespace sf;

GameOverMenu::GameOverMenu(): Entity(false) {
    setName("GameOverMenu");
}

GameOverMenu::~GameOverMenu() {

}

void GameOverMenu::onSignal(const string &signal) {
    if (signal == "GameOver") {
        showSelf();
    }

}

void GameOverMenu::input(const Event &event) {

}

void GameOverMenu::draw(RenderTarget &window, RenderStates states) const {
    RectangleShape rect({500, 200});
    rect.setFillColor(Color::Red);
    window.draw(rect);
}

