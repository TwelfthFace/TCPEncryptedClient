cmake_minimum_required(VERSION 3.14)

project(TCPEncryptedClient LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TCPEncryptedClient
  main.cpp
  src/cipher.cpp
  include/cipher.h
)

include_directories(include)

target_link_libraries(TCPEncryptedClient /usr/lib64/libssl.so /usr/lib64/libcrypto.so)
