# Ros2-avec-Qt
Projet où j'ai découvers comment fonctionne ros2. 
Challange : faire fonctionner ros2 sur Qt. Faire un pub avec une interface graphique.
Second Challenge aprés celui-là : controler des dynamixel à partir de cette interface graphique en communiquant à une node dynamixel_node.

cd ros2_wrks/src/cmd_dynamixel_qt/launch
ros2 launch dynamixel_launch_cmd.xml

Travail sur Vscode. Utilisation de Qtdesigner pour le .ui






To create a simple publisher and subscriber with Qt, you can follow this tutorial:  https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Cpp-Publisher-And-Subscriber.html " and add the .ui file.

The steps to create a publisher with Qt for ROS2 are as follows:

    Create a new project using CMake in Qt (console application), and the location must be within ros2_ws/src/....
    Add the window files (.cpp, .h, and .ui).
    To use QApplication instead of QCoreApplication, add "find_package(Qt6 COMPONENTS Widgets REQUIRED)" in the CMakeLists.
    Design your application on Qt Designer, adding a QLineEdit and a QPushButton.
    Add the callback attached to the button (Go to slot -> clicked).
    Build and ensure everything is correct.
    Now, you have completed the work on Qt, and you will finish the work on VSCode because Qt doesn't recognize Ament.

To continue in VSCode:

    Open VSCode and navigate to the project folder.
    Add publisher.h and publisher.cpp files.
    Refer to the tutorial for further steps (CMakeLists, packages.xml, etc.) :  https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Cpp-Publisher-And-Subscriber.html "
    ...
    Open the terminal and navigate to ros2_ws/.
    Run colcon build.
    ...
