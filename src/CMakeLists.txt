cmake_minimum_required(VERSION 3.17.3)

project(XShell LANGUAGES C CXX VERSION 1.0.0)

############################# Configure Xana Source #############################

add_subdirectory(Xana)

############################ Configure XShell Source ############################

aux_source_directory("${PROJECT_SOURCE_DIR}/XShell" XSHELL_SOURCE)

add_library(XShell SHARED "${PROJECT_SOURCE_DIR}/XShell.cpp" "${XSHELL_SOURCE}")

add_dependencies(XShell Xana)

include(GenerateExportHeader)
generate_export_header(XShell)

target_include_directories(XShell
		PUBLIC "${PROJECT_INCLUDE_DIRECTORY}"
		PUBLIC "${Boost_INCLUDE_DIRS}")

target_link_directories(XShell
		PUBLIC "${PROJECT_LIBRARY_DIRECTORY}"
		PUBLIC "${Boost_LIBRARY_DIRS}")

target_link_libraries(XShell
		PRIVATE Xana)

########################## Configure XShellTest Source ##########################

aux_source_directory("${PROJECT_SOURCE_DIR}/test" XSHELL_TEST_SOURCE)

add_executable(XShellTest "${XSHELL_TEST_SOURCE}")

add_dependencies(XShellTest XShell)

if (WIN32)
	target_link_libraries(XShellTest
			PUBLIC "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libXShell.dll")
else ()
	target_link_libraries(XShellTest
			PUBLIC "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/XShell.so")
endif ()