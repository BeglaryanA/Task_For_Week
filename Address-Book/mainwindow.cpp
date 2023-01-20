#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , help(new helper())
    , valid(new DataValidation())

{
    ui->setupUi(this);
    help->fetch();
    for (auto it : help->save_addres) {
        std::cout << it.first->name << std::endl;
    }
}

MainWindow::~MainWindow()
{

    delete ui;
    delete valid;

}



void MainWindow::reset(QLineEdit* label) {
        label->setStyleSheet("	border:1px solid black; border-radius:20px;");
}

void MainWindow::on_add_clicked()
{
    reset(ui->name_line);
    reset(ui->email_line);
    reset(ui->phone_line);
    addres = new book();

    if (!(ui->name_line->text().isEmpty())) {
        addres->name = ui->name_line->text().toStdString();
    }
    if (!(ui->email_line->text().isEmpty())) {
        if (valid->ValidEamil(ui->email_line->text().toStdString())) {
            addres->email = ui->email_line->text().toStdString();
        } else {
            ui->email_line->setStyleSheet("	border:1px solid red; border-radius:20px;");
             ui->error->setStyleSheet("color:rgb(255, 157, 7);");
             return;
        }
    }
    if (!(ui->phone_line->text().isEmpty())) {
        if (valid->ValidNumber(ui->phone_line->text().toStdString())) {
           addres->phone = ui->phone_line->text().toStdString();
        } else {
            ui->phone_line->setStyleSheet("	border:1px solid red; border-radius:20px;");
             ui->error->setStyleSheet("color:rgb(255, 157, 7);");
             return;
        }
    }
    if((ui->name_line->text().isEmpty()) || (ui->email_line->text().isEmpty()) || (ui->phone_line->text().isEmpty())) {
        if((ui->name_line->text().isEmpty())) {
            ui->name_line->setStyleSheet("	border:1px solid red; border-radius:20px;");
        }
        if ((ui->phone_line->text().isEmpty())) {
            ui->phone_line->setStyleSheet("	border:1px solid red; border-radius:20px;");

        }
        if ((ui->phone_line->text().isEmpty())) {
            ui->email_line->setStyleSheet("	border:1px solid red; border-radius:20px;");

        }
        ui->error->setStyleSheet("color:rgb(255, 157, 7);");
        return;
    }
    help->m_all_adreses.insert(std::make_pair(help->ID, addres));
    help->flush();
    addres = nullptr;
    ui->email_line->setText("");
    ui->name_line->setText("");
    ui->phone_line->setText("");
    ++help->ID;

}

void MainWindow::on_add_2_clicked()
{
    this->members_list = new AllMembers(nullptr, this->help);
    members_list->show();
}
