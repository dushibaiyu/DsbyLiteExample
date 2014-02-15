#include "completelineedit.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList sl = QStringList() << "Biao" << "Bin" << "Huang" << "Hua" << "Hello" << "BinBin" << "Hallo";

    QWidget widgetw;
    CompleteLineEdit * edit= new CompleteLineEdit(&sl);
    QPushButton *button = new QPushButton("Button");
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(edit);
    layout->addWidget(button);
    widgetw.setLayout(layout);
    widgetw.show();

    CompleteLineEdit e(&sl);
    e.show();

    return a.exec();
}
