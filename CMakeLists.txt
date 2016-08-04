cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(openMVG_SfMImageListing_Elphel_Camera C CXX)

# By default build in Release mode
IF(NOT CMAKE_BUILD_TYPE AND NOT MSVC)
  SET(CMAKE_BUILD_TYPE "Release")
ENDIF(NOT CMAKE_BUILD_TYPE AND NOT MSVC)

# ==============================================================================
# OpenMP detection
# ==============================================================================
find_package(OpenMP)
if (OPENMP_FOUND)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  ADD_DEFINITIONS(-DOPENMVG_USE_OPENMP)
  if (NOT MSVC)
    LIST(APPEND OPENMVG_RIG_LIBRARY_DEPENDENCIES gomp)
  endif (NOT MSVC)
endif (OPENMP_FOUND)

# ------------------------------------------------------------------------------
# OpenMVG
# ------------------------------------------------------------------------------
find_package(OpenMVG REQUIRED)
# ------------------------------------------------------------------------------
# OpenGV
# ------------------------------------------------------------------------------
find_package(opengv REQUIRED)

add_subdirectory(third_party)

# ==============================================================================
# Include directories
# ==============================================================================
include_directories(
  ./third_party/libfastcal/src
  ${OPENMVG_INCLUDE_DIRS}
  ${LIBFASTCAL_INCLUDE_DIR}
  ${OPENGV_INCLUDE_DIR}
)

add_executable(main_openMVG_SfMImageListing_Elphel_Camera main.cpp)
target_link_libraries(main_openMVG_SfMImageListing_Elphel_Camera ${OPENMVG_LIBRARIES} libfastcal)

set_target_properties( main_openMVG_SfMImageListing_Elphel_Camera
  PROPERTIES
  CXX_STANDARD 11
  CXX_STANDARD_REQUIRED ON
  DEBUG_POSTFIX d )
