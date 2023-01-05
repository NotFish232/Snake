#include "../include/walls.hpp"

using namespace std;
using namespace sf;

Walls::Walls() {
    setName("Walls");
}

Walls::~Walls() {
}

void Walls::init() {
    m_leftWall.setSize({1, blockSize * verticalBlockCount});
    m_rightWall.setSize({1, blockSize * verticalBlockCount});
    m_topWall.setSize({blockSize * horizontalBlockCount, 1});
    m_bottomWall.setSize({blockSize * horizontalBlockCount, 1});


    m_leftWall.setPosition(-1, 0);
    m_rightWall.setPosition(blockSize * horizontalBlockCount, 0);
    m_topWall.setPosition(0, -1);
    m_bottomWall.setPosition(0, blockSize * verticalBlockCount);
}

const vector<FloatRect> Walls::getBounds() const {
    return {m_leftWall.getGlobalBounds(), m_rightWall.getGlobalBounds(),
            m_topWall.getGlobalBounds(), m_bottomWall.getGlobalBounds()};
}

void Walls::draw(RenderTarget &window, RenderStates states) const {
    window.draw(m_leftWall);
    window.draw(m_rightWall);
    window.draw(m_topWall);
    window.draw(m_bottomWall);
}