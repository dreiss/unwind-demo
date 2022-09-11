cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(rv32_bt)

# set(CMAKE_C_FLAGS "-Os -fno-omit-frame-pointer")
# set(CMAKE_CXX_FLAGS "-Os -funwind-tables -fexceptions")

zephyr_compile_options(-funwind-tables -fasynchronous-unwind-tables)

file(GLOB SRC_FILES
"src/*.c"
"src/*.cc"
)
target_sources(app PRIVATE ${SRC_FILES})
