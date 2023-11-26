#include <QApplication>
#include "mainwindow.h"
#include <QString>
#include <QThread>
// #include "publisher.h"
// #include "subscriber.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rclcpp::init(argc, argv);

    MainWindow w;
    w.show();
//    // Create an instance of TALKERThread
//    TALKERThread talkerThread(argc, argv);
//    LISTENERThread listenThread(argc, argv);
//    // Start the thread
//    //talkerThread.start();
//    listenThread.start();

    return a.exec();
}
