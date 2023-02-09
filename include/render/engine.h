#ifndef _INCLUDE_RENDER_ENGINE_H_
#define _INCLUDE_RENDER_ENGINE_H_

#include "render/manager.h"
#include "render/camera.h"
#include "core/window.h"

namespace atn::render {

class Engine {
 public:
  void update(atn::render::Manager&) const;
  void render(const atn::render::Manager&, atn::core::Window);
};

}

#endif // _INCLUDE_RENDER_ENGINE_H_