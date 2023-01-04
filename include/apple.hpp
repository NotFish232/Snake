#ifndef APPLE_HPP
#define APPLE_HPP

#define TEXTURE_PATH "assets/apple.png"

#include "../../utils/Utils.hpp"
#include "constants.hpp"
#include <random>

class Apple : public sf::Entity {
private:
    sf::Texture m_texture;
    std::random_device m_dev;
    std::mt19937 m_rng;
    std::uniform_int_distribution<std::mt19937::result_type> m_xDist, m_yDist;

    void placeRandom();

public:
    Apple();
    ~Apple();

    void init() override;
    void onCollision(const sf::Entity &entity) override;
};

#endif