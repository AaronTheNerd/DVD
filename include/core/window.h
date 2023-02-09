#ifndef _INCLUDE_CORE_WINDOW_H_
#define _INCLUDE_CORE_WINDOW_H_

#include <GLFW/glfw3.h>

namespace atn::core {

class Window {
 public:
  GLFWwindow* window;

  Window(uint, uint);
  ~Window();
  bool should_close() const;
  void key_callback(GLFWkeyfun);
  void get_size(int*, int*) const;
  void begin_render();
  void end_render();
};

void window_error_callback(int, const char*);
void window_size_callback(GLFWwindow*, int, int);

}  // namespace atn::core

#endif  // _INCLUDE_CORE_WINDOW_H_