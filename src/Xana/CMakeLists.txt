cmake_minimum_required(VERSION 3.15.0)

project(Xana LANGUAGES C CXX VERSION 1.0.0)

aux_source_directory("${PROJECT_SOURCE_DIR}" XANA_SOURCE)

add_library(Xana STATIC "${XANA_SOURCE}")

target_include_directories(Xana
		PRIVATE "${PROJECT_INCLUDE_DIRECTORY}"
		PRIVATE "${OPENSSL_INCLUDE_DIR}")

target_link_directories(Xana
		PRIVATE "${PROJECT_LIBRARY_DIRECTORY}"
		PRIVATE "${OPENSSL_LIBRARIES}")

