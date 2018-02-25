#pragma once

#include <map>
#include <string>

namespace meson_test {
class base {
  public:
    virtual ~base() {}

    virtual void test(int secret) = 0;

    typedef base *(*factory_ptr)();
    static bool register_new(const std::string &name, factory_ptr f);
    static base *new_instance(const std::string &name);

  private:
    static std::map<std::string, factory_ptr> *factories;
};
}  // meson_test
