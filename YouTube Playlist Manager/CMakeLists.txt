cmake_minimum_required(VERSION 3.17)
project(aidk_916_Popa_Andrei_Calin)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_PREFIX_PATH C:\\Qt\\5.12.2\\mingw73_32\\lib\\cmake\\)
#set(CMAKE_PREFIX_PATH C:\\Qt\\5.12.2\\mingw73_32\\lib\\cmake\\Qt5Charts\\)
set(CMAKE_PREFIX_PATH C:\\Qt\\5.12.2\\mingw73_32\\)
# set(CMAKE_PREFIX_PATH D:/Qt/Qt5.4.0MinGw/5.4/mingw491_32)
#find_package(Qt5Widgets REQUIRED)
#find_package(Qt5Charts REQUIRED)

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)

include_directories(GUI)

include_directories(headers)

add_executable(aidk_916_Popa_Andrei_Calin
        GUI/adminadddialog.cpp
        GUI/headers/adminadddialog.h
        GUI/adminremovedialog.cpp
        GUI/headers/adminremovedialog.h
        GUI/adminupdatedialog.cpp
        GUI/headers/adminupdatedialog.h
        GUI/adminwindow.cpp
        GUI/headers/adminwindow.h
        GUI/mainwindow.cpp
        GUI/headers/mainwindow.h
        GUI/userwindow.cpp
        GUI/diagram.cpp
        GUI/headers/userwindow.h
        GUI/headers/diagram.h
        headers/Controller.h
        headers/CSVRepo.h
        headers/HTMLRepo.h
        headers/IFileRepo.h
        headers/Iterator.h
        headers/Repo.h
        headers/Tests.h
        headers/Tutorial.h
        headers/UI.h
        headers/Utils.h
        headers/Validator.h
        Controller.cpp
        CSVRepo.cpp
        HTMLRepo.cpp
        Iterator.cpp
        main.cpp
        Repo.cpp
        Tests.cpp
        Tutorial.cpp
        UI.cpp
        Utils.cpp
        Validator.cpp GUI/headers/PlayButtonDelegate.h GUI/PlayButtonDelegate.cpp
        GUI/TutorialModel.cpp
        GUI/headers/TutorialModel.h
        dark.qss
        )

target_link_libraries(aidk_916_Popa_Andrei_Calin Qt5::Widgets)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Charts REQUIRED)
find_package(Qt5Core REQUIRED)

qt5_use_modules(aidk_916_Popa_Andrei_Calin Widgets Charts)
qt5_wrap_cpp(gui_SRC gui.h gui.cpp)