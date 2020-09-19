cmake_minimum_required(VERSION 3.15.0)

project(XShell LANGUAGES C CXX VERSION 1.0.0)

add_subdirectory(Xana)

aux_source_directory("${PROJECT_SOURCE_DIR}" XSHELL_SOURCE)

add_library(XShell SHARED "${XSHELL_SOURCE}")

add_dependencies(XShell Xana)

target_include_directories(XShell
		PUBLIC "${PROJECT_INCLUDE_DIRECTORY}"
		PUBLIC "${Boost_INCLUDE_DIRS}")

target_link_directories(XShell
		PRIVATE "${PROJECT_LIBRARY_DIRECTORY}"
		PUBLIC "${Boost_LIBRARY_DIRS}")

target_link_libraries(XShell
		PRIVATE Xana
		)

