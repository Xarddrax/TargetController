#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QSerialPort>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_comboBox_activated(const QString &commPort);
    void openSerialPort();

    void readSerial();

    void on_query_pressed();

    void on_connectButton_pressed();

    void on_target1button_pressed();

    void on_target2button_pressed();

    void on_target3button_pressed();

    void on_target4button_pressed();

    void on_target5button_pressed();

    void on_target6button_pressed();

    void on_target7button_pressed();

    void on_target8button_pressed();

    void on_target9button_pressed();

    void on_target10button_pressed();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
