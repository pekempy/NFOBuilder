#ifndef LOADING_H
#define LOADING_H

#include "qobjectdefs.h"
#include "QDialog"

namespace Ui {
    class loading;
}

class loading : public QDialog
{
    Q_OBJECT

public:
    explicit loading(QWidget *parent = nullptr);
    ~loading();

private slots:

signals:

private:
    Ui::loading *ui;
};

#endif // LOADING_H
