cmake_minimum_required(VERSION 3.17)
project(oopTest)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_PREFIX_PATH C:\\Qt\\5.12.2\\mingw73_32\\lib\\cmake\\)
#set(CMAKE_PREFIX_PATH C:\\Qt\\5.12.2\\mingw73_32\\lib\\cmake\\Qt5Charts\\)
set(CMAKE_PREFIX_PATH C:\\Qt\\5.12.2\\mingw73_32\\)
# set(CMAKE_PREFIX_PATH D:/Qt/Qt5.4.0MinGw/5.4/mingw491_32)

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)

include_directories(GUI)

include_directories(headers)

add_executable(oopTest
        GUI/mainwindow.cpp
        GUI/headers/mainwindow.h
        headers/Controller.h
        headers/Iterator.h
        headers/Repo.h
        headers/FileRepo.h
        headers/IFileRepo.h
        headers/List.h
        headers/Utils.h
        Controller.cpp
        Iterator.cpp
        main.cpp
        Repo.cpp
        FileRepo.cpp
        List.cpp
        FileRepo.cpp
        Utils.cpp
        headers/FileRepo.h)

target_link_libraries(oopTest Qt5::Widgets)
target_link_libraries(oopTest C:/Users/Andrei/Documents/Qt_dll)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Charts REQUIRED)
find_package(Qt5Core REQUIRED)

qt5_use_modules(oopTest Widgets Charts)
qt5_wrap_cpp(gui_SRC gui.h gui.cpp)

#find_package(Qt5Widgets REQUIRED)
#find_package(Qt5Charts REQUIRED)

add_custom_target(Qt5CopyBinaries
        COMMAND ${CMAKE_COMMAND} -E copy_if_different C:/Users/Andrei/Documents/Qt_dll/libgcc_s_dw2-1.dll ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different C:/Users/Andrei/Documents/Qt_dll/Qt5Charts.dll ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different C:/Users/Andrei/Documents/Qt_dll/Qt5Chartsd.dll ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different C:/Users/Andrei/Documents/Qt_dll/Qt5Cored.dll ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different C:/Users/Andrei/Documents/Qt_dll/Qt5Guid.dll ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different C:/Users/Andrei/Documents/Qt_dll/Qt5Widgetsd.dll ${CMAKE_CURRENT_BINARY_DIR})

add_dependencies(oopTest Qt5CopyBinaries)

