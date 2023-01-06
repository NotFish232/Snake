#include "../include/gameOverMenu.hpp"

using namespace std;
using namespace sf;

void GameOverMenu::onRestartClicked() {
    emitSignal("RestartGame");
}

void GameOverMenu::onExitClicked() {
    exit(0);
}

GameOverMenu::GameOverMenu() : Entity(false) {
    setName("GameOverMenu");
}

GameOverMenu::~GameOverMenu() {
}

void GameOverMenu::init() {
    if (!m_font.loadFromFile(FONT_PATH)) {
        exit(1);
    }

    m_prompt.setSize({0.75 * windowWidth, 0.75 * windowHeight});
    m_prompt.setFillColor(Color(201, 201, 201));
    m_prompt.setOrigin(0.5f * m_prompt.getLocalBounds().width, 0.5f * m_prompt.getLocalBounds().height);
    m_prompt.setPosition({0.5 * windowWidth, 0.5 * windowHeight});

    m_title.setFont(m_font);
    m_title.setString("Game Over");
    m_title.setFillColor(Color::Black);
    m_title.setOrigin({0.5f * m_title.getLocalBounds().width, 0.5f * m_title.getLocalBounds().height});
    m_title.setPosition({m_prompt.getPosition().x, m_prompt.getPosition().y - 0.3f * windowHeight});

    m_scoreText.setFont(m_font);
    m_scoreText.setString("Score: 0");
    m_scoreText.setFillColor(Color::Black);
    m_scoreText.setOrigin({0.5f * m_scoreText.getLocalBounds().width, 0.5f * m_scoreText.getLocalBounds().height});
    m_scoreText.setPosition({m_prompt.getPosition().x, m_prompt.getPosition().y - 0.1f * windowHeight});

    m_restartButton.setSize({0.1 * windowWidth, 0.1 * windowHeight});
    m_restartButton.setFont(m_font);
    m_restartButton.setText("Restart");
    m_restartButton.setOrigin(0.5f * m_restartButton.getSize());
    m_restartButton.setPosition({m_prompt.getPosition().x - 0.15f * windowWidth, m_prompt.getPosition().y + 0.3f * windowHeight});
    m_restartButton.setOnClickCallback(bind(&GameOverMenu::onRestartClicked, this));

    m_exitButton.setSize({0.1 * windowWidth, 0.1 * windowHeight});
    m_exitButton.setFont(m_font);
    m_exitButton.setText("Exit");
    m_exitButton.setOrigin(0.5f * m_exitButton.getSize());
    m_exitButton.setPosition({m_prompt.getPosition().x + 0.15f * windowWidth, m_prompt.getPosition().y + 0.3f * windowHeight});
    m_exitButton.setOnClickCallback(bind(&GameOverMenu::onExitClicked, this));

    m_score = 0;
}

void GameOverMenu::onSignal(const string &signal) {
    if (signal == "GameOver") {
        showSelf();
    } else if (signal == "AteApple") {
        m_scoreText.setString("Score: " + to_string(++m_score));
    } else if (signal == "RestartGame") {
        hideSelf();
        m_score = 0;
    }
}

void GameOverMenu::input(const Event &event) {
    m_restartButton.input(event);
    m_exitButton.input(event);
}

const vector<FloatRect> GameOverMenu::getBounds() const {
    return {};
}

void GameOverMenu::draw(RenderTarget &window, RenderStates states) const {
    window.draw(m_prompt);
    window.draw(m_title);
    window.draw(m_scoreText);
    window.draw(m_restartButton);
    window.draw(m_exitButton);
}
