#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "../../utils/Utils.hpp"
#include "constants.hpp"

class Background : public sf::Drawable {
private:
    sf::RectangleShape m_horizontalLine, m_verticalLine;

public:
    Background();
    ~Background();

    inline void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
};

#endif