#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QListWidget>
#include <QShortcut>

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
    /* Main Window slots */
    void onChooseFileButtonClicked();
    void onListWidgetItemClicked(QListWidgetItem *item);

    /* Zoom slots */
    void applyZoomIn();
    void applyZoomOut();

    /*Pan slots */
    void moveLabelUp();
    void moveLabelRight();
    void moveLabelDown();
    void moveLabelLeft();

    /* Rotation slots */
    void applyRotationRight();
    void applyRotationLeft();

    /* Brightness slots */
    void applyBrightnessUp();
    void applyBrightnessDown();
private:
    Ui::MainWindow *ui;

    /* label control */
    void displayLabel(QListWidgetItem *newImage);

    /* Zoom keys */
    QShortcut *keyZoomIn;
    QShortcut *keyZoomOut;

    /*Pan keys */
    QShortcut *keyUp;
    QShortcut *keyRight;
    QShortcut *keyDown;
    QShortcut *keyLeft;

    /* Rotation keys */
    QShortcut *keyRotationRight;
    QShortcut *keyRotationLeft;

    /* Brightness keys */
    QShortcut *keyBrightnessUp;
    QShortcut *keyBrightnessDown;

    /* Shortcuts definitions and connections */
    void defineShortcuts();
    void applyConnectors();
};
#endif // MAINWINDOW_HPP
