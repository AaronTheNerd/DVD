#include <GLFW/glfw3.h>

#include <iostream>
#include "core/exit.h"

void atn::core::exit_handler(int status, const char* message) {
  std::cout << message << std::endl;
  glfwTerminate();
  exit(status);
}