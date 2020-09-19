cmake_minimum_required(VERSION 3.15.0)
project(Xana LANGUAGES C CXX VERSION 0.1.0)

# Set Debug Signal
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")

# Set Output Folder
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")

############################## Configure OpenSSL ##############################

set(OPENSSL_ROOT_DIR "${PROJECT_SOURCE_DIR}/lib/openssl")
set(OPENSSL_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/openssl/include")
set(OPENSSL_LIBRARIES "${PROJECT_SOURCE_DIR}/lib/openssl/lib")

############################### Configure Boost ###############################

find_package(Boost REQUIRED)

######################### Configure Project Variants ##########################

set(PROJECT_INCLUDE_DIRECTORY "${PROJECT_SOURCE_DIR}/include")
set(PROJECT_LIBRARY_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")
set(SOLUTION_DIRECTORY "${PROJECT_SOURCE_DIR}")

############################ Include Repositories #############################

add_subdirectory(src)