#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QKeyEvent>
#include <QTimer>
#include <iostream>
using namespace std;


const QString p = "C:/Users/pryce/Documents/projekt/%1.png";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAudioOutput* audioOutput = new QAudioOutput(&player_);
    player_.setAudioOutput(audioOutput);
    player_.setSource(QUrl("C:/Users/pryce/Documents/projekt/muzyka.mp3"));
    //player_.setSource(QUrl(":muzyka.mp3"));
    audioOutput->setVolume(50);
    player_.play();


    //QPixmap(p.arg(0));
    ui->label->setPixmap(QPixmap(p.arg(0)));



    ui->label->setScaledContents(true);
}
//w-++
//c-clouds --
//l-light ++
//d-dry --
//m-majnkraft --
//n-ninja




void MainWindow::keyPressEvent(QKeyEvent* event)
{



    if (event->key() == Qt::Key_Escape)
    {
        qDebug() << "Esc pressed, goodbye";
        close();
        qApp->quit();
        return;
    }
    else if (event->key() == Qt::Key_G)
    {
        licznik=1;

    }
    else if (event->key() == Qt::Key_W)
    {
        licznik++;
        std::cout<<licznik<<endl;

    }
    else if (event->key() == Qt::Key_M)
    {
        licznik = 100;
        ui->label->setPixmap(QPixmap(p.arg(licznik)));
      // QTimer::singleShot(2000, this, SLOT(mySlot()));
       // licznik=1;
        // ui->label->setPixmap(QPixmap(p.arg(licznik)));
        QTimer::singleShot(2000, [this](){licznik=1;  ui->label->setPixmap(QPixmap(p.arg(licznik)));});
    }
    else if (event->key() == Qt::Key_N)
    {
        licznik = 101;
        ui->label->setPixmap(QPixmap(p.arg(licznik)));
        // QTimer::singleShot(2000, this, SLOT(mySlot()));
        // licznik=1;
        // ui->label->setPixmap(QPixmap(p.arg(licznik)));
        QTimer::singleShot(2000, [this](){licznik=1;  ui->label->setPixmap(QPixmap(p.arg(licznik)));});
    }
    else if (event->key() == Qt::Key_D)
    {
        if(licznik==100 || licznik ==101){
            licznik=1;
        }else{
        licznik--;
        }
    }
    else if ( event->key() == Qt::Key_C)
    {
        if(licznik ==100 || licznik==101){
            licznik=1;

        }else{
        licznik--;

        }
    }
    else if (event->key() == Qt::Key_L)
    {
        licznik++;
    }

    else{
        licznik=licznik;

    }


    ui->label->setPixmap(QPixmap(p.arg(licznik)));

    QMainWindow::keyPressEvent(event);
}


MainWindow::~MainWindow()
{
    delete ui;
}
