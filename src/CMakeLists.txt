#  Sets up the minimum required CMake version
#
cmake_minimum_required(VERSION 3.10)

#  Sets up the project name
#
project(Fast-Typing)

#  Requires the package config
#
find_package(PkgConfig REQUIRED)

#  Requires the GTK3
#
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

#  Includes the GTK3 directories
#
include_directories(${GTK3_INCLUDE_DIRS})

#  Links the GTK3 library directories
#
link_directories(${GTK3_LIBRARY_DIRS})

#  Adds the compilation flags
#
add_definitions(${GTK3_CFLAGS_OTHER})

#  Attaches -rdynamic compilation flag
#
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -rdynamic")

#  Sets up the required source files
#
set(SOURCES
    main.c
    collections/Words.c
    extensions/data/Statistics.c
    extensions/signals/Detach.c
    views/setup/SetupView.c
    views/summary/SummaryView.c
    views/training/TrainingView.c
)

#  Sets up the required header files
#
set(HEADERS
    collections/Words.h
    enumerations/TrainingModes.h
    extensions/data/Statistics.h
    extensions/signals/Detach.h
    views/setup/SetupView.h
    views/setup/SetupViewWidgets.h
    views/setup/SetupViewVariables.h
    views/setup/SetupViewFunctionality.h
    views/summary/SummaryView.h
    views/summary/SummaryViewWidgets.h
    views/summary/SummaryViewVariables.h
    views/summary/SummaryViewFunctionality.h
    views/training/TrainingView.h
    views/training/TrainingViewWidgets.h
    views/training/TrainingViewVariables.h
    views/training/TrainingViewFunctionality.h
)

#  Sets up the required resources
#
set(RESOURCES
    resources/Dictionary.txt
    resources/SetupViewUI.glade
    resources/SummaryViewUI.glade
    resources/TrainingViewUI.glade
)

#  Copies the resources into the binary_dir/resources to allow relative paths
#
file(COPY ${RESOURCES} DESTINATION ${CMAKE_BINARY_DIR}/resources)

#  Makes an executable of all the files
#
add_executable(Fast-Typing ${SOURCES} ${HEADERS} ${RESOURCES})

#  Links all the GTK3 libraries
#
target_link_libraries(Fast-Typing ${GTK3_LIBRARIES})
