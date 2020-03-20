cmake_minimum_required(VERSION 3.12)
project(merkle)

set(CMAKE_CXX_STANDARD 17)
set(OPENSSL_USE_STATIC_LIBS ON)
set(SOURCE_FILES main.cpp)
set(OPENSSL_ROOT_DIR /usr/local/Cellar/openssl/1.0.2s/)
find_package(OpenSSL REQUIRED)

add_executable(merkle ${SOURCE_FILES})
target_link_libraries(merkle OpenSSL::SSL)
