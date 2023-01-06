#include "../include/pauseMenu.hpp"

using namespace std;
using namespace sf;

PauseMenu::PauseMenu() : Entity(false) {
    setName("PauseMenu");
}

PauseMenu::~PauseMenu() {
}

const vector<FloatRect> PauseMenu::getBounds() const {
    return {};
}