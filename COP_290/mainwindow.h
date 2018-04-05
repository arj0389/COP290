#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void draw();





    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
Ui::MainWindow *ui;
bool m_clicked;
};

#endif // MAINWINDOW_H




