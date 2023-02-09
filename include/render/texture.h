#ifndef _INCLUDE_CORE_TEXTURE_H_
#define _INCLUDE_CORE_TEXTURE_H_

#include <stdlib.h>
#include "core/image.h"
#include "render/box.h"
#include <glm/vec3.hpp>

namespace atn::core {

class Texture {
 public:
  atn::core::Image image;
  atn::render::Box bounding_box;

  Texture(const char*, float, float, glm::vec3);
  ~Texture();
};

}  // namespace atn::core

#endif  // _INCLUDE_CORE_TEXTURE_H_  