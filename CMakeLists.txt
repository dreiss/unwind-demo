cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(rv32_bt)

# set(CMAKE_C_FLAGS "-Os -fno-omit-frame-pointer")
# set(CMAKE_CXX_FLAGS "-Os -funwind-tables -fexceptions")

zephyr_compile_options(-funwind-tables -fasynchronous-unwind-tables)
#zephyr_ld_options(-Wl,--eh-frame-hdr)

file(GLOB SRC_FILES
"src/*.c"
"src/*.cc"
)
target_sources(app PRIVATE ${SRC_FILES})


add_library(libunwind STATIC IMPORTED GLOBAL)
set_target_properties(libunwind PROPERTIES IMPORTED_LOCATION
  /home/dreiss/stuff/build/libunwind/src/.libs/libunwind.a)
set_target_properties(libunwind PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
  "/home/dreiss/stuff/build/libunwind/include;/home/dreiss/stuff/code/projects/zephyr_libunwind_bridge/include"
)

target_link_libraries(app PUBLIC libunwind)
