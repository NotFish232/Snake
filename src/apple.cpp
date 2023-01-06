#include "../include/apple.hpp"
#include <iostream>

using namespace std;
using namespace sf;

void Apple::placeRandom() {
    auto snake = getEntity("Snake");

    do {
        setPosition({blockSize * (float)m_xDist(m_rng), blockSize * (float)m_yDist(m_rng)});

    } while (collidesWith(*snake));
}

Apple::Apple() : m_rng(m_dev()), m_xDist(0, horizontalBlockCount - 1), m_yDist(0, verticalBlockCount - 1) {
    setName("Apple");
}

Apple::~Apple() {
}

void Apple::init() {
    if (!m_texture.loadFromFile(TEXTURE_PATH)) {
        exit(1);
    }

    setTexture(m_texture);
    auto size = getLocalBounds();
    Vector2f scale{blockSize / size.width, blockSize / size.height};
    setScale(scale);

    placeRandom();
}

void Apple::onCollision(const sf::Entity &entity) {
    if (entity.getName() == "Snake") {
        placeRandom();
    }
}

void Apple::onSignal(const string &signal) {
    if (signal == "GameOver") {
        hideSelf();
    } else if (signal == "RestartGame") {
        placeRandom();
        showSelf();
    }
}
