#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <iostream>
#include "core/exit.h"
#include "game.h"

int main(int argc, char** argv) {
  if (!glfwInit()) {
    std::cout << "Could not initialize GLFW" << std::endl;
    atn::core::exit_handler(EXIT_FAILURE);
  }

  atn::Game game{};
  game.run();

  atn::core::exit_handler(EXIT_SUCCESS);
}
