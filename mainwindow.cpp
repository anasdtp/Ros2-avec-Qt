#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

//TALKER talker_;

//DATA rxMsg[SIZE_FIFO];
//unsigned char FIFO_ecriture = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pub_ = (new PUB());

//    QTimer *timer= new QTimer(this); timer->setInterval(100); // Connecter le signal timeout() du QTimer à votre fonction
//    connect(timer, &QTimer::timeout, this, &MainWindow::RxManage); // Démarrer le QTimer
//    timer->start();
}

MainWindow::~MainWindow()
{
    rclcpp::shutdown();
    delete ui;
}

void MainWindow::on_sendButton_Dyna_clicked()
{
    static uint8_t id = 0; static uint16_t pos = 0;
    id = ui->lineEdit_Dyna_ID->text().toInt();
    pos = ui->lineEdit_Dyna_Position->text().toInt();
    qDebug("   PUB");
    pub_->setPosition(id, pos);
}

void MainWindow::on_sendButton_Dyna_simu_clicked(){
    static uint8_t id = 0, id2 = 0; static uint16_t pos = 0, pos2 = 0;

    id  = (uint8_t)ui->lineEdit_Dyna_simu_ID1->text().toInt();
    id2 = (uint8_t)ui->lineEdit_Dyna_simu_ID2->text().toInt();

    pos  = (uint16_t)ui->lineEdit_Dyna_simu_Position1->text().toInt();
    pos2 = (uint16_t)ui->lineEdit_Dyna_simu_Position2->text().toInt();

    qDebug(" PUB");
    pub_->setPosition(id, pos);
    pub_->setPosition(id2, pos2);
}

void MainWindow::on_sendButton_Dyna_rotation_clicked()
{
    static uint8_t id = 0; static uint16_t rot = 0;
    id = (uint8_t)ui->lineEdit_Dyna_rotation_ID->text().toInt();
    rot= (uint16_t)ui->lineEdit_Dyna_rotation_vitesse->text().toInt();

    qDebug( "Publishing Cmd Rotation Dynamixel n°%d à la vit : %d", id,  rot);
    qDebug("ERREUR ! La fonction rotation continue des Dynamixel n'est pas encore faite");
    // pub_->setPosition(id, pos);
}

// void MainWindow::on_sendButton_Dyna_clicked()
// {
//     static int count = 0;
//     count++;
//     ui->lineEdit_Dyna_Position->setText(QString::number(count));
//     if(count >5){
//         qDebug("   PUB");
//         pub_->publish("Hello, world! " + QString::number(count));
//     }
// }
//void MainWindow::RxManage(){
//    static signed char FIFO_lecture=0,FIFO_occupation=0,FIFO_max_occupation=0;

//    FIFO_occupation=FIFO_ecriture-FIFO_lecture;
//    if(FIFO_occupation<0){FIFO_occupation=FIFO_occupation+SIZE_FIFO;}
//    if(FIFO_max_occupation<FIFO_occupation){FIFO_max_occupation=FIFO_occupation;}

//    if(!FIFO_occupation){return;}

//    ui->textEdit->append(rxMsg[FIFO_lecture].msg);

//    FIFO_lecture=(FIFO_lecture+1)%SIZE_FIFO;
//}