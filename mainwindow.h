#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_CreateNFO_clicked();

    void on_showNameInput_textChanged(const QString &arg1);

    void on_showDateInput_textChanged(const QString &arg1);

    void on_showLocationInput_textChanged(const QString &arg1);

    void on_showTaglineInput_textChanged(const QString &arg1);

    void on_showSynopsisInput_textChanged();

    void on_showPosterInput_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void clearAllValues();
};
#endif // MAINWINDOW_H
