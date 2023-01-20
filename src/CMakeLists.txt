cmake_minimum_required(VERSION 3.10)

project(Fast-Typing-Training)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})

link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -rdynamic")

set(SOURCES
    main.c
    extensions/signals/Detach.c
    extensions/words/Dictionary.c
    extensions/statistics/Statistics.c
    views/setup/SetupView.c
    views/summary/SummaryView.c
    views/training/TrainingView.c
)

set(HEADERS
    extensions/signals/Detach.h
    extensions/words/Dictionary.h
    extensions/statistics/Statistics.h
    views/setup/SetupViewBehavior.h
    views/setup/SetupViewWidgets.h
    views/summary/SummaryViewBehavior.h
    views/summary/SummaryViewWidgets.h
    views/training/TrainingViewBehavior.h
    views/training/TrainingViewVariables.h
    views/training/TrainingViewWidgets.h
)

set(RESOURCES
    resources/setup.glade
    resources/summary.glade
    resources/training.glade
    resources/statistics.txt
    resources/words.txt
)

file(COPY ${RESOURCES} DESTINATION ${CMAKE_BINARY_DIR})

add_executable(Fast-Typing-Training ${SOURCES} ${HEADERS} ${RESOURCES})

target_link_libraries(Fast-Typing-Training ${GTK3_LIBRARIES})