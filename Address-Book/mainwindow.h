#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <map>
#include <fstream>
#include <iomanip>
#include <vector>


#include "DataValidation.h"
#include "allmembers.h"
#include "helper.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_clicked();
    void on_add_2_clicked();

public:
    void reset(QLineEdit*);


private:    
    Ui::MainWindow *ui;
    book* addres;
    helper* help;
private:
    DataValidation* valid;
    AllMembers* members_list;
};
#endif // MAINWINDOW_H
