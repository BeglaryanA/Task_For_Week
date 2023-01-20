#include "allmembers.h"
#include "ui_allmembers.h"

AllMembers::AllMembers(QWidget *parent, helper* hp) :
    QWidget(parent),
    ui(new Ui::AllMembers)
  , help(hp)
{

    ui->setupUi(this);
    this->init_members();
}

AllMembers::~AllMembers()
{
    delete ui;
}


void AllMembers::init_members()
{
    ui->tableWidget->clearContents();

    QTableWidgetItem* ptr = nullptr;
    int count = 0;
    for (auto x : help->save_addres) {

        ui->tableWidget->insertRow(count);
        ptr = new QTableWidgetItem(QString::fromStdString(x.first->name));
        ui->tableWidget->setItem(count,0,ptr);

        ptr = new QTableWidgetItem(QString::fromStdString(x.first->email));
        ui->tableWidget->setItem(count,1,ptr);

        ptr = new QTableWidgetItem(QString::fromStdString(x.first->phone));
        ui->tableWidget->setItem(count++, 2, ptr);
    }
    for (auto x : help->m_all_adreses) {
        ui->tableWidget->insertRow(count);
        ptr = new QTableWidgetItem(QString::fromStdString(x.second->name));
        ui->tableWidget->setItem(count, 0, ptr);

        ptr = new QTableWidgetItem(QString::fromStdString(x.second->email));
        ui->tableWidget->setItem(count, 1, ptr);

        ptr = new QTableWidgetItem(QString::fromStdString(x.second->phone));
        ui->tableWidget->setItem(count++, 2, ptr);
    }
    delete ptr;
}

void AllMembers::on_del_btn_clicked()
{
    std::string personal_email = ui->email_del->text().toStdString();
    auto it_del = std::find_if(help->m_all_adreses.begin(), help->m_all_adreses.end(),
                               [&] (std::pair<int, book*> args){
                                   return  args.second->email == personal_email; });
    auto it_del_fetch = std::find_if(help->save_addres.begin(), help->save_addres.end(),
                               [&] (std::pair<book*, std::streampos> args){
                                   return  args.first->email == personal_email; });
    if (it_del != help->m_all_adreses.end()) {
        it_del->second->status = -1;
        help->m_all_adreses.erase(it_del);
    }
    if (it_del_fetch !=  help->save_addres.end()) {
        it_del_fetch->first->status = -1;
        help->save_addres.erase(it_del_fetch);
    }
    ui->email_del->clear();
    this->init_members();
    help->flush();
}


void AllMembers::on_upd_btn_clicked()
{
    std::string email_cheacker = ui->email_cheker->text().toStdString();

    auto it_del = std::find_if(help->m_all_adreses.begin(), help->m_all_adreses.end(),
                               [&] (std::pair<int, book*> args){
                                   return  args.second->email == email_cheacker; });
    auto it_del_fetch = std::find_if(help->save_addres.begin(), help->save_addres.end(),
                               [&] (std::pair<book*, std::streampos> args){
                                   return  args.first->email == email_cheacker; });
    if (it_del != help->m_all_adreses.end()) {
        if (!(ui->upd_email->text().isEmpty())) { it_del->second->email = ui->upd_email->text().toStdString(); }
        if (!(ui->upd_name->text().isEmpty())) { it_del->second->name = ui->upd_name->text().toStdString(); }
        if (!(ui->upd_phone->text().isEmpty())) { it_del->second->email = ui->upd_phone->text().toStdString(); }
    }
    if (it_del_fetch != help->save_addres.end()) {
        if (!(ui->upd_email->text().isEmpty())) { it_del_fetch->first->email = ui->upd_email->text().toStdString(); }
        if (!(ui->upd_name->text().isEmpty())) { it_del_fetch->first->name = ui->upd_name->text().toStdString(); }
        if (!(ui->upd_phone->text().isEmpty())) { it_del_fetch->first->email = ui->upd_phone->text().toStdString(); }
    }
    this->init_members();
    help->flush();
}

