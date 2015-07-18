cmake_minimum_required(VERSION 2.8)
project(CawotteSrv)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

set(CawotteSrv_MAJOR 0)
set(CawotteSrv_MINOR 1)
set(CawotteSrv_PATCH 0)

add_definitions(-DCawotteSrv_MAJOR=${CawotteSrv_MAJOR})
add_definitions(-DCawotteSrv_MINOR=${CawotteSrv_MINOR})
add_definitions(-DCawotteSrv_PATCH=${CawotteSrv_PATCH})

find_package(LibEvent)
include_directories(${LIBEVENT_INCLUDE_DIR})

if(WIN32)
  include_directories(${LIBEVENT_WIN32_INCLUDE_DIR})
endif()

include_directories(src)
include_directories(dep)
file(GLOB_RECURSE SOURCE_FILES src/*.* dep/*.*)

file(COPY config/cawotte.ini DESTINATION config)
file(COPY key/dofus.key DESTINATION key)
file(COPY tools/AuthPatch/bin/AuthPatch.swf DESTINATION tools/AuthPatch/bin)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if(WIN32)
  target_link_libraries(${PROJECT_NAME} ${LIBEVENT_LIB} ws2_32)
else()
  target_link_libraries(${PROJECT_NAME} ${LIBEVENT_LIB})
endif()