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
    this->ui->lbEquationX->setText(" x = (cos(t))^3;");
    this->ui->lbEquationY->setText(" y = (sin(t))^3;");
    this->ui->FancyCurveGB->setVisible(false);
    this->ui->editA->setText(QString::number(11));
    this->ui->bEdit->setText(QString::number(6));

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
    this->ui->lbEquationX->setText(" x = (cos(t))^3;");
    this->ui->lbEquationY->setText(" y = (sin(t))^3;");
    this->ui->FancyCurveGB->setVisible(false);
}


void MainWindow::on_btnCicloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();
    update_ui();
    this->ui->FancyCurveGB->setVisible(false);
    this->ui->lbEquationX->setText(" x = 1.5 * (1 - cos(t));");
    this->ui->lbEquationY->setText(" y = 1.5 * (t - sin(t));");
}


void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderArea->repaint();
    update_ui();
    this->ui->FancyCurveGB->setVisible(false);
    this->ui->lbEquationX->setText(" x = 4 * (3 * cos(t) - cos(3*t));");
    this->ui->lbEquationY->setText(" y = 4 * (3 * sin(t) - sin(3*t));");
}


void MainWindow::on_btnHypoCicloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    this->ui->renderArea->repaint();
    update_ui();
    this->ui->FancyCurveGB->setVisible(false);
    this->ui->lbEquationX->setText(" x =  1.5 * (2 * cos(t) - cos(2*t));");
    this->ui->lbEquationY->setText(" y =  1.5 * (2 * sin(t) - sin(2*t));");
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


void MainWindow::on_btnFancy_clicked()
{
    this->ui->renderArea->setShape(RenderArea::FancyCurve);
    this->ui->FancyCurveGB->setVisible(true);
    this->ui->lbEquationX->setText(" x = a * cos(t) - b * cos((a/b)*t);");
    this->ui->lbEquationY->setText(" y = a * sin(t) - b * sin((a/b)*t);");
    this->ui->editA->setText(QString::number(this->ui->renderArea->getFancyCurveA()));
    this->ui->bEdit->setText(QString::number(this->ui->renderArea->getFancyCurveB()));
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_editA_textChanged(const QString &arg1)
{
    this->ui->renderArea->setFancyCurveParams(this->ui->editA->text().toInt(),this->ui->bEdit->text().toInt());
    this->ui->renderArea->repaint();

}


void MainWindow::on_bEdit_textChanged(const QString &arg1)
{
    this->ui->renderArea->setFancyCurveParams(this->ui->editA->text().toInt(),this->ui->bEdit->text().toInt());
    this->ui->renderArea->repaint();

}


void MainWindow::on_editA_editingFinished()
{
}


void MainWindow::on_editA_textEdited(const QString &arg1)
{
}

