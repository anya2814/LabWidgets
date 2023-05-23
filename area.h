#ifndef AREA_H
#define AREA_H

#include "figura.h"

class Area : public QWidget         // класс окна, в котором рисуются фигуры
{
    int myTimer; // идентификатор таймера
    float alpha; // угол поворота

public:
    Area(QWidget *parent = 0);      // конструктор
    ~Area();                        // деструктор
    MyLine *myline;                 // указатель на объект линия
    MyRect *myrect;                 // указатель на объект прямоугольник

protected:
    // обработчики событий
    void paintEvent(QPaintEvent *event);    // рисование пошагово перемещающихся фигур
    void timerEvent(QTimerEvent *event);    // инициация перерисовки Холста
    void showEvent(QShowEvent *event);      // включение таймера
    void hideEvent(QHideEvent *event);      // выключение таймера
};

#endif // AREA_H
