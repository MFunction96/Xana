cmake_minimum_required(VERSION 3.17.3)

project(Xana LANGUAGES C CXX VERSION 1.0.0)

############################# Configure Xana Source #############################

aux_source_directory("${PROJECT_SOURCE_DIR}/IO" XANA_IO_SOURCE)
aux_source_directory("${PROJECT_SOURCE_DIR}" XANA_SOURCE)

add_library(Xana STATIC "${PROJECT_SOURCE_DIR}/Xana.cpp" "${XANA_SOURCE}" "${XANA_IO_SOURCE}")

target_include_directories(Xana
		PUBLIC "${PROJECT_INCLUDE_DIRECTORY}"
		PUBLIC "${OPENSSL_INCLUDE_DIR}")

target_link_directories(Xana
		PUBLIC "${PROJECT_LIBRARY_DIRECTORY}"
		PUBLIC "${OPENSSL_LIBRARIES}")

########################### Configure XanaTest Source ###########################

aux_source_directory("${PROJECT_SOURCE_DIR}/test" XANA_TEST_SOURCE)

add_executable(XanaTest "${XANA_TEST_SOURCE}")

add_dependencies(XanaTest Xana)

target_link_libraries(XanaTest
		PRIVATE Xana)