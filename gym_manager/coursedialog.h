#ifndef COURSEDIALOG_H
#define COURSEDIALOG_H

#include <QDialog>
#include <QVector>
#include "member.h"

namespace Ui {
class CourseDialog;
}

class CourseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CourseDialog(QWidget *parent = nullptr);
    ~CourseDialog();

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_homeButton_clicked();
    void on_tableWidget_cellChanged(int row, int column);

private:
    Ui::CourseDialog *ui;
    QVector<Member> m_members;
    bool m_updating = false;
};

#endif // COURSEDIALOG_H
