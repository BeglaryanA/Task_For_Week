#ifndef UPDATE_H
#define UPDATE_H

#include <QWidget>

namespace Ui {
class Update;
}

class Update : public QWidget
{
    Q_OBJECT

public:
    explicit Update(QWidget *parent = nullptr);
    ~Update();

private:
    Ui::Update *ui;
};

#endif // UPDATE_H
