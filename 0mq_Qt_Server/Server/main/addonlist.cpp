#include "addonlist.h"
#include <QtCore>

AddonList::AddonList()
{
    loadAddon();
}

AddonList & AddonList::getClass()
{
    static AddonList addon;
    return addon;
}

QList<DataHandleInterface *> AddonList::getInterface(const QString & key) const
{
    return addonMap.values(key);
}

int AddonList::getsize() const
{
    return addonMap.size();
}

void AddonList::loadAddon()
{
    QDir pluginsDir(qApp->applicationDirPath());
    pluginsDir.cd("plugins");
    QStringList tstrlist =  pluginsDir.entryList(QStringList()<<"*.so"<<"*.dll",QDir::Files);
    foreach (QString fileName, tstrlist)
    {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        qDebug()<<fileName<<pluginsDir.absoluteFilePath(fileName);
        QObject *plugin = pluginLoader.instance();
        if (plugin)
        {
            DataHandleInterface * dataInterface = qobject_cast<DataHandleInterface *>(plugin);
            if (dataInterface)
            {
                QStringList strl = dataInterface->getCommod();
                for (int i = 0; i < strl.size(); ++i)
                {
                    addonMap.insert(strl.at(i),dataInterface);
                }
            }
        }
    }
}
