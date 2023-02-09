#include "render/camera.h"
#include <glm/gtc/matrix_transform.hpp>

atn::render::Camera::Camera(glm::vec2 size)
    : size(size), offset(this->size / 2.f) {}

void atn::render::Camera::set_position(const glm::vec2& position) {
  this->offset = position;
}

void atn::render::Camera::set_size(const glm::vec2& size) { this->size = size; }

glm::mat4 atn::render::Camera::get_perspective() const {
  glm::mat4 perspective{1.f};
  perspective = glm::scale(perspective, glm::vec3{this->size / 2.f, 1.f});
  perspective = glm::translate(perspective, glm::vec3{-this->offset, 0.f});
  return perspective;
}
