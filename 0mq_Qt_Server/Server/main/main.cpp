#define NZMQT_LIB
#include <QCoreApplication>
#include <QtCore>
#include "addonlist.h"
#include "switchthread.h"
#include "controlworker.h"
#include "configclass.h"

void customMessageHandler(QtMsgType type, const QMessageLogContext &context,const QString & msg)
{
        QString txt;
        switch (type) {
        //调试信息提示
        case QtDebugMsg:
//            txt = QString("%1: Debug: at:%2,%3 on %4; %5").arg(QTime::currentTime().toString("hh:mm:ss.zzz"))
//                    .arg(context.file).arg(context.line).arg(context.function).arg(msg);
            txt = msg;
                break;

        //一般的warning提示
        case QtWarningMsg:
                txt = QString("%1:Warning: at:%2,%3 on %4; %5").arg(QTime::currentTime().toString("hh:mm:ss.zzz"))
                        .arg(context.file).arg(context.line).arg(context.function).arg(msg);
        break;
        //严重错误提示
        case QtCriticalMsg:
                txt = QString("%1:Critical: at:%2,%3 on %4; %5").arg(QTime::currentTime().toString("hh:mm:ss.zzz"))
                        .arg(context.file).arg(context.line).arg(context.function).arg(msg);
        break;
        //致命错误提示
        case QtFatalMsg:
                txt = QString("%1:Fatal: at:%2,%3 on %4; %5").arg(QTime::currentTime().toString("hh:mm:ss.zzz"))
                        .arg(context.file).arg(context.line).arg(context.function).arg(msg);
                abort();
        }
        QFile outFile(QString("%1/%2.csv").arg(QDir::currentPath()).arg(QDate::currentDate().toString("yyyy-MM-dd")));
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream ts(&outFile);
        ts << txt << endl;
}


int main(int argc, char *argv[])
{
    //    qInstallMessageHandler(customMessageHandler);
    QCoreApplication a(argc, argv);
    if (AddonList::getClass().getsize() <= 0)
    {
        qDebug() << "Erro: 没有插件！";
        return -1;
    }
    SwitchThread th;
    if (ConfigClass::getClass().isBind)
    {
        th.start();
    }

    ControlWorker  cw;
    cw.setWork(5);
    cw.beginWork();

    return a.exec();
}
