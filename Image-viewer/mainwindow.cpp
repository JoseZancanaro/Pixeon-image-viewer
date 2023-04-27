#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QLabel>
#include <QFileDialog>
#include <QListWidget>
#include <QMessageBox>
#include <QKeyEvent>

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
    QStringList filenames = QFileDialog::getOpenFileNames(this, tr("Choose a image file"), "../Images/", tr("Image Files (*.bmp *.png *.jpeg)"));

    if (!filenames.isEmpty()) {
        for (auto &filename : filenames) {
            auto rael = ui->listWidget->findItems(filename, Qt::MatchExactly);

            if (rael.empty()) {
                ui->listWidget->addItem(filename);
            }
        }
        this->showImage(ui->listWidget->item(0));
    }
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    this->showImage(item);
}

void MainWindow::showImage(QListWidgetItem *image)
{
    QPixmap pixmap(QString(image->text()));
    ui->imageLabel->setPixmap(pixmap);
}

void MainWindow::imageBrightness(QLabel *label, int value)
{
    QPixmap pixmap = label->pixmap().copy();
    QImage image = pixmap.toImage();

    for (int i = 0; i < image.width(); i++) {
        for (int j = 0; j < image.height(); j++) {
            QRgb pixel = image.pixel(i, j);

            int red = qRed(pixel);
            int green = qGreen(pixel);
            int blue = qBlue(pixel);

            red += value;
            green += value;
            blue += value;

            red = qBound(0, red + value, 255);
            green = qBound(0, green + value, 255);
            blue = qBound(0, blue + value, 255);

            image.setPixel(i, j, qRgb(red, green, blue));
        }
    }

    pixmap = QPixmap::fromImage(image);
    label->setPixmap(pixmap);
}

void MainWindow::imageRotate(QLabel *label, int value)
{
    QPixmap pixmap(label->pixmap().copy());
    QTransform tr;
    tr.rotate(value);
    pixmap = pixmap.transformed(tr);
    label->setPixmap(pixmap);
}

void MainWindow::imageZoom(QLabel *label, double value)
{
    QPixmap pixmap = label->pixmap();
    double currentScale = pixmap.devicePixelRatioF();
    double newScale = value * currentScale;

    int maxLabelWidth = label->maximumWidth();
    int maxLabelHeight = label->maximumHeight();

    int pixmapWidth = pixmap.width() * newScale;
    int pixmapHeight = pixmap.height() * newScale;

    if (pixmapWidth > maxLabelWidth || pixmapHeight > maxLabelHeight) {
        double maxWidthScale = maxLabelWidth / (double)pixmap.width();
        double maxHeightScale = maxLabelHeight / (double)pixmap.height();
        double maxScale = qMin(maxWidthScale, maxHeightScale);
        newScale = qMin(newScale, maxScale);
    }

    QPixmap newPixmap = pixmap.scaled(pixmap.size() * newScale);
    label->setPixmap(newPixmap);
}

void MainWindow::imagemPan(QLabel *label, int x, int y)
{
    QPoint currentPos = ui->imageLabel->pos();
    ui->imageLabel->move(currentPos.x() + x, currentPos.y() + y);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Right) {
        this->imageBrightness(ui->imageLabel, 5);
    } else if (event->key() == Qt::Key_Left) {
        this->imageBrightness(ui->imageLabel, -5);
    } else if (event->key() == Qt::Key_R) {
        this->imageRotate(ui->imageLabel, 90);
    } else if (event->key() == Qt::Key_E) {
        this->imageRotate(ui->imageLabel, -90);
    } else if (event->key() == Qt::Key_Plus) {
        this->imageZoom(ui->imageLabel, 1.2);
    } else if (event->key() == Qt::Key_Minus) {
        this->imageZoom(ui->imageLabel, 0.75);
    } else if (event->key() == Qt::Key_D) {
        this->imagemPan(ui->imageLabel, -10, 0);
    } else if (event->key() == Qt::Key_A) {
        this->imagemPan(ui->imageLabel, 10, 0);
    } else if (event->key() == Qt::Key_W) {
        this->imagemPan(ui->imageLabel, 0, 10);
    } else if (event->key() == Qt::Key_S) {
        this->imagemPan(ui->imageLabel, 0, -10);
    }
}
