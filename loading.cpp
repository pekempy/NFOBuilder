#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_loading.h"
#include "loading.h"


loading::loading(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loading)
{
    ui->setupUi(this);
}

loading::~loading()
{
    delete ui;
}
