#include "render/box.h"

atn::render::Box::Box(glm::vec3 top_left, glm::vec2 size)
    : top_left(top_left), size(size), atn::render::Object() {
  this->positions.emplace_back(this->top_left);
  this->positions.emplace_back(glm::vec3{
      this->top_left.x + this->size.x, this->top_left.y, this->top_left.z});
  this->positions.emplace_back(glm::vec3{
      this->top_left.x, this->top_left.y + this->size.y, this->top_left.z});
  this->positions.emplace_back(glm::vec3{this->top_left.x + this->size.x,
      this->top_left.y + this->size.y, this->top_left.z});
  this->indicies = std::vector<uint>{0, 1, 2, 1, 2, 3};
}
