cmake_minimum_required(VERSION 3.2)
project(DofusLanSrv)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

set(DofusLanSrv_MAJOR 0)
set(DofusLanSrv_MINOR 0)
set(DofusLanSrv_MICRO 1)

find_package(Poco)
include_directories(${Poco_INCLUDE_DIRS})
link_directories(${Poco_LIBRARY_DIRS})

set(SOURCE_FILES
    src/net/client.cpp
    src/net/client.h
    src/net/server.cpp
    src/net/server.h
    src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${POCO_LIBRARY_REL} ${POCO_Net_LIBRARY_REL})