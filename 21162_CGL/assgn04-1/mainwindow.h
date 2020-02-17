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
    void mousePressEvent(QMouseEvent *ev) ;
    void dda(int x1, int y1, int x2, int y2) ;
    void Draw() ;
    ~MainWindow();

private slots:
    void on_verticalScrollBar_valueChanged(int value);

    void on_verticalScrollBar_2_valueChanged(int value);

    void on_verticalScrollBar_3_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    int a[20],bb[20];
    int x1,y1,x2,y2,vertices;
    bool start;
};

#endif // MAINWINDOW_H
