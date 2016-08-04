CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(libfastcal C)

# ==============================================================================
# Library
# ==============================================================================
SET(LIBFASTCAL_INCLUDES ./src)

FILE(
  GLOB_RECURSE
  header_files
  *.h
)

FILE(
  GLOB_RECURSE
  source_files
  *.c
)

SET_SOURCE_FILES_PROPERTIES(${source_files} PROPERTIES LANGUAGE C)
ADD_LIBRARY(libfastcal ${source_files} ${header_files})
