#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogs/newdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
    ui->mdiArea->setTabsClosable(true);
    ui->mdiArea->setTabsMovable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addChildWindow(PaintWidget *widget)
{
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    QMdiSubWindow *mdiSubWindow = ui->mdiArea->addSubWindow(widget);
    QString title = widget->getImagePath().isEmpty() ? "Untitled" : widget->getImagePath();
    title = title + " [*]";
    mdiSubWindow->setWindowTitle(title);

    mdiSubWindow->installEventFilter(this);
    mdiSubWindow->show();
}

void MainWindow::addPaintWidget(PaintWidget *widget)
{
    addChildWindow(widget);
}

PaintWidget *MainWindow::createPaintWidget(const QString &imagePath) const
{
    return new PaintWidget(imagePath);
}

void MainWindow::on_actionOpen_triggered()
{
    const QString& fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                QStandardPaths::writableLocation(QStandardPaths::HomeLocation) ,
                                 tr(
                                "Image Files (*.png *.jpg *.jpeg *.gif);;"
                                "PNG(*.png);;"
                                "JPEG(*.jpg *.jpeg);;"
                                "GIF(*.gif);;"
                                "TIFF(*.tif *.tiff);;"
                                "BMP(*.bmp);;"
                                "ICO(*.ico)"));

    if (isFileValid(fileName)) {
        addPaintWidget(new PaintWidget(fileName));
    }
}

bool MainWindow::isFileValid(const QString& fileName)
{
    return isImageSupported(fileName);
}

bool MainWindow::isImageSupported(const QString &fileName)
{
    QImageReader reader(fileName);
    return reader.format() != "";
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionNew_triggered()
{
    NewDialog *newDialog = new NewDialog(this);
    newDialog->show();
}

void MainWindow::createNewDocument(const Document *document)
{

    addPaintWidget(new PaintWidget(document));
}
