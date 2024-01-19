project('ClashOfArmies', 'cpp', default_options: ['warning_level=3'],
    version: '1.0.0')

add_project_arguments('-Wno-missing-field-initializers', language: ['cpp'])
sfml_version = '>=2.5.1'  # Replace with your desired SFML version

sfml_dep = dependency('sfml-all', version: sfml_version)

# Use the files() function to include all .cpp files under the src/ directory
source_files = [
    'src/weapon_toolbar_renderer.cpp',
    'src/background_renderer.cpp',
    'src/fighterplane.cpp',
    'src/testmapinfo.cpp',
    'src/menu_level.cpp',
    'src/projectile.cpp',
    'src/enemy_wave.cpp',
    'src/gameobject.cpp',
    'src/attackplane.cpp',
    'src/enemy_path_renderer.cpp',
    'src/gamegrid.cpp',
    'src/texture_manager.cpp',
    'src/tank.cpp',
    'src/tower_selector.cpp',
    'src/map_parser.cpp',
    'src/footsoldier.cpp',
    'src/missilelauncher.cpp',
    'src/bullet.cpp',
    'src/missile.cpp',
    'src/gameobject_renderer.cpp',
    'src/highscores.cpp',
    'src/game.cpp',
    'src/highscore_renderer.cpp',
    'src/utility_func_game.cpp',
    'src/enemy.cpp',
    'src/map_tile_selector_renderer.cpp',
    'src/levelinfo_renderer.cpp',
    'src/menu_home.cpp',
    'src/tower.cpp',
    'src/cannon.cpp',
    'src/gameloop.cpp',
    'src/tile.cpp'
    ]
app_lib = static_library('app_lib', source_files)

executable('ClashOfArmies',
  'src/main.cpp',
  link_with: app_lib,
  dependencies: [sfml_dep],
)

gtest_dep = dependency('gtest_main', required : true)
e = executable('unittests',
    sources: [#'tests/test_main.cpp',
              'tests/test_example.cpp',
              'tests/game_test.cpp'],
    link_with: app_lib,
    include_directories: 'src',
    dependencies: [gtest_dep])

test('ClashOfArmiesTests', e)