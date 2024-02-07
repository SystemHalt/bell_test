cmake_minimum_required(VERSION 3.0.0)

project(reverse_server DESCRIPTION "Reverse TCPServer")

set(SRC src/main.cpp src/Connection.cpp)
set(INC inc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

find_package(Poco REQUIRED Foundation Net)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ${INC})
target_link_libraries(${PROJECT_NAME} Poco::Foundation Poco::Net)