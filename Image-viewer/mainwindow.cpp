#include "mainwindow.hpp"
#include "./ui_mainwindow.h"
#include "graphicsmanager.hpp"

#include <QFileDialog>
#include <QListWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Image Viewer");

    this->defineShortcuts();
    this->applyConnectors();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::defineShortcuts()
{
    /* Zoom keys */
    this->keyZoomIn = new QShortcut(QKeySequence(Qt::Key_Plus), this);
    this->keyZoomOut = new QShortcut(QKeySequence(Qt::Key_Minus), this);

    /*Pan keys */
    this->keyUp = new QShortcut(QKeySequence(Qt::Key_W), this);
    this->keyRight = new QShortcut(QKeySequence(Qt::Key_D), this);
    this->keyDown = new QShortcut(QKeySequence(Qt::Key_S), this);
    this->keyLeft = new QShortcut(QKeySequence(Qt::Key_A), this);

    /* Rotation keys */
    this->keyRotationRight = new QShortcut(QKeySequence(Qt::Key_R), this);
    this->keyRotationLeft = new QShortcut(QKeySequence(Qt::Key_E), this);

    /* Brightness keys */
    this->keyBrightnessUp = new QShortcut(QKeySequence(Qt::Key_Right), this);
    this->keyBrightnessDown = new QShortcut(QKeySequence(Qt::Key_Left), this);
}

void MainWindow::applyConnectors()
{
    /* Main Window connectors */
    connect(this->ui->chooseFileButton, &QPushButton::clicked, this, &MainWindow::onChooseFileButtonClicked);
    connect(this->ui->listWidget, &QListWidget::itemClicked, this, &MainWindow::onListWidgetItemClicked);

    /* Zoom connectors */
    connect(this->keyZoomIn, SIGNAL(activated()), this, SLOT(applyZoomIn()));
    connect(this->keyZoomOut, SIGNAL(activated()), this, SLOT(applyZoomOut()));

    /*Pan connectors */
    connect(this->keyUp, SIGNAL(activated()), this, SLOT(moveLabelUp()));
    connect(this->keyRight, SIGNAL(activated()), this, SLOT(moveLabelRight()));
    connect(this->keyDown, SIGNAL(activated()), this, SLOT(moveLabelDown()));
    connect(this->keyLeft, SIGNAL(activated()), this, SLOT(moveLabelLeft()));

    /* Rotation connectors */
    connect(this->keyRotationRight, SIGNAL(activated()), this, SLOT(applyRotationRight()));
    connect(this->keyRotationLeft, SIGNAL(activated()), this, SLOT(applyRotationLeft()));

    /* Brightness connectors */
    connect(this->keyBrightnessUp, SIGNAL(activated()), this, SLOT(applyBrightnessUp()));
    connect(this->keyBrightnessDown, SIGNAL(activated()), this, SLOT(applyBrightnessDown()));
}

void MainWindow::onChooseFileButtonClicked()
{
    QStringList filenames = QFileDialog::getOpenFileNames(this, tr("Choose a image file"), "../Images/", tr("Image Files (*.bmp *.png *.jpeg)"));
    this->insertWidgetItem(filenames);
}

void MainWindow::onListWidgetItemClicked(QListWidgetItem *item)
{
    this->displayLabel(item);
}

void MainWindow::insertWidgetItem(QStringList filenames)
{
    if (!filenames.isEmpty()) {
        for (auto &filename : filenames) {
            if (ui->listWidget->findItems(filename, Qt::MatchExactly).empty()) {
                ui->listWidget->addItem(filename);
            }

        /* Always display the first item */
        this->displayLabel(ui->listWidget->item(0));
        }
    }
}

void MainWindow::displayLabel(QListWidgetItem *item)
{
    GraphicsManager::changeImageLabel(ui->label, item);
}

void MainWindow::applyZoomIn()
{
    GraphicsManager::applyZoom(ui->label, 1.25);
}

void MainWindow::applyZoomOut()
{
    GraphicsManager::applyZoom(ui->label, 0.75);
}

void MainWindow::moveLabelUp()
{
    GraphicsManager::applyPan(ui->label, {0, -10});
}

void MainWindow::moveLabelRight()
{
    GraphicsManager::applyPan(ui->label, {10, 0});
}

void MainWindow::moveLabelDown()
{
    GraphicsManager::applyPan(ui->label, {0, 10});
}

void MainWindow::moveLabelLeft()
{
    GraphicsManager::applyPan(ui->label, {-10, 0});
}

void MainWindow::applyRotationRight()
{
    GraphicsManager::applyRotation(ui->label, 90);
}

void MainWindow::applyRotationLeft()
{
    GraphicsManager::applyRotation(ui->label, -90);
}

void MainWindow::applyBrightnessUp()
{
    GraphicsManager::applyBrightness(ui->label, 3);
}

void MainWindow::applyBrightnessDown()
{
    GraphicsManager::applyBrightness(ui->label, -3);
}
