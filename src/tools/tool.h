#ifndef TOOL_H
#define TOOL_H

#include <QAction>
#include "../layers/layer.h"
class Tool : public QAction
{
public:
    enum ToolGroup {
        SELECTION,
        CREATION,
        MODIFICATION,
        PERCEPTION
    };

    enum ToolType {
        TRANSFORM,
        PAN
    };

    Tool(QIcon ico, const QString &name, QCursor cur, ToolGroup group, ToolType type, QWidget* parent = 0);
    ~Tool();

    inline const QCursor getToolCursor() { return _cursor; }
    inline const QString getToolName() { return _name; }
    inline ToolGroup getToolGroup() { return _group; }
    inline ToolType getToolType() { return _type; }

public:
    virtual void move(QMouseEvent *event) = 0;
    virtual void press(QMouseEvent *event) = 0;
    virtual void release(QMouseEvent *event) = 0;
    virtual QWidget* getToolMenu() = 0;

private:
    QCursor _cursor;
    QString _name;
    ToolGroup _group;
    ToolType _type;

    void drawRectItem();
    virtual void connectMenu() = 0;

};

#endif // TOOL_H
