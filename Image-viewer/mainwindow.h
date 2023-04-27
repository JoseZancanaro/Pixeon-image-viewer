#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showImage(QListWidgetItem *image);
    void keyPressEvent(QKeyEvent *event) override;

    void imageBrightness(QLabel *label, int value);
    void imageRotate(QLabel *label, int value);
    void imageZoom(QLabel *label, double value);
    void imagemPan(QLabel *label, int x, int y);
private slots:
    void on_pushButton_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
