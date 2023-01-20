#include "update.h"
#include "ui_update.h"

Update::Update(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Update)
{
    ui->setupUi(this);
}

Update::~Update()
{
    delete ui;
}
