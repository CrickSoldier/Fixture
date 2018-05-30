#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QFileDialog>

#include "widgets/paintwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;

    void addChildWindow(PaintWidget *widget);
    void addPaintWidget(PaintWidget *widget);
    PaintWidget *createPaintWidget(const QString &imagePath) const;
};

#endif // MAINWINDOW_H
