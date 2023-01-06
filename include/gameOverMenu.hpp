#ifndef GAMEOVERMENU_HPP
#define GAMEOVERMENU_HPP

#include "../../utils/Utils.hpp"
#include "constants.hpp"

#define FONT_PATH "assets/font.ttf"

class GameOverMenu : public sf::Entity {
private:
    sf::RectangleShape m_prompt;
    sf::Font m_font;
    sf::Text m_title, m_scoreText;
    sf::Button m_restartButton, m_exitButton;
    int m_score;

    void onRestartClicked();
    void onExitClicked();

public:
    GameOverMenu();
    ~GameOverMenu();
    void init() override;
    void onSignal(const std::string &signal) override;
    void input(const sf::Event &event) override;
    const std::vector<sf::FloatRect> getBounds() const override;
    inline void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
};

#endif