#include "filesystem.h"

#include <QDir>
#include <QFileDialog>

FileSystem::FileSystem()
{

}

QString FileSystem::absolutePath(const QString &dir)
{
    QFileInfo path(dir);
    return path.absolutePath();
}

QString FileSystem::fileName(const QString &file)
{
    return QFileInfo(file).fileName();
}

QString FileSystem::openFile()
{
    if (m_lastDir.isEmpty())
        m_lastDir = QDir::homePath() + "/Pictures";
    QString fileName = QFileDialog::getOpenFileName(nullptr, QObject::tr("Open file"),
                                                    m_lastDir,
                                                    QObject::tr("All (*.*);;*.jpg;;*.jpeg;;*.bmp;;*.png;;*.tiff;;"));
    if (fileName.isEmpty())
        return QString();

    m_currentFileName = fileName;
    m_lastDir = absolutePath(fileName);

    return fileName;
}
