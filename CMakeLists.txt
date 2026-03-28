cmake_minimum_required(VERSION 3.10)
project(Tarea2)

set(CMAKE_CXX_STANDARD 11)

add_executable(auth_manager leetcode/1797_authentication_manager.cpp)
add_executable(exam_tracker leetcode/3709_exam_tracker.cpp)
add_executable(crypto_square exercism/crypto_square.cpp)
add_executable(bank_account exercism/bank_account.cpp)