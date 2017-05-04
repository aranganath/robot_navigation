# Install script for directory: /home/aditya/CSE180/src/pcl-pcl-1.7.2/octree

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_octree")
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_octree.so.1.7.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_octree.so.1.7"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_octree.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "/usr/local/lib")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/build/lib/libpcl_octree.so.1.7.2"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/build/lib/libpcl_octree.so.1.7"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/build/lib/libpcl_octree.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_octree.so.1.7.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_octree.so.1.7"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_octree.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "::::::::::::::"
           NEW_RPATH "/usr/local/lib")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_octree")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/aditya/CSE180/src/pcl-pcl-1.7.2/build/octree/pcl_octree-1.7.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_octree")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl/octree" TYPE FILE FILES
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/boost.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_base.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_container.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_impl.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_nodes.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_key.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_density.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_occupancy.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_singlepoint.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_pointvector.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_changedetector.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_voxelcentroid.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_iterator.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_search.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree2buf_base.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_adjacency.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/octree_pointcloud_adjacency_container.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_octree")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl/octree/impl" TYPE FILE FILES
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/impl/octree_base.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/impl/octree_pointcloud.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/impl/octree2buf_base.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/impl/octree_iterator.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/impl/octree_search.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/impl/octree_pointcloud_voxelcentroid.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/octree/include/pcl/octree/impl/octree_pointcloud_adjacency.hpp"
    )
endif()

