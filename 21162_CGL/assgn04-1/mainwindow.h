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
    void dda(int x1, int y1, int x2, int y2) ;
    ~MainWindow();

private slots:
    void on_verticalScrollBar_valueChanged(int value);

    void on_verticalScrollBar_2_valueChanged(int value);

    void on_verticalScrollBar_3_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
