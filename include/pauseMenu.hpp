#ifndef PAUSEMENU_HPP
#define PAUSEMENU_HPP

#include "../../utils/Utils.hpp"

class PauseMenu : public sf::Entity {
public:
    PauseMenu();
    ~PauseMenu();

    const std::vector<sf::FloatRect> getBounds() const;
};

#endif