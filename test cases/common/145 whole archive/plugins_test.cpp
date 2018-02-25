#include "factory.hpp"

#include <iostream>

int main() {
    meson_test::base *plugin1 = meson_test::base::new_instance("plugin1");
    if (!plugin1) {
        std::cerr << "could not create plugin1\n";
        return 1;
    }
    meson_test::base *plugin2 = meson_test::base::new_instance("plugin2");
    if (!plugin2) {
        std::cerr << "could not create plugin2\n";
        return 1;
    }
    plugin1->test(1);
    plugin2->test(2);
}
