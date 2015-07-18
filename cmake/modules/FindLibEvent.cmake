# - Find LibEvent (a cross event library)
# This module defines
# LIBEVENT_INCLUDE_DIR, where to find LibEvent headers
# LIBEVENT_LIB, LibEvent libraries
# LibEvent_FOUND, If false, do not try to use libevent

set(LibEvent_ROOT_DIR CACHE PATH "LibEvent root path")

set(LibEvent_EXTRA_PREFIXES /usr/local /opt/local ${LibEvent_ROOT_DIR})
foreach(prefix ${LibEvent_EXTRA_PREFIXES})
  list(APPEND LibEvent_INCLUDE_PATHS "${prefix}/include")
  list(APPEND LibEvent_LIB_PATHS "${prefix}/lib")
  if(WIN32)
    list(APPEND LibEvent_WIN32_PATHS "${prefix}/WIN32-Code/nmake")
  endif()
endforeach()

find_path(LIBEVENT_INCLUDE_DIR event.h PATHS ${LibEvent_INCLUDE_PATHS})
find_library(LIBEVENT_LIB NAMES event PATHS ${LibEvent_LIB_PATHS})

if(WIN32)
  find_path(LIBEVENT_WIN32_INCLUDE_DIR event2/event-config.h PATHS ${LibEvent_WIN32_PATHS})
endif()

if (LIBEVENT_LIB AND LIBEVENT_INCLUDE_DIR)
  set(LibEvent_FOUND TRUE)
  set(LIBEVENT_LIB ${LIBEVENT_LIB})
else ()
  set(LibEvent_FOUND FALSE)
endif ()

if (LibEvent_FOUND)
  if (NOT LibEvent_FIND_QUIETLY)
    message(STATUS "Found libevent: ${LIBEVENT_LIB}")
  endif ()
else ()
  if (LibEvent_FIND_REQUIRED)
    message(FATAL_ERROR "Could NOT find libevent.")
  endif ()
  message(STATUS "libevent NOT found.")
endif ()

mark_as_advanced(
    LIBEVENT_LIB
    LIBEVENT_INCLUDE_DIR
	LIBEVENT_WIN32_INCLUDE_DIR
  )
