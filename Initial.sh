#!/bin/sh
# Declare global variant
PROJECT_DIR=`pwd`
THIRD_PARTY_DIR="${PROJECT_DIR}/thirdparty"
STAGE_INFO='\e[1;36m'
NORMAL_INFO='\e[0m'
ERROR_INFO='\e[0;31m'
OK_INFO='\e[0;32m'

echo "${STAGE_INFO}Start cross compiling Xana...${NORMAL_INFO}"
OPENSSL_VERSION_PREFIX="3.0.0-alpha6"
OPENSSL_ARCHIVE_FILE="openssl-${OPENSSL_VERSION_PREFIX}.tar.gz"
OPENSSL_EXTRACT_DIR="${THIRD_PARTY_DIR}/openssl-openssl-${OPENSSL_VERSION_PREFIX}"
OPENSSL_ROOT_DIR="${PROJECT_DIR}/lib/openssl"
echo "${STAGE_INFO}Compiling OpenSSL...${NORMAL_INFO}"
cd "${PROJECT_DIR}"
mkdir -p "${OPENSSL_EXTRACT_DIR}"
cd "${THIRD_PARTY_DIR}"
curl -SL "https://github.com/openssl/openssl/archive/${OPENSSL_ARCHIVE_FILE}" -o "${OPENSSL_ARCHIVE_FILE}"
tar -zxf ${OPENSSL_ARCHIVE_FILE}
rm ${OPENSSL_ARCHIVE_FILE}
cd "${OPENSSL_EXTRACT_DIR}"
./Configure mingw64 shared --prefix="${OPENSSL_ROOT_DIR}" --openssldir="${OPENSSL_ROOT_DIR}/openssl"
make depend
make
make install
# CMake building
echo "${STAGE_INFO}Compiling Xana...${NORMAL_INFO}"
cd "${PROJECT_DIR}"
cmake -B./build -DCMAKE_TOOLCHAIN_FILE=./cmake/native.cmake -G Ninja .
cmake --build ./build --target all -- -j 10
echo "${OK_INFO}Building finished!${NORMAL_INFO}"
