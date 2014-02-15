#include "completelineedit.h"

#include <QKeyEvent>

#include <QListView>

#include <QStringListModel>

#include <QDebug>



CompleteLineEdit::CompleteLineEdit(QStringList * words, QWidget *parent)

    : QLineEdit(parent), words(words)
{
    listView = new QListView(this);
    model = new QStringListModel(this);
    listView->setWindowFlags(Qt::ToolTip);
    connect(this, SIGNAL(textChanged(const QString &)), this, SLOT(setCompleter(const QString &)));
    connect(listView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(completeText(const QModelIndex &)));
}

void CompleteLineEdit::focusOutEvent(QFocusEvent *)
{

    //listView->hide();
}

void CompleteLineEdit::keyPressEvent(QKeyEvent *e)
{
    if (!listView->isHidden())
    {
        int key = e->key();
        int count = listView->model()->rowCount();
        QModelIndex currentIndex = listView->currentIndex();
        if (Qt::Key_Down == key)
        {
            // 按向下方向键时，移动光标选中下一个完成列表中的项
            int row = currentIndex.row() + 1;
            if (row >= count)
            {
                row = 0;
            }
            QModelIndex index = listView->model()->index(row, 0);
            listView->setCurrentIndex(index);
        }
        else if (Qt::Key_Up == key)
        {
            // 按向下方向键时，移动光标选中上一个完成列表中的项
            int row = currentIndex.row() - 1;
            if (row < 0)
            {
                row = count - 1;
            }
            QModelIndex index = listView->model()->index(row, 0);
            listView->setCurrentIndex(index);
        }
        else if (Qt::Key_Escape == key)
        {
            // 按下Esc键时，隐藏完成列表
            listView->hide();
        } else if (Qt::Key_Enter == key || Qt::Key_Return == key)
        {
            // 按下回车键时，使用完成列表中选中的项，并隐藏完成列表
            if (currentIndex.isValid())
            {
                QString text = listView->currentIndex().data().toString();
                setText(text);
            }
            listView->hide();

        }
        else
        {
            // 其他情况，隐藏完成列表，并使用QLineEdit的键盘按下事件
            listView->hide();
            QLineEdit::keyPressEvent(e);
        }
    }
    else
    {
        QLineEdit::keyPressEvent(e);
    }
}



void CompleteLineEdit::setCompleter(const QString &text)
{
    if (text.isEmpty())
    {
        listView->hide();
        return;
    }
    if ((text.length() > 1) && (!listView->isHidden()))
    {
        return;
    }
    // 如果完整的完成列表中的某个单词包含输入的文本，则加入要显示的完成列表串中
    QStringList sl;
    foreach(QString word, * words)
    {
        if (word.contains(text))
        {
            sl << word;
        }
    }
    model->setStringList(sl);
    listView->setModel(model);
    if (model->rowCount() == 0)
    {
        return;
    }
    // Position the text edit
    listView->setMinimumWidth(width());
    listView->setMaximumWidth(width());
    QPoint p(0, height());
    int x = mapToGlobal(p).x();
    int y = mapToGlobal(p).y() + 1;
    listView->move(x, y);
    listView->show();
}


void CompleteLineEdit::completeText(const QModelIndex &index)
{
    QString text = index.data().toString();
    setText(text);
    listView->hide();
}
