#ifndef WINDOWNEWFILE_H
#define WINDOWNEWFILE_H

#include <QDialog>
#include <QVector>
#include <QList>

namespace Ui {
    class WindowNewFile;
}


struct NewFileInfo
{
    QString typeIndex;
    QString typeName;
    QString group;
    QString description;
    QString defaultName;
    QString defaultPath;
    void(*newfileCallback)(const QString& fullname);
};

struct NewFileGroup
{
    QString groupName;
    QList<NewFileInfo> items;
};

struct NewFileData
{
    QList<NewFileGroup> groups;

    inline NewFileGroup* findGroup(const QString& groupName) {
        for (auto& item : groups) {
            if (item.groupName == groupName) {
                return &item;
            }
        }
        return nullptr;
    }
    inline NewFileGroup* prepareGroup(const QString& groupName) {
        NewFileGroup* ret = findGroup(groupName);
        if (ret == nullptr) {
            groups.push_back(NewFileGroup());
            ret = &groups.last();
        }
        return ret;
    }
};

class WindowNewFile : public QDialog
{
    Q_OBJECT

public:
    explicit WindowNewFile();
    ~WindowNewFile();
public:

private:
    Ui::WindowNewFile* ui;
    bool isCheck;
private:
    void clearTypeList();
    void clearState();
public:
    static void registerFileType(const NewFileInfo& info);
    static QString newFile();
private slots:
    void on_lst_group_clicked(const QModelIndex& index);
    void on_lst_types_clicked(const QModelIndex& index);
    void on_btn_cancel_clicked();
    void on_btn_ok_clicked();
};

#endif // WINDOWNEWFILE_H
