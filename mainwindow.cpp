#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->spinScale->setValue(this->ui->renderArea->scale());
    this->ui->spinLength->setValue(this->ui->renderArea->internalLength());
    this->ui->spinBox->setValue(this->ui->renderArea->stepCount());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui()
{
    this->ui->spinScale->setValue(this->ui->renderArea->scale());
    this->ui->spinLength->setValue(this->ui->renderArea->internalLength());
    this->ui->spinBox->setValue(this->ui->renderArea->stepCount());
}


void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();
    update_ui();

}


void MainWindow::on_btnCicloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_btnHypoCicloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_btnBGColor_clicked()
{
    QColor color = QColorDialog::getColor(this->ui->renderArea->backgroundColor(), this, "Select Color");
    this->ui->renderArea->setBackgroundColor(color);
}


void MainWindow::on_pushButton_2_clicked()
{
    QColor color = QColorDialog::getColor(this->ui->renderArea->shapeColor(), this, "Select Color");
    this->ui->renderArea->setShapeColor(color);
}


void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->setScale(scale);
}
void MainWindow::on_Length_valueChanged(double intLenth)
{
    this->ui->renderArea->setInternalLength(intLenth);
}

void MainWindow::on_spinLength_valueChanged(double intLenth)
{
    this->ui->renderArea->setInternalLength(intLenth);
}


void MainWindow::on_spinBox_valueChanged(int cnt)
{
    this->ui->renderArea->setStepCount(cnt);
}

