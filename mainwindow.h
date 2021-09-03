#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAstroid_clicked();

    void on_btnCicloid_clicked();

    void on_btnHuygens_clicked();

    void on_btnHypoCicloid_clicked();

    void on_btnBGColor_clicked();

    void on_pushButton_2_clicked();

    void on_spinScale_valueChanged(double arg1);

    void on_Length_valueChanged(double arg1);

    void on_spinLength_valueChanged(double arg1);

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    void update_ui();
};
#endif // MAINWINDOW_H
