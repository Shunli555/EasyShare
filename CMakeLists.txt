cmake_minimum_required(VERSION 3.23)
project(EasyShare)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt/6.5.1/bin")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(EasyShare src/main.cpp src/ui/MainAppPage.cpp src/ui/MainAppPage.h src/data/Message.cpp src/data/Message.h)
target_link_libraries(EasyShare
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

