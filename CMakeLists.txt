cmake_minimum_required(VERSION 3.14)

project(cmd_dynamixel_qt LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)## need this for qt auto generated headers to include!

set(dynamixel_sdk_custom_interfaces_DIR "/home/anas/ros2_humble/install/dynamixel_sdk_custom_interfaces/share/dynamixel_sdk_custom_interfaces/cmake") #pour que Vscode reconnaisse la librairie et que je puisse coder. A mettre en commentaire avant colcon build
# Spécifier les fichiers source
set(SOURCES
    main.cpp
    mainwindow.cpp
    publisher.cpp
)

# Inclure les fichiers d'en-tête
set(HEADERS
    mainwindow.h
    publisher.h
)

# Spécifier l'interface utilisateur
set(FORMS
    mainwindow.ui
)

##########################################
##  Be Carefull editing below this line ##
##########################################

find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
# Inclure les bibliothèques ROS 2
find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

find_package(dynamixel_sdk_custom_interfaces REQUIRED) #protocole, contenu des msg

add_executable(cmd_dynamixel_qt ${SOURCES} ${HEADERS} ${FORMS})

ament_target_dependencies(cmd_dynamixel_qt
   rclcpp
   std_msgs
   dynamixel_sdk_custom_interfaces
)

# Your package locations should be listed before other locations
include_directories(
       ${rclcpp_INCLUDE_DIRS}
       ${std_msgs_INCLUDE_DIRS}
       )

target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Widgets)



include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    DESTINATION lib/${PROJECT_NAME})

ament_package()
