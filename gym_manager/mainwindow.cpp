#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coursedialog.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->taekwondoButton, &QPushButton::clicked, this, &MainWindow::openCourse);
    connect(ui->womenButton, &QPushButton::clicked, this, &MainWindow::openCourse);
    connect(ui->musculationButton, &QPushButton::clicked, this, &MainWindow::openCourse);
    connect(ui->addCourseButton, &QPushButton::clicked, this, &MainWindow::openCourse);
    connect(ui->quitButton, &QPushButton::clicked, this, &MainWindow::quitApp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openCourse()
{
    CourseDialog dlg(this);
    dlg.exec();
}

void MainWindow::quitApp()
{
    close();
}
