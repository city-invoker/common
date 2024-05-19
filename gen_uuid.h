// copyright skylanwei 2024-04-23

#pragma once

#include <uuid/uuid.h>
#include <string>

namespace trpc {
namespace app {

class UUID {

public:
  static std::string uuid() {

    uuid_t uuid;
    uuid_generate(uuid);
    char uuid_str[37];
    uuid_unparse_lower(uuid, uuid_str);
    std::string uniq_id(uuid_str);
    size_t pos = uniq_id.find("-");
    while(pos != std::string::npos) {
      uniq_id.replace(pos, 1, "");
      pos = uniq_id.find("-");
    }

    return uniq_id;
  }

};


}
}
