#ifndef WIN_H
#define WIN_H

#include <QtGui>
#include <QWidget>
#include <QObject>
#include <QtWidgets>

class Counter:public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent=0):  // конструктор объекта Counter (строка ввода)
        QLineEdit(contents,parent){}
signals:
    void tick_signal();                                     // сигнал о добавлении 1 во второй счетчик
public slots:
    void add_one()                                          // функция, которая проверяет, нужно ли добавлять  во второй счетчик
    {
        QString str=text();
        int r=str.toInt();                                  // строку str конвертируем в число r
        if (r!=0 && r%5 ==0) emit tick_signal();            // проверка условия
        r++;
        str.setNum(r);                                      // число r вводим в строку
        setText(str);
    }
};

class Win: public QWidget
{
    Q_OBJECT
protected:
    QTextCodec *codec;
    QLabel *label1,*label2;             // лейблы
    Counter *edit1,*edit2;              // строки Counter
    QPushButton *calcbutton;            // кнопка "+1"
    QPushButton *exitbutton;            // кнопка "Выход"
public:
    Win(QWidget *parent = 0);           // конструктор окна
};

#endif
