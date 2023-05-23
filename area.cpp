#include "area.h"

Area::Area(QWidget *parent):QWidget(parent) // конструктор класса Area
{
    setFixedSize(QSize(300,200));           // задаем фиксированный размер
    myline=new MyLine(80,100,50);           // создаем линию
    myrect=new MyRect(220,100,50);          // создаем прямоугольник
    alpha=0;                                // угол поворота задаем равным 0
}

void Area::showEvent(QShowEvent *)          // включение таймера
{
    myTimer=startTimer(50);                 // создать таймер
}

void Area::paintEvent(QPaintEvent *)        // рисование пошагово перемещающихся фигур
{
    QPainter painter(this);                 // создаем объект QPainter
    painter.setPen(Qt::red);                // задаем цвет рисования
    myline->move(alpha,&painter);           // вызываем метод вращения для линии
    myrect->move(alpha*(-0.5),&painter);    // вызываем метод вращения для прямоугольника
}

void Area::timerEvent(QTimerEvent *event)   // инициация перерисовки Холста
{
    if (event->timerId() == myTimer)        // если наш таймер
    {
        alpha=alpha+0.2;
        update();                           // обновить внешний вид
    }
    else
        QWidget::timerEvent(event);         // иначе передать для стандартной
                                            // обработки
}

void Area::hideEvent(QHideEvent *)          // выключение таймера
{
    killTimer(myTimer);                     // уничтожить таймер
}

Area::~Area()                               // деструктор
{
    delete myline;
    delete myrect;
}

