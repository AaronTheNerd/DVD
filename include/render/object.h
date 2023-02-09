#ifndef _INCLUDE_RENDER_OBJECT_H_
#define _INCLUDE_RENDER_OBJECT_H_

#include <glm/glm.hpp>
#include <memory>
#include <vector>

namespace atn::render {

class Object {
 public:
  std::vector<glm::vec3> positions;
  std::vector<uint> indicies;

  Object();
};

typedef std::shared_ptr<atn::render::Object> SharedObject;

}  // namespace atn::render

#endif  // _INCLUDE_RENDER_OBJECT_H_