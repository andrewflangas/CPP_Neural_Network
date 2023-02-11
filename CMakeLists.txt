cmake_minimum_required(VERSION 3.10)

project(NeuralNetwork CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add Boost library
find_package(Boost REQUIRED COMPONENTS random)
include_directories(${BOOST_INCLUDE_DIRS})

# Add include directory
include_directories(include)

# Add sources
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(NeuralNetwork ${SOURCES})

# Link Boost library
target_link_libraries(NeuralNetwork ${Boost_LIBRARIES})