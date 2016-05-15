#include "form.h"
#include "ui_form.h"
#include <QMediaPlayer>
#include <QTime>
#include <QTimer>
#include <QKeyEvent>
#include "time.h"
#include <QMessageBox>
#include <QThread>


QTimer *timer;
int cnt = 40;
int scorer=0;
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

}

void Form::timer_timeout()
{
    ui->label_2->show();
    ui->label_3->show();

    cnt--;
    ui->Counter->setText(QString::number(cnt));
    ui->label_6->setText(QString::number(scorer));
    if(cnt<=0)
    {
        timer -> stop();
        ui->pushButton_4->show();
        ui->pushButton_5->show();
    }
}


Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    ui->pushButton->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_timeout())) ;
    timer -> start(1000);

    QMediaPlayer* player = new QMediaPlayer(this);
    player -> setMedia(QUrl("qrc:/music/butterfly.mp3"));
    player->play();

    Form::movelabel();

}

void Form::movelabel()
{
    int x = 8;

    srand(time(NULL));


    while(1){
        if(cnt>0)
            n = rand()%2;
        else
            n=2;
        switch(n){
    case 0 :
        ui->label_7->show();
        while(ui->label_7->x()>0){
        ui->label_7->move(ui->label_7->x()-x,ui->label_7->y());
        t.start();
        while(t.elapsed() < 10)
            QCoreApplication::processEvents();
        if(ui->label_7->x()<=280)
        {
           ui->label_7->hide();
           ui->label_7->move(1490,250);
           break;
        }

    }
        break;

    case 1:
        ui->label_8->show();
        while(ui->label_8->x()>0)
        {
        ui->label_8->move(ui->label_8->x()-x,ui->label_8->y());

        t.start();
            while(t.elapsed() < 10)
             QCoreApplication::processEvents();
            if(ui->label_8->x()<=280)
            {
               ui->label_8-> hide();
               ui->label_8->move(1490,250);
               break;
            }

        }
        break;
    }
    t.start();
    while(t.elapsed()<50)
    QCoreApplication::processEvents();
   }
}


void Form::keyPressEvent(QKeyEvent *event)
{
    while (event->key() == Qt::Key_K)
   {
        if(ui->label_7->x()-380<=50 && ui->label_7->x() >= 310)
        {
            ui->label_7->hide();
            scorer++;
            ui->label_7->move(1490,250);
        }
            break;
    }

    while (event->key() == Qt::Key_J)
    {
        if(ui->label_8->x()-380<=50 && ui->label_8->x() >= 310)
        {
            ui->label_8->hide();
            scorer++;
            ui->label_8->move(1490,250);
        }
            break;
    }
}



void Form::on_pushButton_4_clicked()
{
    cnt = 40;
    scorer = 0;
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_timeout())) ;
    timer -> start(1000);

    QMediaPlayer* player = new QMediaPlayer(this);
    player -> setMedia(QUrl("qrc:/music/butterfly.mp3"));
    player->play();

    Form::movelabel();
}

void Form::on_pushButton_5_clicked()
{
    close();
}
