cmake_minimum_required(VERSION 3.10)
project(Fast-Typing-Training)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -rdynamic")

include_directories(views)

# Use relative path for the glade files
configure_file(views/setup/SetupUI.glade ${CMAKE_CURRENT_BINARY_DIR}/views/setup COPYONLY)
configure_file(views/summary/SummaryUI.glade ${CMAKE_CURRENT_BINARY_DIR}/views/summary COPYONLY)
configure_file(views/training/TrainingUI.glade ${CMAKE_CURRENT_BINARY_DIR}/views/training COPYONLY)
configure_file(database/words.txt ${CMAKE_CURRENT_BINARY_DIR}/database COPYONLY)

# Use relative path for the source files
add_executable(Fast-Typing-Training
    main.c
    views/setup/SetupView.c
    views/setup/SetupViewBehavior.h
    views/setup/SetupViewWidgets.h
    views/summary/SummaryView.c
    views/summary/SummaryViewBehavior.h
    views/summary/SummaryViewWidgets.h
    views/training/TrainingView.c
    views/training/TrainingViewBehavior.h
    views/training/TrainingViewWidgets.h
    extensions/signals/SignalsDetach.c
    extensions/signals/SignalsDetach.h
    extensions/database/Dictionary.c
    extensions/database/Dictionary.h
)

target_link_libraries(Fast-Typing-Training ${GTK3_LIBRARIES})