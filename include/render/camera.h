#ifndef _INCLUDE_RENDER_CAMERA_H_
#define _INCLUDE_RENDER_CAMERA_H_

#include <glm/vec2.hpp>
#include <glm/matrix.hpp>

namespace atn::render {

class Camera {
 public:
  glm::vec2 size, offset;

  Camera(glm::vec2);

  void set_position(const glm::vec2&);
  void set_size(const glm::vec2&);
  glm::mat4 get_perspective() const;
};

}

#endif // _INCLUDE_RENDER_CAMERA_H_