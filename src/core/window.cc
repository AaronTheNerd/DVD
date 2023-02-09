#include "core/exit.h"
#include "core/window.h"
#include <glad/gl.h>
#include <stdio.h>
#include <stdlib.h>

atn::core::Window::Window(uint width, uint height) : window() {
  // Set error callback
  glfwSetErrorCallback(window_error_callback);

  // Set OpenGL version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // Create window
  this->window = glfwCreateWindow(width, height, "DVD", NULL, NULL);

  // Check that window was created successfully
  if (!this->window) {
    atn::core::exit_handler(EXIT_FAILURE, "Window failed to load");
  }
  // Make context current
  glfwMakeContextCurrent(this->window);
  glfwSetFramebufferSizeCallback(this->window, window_size_callback);
  gladLoadGL(glfwGetProcAddress);
  glEnable(GL_DEPTH_TEST);
  glfwSwapInterval(1);
}

atn::core::Window::~Window() { glfwDestroyWindow(this->window); }

bool atn::core::Window::should_close() const {
  return glfwWindowShouldClose(this->window);
}

void atn::core::Window::key_callback(GLFWkeyfun cbfun) {
  glfwSetKeyCallback(this->window, cbfun);
}

void atn::core::Window::get_size(int* width, int* height) const {
  glfwGetFramebufferSize(this->window, width, height);
}

void atn::core::Window::begin_render() {
  glClearColor(0.f, 0.f, 0.f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void atn::core::Window::end_render() {
  glfwSwapBuffers(this->window);
  glfwPollEvents();
}

void atn::core::window_error_callback(int error, const char* description) {
  fprintf(stderr, "Error: %s\n", description);
}

void atn::core::window_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}
