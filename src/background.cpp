#include "../include/background.hpp"

using namespace std;
using namespace sf;

Background::Background() {
    m_horizontalLine.setSize({blockSize * horizontalBlockCount, 1});
    m_verticalLine.setSize({1, blockSize * verticalBlockCount});

    m_horizontalLine.setOrigin({0, m_horizontalLine.getLocalBounds().height / 2});
    m_verticalLine.setOrigin({m_verticalLine.getLocalBounds().width / 2, 0});

    m_horizontalLine.setFillColor(Color::Black);
    m_verticalLine.setFillColor(Color::Black);
}

Background::~Background() {
}

void Background::draw(RenderTarget &window, RenderStates states) const {
    window.clear(Color(169, 169, 169));

    for (float i = 0; i < verticalBlockCount; ++i) {
        auto rect(m_horizontalLine);
        rect.setPosition({0, blockSize * i});
        window.draw(rect);
    }
    
    for (float i = 0; i < horizontalBlockCount; ++i) {
        auto rect(m_verticalLine);
        rect.setPosition({blockSize * i, 0});
        window.draw(rect);
    }
}