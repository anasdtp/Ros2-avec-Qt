#include "publisher.h"

rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
rclcpp::Publisher<dynamixel_sdk_custom_interfaces::msg::SetPosition>::SharedPtr publisher_dyna;

publisher::publisher(): Node("publisher")
{
    static bool pubCreated = false;
    if(!pubCreated){
        publisher_ = this->create_publisher<std_msgs::msg::String>("talker", 10);
        publisher_dyna = this->create_publisher<dynamixel_sdk_custom_interfaces::msg::SetPosition>("/set_position", 10);
        pubCreated = true;
    }
}

PUB::PUB(){
    static bool Init = false;
    if(!Init){
        spinOnce(); 
        Init = true;
    }
}

void PUB::spinOnce(){
    if(rclcpp::ok()){
        rclcpp::spin_some(std::make_shared<publisher>());//Elle n'est pas bloquante!! HOORAY!!
    }else{
        rclcpp::shutdown();
    }
}

/*Cela détruira le publisher et arrêtera la publication*/
void PUB::reset(Publisher pub){
    switch (pub)
    {
    case PUB_string:
        publisher_.reset();
        break;
    case PUB_dynamixel:
        publisher_dyna.reset();
        break;
    default:
        break;
    }
}

/*Pour une fermeture propre sans erreur*/
void PUB::stop() {
    // Arrêter la publication
    reset(PUB_dynamixel);  // Cela détruira le publisher et arrêtera la publication
    reset(PUB_string);
    // Arrêter le contexte ROS2
    rclcpp::shutdown();
}

void PUB::callback_(){
}

void PUB::publish(QString msg){
    static auto message = std_msgs::msg::String();      
    message.data = msg.toStdString().c_str();
    // RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    qDebug( "Publishing QString: '%s'", message.data.c_str() );
    publisher_->publish(message);
}

void PUB::setPosition(int ID, int position){
    static auto message = dynamixel_sdk_custom_interfaces::msg::SetPosition();      
    message.id = ID;
    message.position = position;
    // RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    qDebug( "Publishing Cmd Dynamixel n°%d à la pos : %d", message.id,  message.position);
    publisher_dyna->publish(message);
}