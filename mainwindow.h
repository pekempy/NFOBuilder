#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "image_search.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    image_search *imageSearch;

public slots:
    void linkChangedHandler(const QString &actorName, const QString &url);

private slots:
    void on_CreateNFO_clicked();

    void on_showNameInput_textChanged(const QString &arg1);

    void on_showDateInput_textChanged(const QString &arg1);

    void on_showLocationInput_textChanged(const QString &arg1);

    void on_showTaglineInput_textChanged(const QString &arg1);

    void on_showSynopsisInput_textChanged();

    void on_showPosterInput_textChanged(const QString &arg1);

    void on_outputFolderInput_textChanged(const QString &arg1);

    void on_outputFolderInput_editingFinished();

    void on_castTable_cellChanged(int row, int column);

    void on_castTable_cellClicked(int row, int column);

    void on_encoraIDText_textChanged(const QString &arg1);

    void on_encoraLookupButton_clicked();

private:
    Ui::MainWindow *ui;
    void clearAllValues();
    QString actorNameFromDialog;
    QString downloadLinkFromDialog;
};
#endif // MAINWINDOW_H
