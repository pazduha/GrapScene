#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QGraphicsLinearLayout>
#include <QLineEdit>
#include <QListWidget>


namespace Ui {
class MainWindow;
}


class MyGraphicsView : public QGraphicsView
{

protected:

    void MyGraphicsView::resizeEvent(QResizeEvent *event);

public:

    QWidget* contents;


};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene* scene1;
    MyGraphicsView* view1;



};

#endif // MAINWINDOW_H
