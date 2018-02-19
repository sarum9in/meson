#include "registry.hpp"

#include <iostream>

namespace {
bool test_plugin(const std::string &name, const int f) {
    using meson_test_link_whole::base;
    using meson_test_link_whole::base_ptr;

    base_ptr p = base::new_instance(name);
    if (!p) {
        std::cerr << "unable to instantiate " << name << std::endl;
        return false;
    }
    const int value = p->f();
    if (value != f) {
        std::cerr << "failed " << name << "->f(), want " << f << ", got "
                  << value << std::endl;
    }
    delete p;
    return value == f;
}
}  // namespace

int main() {
    if (!test_plugin("plugin1", 1)) { return 1; }
    if (!test_plugin("plugin2", 2)) { return 1; }
    if (!test_plugin("plugin3", 3)) { return 1; }
    return 0;
}
