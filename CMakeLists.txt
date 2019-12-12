cmake_minimum_required(VERSION 3.15.3)

project(libft)

set(DST_NAME ft)

set(SRC_DIR sources)
aux_source_directory(${CMAKE_SOURCE_DIR}/${SRC_DIR} LIBFT_SOURCES)

add_library(${DST_NAME} STATIC ${LIBFT_SOURCES})

target_include_directories(${DST_NAME} PUBLIC ./includes)
target_include_directories(${DST_NAME} PUBLIC ./)

set_target_properties(${DST_NAME} PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# set(CMAKE_COMPILER_IS_GNUCC)


