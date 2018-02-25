project('whole archive', ['c', 'cpp'])

add_project_arguments('-I' + meson.source_root(), language : 'c')

cc = meson.get_compiler('c')

if cc.get_id() == 'msvc'
  if cc.version().version_compare('<19')
    error('MESON_SKIP_TEST link_whole only works on VS2015 or newer.')
  endif
endif

# Test 1: link_whole keeps all symbols
# Make static func1
subdir('st_func1')
# Make shared func2 linking whole func1 archive
subdir('sh_func2_linked_func1')
# Link exe with shared library only
subdir('exe')
# Test that both func1 and func2 are accessible from shared library
test('prog', exe)

# Test 2: link_whole can be used instead of source list, see #2180
# Make static func2
subdir('st_func2')
# Link both func1 and func2 into same shared library
# which does not have any sources other than 2 static libraries
subdir('sh_only_link_whole')
# Link exe2 with shared library only
subdir('exe2')
# Test that both func1 and func2 are accessible from shared library
test('prog2', exe2)

# Test 3: link_whole without any references at all.
# Plugins are self-registering in factory and no symbols are called from them.
factory = static_library('factory', 'factory.cpp')
plugin1 = static_library('plugin1', 'plugin1.cpp', pic : true)
plugin2 = static_library('plugin2', 'plugin2.cpp', pic : true)
exe3 = executable('exe3', 'plugins_test.cpp', link_with : factory, link_whole : [plugin1, plugin2])
test('prog3', exe3)

# Test 4: same as 3 but link into shared library first.
shared_proxy = shared_library('shared_proxy', link_whole : [factory, plugin1, plugin2])
exe4 = executable('exe4', 'plugins_test.cpp', link_with : shared_proxy)
test('prog4', exe4)

# Test 5: same as test 4 but use factory.cpp directly.
shared_factory = shared_library('shared_factory', 'factory.cpp', link_whole : [plugin1, plugin2])
exe5 = executable('exe5', 'plugins_test.cpp', link_with : shared_factory)
test('prog5', exe5)
