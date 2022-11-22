cmake_minimum_required(VERSION 3.13)

project(heap)

FILE(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")
add_executable(${PROJECT_NAME}
	${SOURCES}
)