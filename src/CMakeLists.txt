cmake_minimum_required(VERSION 3.10)

project(fast-typing-app)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})

link_directories(${GTK3_LIBRARY_DIRS})

file(GLOB SOURCE_FILES
    "*.c"
    "views/*/*.c"
)

add_executable(fast-typing-app ${SOURCE_FILES})

target_link_libraries(fast-typing-app ${GTK3_LIBRARIES})