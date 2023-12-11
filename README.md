# Clash Of Armies - A tower defense game written in modern C++

# Group
- Aleksi Kalliomäki
- Leevi Salonen
- Mamin Imran
- Theodora Valerie

# Library requirements

* SFML

# Build tool requirements

* CMake
* Standard GCC / Clang (or g++ / clang++) compiler supporting C++ version 17 should work.

# Build instructions

## Windows
To build and run the program one should proceed with the following steps:
1. Clone the project to the local environment (repository).
2. Navigate to the project in the terminal (Ubuntu or other platform depending on the operating system).
3. Create a build directory by using the following commands:
    a. mkdir build
    b. cd build
4. Now, to build the project the following commands should be executed:
    a. cmake ..
    b. make
5. The executable name is ‘ClashofArmies’, so to run the program one should type
./ClashOfArmies


### TODO

## Linux

In the project root directory execute the following commands:
```
# Create the build directory
mkdir build
cd build/

# Configure and compile the project
cmake ..
make -j$(nproc)

# To launch the game just run
./ClashOfArmies
```

## MacOS

### TODO
