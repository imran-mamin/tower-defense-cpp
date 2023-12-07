cmake_minimum_required(VERSION 3.22.1)
project(ClashOfArmies)
set (CMAKE_CXX_STANDARD 17)
include_directories("src")



# Set the executable name.
set(EXECUTABLE_NAME ClashOfArmies)

file(GLOB SOURCES src/*.cpp)
add_executable(${EXECUTABLE_NAME} ${SOURCES})
set(CMAKE_BUILD_TYPE Debug)

# Add the main executable and link with the library
add_executable(${PROJECT_NAME} ${MAIN_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)

# Set the include directories for the main project
target_include_directories(${PROJECT_NAME} PRIVATE src)

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

target_include_directories(${PROJECT_NAME} PRIVATE ${TMXLITE_INCLUDE_LIBS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${TMXLITE_LIBRARIES})
