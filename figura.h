#ifndef FIGURA_H
#define FIGURA_H

#include <QtGui>
#include <QObject>
#include <QWidget>

class Figura
{
protected:
    int x,y,halflen,dx,dy,r;                    // x и y - координаты центра
    virtual void draw(QPainter *Painter)=0;
public:
    Figura(int X,int Y,int Halflen):            // конструктор класса Figura
        x(X),y(Y),halflen(Halflen){}
    void move(float Alpha,QPainter *Painter);   // метод для вращения фигуры
};

class MyLine:public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){}
};

class MyRect:public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){}
};

#endif // FIGURA_H
