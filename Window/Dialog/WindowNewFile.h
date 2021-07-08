#ifndef WINDOWNEWFILE_H
#define WINDOWNEWFILE_H

#include <QDialog>
#include <QVector>
#include <QList>

namespace Ui {
    class WindowNewFile;
}



struct NewFileTypeInfo
{
    QString type;
    QString name;
};

struct NewFileTemplateInfo
{
    QString name;
    QString desc;
    QString file;
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
    bool hasResult = false;
private:
    void clearTypeList();
    void clearState();
public:
    static void registerFileType(const NewFileTypeInfo& type);
    static void registerFileTemplate(const QString& type, const NewFileTemplateInfo& info);

    static QString newFile();
private slots:
    void on_lst_group_clicked(const QModelIndex& index);
    void on_lst_types_clicked(const QModelIndex& index);
    void on_btn_cancel_clicked();
    void on_btn_ok_clicked();
};

#endif // WINDOWNEWFILE_H
