cmake_minimum_required(VERSION 3.23)


add_executable(Skillbox25 main.cpp ${INCLUDE_DIR}/use-lib.h ${INCLUDE_DIR}/task-one.h)
target_include_directories(Skillbox25 PUBLIC ${INCLUDE_DIR})
