#include "game.h"

static void key_callback(
    GLFWwindow* window, int key, int scancode, int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

atn::Game::Game()
    : window(640, 480),
      object_manager(),
      renderer(),
      camera(glm::vec2{640, 480}) {
  this->window.key_callback(key_callback);
}

void atn::Game::tick() {
  this->window.begin_render();

  this->renderer.update(this->object_manager);
  this->renderer.render(this->object_manager, this->window);

  this->window.end_render();
}

void atn::Game::run() {
  while (!this->window.should_close()) {
    this->tick();
  }
}