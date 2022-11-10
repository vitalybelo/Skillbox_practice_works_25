cmake_minimum_required(VERSION 3.23)


add_executable(Skillbox25
        main.cpp
#        task1_main.cpp
        ${INCLUDE_DIR}/use_lib.h
        ${INCLUDE_DIR}/task1_class.h
        ${INCLUDE_DIR}/task1_structs.h
        ${INCLUDE_DIR}/task2_macros.h
        ${INCLUDE_DIR}/task2_structs.h
        ${INCLUDE_DIR}/task2_cpu_class.h
        ${INCLUDE_DIR}/task2_ram_class.h
        ${INCLUDE_DIR}/task2_gpu_class.h
        ${INCLUDE_DIR}/task2_disk_class.h
        )

target_include_directories(Skillbox25 PUBLIC ${INCLUDE_DIR})
