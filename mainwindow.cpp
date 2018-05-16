#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->w1_move->setParent(NULL);

    view1 = new MyGraphicsView;
    view1->contents = ui->w1_move;
    scene1 = new QGraphicsScene(this);

    view1->setScene(scene1);
    QGraphicsProxyWidget *pwig = scene1->addWidget(ui->w1_move);
    ui->dockWidgetContents->layout()->addWidget(view1);

    view1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget->setEditTriggers(QAbstractItemView::DoubleClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MyGraphicsView::resizeEvent(QResizeEvent *event)
{

    contents->resize(event->size());

    QGraphicsView::resizeEvent(event);
}

void MainWindow::on_pushButton_clicked()
{
    QWidget* list_widget = new QWidget(this);
    list_widget->setStyleSheet("QWidget { background-color: transparent #3daee9; border:1px transparent #76797C; }");
    list_widget->setContentsMargins(0, 0, 0, 0);
    list_widget->resize(100,30);

    QHBoxLayout* h_layout = new QHBoxLayout(list_widget);
    h_layout->setContentsMargins(0, 0, 0, 0);
    h_layout->setSpacing(0);


    QLineEdit* name_lineedit = new QLineEdit(this);
    name_lineedit->setStyleSheet("QLineEdit{ background: transparent;}");
    name_lineedit->setMaximumSize(QSize(70, 20));
    name_lineedit->setMinimumSize(QSize(70, 20));
    name_lineedit->setContextMenuPolicy(Qt::NoContextMenu);
    name_lineedit->setText("name");


    QSpacerItem* h_spacer = new QSpacerItem(1,13,QSizePolicy::Expanding,QSizePolicy::Minimum);

    QCheckBox* trigger_active = new QCheckBox(list_widget);
    trigger_active->setMinimumWidth(50);
    QCheckBox* trigger_visible = new QCheckBox(list_widget);
    trigger_visible->setMinimumWidth(40);


    h_layout->addWidget(name_lineedit);
    h_layout->addItem(h_spacer);
    h_layout->addWidget(trigger_active);
    h_layout->addWidget(trigger_visible);


    int row = ui->listWidget->currentRow()+1;

    QListWidgetItem* list_item = new QListWidgetItem;

    ui->listWidget->insertItem(row,list_item);
    ui->listWidget->setItemWidget(list_item,list_widget);
}
