#ifndef PANTOOL_H
#define PANTOOL_H

#include "abstractperception.h"
#include "tooloptions/pan_menu.h"

class Pan : public AbstractPerception
{
public:
    Pan(QWidget *parent=0);
    ~Pan();
    void move(QMouseEvent *event);
    void press(QMouseEvent *event);
    void release(QMouseEvent *event);
    QWidget* getToolMenu();
};

#endif // PANTOOL_H
