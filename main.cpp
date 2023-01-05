#include "include/apple.hpp"
#include "include/background.hpp"
#include "include/constants.hpp"
#include "include/snake.hpp"
#include "include/walls.hpp"
#include "include/pauseMenu.hpp"
#include "include/gameOverMenu.hpp"

using namespace std;
using namespace sf;

int main(int argc, char **argv) {
    Background background;
    Walls walls;
    Snake snake;
    Apple apple;
    PauseMenu pauseMenu;
    GameOverMenu gameOverMenu;
    GameLoop game("Snake Game", blockSize * horizontalBlockCount, blockSize * verticalBlockCount, FPS);
    game.addDrawable(background);
    game.addEntity(walls);
    game.addEntity(snake);
    game.addEntity(apple);
    game.addEntity(pauseMenu);
    game.addEntity(gameOverMenu);
    game.run();
    return 0;
}