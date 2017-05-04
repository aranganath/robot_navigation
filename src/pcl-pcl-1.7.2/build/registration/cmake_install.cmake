# Install script for directory: /home/aditya/CSE180/src/pcl-pcl-1.7.2/registration

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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_registration")
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_registration.so.1.7.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_registration.so.1.7"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_registration.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "/usr/local/lib")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/build/lib/libpcl_registration.so.1.7.2"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/build/lib/libpcl_registration.so.1.7"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/build/lib/libpcl_registration.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_registration.so.1.7.2"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_registration.so.1.7"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpcl_registration.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/aditya/CSE180/src/pcl-pcl-1.7.2/build/lib:"
           NEW_RPATH "/usr/local/lib")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_registration")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/aditya/CSE180/src/pcl-pcl-1.7.2/build/registration/pcl_registration-1.7.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_registration")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl/registration" TYPE FILE FILES
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/eigen.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/boost.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/boost_graph.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/convergence_criteria.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/default_convergence_criteria.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_estimation.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_estimation_normal_shooting.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_estimation_backprojection.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_estimation_organized_projection.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_rejection.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_rejection_distance.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_rejection_median_distance.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_rejection_surface_normal.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_rejection_features.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_rejection_one_to_one.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_rejection_poly.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_rejection_sample_consensus.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_rejection_sample_consensus_2d.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_rejection_trimmed.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_rejection_var_trimmed.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_rejection_organized_boundary.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_sorting.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/correspondence_types.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/ia_ransac.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/icp.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/joint_icp.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/icp_nl.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/lum.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/elch.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/ndt.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/ndt_2d.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/ppf_registration.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/pairwise_graph_registration.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/pyramid_feature_matching.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/registration.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/transforms.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/transformation_estimation.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/transformation_estimation_2D.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/transformation_estimation_svd.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/transformation_estimation_svd_scale.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/transformation_estimation_dual_quaternion.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/transformation_estimation_lm.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/transformation_estimation_point_to_plane.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/transformation_estimation_point_to_plane_weighted.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/transformation_estimation_point_to_plane_lls.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/transformation_estimation_point_to_plane_lls_weighted.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/transformation_validation.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/transformation_validation_euclidean.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/gicp.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/gicp6d.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/bfgs.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/warp_point_rigid.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/warp_point_rigid_6d.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/warp_point_rigid_3d.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/distances.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/exceptions.h"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/sample_consensus_prerejective.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "pcl_registration")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pcl-1.7/pcl/registration/impl" TYPE FILE FILES
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/default_convergence_criteria.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_estimation.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_estimation_normal_shooting.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_estimation_backprojection.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_estimation_organized_projection.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_rejection.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_rejection_distance.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_rejection_median_distance.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_rejection_surface_normal.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_rejection_features.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_rejection_one_to_one.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_rejection_poly.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_rejection_sample_consensus.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_rejection_sample_consensus_2d.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_rejection_trimmed.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_rejection_var_trimmed.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_rejection_organized_boundary.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/correspondence_types.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/ia_ransac.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/icp.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/joint_icp.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/icp_nl.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/elch.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/lum.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/ndt.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/ndt_2d.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/ppf_registration.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/pyramid_feature_matching.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/registration.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/transformation_estimation_2D.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/transformation_estimation_svd.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/transformation_estimation_svd_scale.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/transformation_estimation_dual_quaternion.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/transformation_estimation_lm.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/transformation_estimation_point_to_plane_lls.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/transformation_estimation_point_to_plane_lls_weighted.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/transformation_estimation_point_to_plane_weighted.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/transformation_validation_euclidean.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/gicp.hpp"
    "/home/aditya/CSE180/src/pcl-pcl-1.7.2/registration/include/pcl/registration/impl/sample_consensus_prerejective.hpp"
    )
endif()

