# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Kashnitskiy <elijahkash.code@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created:                     by mtrisha           #+#    #+#              #
#    Updated:                     by Kashnitskiy      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.13.4)

set(CMAKE_C_COMPILER "/usr/bin/clang")

project(libft C)

set(BUILD_FLAGS "-O3 -Wall -Wextra")
set(BUILD_FLAGS "-O3 -Wall -Wextra -Werror")
set(DEBUG_FLAGS "-g3 -Wall -Wextra")
set(DST_NAME ft)
set(DEBUG_NAME ftdebug)
set(SRC_DIR ${PROJECT_SOURCE_DIR}/sources/)
set(INC_DIR ${PROJECT_SOURCE_DIR}/includes/)

MACRO(INCLUDE_DIRS return_list)
	FILE(GLOB_RECURSE new_list ${INC_DIR}*.h)
	SET(dir_list "")
	FOREACH(file_path ${new_list})
		GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
		SET(dir_list ${dir_list} ${dir_path})
	ENDFOREACH()
	LIST(REMOVE_DUPLICATES dir_list)
	SET(${return_list} ${dir_list})
ENDMACRO()

set(INC_DIRS ./)
INCLUDE_DIRS(INC_DIRS)

FILE(GLOB_RECURSE LIBFT_SOURCES ${SRC_DIR}*.c)


add_library(${PROJECT_NAME} STATIC ${LIBFT_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INC_DIRS})
set_target_properties(${PROJECT_NAME} PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
	ARCHIVE_OUTPUT_NAME  ${DST_NAME}
	COMPILE_FLAGS ${BUILD_FLAGS})

set(DEBUG_RULE ${PROJECT_NAME}debug)

add_library(${DEBUG_RULE} STATIC EXCLUDE_FROM_ALL ${LIBFT_SOURCES})
target_include_directories(${DEBUG_RULE} PUBLIC ${INC_DIRS})
set_target_properties(${DEBUG_RULE} PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
	ARCHIVE_OUTPUT_NAME  ${DEBUG_NAME}
	COMPILE_FLAGS ${DEBUG_FLAGS}
	COMPILE_DEFINITIONS DEBUG)

set(TEST_NAME test)
set(TEST_DIR ${PROJECT_SOURCE_DIR}/test)
FILE(GLOB_RECURSE TEST_SOURCES ${TEST_DIR}*.c)

add_executable(test EXCLUDE_FROM_ALL ${TEST_SOURCES})
target_include_directories(test PUBLIC ${TEST_DIR})
target_include_directories(test PUBLIC ${INC_DIRS})
target_link_libraries(test ${PROJECT_SOURCE_DIR}/lib${DEBUG_NAME}.a)
set_target_properties(test PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${TEST_DIR}
		OUTPUT_NAME ${TEST_NAME}
		COMPILE_FLAGS ${DEBUG_FLAGS}
		COMPILE_DEFINITIONS DEBUG)

add_dependencies(test ${DEBUG_RULE})
