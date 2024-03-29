cmake_minimum_required(VERSION 3.22.1)
project(ClashOfArmies)
set(CMAKE_CXX_STANDARD 17)

if (APPLE)
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

else()
  # Add the source files to the library
  file(GLOB_RECURSE LIB_SOURCES src/*.cpp)
  list(REMOVE_ITEM LIB_SOURCES "src/game.cpp")
  file(GLOB_RECURSE MAIN_SOURCES main.cpp)

  # Create a library from the source files
  add_library(${PROJECT_NAME}_lib ${LIB_SOURCES})
  set(CMAKE_BUILD_TYPE Debug)

  # Add the main executable and link with the library
  add_executable(${PROJECT_NAME} ${MAIN_SOURCES})
  target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)

  # Set the include directories for the main project
  target_include_directories(${PROJECT_NAME} PRIVATE src)

  # get a lot of warnings
  if(MSVC)
      target_compile_options(${PROJECT_NAME} PRIVATE /Wall)
  else()
      # gcc and clang
      target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Wno-missing-field-initializers)
  endif()

  # Find and link SFML
  find_package(SFML 2.5 COMPONENTS network audio graphics window system REQUIRED)
  if(SFML_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} PRIVATE sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
  endif()

  # Fetch Google Test
  include(FetchContent)

  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
  )

  # Populate or update content as needed
  FetchContent_MakeAvailable(googletest)

  # Enable testing for our project
  enable_testing()

  # Add a target for running the tests
  file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)
  add_executable(unit_tests ${TEST_SOURCES})
  target_link_libraries(unit_tests PRIVATE ${PROJECT_NAME}_lib gtest gtest_main sfml-graphics sfml-system)

  # Set the working directory for tests
  set_target_properties(unit_tests PROPERTIES
                        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests)

  # Set the include directories for the tests
  target_include_directories(unit_tests PRIVATE src)

  # Add a test
  add_test(NAME MyTest COMMAND unit_tests)
endif()
