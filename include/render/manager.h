#ifndef _INCLUDE_RENDER_MANAGER_H_
#define _INCLUDE_RENDER_MANAGER_H_

#include "render/object.h"
#include <memory>
#include <vector>

namespace atn::render {

struct Triangles {
  
};

class Manager {
 private:
  std::vector<atn::render::SharedObject> objects;
 public:
  Manager();

  void update_all();
};

}

#endif // _INCLUDE_RENDER_MANAGER_H_
