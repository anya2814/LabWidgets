#ifndef WIN_H
#define WIN_H

#include <QtGui>
#include <QPushButton>
#include <QVBoxLayout>
#include "area.h"

class Window : public QWidget
{
protected:
    QTextCodec *codec;
    Area * area; // область отображения рисунка
    QPushButton * btn;
public:
    Window();
};

#endif // WIN_H
