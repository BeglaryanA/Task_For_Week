#ifndef ALLMEMBERS_H
#define ALLMEMBERS_H

#include <QWidget>
#include <iostream>
#include "helper.h"


namespace Ui {
class AllMembers;
}

class AllMembers : public QWidget
{
    Q_OBJECT

public:
    explicit AllMembers(QWidget *parent = nullptr, helper* hp = nullptr);
    ~AllMembers();
private slots:
    void on_del_btn_clicked();

    void on_upd_btn_clicked();

private:
    void init_members();
private:
    Ui::AllMembers *ui;
    helper* help;
};

#endif // ALLMEMBERS_H
