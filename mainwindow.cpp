#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

#include <QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    update_ui();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui()
{
    this->ui->renderArea->repaint();
    this->ui->spinScale->setValue(this->ui->renderArea->shape()->scale());
    this->ui->spinInterval->setValue(this->ui->renderArea->shape()->intervalLength());
    this->ui->spinStepCount->setValue(this->ui->renderArea->shape()->stepCount());
}

void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderArea->setShape(new Astroid());
    update_ui();
}

void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(new Cycloid());
    update_ui();
}

void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(new HygensCycloid());
    update_ui();
}

void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderArea->setShape(new HypoCycloid());
    update_ui();
}

void MainWindow::on_btnLine_clicked()
{
    this->ui->renderArea->setShape(new Line());
    update_ui();
}

void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->shape()->setScale(scale);
    this->ui->renderArea->repaint();
}

void MainWindow::on_spinInterval_valueChanged(double interval)
{
    this->ui->renderArea->shape()->setInterval(interval);
    this->ui->renderArea->repaint();
}

void MainWindow::on_spinStepCount_valueChanged(int count)
{
    this->ui->renderArea->shape()->setStepCount(count);
    this->ui->renderArea->repaint();
}

void MainWindow::on_btnBackgroundColor_clicked()
{
    QColor backgroundColor = QColorDialog::getColor(Qt::white, this, "Select Color");
    this->ui->renderArea->setBackgroundColor(backgroundColor);
    this->ui->renderArea->repaint();
}

void MainWindow::on_btnLineColor_clicked()
{
    QColor lineColor = QColorDialog::getColor(Qt::white, this, "Select Color");
    this->ui->renderArea->setShapeColor(lineColor);
    this->ui->renderArea->repaint();
}
