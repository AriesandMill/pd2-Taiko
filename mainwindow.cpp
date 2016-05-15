#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   // setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    player -> setMedia(QUrl("qrc:/music/flowerdance.mp3"));
    player -> play();
}

MainWindow::~MainWindow()

{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    form.setFixedSize(1600,900);
    form.show();
    player->stop();
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}
