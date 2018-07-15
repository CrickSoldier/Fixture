#ifndef DRAWING_H
#define DRAWING_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QImageReader>
#include <QWheelEvent>
#include <QScrollBar>
#include <QObject>
#include <QWidget>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>

#include "../layers/rasterlayer.h"

class Drawing : public QGraphicsScene
{
    Q_OBJECT

public:
    Drawing(QWidget *widget,QImage &image);
    ~Drawing();

private:
    int _height,_width;

    void dragEnterEvent(QGraphicsSceneDragDropEvent *e);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *e);
    void dropEvent(QGraphicsSceneDragDropEvent *e);

signals:
    void importAvailable(const QString &fileName);

};

#endif // DRAWING_H
