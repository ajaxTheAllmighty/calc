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
    ~MainWindow();

private slots:
    void numberClick();
    void dotClick();
    void signClick();
    void operationClick();
    void clear();
    void compute();

    void on_dot_2_clicked();

    void on_sin_clicked();

    void on_cos_clicked();

    void on_tan_clicked();

    void on_ctg_clicked();

    void on_precent_clicked();

    void on_inverse_clicked();

    void on_sqrt_clicked();

    void on_pow_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
