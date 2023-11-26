#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "publisher.h"
//#include "listener_tuto/subscriber.h"
#include <QCloseEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    // Redéfinition de l'événement closeEvent
    void closeEvent(QCloseEvent *event) override {
        qDebug("App closing...");
        pub_->stop();
        delete pub_;
        // Laisser la fenêtre se fermer normalement
        event->accept();
    }
private slots:
    void on_sendButton_Dyna_clicked();
    void on_sendButton_Dyna_simu_clicked();
    void on_sendButton_Dyna_rotation_clicked();

private:
    Ui::MainWindow *ui;
    PUB *pub_;
//    void RxManage();
};

#endif // MAINWINDOW_H
