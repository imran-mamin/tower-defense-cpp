cmake_minimum_required(VERSION 3.22.1)
project(ClashOfArmies)
set (CMAKE_CXX_STANDARD 17)
include_directories("src")



# Set the executable name.
set(EXECUTABLE_NAME ClashOfArmies)

file(GLOB SOURCES src/*.cpp)
add_executable(${EXECUTABLE_NAME} ${SOURCES})
set(CMAKE_BUILD_TYPE Debug)

# get a lot of warnings
if(MSVC)
    target_compile_options(${EXECUTABLE_NAME} PRIVATE /Wall)
else()
    # gcc and clang
    target_compile_options(${EXECUTABLE_NAME} PRIVATE -Wall -Wextra -pedantic -Wno-missing-field-initializers)
endif()


find_package(SFML 2.5 COMPONENTS network audio graphics window system REQUIRED)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  # SFML version >= 2.5
  #In SFML Version 2.5 or later, ${SFML_LIBRARIES}, ${SFML_DEPENDENCIES}, ${SFML_INCLUDE_DIR} no longer exist. Specify libraries individually.
  target_link_libraries(${PROJECT_NAME} sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
endif()


include_directories(${TMXLITE_INCLUDE_LIBS})
target_link_libraries(${EXECUTABLE_NAME} ${TMXLITE_LIBRARIES})


