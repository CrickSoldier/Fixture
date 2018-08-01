#include "document.h"

Document::Document(const QList<Layer *> layers, const QSharedDataPointer<Canvas> canvas) :
    _layers(layers),
    _canvas(canvas)
{
}


Document::Document(const QString &name)
{
    _name = name;
}
bool Document::isDocumentValid(const QString &fileName)
{
    return !fileName.endsWith(".fxt") && !fileName.endsWith(".fxd");
}

void Document::write(QDataStream &out) const
{
    out << _magicNum << _version << *_canvas.constData() << _layers;
}

void Document::read(QDataStream &in)
{
    QList<Layer*> layers;
    Canvas *canvas = new Canvas(_name);
    qint32 magicNum, version;

    in >> magicNum >> version;

    if (magicNum != _magicNum) {
        //emit badFileFormat("The file selected is either corrupted or not selected");
        return;
    }

    in  >> *canvas >> layers;

    _layers = layers;
    _canvas = QSharedDataPointer<Canvas>(canvas);
    // To check if canvas is working properly
    //qDebug() << _canvas->getResolution() << _canvas->getWidth();
}

QDataStream &operator <<(QDataStream &out, const Document &document)
{
    document.write(out);
    return out;
}

QDataStream &operator >>(QDataStream &in, Document &document)
{
    document.read(in);
    return in;
}
