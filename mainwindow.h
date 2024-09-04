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

    void onShowNameInputTextChanged(const QString &arg1);

    void onShowDateInputTextChanged(const QString &arg1);

    void onShowLocationInputTextChanged(const QString &arg1);

    void onShowMasterInputTextChanged(const QString &arg1);

    void onShowSynopsisInputTextChanged();

    void onOutputFolderInputTextChanged(const QString &arg1);

    void onOutputFolderInputEditingFinished();

    void onCastTableCellChanged(int row, int column);

    void onCastTableCellClicked(int row, int column);

    void onEncoraIDTextTextChanged(const QString &arg1);

    void onEncoraAPIKeyTextChanged(const QString &arg1);

    void onEncoraLookupButtonClicked();

    QString getDataFromURL();

    void sortCastData(const QString cast);

    QString getCharacterName(const QString character);

    void modifyGenre(std::string genre, bool checked);

    void onCheckboxMusicalToggled(bool checked);

    void onCheckboxPlayToggled(bool checked);

    void onCheckboxBalletToggled(bool checked);

    void onCheckboxBootlegToggled(bool checked);

    void onCheckboxProshotToggled(bool checked);

private:
    Ui::MainWindow *ui;
    void clearAllValues();
    QString actorNameFromDialog;
    QString downloadLinkFromDialog;
};
#endif // MAINWINDOW_H
