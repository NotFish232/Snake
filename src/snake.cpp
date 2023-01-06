#include "../include/snake.hpp"

using namespace std;
using namespace sf;

bool Snake::collidesWithSelf() const {
    auto &front = m_bodyParts.front();
    for (int i = 1; i < m_bodyParts.size(); ++i) {
        if (front == m_bodyParts[i]) {
            return true;
        }
    }
    return false;
}

Snake::Snake() {
    setName("Snake");
}

Snake::~Snake() {
}

void Snake::init() {
    m_bodyParts.push_back({(int)(horizontalBlockCount / 2), (int)(verticalBlockCount / 2)});

    m_velocity = {0, 0};

    m_elapsed = 0;
}

void Snake::input(const sf::Event &event) {
    switch (event.type) {
    case Event::KeyPressed:
        switch (event.key.code) {
        case Keyboard::A:
        case Keyboard::Left:
            if (m_velocity.x != 1) {
                m_velocity = {-1, 0};
            }
            break;
        case Keyboard::D:
        case Keyboard::Right:
            if (m_velocity.x != -1) {
                m_velocity = {1, 0};
            }
            break;
        case Keyboard::W:
        case Keyboard::Up:
            if (m_velocity.y != 1) {
                m_velocity = {0, -1};
            }
            break;
        case Keyboard::S:
        case Keyboard::Down:
            if (m_velocity.y != -1) {
                m_velocity = {0, 1};
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void Snake::process(float delta) {
    m_elapsed += delta;
    if (m_elapsed < 1 / moveSpeed) {
        return;
    }

    m_elapsed = 0;

    for (int i = m_bodyParts.size() - 1; i > 0; --i) {
        m_bodyParts[i] = m_bodyParts[i - 1];
    }

    m_bodyParts.front() += m_velocity;

    if (collidesWithSelf()) {
        emitSignal("GameOver");
    }
}

void Snake::onCollision(const Entity &entity) {
    if (entity.getName() == "Apple") {
        emitSignal("AteApple");
        grow();
    } else if (entity.getName() == "Walls") {
        emitSignal("GameOver");
    }
}

void Snake::onSignal(const string &signal) {
    if (signal == "GameOver") {
        hideSelf();
    } else if (signal == "RestartGame") {
        m_bodyParts.clear();
        init();
        showSelf();
    }
}

const vector<FloatRect> Snake::getBounds() const {
    vector<FloatRect> bounds;
    for (const auto &bodyPart : m_bodyParts) {
        FloatRect bound{(float)blockSize * bodyPart.x, (float)blockSize * bodyPart.y, blockSize, blockSize};
        bounds.push_back(bound);
    }
    return bounds;
}

void Snake::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < m_bodyParts.size(); ++i) {
        RectangleShape rect;
        rect.setSize({blockSize, blockSize});
        rect.setPosition((float)blockSize * m_bodyParts[i]);
        if (i == 0) {
            rect.setFillColor(Color::Blue);
        } else {
            rect.setFillColor(Color::Green);
        }
        window.draw(rect);
    }
}

void Snake::grow() {
    auto last = m_bodyParts.back();
    last -= blockSize * m_velocity;
    m_bodyParts.push_back(last);
}