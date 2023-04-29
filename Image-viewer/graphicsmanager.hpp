#ifndef GRAPHICSMANAGER_HPP
#define GRAPHICSMANAGER_HPP

#include <QListWidgetItem>
#include <QLabel>

namespace GraphicsManager {

void changeImageLabel(QLabel *label, QListWidgetItem *newImage)
{
    QPixmap pixmap(QString(newImage->text()));
    label->setPixmap(pixmap);
}

void applyZoom(QLabel *label, double value)
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

void applyPan(QLabel *label, int x, int y)
{
    QPoint currentPos = label->pos();
    label->move(currentPos.x() + x, currentPos.y() + y);
}

void applyRotation(QLabel *label, int value)
{
    QPixmap pixmap(label->pixmap().copy());
    QTransform tr;
    tr.rotate(value);
    pixmap = pixmap.transformed(tr);
    label->setPixmap(pixmap);
}

void applyBrightness(QLabel *label, int value)
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

}

#endif // GRAPHICSMANAGER_HPP
