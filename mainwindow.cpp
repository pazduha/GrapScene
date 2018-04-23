#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->w1_move->setParent(NULL);

    view1 = new QGraphicsView(this);
    scene1 = new QGraphicsScene(this);

    view1->setScene(scene1);
    QGraphicsProxyWidget *pwig = scene1->addWidget(ui->w1_move);
    ui->dockWidgetContents->layout()->addWidget(view1);

}

MainWindow::~MainWindow()
{
    delete ui;
}
