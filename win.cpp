#include "win.h"

// Файл win.cpp в этом случае содержит только описание конструктора класса окна:
Win::Win(QWidget *parent):QWidget(parent)
{
    codec = QTextCodec::codecForName("UTF-8");                      // для переформатирования текста
    this->setWindowTitle(codec->toUnicode("Счетчик"));              // задание названия окна
    label1 = new QLabel(codec->toUnicode("Cчет по 1"),this);        // создание лейбла для 1 счетчика
    label2 = new QLabel(codec->toUnicode("Cчет по 5"),this);        // создание лейбла для 2 счетчика
    edit1 = new Counter("0",this);                                  // создание объекта Counter edit1 для первой строки счета
    edit2 = new Counter("0",this);                                  // создание объекта Counter edit2 для второй строки счета
    calcbutton=new QPushButton("+1",this);                          // создание кнопки "+1"
    exitbutton=new QPushButton(codec->toUnicode("Выход"),this);     // создание кнопки "Выход"

    QHBoxLayout *layout1 = new QHBoxLayout();                   // создание первого горизонтального компоновщика и добавление туда
    layout1->addWidget(label1);                                 // первого лейбла
    layout1->addWidget(label2);                                 // второго лейбла

    QHBoxLayout *layout2 = new QHBoxLayout();                   // создание второго горизонтального компоновщика и добавление туда
    layout2->addWidget(edit1);                                  // edit1
    layout2->addWidget(edit2);                                  // edit2

    QHBoxLayout *layout3 = new QHBoxLayout();                   // создание третьего горизонтального компоновщика и добавление туда
    layout3->addWidget(calcbutton);                             // кнопки "+1"
    layout3->addWidget(exitbutton);                             // кнопки "Выход"

    QVBoxLayout *layout4 = new QVBoxLayout(this);               // создание вертикального компоновщика в окне и добавление туда
    layout4->addLayout(layout1);                                // трех горизонтальных компоновщиков
    layout4->addLayout(layout2);
    layout4->addLayout(layout3);

    // связь сигнала нажатия кнопки и слота закрытия окна
    connect(calcbutton,SIGNAL(clicked(bool)),                   // сигнал о нажатии кнопки "+1"
            edit1,SLOT(add_one()));
    connect(edit1,SIGNAL(tick_signal()),                        // сигнал о добавлении 1 во второй счетчик
            edit2,SLOT(add_one()));
    connect(exitbutton,SIGNAL(clicked(bool)),                   // сигнал о нажатии кнопки "Выход"
            this,SLOT(close()));
}
