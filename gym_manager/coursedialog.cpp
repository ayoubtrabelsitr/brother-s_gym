#include "coursedialog.h"
#include "ui_coursedialog.h"
#include <QTableWidget>

CourseDialog::CourseDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CourseDialog)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(5);
    QStringList headers;
    headers << "Nom" << "Pr\xE9nom" << "Date de naissance" << "Statut" << "Validit\xE9";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    connect(ui->tableWidget, &QTableWidget::cellChanged,
            this, &CourseDialog::on_tableWidget_cellChanged);
}

CourseDialog::~CourseDialog()
{
    delete ui;
}

void CourseDialog::on_addButton_clicked()
{
    Member m;
    m_members.append(m);
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    m_updating = true;
    for (int c = 0; c < 5; ++c) {
        ui->tableWidget->setItem(row, c, new QTableWidgetItem());
    }
    m_updating = false;
}

void CourseDialog::on_removeButton_clicked()
{
    auto rows = ui->tableWidget->selectionModel()->selectedRows();
    for (int i = rows.count() - 1; i >= 0; --i) {
        int r = rows.at(i).row();
        ui->tableWidget->removeRow(r);
        if (r >= 0 && r < m_members.size())
            m_members.remove(r);
    }
}

void CourseDialog::on_homeButton_clicked()
{
    accept();
}

void CourseDialog::on_tableWidget_cellChanged(int row, int column)
{
    if (m_updating || row < 0 || row >= m_members.size())
        return;

    QTableWidgetItem *item = ui->tableWidget->item(row, column);
    QString text = item ? item->text() : QString();

    Member &m = m_members[row];
    switch (column) {
    case 0: m.nom = text; break;
    case 1: m.prenom = text; break;
    case 2: m.naissance = text; break;
    case 3: m.statut = text; break;
    case 4: m.validite = text; break;
    default: break;
    }
}

