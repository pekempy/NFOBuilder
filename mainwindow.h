#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_CreateNFO_clicked();

    QString getDataFromURL();
    void modifyGenre(const std::string& genre, bool checked);

    // textChanged events for the form
    void on_showNameInput_textChanged(const QString &arg1);
    void on_showPosterInput_textChanged(const QString &arg1);
    void on_showDateInput_textChanged(const QString &arg1);
    void on_showLocationInput_textChanged(const QString &arg1);
    void on_showMasterInput_textChanged(const QString &arg1);
    void on_showSynopsisInput_textChanged();
    void on_outputFolderInput_textChanged(const QString &arg1);
    void on_outputFolderInput_editingFinished();
    void on_encoraIDText_textChanged(const QString &arg1);
    void on_encoraAPIKey_textChanged(const QString &arg1);

    // Genre toggles
    void on_checkbox_musical_toggled(bool checked);
    void on_checkbox_play_toggled(bool checked);
    void on_checkbox_ballet_toggled(bool checked);
    void on_checkbox_bootleg_toggled(bool checked);
    void on_checkbox_proshot_toggled(bool checked);

    // NFT
    void on_isNFTCheckbox_toggled(bool checked);

    // API buttons
    void on_resetAPIKeyButton_pressed();
    void on_encoraLookupButton_clicked();

    // cast table functions
    void on_castTable_cellClicked(int row, int column);
    void on_castTable_cellChanged(int row, int column);

    void on_actionReset_API_Key_triggered();


    void on_actionLoad_NFO_triggered();

private:
    Ui::MainWindow *ui;
    void clearAllValues();
    QString actorNameFromDialog;
    QString downloadLinkFromDialog;
};
#endif
