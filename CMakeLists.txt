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
        Network
        REQUIRED)

add_executable(EasyShare src/main.cpp src/ui/MainAppPage.cpp src/ui/MainAppPage.h src/data/Message.cpp src/data/Message.h src/sockio/Server.cpp src/sockio/Server.h src/sockio/BroadCaster.cpp src/sockio/BroadCaster.h src/sockio/PartnerScanner.cpp src/sockio/PartnerScanner.h src/sockio/Client.cpp src/sockio/Client.h src/sockio/NetConfig.h src/data/DeviceInfo.cpp src/data/DeviceInfo.h src/utils/StorageUtil.h)
target_link_libraries(EasyShare
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt6::Network
        )

