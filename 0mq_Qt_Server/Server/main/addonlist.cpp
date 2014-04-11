#include "addonlist.h"
#include <QtCore>

AddonList::AddonList()
{
    loadAddon();
    size = list.size();
}

DataHandleInterface* const & AddonList::at(int i) const
{
    return list.at(i);
}

int AddonList::getsize() const
{
    return size;
}

AddonList & AddonList::getClass()
{
    static AddonList addon;
    return addon;
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
                list.append(dataInterface);
            }
        }
    }
}
