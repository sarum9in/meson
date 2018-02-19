project('link_whole shared', 'cpp')

registry = shared_library('registry', 'registry.cpp',
  cpp_args : '-DBUILDING_DLL',
)

plugin1 = shared_library('plugin1', 'plugin1.cpp',
  link_with : registry,
)

plugin2 = shared_library('plugin2', 'plugin2.cpp',
  link_with : registry,
)

plugin3 = static_library('plugin3', 'plugin3.cpp',
  cpp_args : '-DBUILDING_EMBEDDED',
)

exe = executable('main', 'main.cpp',
  link_with : registry,
  link_whole : [plugin1, plugin2, plugin3],
)
test('has plugins', exe)
