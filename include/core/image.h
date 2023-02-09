#ifndef _INCLUDE_CORE_IMAGE_H_
#define _INCLUDE_CORE_IMAGE_H_

#include <stdlib.h>

namespace atn::core {

class Image {
 public:
  int width, height, channel_count;
  uint texture_id;

  Image(const char*);
  ~Image();
};

}  // namespace atn::core

#endif  // _INCLUDE_CORE_IMAGE_H_