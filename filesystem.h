#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QString>

class FileSystem
{
public:
    FileSystem();

    static QString absolutePath(const QString &dir);
    static QString fileName(const QString &file);

    QString openFile();

private:
    QString m_lastDir;
    QString m_currentFileName;
};

#endif // FILESYSTEM_H
