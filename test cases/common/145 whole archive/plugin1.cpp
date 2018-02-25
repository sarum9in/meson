#include "factory.hpp"

#include <iostream>
#include <stdexcept>

namespace meson_plugin {
namespace {
class plugin : public meson_test::base {
  public:
    virtual void test(const int secret) {
        if (secret != 1) {
            std::cerr << "invalid secret, want 1, got " << secret << '\n';
            throw std::runtime_error("invalid secret");
        }
    }
    static meson_test::base *create() {
        return new plugin;
    }
};
const bool registration =
    meson_test::base::register_new("plugin1", plugin::create);
}  // namespace
}  // namespace meson_plugin
