#ifndef SNAKE_CPP
#define SNAKE_CPP

#include "../../utils/Utils.hpp"
#include "constants.hpp"
#include <vector>

class Snake : public sf::Entity {
private:
    const constexpr static float moveSpeed = 10;
    std::vector<sf::RectangleShape> m_bodyParts;
    sf::Vector2i m_velocity;
    float m_elapsed;

public:
    Snake();
    ~Snake();

    void init() override;
    void input(const sf::Event &event) override;
    void process(float delta) override;
    void onCollision(const Entity &entity) override;
    const std::vector<sf::FloatRect> getBounds() const override;
    inline void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
    void grow();
};

#endif