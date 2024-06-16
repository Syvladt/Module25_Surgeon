cmake_minimum_required (VERSION 3.8)

add_executable (Surgeon Surgeon.cpp ${INC_DIR}/Surgeon.h Subroutine.cpp)
target_include_directories(Surgeon PUBLIC ${INC_DIR})