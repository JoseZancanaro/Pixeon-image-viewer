#ifndef GRAPHICSMANAGER_HPP
#define GRAPHICSMANAGER_HPP

#include <QListWidgetItem>
#include <QLabel>


namespace GraphicsManager {

void changeImageLabel(QLabel *label, QListWidgetItem *item)
{
    QString filename = item->text();

    QPixmap newImage(filename);
    label->setPixmap(newImage);
}

void applyZoom(QLabel *label, double value)
{
    QPixmap pixmap = label->pixmap().copy();
    double scaleWidth = pixmap.width() * value;
    double scaleHeight = pixmap.height() * value;

    pixmap = pixmap.scaled(scaleWidth, scaleHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    label->setPixmap(pixmap);
}

void applyPan(QLabel *label, QPoint shift)
{
    label->move(label->pos().x() + shift.x(), label->pos().y() + shift.y());
}

void applyRotation(QLabel *label, int angle)
{
    QPixmap pixmap = label->pixmap().copy();

    pixmap = pixmap.transformed(QTransform().rotate(angle), Qt::SmoothTransformation);
    label->setPixmap(pixmap);
}

void applyBrightness(QLabel *label, int value)
{
    QPixmap pixmap = label->pixmap().copy();
    QImage image = pixmap.toImage();

    for (int i = 0; i < image.width(); i++) {
        for (int j = 0; j < image.height(); j++) {
            QRgb pixel = image.pixel(i, j);
            QColor color(pixel);

            int newRed = qBound(0, color.red() + value, 255);
            int newGreen = qBound(0, color.green() + value, 255);
            int newBlue = qBound(0, color.blue() + value, 255);

            color.setRed(newRed);
            color.setGreen(newGreen);
            color.setBlue(newBlue);

            image.setPixel(i, j, color.rgb());
        }
    }

    label->setPixmap(QPixmap::fromImage(image));
}

}

#endif // GRAPHICSMANAGER_HPP
