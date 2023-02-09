#ifndef _INCLUDE_GAME_H_
#define _INCLUDE_GAME_H_

#include "core/window.h"
#include "render/camera.h"
#include "render/manager.h"
#include "render/engine.h"

namespace atn {

class Game {
 public:
  atn::core::Window window;
  atn::render::Manager object_manager;
  atn::render::Engine renderer;
  atn::render::Camera camera;

  Game();
  void tick();
  void run();
};

}

#endif // _INCLUDE_GAME_H_