#include "../include/snake.hpp"

using namespace std;
using namespace sf;

Snake::Snake() {
    setName("snake");
}

Snake::~Snake() {
}

void Snake::init() {
    RectangleShape head({blockSize, blockSize});
    Vector2i center = {horizontalBlockCount / 2, verticalBlockCount / 2};
    head.setPosition((Vector2f)(blockSize * center));
    head.setFillColor(Color::Blue);
    m_bodyParts.push_back(head);

    m_velocity = {0, 0};

    m_elapsed = 0;
}

void Snake::input(const sf::Event &event) {
    switch (event.type) {
    case Event::KeyPressed:
        switch (event.key.code) {
        case Keyboard::Left:
            m_velocity = {-1, 0};
            break;
        case Keyboard::Right:
            m_velocity = {1, 0};
            break;
        case Keyboard::Up:
            m_velocity = {0, -1};
            break;
        case Keyboard::Down:
            m_velocity = {0, 1};
            break;
        default:
            break;
        }
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
        m_bodyParts[i].setPosition(m_bodyParts[i - 1].getPosition());
    }

    auto &front = m_bodyParts.front();
    auto currentPosition = front.getPosition();
    front.setPosition(currentPosition + blockSize * m_velocity);
}

void Snake::onCollision(const Entity &entity) {
    if (entity.getName() == "apple") {
        grow();
    } else if (entity.getName() == "walls") {
        sendSignal("snakeDied");
        std::cout << "hi \n";
        exit(1);
    }
}

const vector<FloatRect> Snake::getBounds() const {
    vector<FloatRect> bounds;
    for (const auto &bodyPart : m_bodyParts) {
        bounds.push_back(bodyPart.getGlobalBounds());
    }
    return bounds;
}

void Snake::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (const auto &bodyPart : m_bodyParts) {
        window.draw(bodyPart);
    }
}

void Snake::grow() {
    auto last = m_bodyParts.back();
    last.setPosition(last.getPosition() - blockSize * m_velocity);
    last.setFillColor(Color::Green);
    m_bodyParts.push_back(last);
}