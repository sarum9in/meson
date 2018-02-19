#pragma once

#include "export.h"

#include <string>

namespace meson_test_link_whole {
class base {
  public:
    virtual int f() = 0;
    virtual ~base() {}

    typedef base *base_ptr;
    typedef base_ptr (*ctor_type)();
    static bool DLL_PUBLIC register_instance(const std::string &name, ctor_type ctor);
    static base_ptr DLL_PUBLIC new_instance(const std::string &name);
};

typedef base::base_ptr base_ptr;

}  // namespace meson_test_link_whole
