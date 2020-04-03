cmake_minimum_required(VERSION 3.11.3)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

# set(CMAKE_CXX_STANDARD 17)
project(RotoDots)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")

find_package(OpenCV 4.1 REQUIRED)
find_package(Boost COMPONENTS filesystem)

# Link to shared libraries.
add_definitions(-DUSE_IMPORT_EXPORT)

include_directories(${OpenCV_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS} ${Boost_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})
add_definitions(-DUNDER_MACOS)

# Find all executables
file(GLOB project_SRCS src/*.cpp) #src/*.h

# Add project executable
add_executable(RotoDots ${project_SRCS})
target_link_libraries(RotoDots ${OpenCV_LIBRARIES}
    ${Boost_FILESYSTEM_LIBRARY})
