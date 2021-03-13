#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    this->ui->spinScale->setValue(this->ui->renderArea->shape()->scale());
    this->ui->spinInterval->setValue(this->ui->renderArea->shape()->intervalLength());
}

void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderArea->setShape(new Astroid());
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(new Cycloid());
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(new HygensCycloid());
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderArea->setShape(new HypoCycloid());
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnLine_clicked()
{
    this->ui->renderArea->setShape(new Line());
    this->ui->renderArea->repaint();
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
