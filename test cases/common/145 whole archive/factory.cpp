#include "factory.hpp"

namespace meson_test {
typedef std::map<std::string, base::factory_ptr> factory_storage;
factory_storage *base::factories = 0;

bool base::register_new(const std::string &name, factory_ptr f) {
    if (!factories) factories = new factory_storage;
    std::pair<factory_storage::iterator, bool> ret = factories->insert(
        std::make_pair(name, f));
    return ret.second;
}

base *base::new_instance(const std::string &name) {
    if (!factories) return 0;
    factory_storage::const_iterator it = factories->find(name);
    if (it == factories->end()) return 0;
    return it->second();
}
}  // meson_test
