#ifndef _INCLUDE_RENDER_BOX_H_
#define _INCLUDE_RENDER_BOX_H_

#include "render/object.h"

#include <glm/vec3.hpp>
#include <vector>

namespace atn::render {

class Box : public atn::render::Object {
 public:
  glm::vec3 top_left;
  glm::vec2 size;

  Box(glm::vec3, glm::vec2);
};

}  // namespace atn::render

#endif  // _INCLUDE_RENDER_BOX_H_