#ifndef PROJECTFILETYPE_H
#define PROJECTFILETYPE_H
#include <QString>
#include <QList>

struct FileTypeInfo
{
    QString ext;
    void(*editor)(const QString& fullFilename);
};

class ProjectFileType
{
private:
    QList<FileTypeInfo> filetypes;
public:
    ProjectFileType();


    void registerFileType();
    FileTypeInfo* queryByFilename(const QString& filename);
};

#endif // PROJECTFILETYPE_H
