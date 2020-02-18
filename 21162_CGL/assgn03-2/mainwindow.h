#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void dda(int x1, int y1, int x2, int y2);
    void clipping(int xs1,int ys1,int xe1,int ye1);
    int compute(int x11,int y11);
    ~MainWindow();

private slots:
    void mousePressEvent(QMouseEvent *eve);
    void mouseReleaseEvent(QMouseEvent *event);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
