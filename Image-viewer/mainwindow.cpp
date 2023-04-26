#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QLabel>
#include <QFileDialog>

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Image Viewer");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose a image file"), "../Images/", tr("Image Files (*.bmp *.png *.jpeg)"));

    QMessageBox::information(this, "..", filename);

    QPixmap pixmap(filename);

    ui->imageLabel->setPixmap(pixmap);
    //ui->label->setFixedSize(pixmap.width(), pixmap.height());
}

