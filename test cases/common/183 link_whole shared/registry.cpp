#include "registry.hpp"

#include <map>

namespace meson_test_link_whole {

namespace {
typedef std::map<std::string, base::ctor_type> registry_type;
registry_type *registry = 0;
}  // namespace

bool base::register_instance(const std::string &name, ctor_type ctor) {
    if (!registry) {
        registry = new registry_type;
    }
    if (registry->find(name) != registry->end()) {
        return false;
    }
    (*registry)[name] = ctor;
    return true;
}

base_ptr base::new_instance(const std::string &name) {
    if (!registry) {
        return 0;
    }
    const registry_type::const_iterator it = registry->find(name);
    if (it == registry->end()) {
        return 0;
    }
    return it->second();
}

}  // namespace meson_test_link_whole
