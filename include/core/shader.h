/*
Code from learnopengl.com's getting started
*/
#ifndef _INCLUDE_CORE_SHADER_H_
#define _INCLUDE_CORE_SHADER_H_

#include <glad/gl.h>
#include <glm/glm.hpp>

#include <string>

namespace atn::core {

class Shader {
 public:
  uint ID;

  Shader(const char*, const char*);
  void use() const;
  void setBool(const std::string&, bool) const;
  void setInt(const std::string&, int) const;
  void setFloat(const std::string&, float) const;
  void setVec2(const std::string&, const glm::vec2&) const;
  void setVec2(const std::string&, float, float) const;
  void setVec3(const std::string&, const glm::vec3&) const;
  void setVec3(const std::string&, float, float, float) const;
  void setVec4(const std::string&, const glm::vec4&) const;
  void setVec4(const std::string&, float, float, float, float) const;
  void setMat2(const std::string&, const glm::mat2&) const;
  void setMat3(const std::string&, const glm::mat3&) const;
  void setMat4(const std::string&, const glm::mat4&) const;

 private:
  void checkCompileErrors(GLuint, std::string);
};

}  // namespace atn::core

#endif
