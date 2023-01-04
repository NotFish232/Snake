#ifndef WALLS_HPP
#define WALLS_HPP

#include "../../utils/Utils.hpp"
#include "constants.hpp"
#include <vector>

class Walls : public sf::Entity {
private:
    sf::RectangleShape m_leftWall, m_rightWall, m_topWall, m_bottomWall;

public:
    Walls();
    ~Walls();
    void init() override;
    const std::vector<sf::FloatRect> getBounds() const override;
    inline void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
};

#endif