#include "include/apple.hpp"
#include "include/background.hpp"
#include "include/constants.hpp"
#include "include/snake.hpp"
#include "include/walls.hpp"

using namespace std;
using namespace sf;

int main(int argc, char **argv) {
    Background background;
    Walls walls;
    Snake snake;
    Apple apple;
    MainLoop window("Snake Game", blockSize * horizontalBlockCount, blockSize * verticalBlockCount, FPS);
    window.addDrawable(background);
    window.addEntity(walls);
    window.addEntity(snake);
    window.addEntity(apple);
    window.run();
    return 0;
}