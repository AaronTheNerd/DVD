#include "core/image.h"
#include "core/exit.h"
#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <stb/stb_image.h>

atn::core::Image::Image(const char* filename)
    : width(), height(), channel_count(), texture_id() {
  unsigned char* data =
      stbi_load(filename, &this->width, &this->height, &this->channel_count, 0);
  if (!data) {
    atn::core::exit_handler(EXIT_FAILURE);
  }
  glGenTextures(1, &this->texture_id);
  glBindTexture(GL_TEXTURE_2D, this->texture_id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB,
               GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);
  stbi_image_free(data);
}

atn::core::Image::~Image() {}