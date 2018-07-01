#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include "../model/document.h"
#include "../mainwindow.h"
#include <QDialog>

namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDialog(QWidget *parent = 0);
    ~NewDialog();
    Document *getDocument() const;

signals:
    void documentAvailable(const Document *document);

private slots:
    void on_actionOk_clicked();
    //void generateDocument();

    void on_actionCancel_clicked();

private:
    Ui::NewDialog *ui;
    Document *document;
};

#endif // NEWDIALOG_H
