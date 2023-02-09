#include <GLFW/glfw3.h>

#include "core/exit.h"

void atn::core::exit_handler(int status) {
  glfwTerminate();
  exit(status);
}