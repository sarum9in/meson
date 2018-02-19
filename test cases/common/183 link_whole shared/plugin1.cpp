#include "registry.hpp"

namespace meson_test_link_whole {
namespace {
class plugin : public base {
  public:
    int f() { return 1; }
};

base_ptr new_plugin() {
    return new plugin;
}

const bool register_inst = base::register_instance("plugin1", &new_plugin);

}  // namespace
}  // namespace meson_test_link_whole
