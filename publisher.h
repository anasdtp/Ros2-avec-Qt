#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <QString>
#include <QTimer>
#include <QObject>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include "dynamixel_sdk_custom_interfaces/msg/set_position.hpp"

typedef enum Publisher{
    NO_PUB,
    PUB_string,
    PUB_dynamixel,
}Publisher;

class publisher : public rclcpp::Node
{
public:
    explicit publisher();
};

class PUB
{
public:
    PUB();
    void publish(QString msg);
    void setPosition(int ID, int position);
    void reset(Publisher pub);
    void stop();
public slots:
    void spinOnce();
private:
    void callback_();
};
#endif // PUBLISHER_H
