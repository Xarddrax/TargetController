#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QApplication>
#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>

QString commPort;
QSerialPortInfo serialPortInfo;
QSerialPort serial;
QByteArray charBuffer;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) //populates the combo box with all availble comm ports.
        {
        ui->comboBox->addItem(serialPortInfo.portName());
        commPort=serialPortInfo.portName();
        }

}

MainWindow::~MainWindow()
{
    delete ui;
    serial.close();
}

void MainWindow::on_comboBox_activated(const QString &commPort) //selects the chosen comm port.
{
    ui->report->setText(commPort);
}

void MainWindow::openSerialPort()
{

    serial.setPortName(commPort);

    if(serial.open(QIODevice::ReadWrite))
     {
         qDebug("Serial Opened");
         ui->report->setStyleSheet("QLabel{background-color:'green';}");
         serial.setPort(serialPortInfo);
         serial.setBaudRate(QSerialPort::Baud9600);
         serial.setDataBits(QSerialPort::Data8);
         serial.setParity(QSerialPort::NoParity);
         serial.setStopBits(QSerialPort::OneStop);
         serial.setFlowControl(QSerialPort::NoFlowControl);
         connect(&serial, &QSerialPort::readyRead, this, &MainWindow::readSerial);
     }
     else
     {
         ui->report->setStyleSheet("QLabel{background-color:'red';}");
         qDebug ("Serial NOT Opened");
         qDebug() << serial.error();
         qDebug() << serial.errorString();
     }

}

void MainWindow::on_connectButton_pressed()
{
    openSerialPort();
}

void MainWindow::readSerial()
{
        qApp->processEvents();
        // Read data
        static QByteArray byteArray;
        byteArray += serial.readAll();

        //we want to read all message not only chunks
        if(!QString(byteArray).contains("\r"))
            return;

        //sanitize data
        QString data = QString( byteArray ).remove("\r").remove("\n");
        byteArray.clear();

        //Query from "WHO"
        if ((data.contains("1$")))
           {
            ui->target1button->setStyleSheet("background-color:green");
           }
        if ((data.contains("2$")))
           {
            ui->target2button->setStyleSheet("background-color:green");
           }
        if ((data.contains("3$")))
           {
            ui->target3button->setStyleSheet("background-color:green");
           }
        if ((data.contains("4$")))
           {
            ui->target4button->setStyleSheet("background-color:green");
           }
        if ((data.contains("5$")))
           {
            ui->target5button->setStyleSheet("background-color:green");
           }
        if ((data.contains("6$")))
           {
            ui->target6button->setStyleSheet("background-color:green");
           }
        if ((data.contains("7$")))
           {
            ui->target7button->setStyleSheet("background-color:green");
           }
        if ((data.contains("8$")))
           {
            ui->target8button->setStyleSheet("background-color:green");
           }
        if ((data.contains("9$")))
           {
            ui->target9button->setStyleSheet("background-color:green");
           }
        if ((data.contains("X$")))
           {
            ui->target10button->setStyleSheet("background-color:green");
           }


        //Target1
        if ((data.contains("11000"))||(data.contains("10000")))
            {
            ui->target1image->setGeometry(80, 500, 91, 21);
            }
        if ((data.contains("11100"))||(data.contains("10100")))
            {
            ui->target1image->setGeometry(80, 330, 91, 191);
            }

        //Target2
        if ((data.contains("21000"))||(data.contains("20000")))
            {
            ui->target2image->setGeometry(250, 500, 91, 21);
            }
        if ((data.contains("21100"))||(data.contains("20100")))
            {
            ui->target2image->setGeometry(250, 330, 91, 191);
            }

        //Target3
        if ((data.contains("31000"))||(data.contains("30000")))
             {
             ui->target3image->setGeometry(420, 500, 91, 21);
             }
        if ((data.contains("31100"))||(data.contains("30100")))
             {
             ui->target3image->setGeometry(420, 330, 91, 191);
             }

        //Target4
        if ((data.contains("41000"))||(data.contains("40000")))
             {
             ui->target4image->setGeometry(590, 500, 91, 21);
             }
        if ((data.contains("41100"))||(data.contains("40100")))
             {
             ui->target4image->setGeometry(590, 330, 91, 191);
             }

        //Target5
        if ((data.contains("51000"))||(data.contains("50000")))
             {
             ui->target5image->setGeometry(760, 500, 91, 21);
             }
        if ((data.contains("51100"))||(data.contains("50100")))
             {
             ui->target5image->setGeometry(760, 330, 91, 191);
             }

        //Target6
        if ((data.contains("61000"))||(data.contains("60000")))
             {
             ui->target6image->setGeometry(760, 500, 91, 21);
             }
        if ((data.contains("61100"))||(data.contains("60100")))
             {
             ui->target6image->setGeometry(760, 330, 91, 191);
             }

        //Target7
        if ((data.contains("71000"))||(data.contains("70000")))
             {
             ui->target7image->setGeometry(760, 500, 91, 21);
             }
        if ((data.contains("71100"))||(data.contains("70100")))
             {
             ui->target7image->setGeometry(760, 330, 91, 191);
             }

        //Target8
        if ((data.contains("81000"))||(data.contains("80000")))
             {
             ui->target8image->setGeometry(760, 500, 91, 21);
             }
        if ((data.contains("81100"))||(data.contains("80100")))
             {
             ui->target8image->setGeometry(760, 330, 91, 191);
             }

        //Target9
        if ((data.contains("91000"))||(data.contains("90000")))
             {
             ui->target9image->setGeometry(760, 500, 91, 21);
             }
        if ((data.contains("91100"))||(data.contains("90100")))
             {
             ui->target9image->setGeometry(760, 330, 91, 191);
             }

        //Target10
        if ((data.contains("X1000"))||(data.contains("X0000")))
             {
             ui->target10image->setGeometry(760, 500, 91, 21);
             }
        if ((data.contains("X1100"))||(data.contains("X0100")))
             {
             ui->target10image->setGeometry(760, 330, 91, 191);
             }


        // Print data
        ui->readout->setText(data);
        qDebug()<< data;
}


void MainWindow::on_target1button_pressed()
{
    serial.write("1 up\r");
    serial.waitForBytesWritten(250);
}

void MainWindow::on_target2button_pressed()
{
    serial.write("2 up\r");
    serial.waitForBytesWritten(250);
}

void MainWindow::on_target3button_pressed()
{
    serial.write("3 up\r");
    serial.waitForBytesWritten(250);
}

void MainWindow::on_target4button_pressed()
{
    serial.write("4 up\r");
    serial.waitForBytesWritten(250);
}

void MainWindow::on_target5button_pressed()
{
    serial.write("5 up\r");
    serial.waitForBytesWritten(250);
}
void MainWindow::on_target6button_pressed()
{
    serial.write("6 up\r");
    serial.waitForBytesWritten(250);
}

void MainWindow::on_target7button_pressed()
{
    serial.write("7 up\r");
    serial.waitForBytesWritten(250);
}

void MainWindow::on_target8button_pressed()
{
    serial.write("8 up\r");
    serial.waitForBytesWritten(250);
}

void MainWindow::on_target9button_pressed()
{
    serial.write("9 up\r");
    serial.waitForBytesWritten(250);
}

void MainWindow::on_target10button_pressed()
{
    serial.write("X up\r");
    serial.waitForBytesWritten(250);
}

void MainWindow::on_query_pressed()
{
    serial.write("WHO\r");
    serial.waitForBytesWritten(250);
}


