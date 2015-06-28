cmake_minimum_required(VERSION 3.2)
project(CawotteSrv)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

set(CawotteSrv_MAJOR 0)
set(CawotteSrv_MINOR 0)
set(CawotteSrv_PATCH 1)

add_definitions(-DCawotteSrv_MAJOR=${CawotteSrv_MAJOR})
add_definitions(-DCawotteSrv_MINOR=${CawotteSrv_MINOR})
add_definitions(-DCawotteSrv_PATCH=${CawotteSrv_PATCH})

find_package(Poco)
include_directories(${Poco_INCLUDE_DIRS})
link_directories(${Poco_LIBRARY_DIRS})

file(GLOB_RECURSE SOURCE_FILES src/*.*)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${POCO_LIBRARY_REL} ${POCO_Net_LIBRARY_REL})