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
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void linkChangedHandler(const QString &actorName, const QString &url);

private slots:

    void onCreateNFOClicked();

    void on_showNameInput_textChanged(const QString &arg1);

    void on_showDateInput_textChanged(const QString &arg1);

    void on_showLocationInput_textChanged(const QString &arg1);

    void on_showMasterInput_textEdited(const QString &arg1);

    void on_showSynopsisInput_textChanged();

    void on_outputFolderInput_textChanged(const QString &arg1);

    void on_outputFolderInput_editingFinished();

    void onCastTableCellChanged(int row, int column);

    void onCastTableCellClicked(int row, int column);

    void on_encoraIDText_textChanged(const QString &arg1);

    void on_encoraAPIKey_textChanged(const QString &arg1);

    void onEncoraLookupButtonClicked();

    QString getDataFromURL();

    void sortCastData(const QString cast);

    QString getCharacterName(const QString character);

    void modifyGenre(std::string genre, bool checked);

    void on_checkbox_musical_toggled(bool checked);

    void on_checkbox_play_toggled(bool checked);

    void on_checkbox_ballet_toggled(bool checked);

    void on_checkbox_bootleg_toggled(bool checked);

    void on_checkbox_proshot_toggled(bool checked);

    void on_isNFTCheckbox_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    void clearAllValues();
    QString actorNameFromDialog;
    QString downloadLinkFromDialog;
};
#endif // MAINWINDOW_H
