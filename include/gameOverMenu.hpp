#ifndef GAMEOVERMENU_HPP
#define GAMEOVERMENU_HPP

#include "../../utils/Utils.hpp"

class GameOverMenu: public sf::Entity {
public:
    GameOverMenu();
    ~GameOverMenu();
    void onSignal(const std::string &signal) override;
    void input(const sf::Event &event) override;
    inline void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
};

#endif