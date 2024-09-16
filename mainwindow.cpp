#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>
#include <QDesktopServices>
#include <QDebug>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSettings>
#include <QStandardPaths>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filedownloader.h"


using std::vector; using std::string;
using std::endl; using std::copy;

//global strings
string encoraID;
string encoraIDURL;
string showName;
string showDirector;
string showDate;
string showYear;
string showLocation;
string showGenre;
string showPlot;
string castList;
string actorXmlString;
string testValue;
string castMember = "  <actor>\n"
                    "       <name>str1</name>\n"
                    "       <role>str2</role>\n"
                    "       <thumb>str3</thumb>\n"
                    "       <type>Actor</type>\n"
                    "   </actor>";
string outputFolder;
string encoraAPIKey;
QString headshotsFileName = "headshots.json";
bool isNFT = false;
FileDownloader * file;
//settings file set org/app name
QSettings mySettings("Pekempy","NFO Builder");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFormLayout * centralWidget = ui->formLayout;
    centralWidget->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
    //restrict date input to YYYY-MM-DD.
    QRegularExpression re("^\\d{4}[\\-\\/\\s]?((((0[13578])|(1[02]))[\\-\\/\\s]?(([0-2][0-9])|(3[01])))|(((0[469])|(11))[\\-\\/\\s]?(([0-2][0-9])|(30)))|(02[\\-\\/\\s]?[0-2][0-9]))$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(re, this);
    ui->showDateInput->setValidator(validator);
    ui->encoraIDText->setValidator(new QIntValidator(1,2147483647, this));
    if(mySettings.value("encora-apikey").toString() != "") {
        QString apikey = mySettings.value("encora-apikey").toString();
        ui->encoraAPIKey->setText(apikey);
        ui->encoraAPIKey->hide();
        ui->encoraAPIKeyLabel->hide();
    } else {
        ui->encoraAPIKey->show();
        ui->encoraAPIKeyLabel->show();
    }
    ui->outputFolderInput->setText(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::linkChangedHandler(const QString &actorName, const QString &url) {
    actorNameFromDialog = actorName;
    downloadLinkFromDialog = url;
    //find actor name in table and add the link
    auto table = ui->castTable;
    //QTextStream out(stderr);
    int actorRow;
    for (int col = 0; col<table->columnCount(); col++) {
        QModelIndexList results = table->model()->match(
                    table->model()->index(0, col),
                    Qt::DisplayRole,
                    actorName,
                    -1,
                    Qt::MatchContains);
        for (QModelIndex idx:results)
            actorRow = idx.row();
    }
    QTableWidgetItem * dlLink = ui->castTable->item(actorRow,2);
    if(!dlLink) {
        dlLink = new QTableWidgetItem();
        ui->castTable->setItem(actorRow,2,dlLink);
    }
    dlLink->setText(downloadLinkFromDialog);
    downloadLinkFromDialog = "";
    actorNameFromDialog = "";
}

string buildXML(){
    string xmlPart1 =   "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"yes\"?>\n"
                        "<movie>\n"
                        "   <title>" + showName + "</title>\n"
                        "   <originaltitle>" + showName + "</originaltitle>\n"
                        "   <sorttitle>" + showName + "</sorttitle>\n"
                        "   <premiered>" + showDate + "</premiered>\n"
                        "   <releasedate>" + showDate + "</releasedate>\n"
                        "   <director>" + showDirector + "</director>\n"
                        + showGenre +
                        "   <year>" + showYear + "</year>\n"
                        "   <studio>" + showLocation + "</studio>\n"
                        "   <plot>" + showPlot + "</plot>\n"
                        "   <lockdata>true</lockdata>\n";
    string xmlPart2 = "   <certification>UK:NFT</certification>\n"
                      "   <certification>US:NFT</certification>\n"
                      "   <certification>SP:NFT</certification>\n"
                      "   <certification>HK:NFT</certification>\n"
                      "   <certification>CN:NFT</certification>\n"
                      "   <certification>FR:NFT</certification>\n"
                      "   <certification>IT:NFT</certification>\n"
                      "   <certification>BR:NFT</certification>\n"
                      "   <certification>PT:NFT</certification>\n"
                      "   <certification>NL:NFT</certification>\n";
    string xmlPart3 = actorXmlString;
    string xmlPart4 =   "</movie>";
    if(isNFT) {
    return xmlPart1 + xmlPart2 + xmlPart3 + xmlPart4;
    } else {
        return xmlPart1 + xmlPart3 + xmlPart4;
    }
}

bool fileExists(QString handle){
    QFileInfo check_file(handle);
    QString absolute_file_path = check_file.absolutePath();
    if(!QDir(absolute_file_path).exists()) {
        QDir().mkdir(absolute_file_path);
    }
    if(check_file.exists() && check_file.isFile())
       { return true; } else { return false; }
}

QJsonDocument loadJson(QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::ReadOnly);
    return QJsonDocument().fromJson(jsonFile.readAll());
}

void saveJson(QJsonDocument document, QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}

void setHeadshotsFile(QJsonObject obj, QString headshotsFilePath) {
    QJsonDocument doc(obj);
    saveJson(doc, headshotsFilePath);
}

QJsonObject getHeadshotsFile(QString headshotsFilePath) {
    if(!fileExists(headshotsFilePath)) {
        QString emptyFileStr = "{}";
        QJsonDocument emptyDoc = QJsonDocument::fromJson(emptyFileStr.toUtf8());
        saveJson(emptyDoc, headshotsFilePath);
    }
    QJsonDocument doc = loadJson(headshotsFilePath);

    QJsonObject obj;
    if(doc.isObject()){
        obj = doc.object();
    }
    return obj;
}

void MainWindow::on_CreateNFO_clicked() {
  //Loop to create XML for cast information
  for (int i = 0; i < ui -> castTable -> rowCount(); i++) {
    for (int j = 0; j < ui -> castTable -> columnCount(); j++) {
      if (QTableWidgetItem * item = ui -> castTable -> item(i, j)) {
        if (j == 0) {
          castMember.find("str1");
          castMember.replace(castMember.find("str1"), 4, item -> text().toStdString());
        }
        else if (j == 1) {
          castMember.find("str2");
          castMember.replace(castMember.find("str2"), 4, item -> text().toStdString());
        }
        else if (j == 2) {
          castMember.find("str3");
          castMember.replace(castMember.find("str3"), 4, item -> text().toStdString());
          if(castMember.find("<name></name>") == string::npos) {
            actorXmlString.append(castMember + "\n");
          }
        }
      }
    }
    castMember = "  <actor>\n"
                 "       <name>str1</name>\n"
                 "       <role>str2</role>\n"
                 "       <thumb>str3</thumb>\n"
                 "       <type>Actor</type>\n"
                 "   </actor>";
  }

  string output = buildXML();
  if (showName != "") {
    //ui -> outputTextArea -> setText(QString::fromStdString(output));
     std::ofstream myfile;
     string showNameEscaped = showName;
     std::replace(begin(showNameEscaped),end(showNameEscaped),':','-');
     string fileName = outputFolder + showNameEscaped + "-" + showDate + ".nfo";
     QString qsFileName = QString::fromStdString(fileName);
     myfile.open(fileName);
     myfile << output;
     myfile.close();
     if (fileExists(qsFileName)) {
         auto m = new QMessageBox();
         m->setText("Successfully created: " + qsFileName);
         m->setAttribute(Qt::WA_DeleteOnClose);
         m->setModal(false);
         m->show();
         // 1140495
    }
  }
  clearAllValues();
}

//Set variables upon text changed for each section.

// TODO: update to pull from new API
void MainWindow::on_encoraIDText_textChanged(const QString &arg1)
{
    encoraID = arg1.toStdString();
    encoraIDURL = "https://encora.it/api/recording/" + encoraID;
    if(encoraID.length() > 0 && encoraAPIKey.length() > 0) {
        ui->encoraLookupButton->setEnabled(true);
    } else {
        ui->encoraLookupButton->setEnabled(false);
    }
}

// TODO: update to validate API key on-site
void MainWindow::on_encoraAPIKey_textChanged(const QString &arg1)
{
    encoraAPIKey = arg1.toStdString();
    QVariant apiKey(arg1);
    mySettings.setValue("encora-apikey", apiKey);
    if(encoraID.length() > 0 && encoraAPIKey.length() > 0) {
        ui->encoraLookupButton->setEnabled(true);
    } else {
        ui->encoraLookupButton->setEnabled(false);
    }
}

void MainWindow::on_resetAPIKeyButton_pressed()
{
    ui->encoraAPIKey->setText("");
    mySettings.remove("encora-apikey");
    ui->encoraAPIKey->show();
    ui->encoraAPIKeyLabel->show();
    if(encoraID.length() > 0 && encoraAPIKey.length() > 0) {
        ui->encoraLookupButton->setEnabled(true);
    } else {
        ui->encoraLookupButton->setEnabled(false);
    }
}


void MainWindow::on_showNameInput_textChanged(const QString &arg1)
{
    showName = arg1.toStdString();
}

void MainWindow::on_showDateInput_textChanged(const QString &arg1)
{
    showDate = arg1.toStdString();
    //also get year from date
    if(arg1.toStdString().length() == 10){
        showYear = arg1.toStdString().erase(arg1.toStdString().length()-6);
    }

}

void MainWindow::on_showLocationInput_textChanged(const QString &arg1)
{
    showLocation = arg1.toStdString();
}

void MainWindow::on_showMasterInput_textEdited(const QString &arg1)
{
    showDirector = arg1.toStdString();
}

void MainWindow::on_showSynopsisInput_textChanged()
{
    showPlot = ui->showSynopsisInput->toPlainText().toStdString();
}

void MainWindow::on_outputFolderInput_textChanged(const QString &arg1)
{
    outputFolder = arg1.toStdString();
}

void MainWindow::on_outputFolderInput_editingFinished()
{
    //check if last char is '\' if not add it.
    char last = outputFolder.back();
    if(last != '/') {
        outputFolder = outputFolder + '/';
        ui->outputFolderInput->setText(QString::fromStdString(outputFolder));
    }
}


void MainWindow::clearAllValues(){

    //clear global strings
    showName = "";
    showDate = "";
    showYear = "";
    showLocation = "";
    showDirector = "";
    showPlot = "";
    actorXmlString = "";
    encoraID = "";

    //clear UI values
    ui->encoraIDText->setText("");
    ui->showNameInput->setText("");
    ui->showDateInput->setText("");
    ui->showLocationInput->setText("");
    ui->showMasterInput->setText("");
    ui->showSynopsisInput->setText("");

    //clear genres
    ui->checkbox_musical->setChecked(false);
    ui->checkbox_ballet->setChecked(false);
    ui->checkbox_play->setChecked(false);
    ui->checkbox_bootleg->setChecked(false);
    ui->checkbox_proshot->setChecked(false);
    ui->isNFTCheckbox->setChecked(false);

    // Set the entire cast table to empty
    for(int i = 0; i < 39; ++i) {
        ui->castTable->item(i, 0)->setText("");
        ui->castTable->item(i, 1)->setText("");
        ui->castTable->item(i, 2)->setText("");
        ui->castTable->item(i, 3)->setText("");
    }

    //jump to top of cast table
    ui->castTable->scrollToTop();
}


void MainWindow::on_castTable_cellChanged(int row, int column)
{
    string test;
    //when each row, column a changed, update link in column 4 for that row.
    if(column != 3) {
        for (int i = 0; i < ui-> castTable -> rowCount(); i++) {
            //for each row
            if (i == row && column != 3) {
                //ui -> castTable -> item(i, 3) -> setText(QString::fromStdString("Test"));
                QTableWidgetItem * cellLink = ui -> castTable -> item(i, 3);
                if(!cellLink){
                    cellLink = new QTableWidgetItem();
                    ui -> castTable -> setItem(i,3,cellLink);
                }
                QTableWidgetItem * actor = ui -> castTable -> item(i, 0);
                string actorName = actor->text().toStdString();
                string url = "https://google.com/search?tbm=isch&q=actor+headshot+-+" + actorName;
                cellLink->setText(QString::fromStdString(url));
            }
        }
    }

    if(column == 0) {
        QString headshotsFilePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/" + headshotsFileName;
        QJsonObject headshots = getHeadshotsFile(headshotsFilePath);

        QTableWidgetItem * performer = ui -> castTable -> item(row, 0);
        QString performerName = performer->text();

        QTableWidgetItem * headshotCell = ui -> castTable -> item(row, 2);
        if(performerName.isEmpty()) {
            headshotCell->setText(QString::fromStdString(""));
        } else if(headshots.keys().contains(performerName)) {
            QJsonValueRef headshot = headshots[performerName];
            headshotCell->setText(headshot.toString());
        } else {
            headshotCell->setText(QString::fromStdString(""));
        }
    }
    if(column == 2) {
        QString headshotsFilePath = QStandardPaths::writableLocation((QStandardPaths::AppDataLocation)) + "/" + headshotsFileName;
        QJsonObject headshots = getHeadshotsFile(headshotsFilePath);

        QTableWidgetItem * actor = ui -> castTable -> item(row, 0);
        QString actorName = actor->text();

        if(actorName.isEmpty()) {
            return;
        }

        QTableWidgetItem * headshotCell = ui -> castTable -> item(row, 2);
        QString headshotText = headshotCell->text();

        if(!headshots.keys().contains(actorName) && !headshotText.isEmpty()) {
            headshots[actorName] = headshotText;
            setHeadshotsFile(headshots, headshotsFilePath);
        } else {
            if(headshots[actorName] != headshotText) {
                if(headshotText.isEmpty()) {
                    headshots.remove(actorName);
                } else {
                    headshots[actorName] = headshotText;
                }
                setHeadshotsFile(headshots, headshotsFilePath);
            }
        }

        for (int i = 0; i < ui-> castTable -> rowCount(); i++) {
            if(i == row) {
                continue;
            }
            QTableWidgetItem * nextActor = ui -> castTable -> item(i, 0);
            QString nextActorName = nextActor->text();
            if(nextActorName == actorName) {
                QTableWidgetItem * nextHeadshotCell = ui -> castTable -> item(i, 2);
                QString nextHeadshotText = nextHeadshotCell->text();
                if(nextHeadshotText != headshotText) {
                    nextHeadshotCell->setText(headshotText);
                }
            }
        }
    }
}

QString MainWindow::getDataFromURL(){
    QNetworkAccessManager manager;
    QNetworkRequest request = QNetworkRequest(QUrl(QString::fromStdString(encoraIDURL)));
    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer " + QByteArray::fromStdString(encoraAPIKey)));
    QNetworkReply *response = manager.get(request);
    QEventLoop event;
    connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    QString source = response->readAll();
    return source;
}

QString MainWindow::getCharacterName(QString character) {
    QString characterFixed;

    characterFixed = character;
    characterFixed = characterFixed.replace(")", "");

    return characterFixed;
}

//genre checkboxes
void MainWindow::modifyGenre(string genre, bool checked) {
    std::cout << "Genre: " + genre;
    std::cout << &"Checked: " [ checked];
    if(checked) {
        showGenre += genre;
    } else {
        showGenre.replace(showGenre.find(genre), genre.length() - 1, "");
        showGenre.erase(std::unique(showGenre.begin(), showGenre.end(),
                              [] (char a, char b) {return a == '\n' && b == '\n';}),
                  showGenre.end());
    }
}
void MainWindow::on_checkbox_musical_toggled(bool checked)
{
    string genre = "   <genre>Musical</genre>\n";
    modifyGenre(genre, checked);
}

void MainWindow::on_checkbox_play_toggled(bool checked)
{
    string genre = "   <genre>Play</genre>\n";
    modifyGenre(genre, checked);
}

void MainWindow::on_checkbox_ballet_toggled(bool checked)
{
    string genre = "   <genre>Ballet</genre>\n";
    modifyGenre(genre, checked);
}

void MainWindow::on_checkbox_bootleg_toggled(bool checked)
{
    string genre = "   <genre>Bootleg</genre>\n";
    modifyGenre(genre, checked);
}

void MainWindow::on_checkbox_proshot_toggled(bool checked)
{
    string genre = "   <genre>Pro-Shot</genre>\n";
    modifyGenre(genre, checked);
}

void MainWindow::on_isNFTCheckbox_toggled(bool checked)
{
    if (checked) {
        isNFT = true;
    } else {
        isNFT = false;
    }
}


void MainWindow::on_encoraLookupButton_clicked()
{
    // Clear the cast table to "" value instead of null
    for(int i = 0; i < 39; ++i) {
        ui->castTable->item(i, 0)->setText("");
        ui->castTable->item(i, 1)->setText("");
        ui->castTable->item(i, 2)->setText("");
        ui->castTable->item(i, 3)->setText("");
    }

    // Fetch the data from the Encora API using the users API key
    QString siteData = getDataFromURL();
    QJsonObject obj;
    QJsonDocument doc = QJsonDocument::fromJson(siteData.toUtf8());
    if(doc.isObject()){
        obj = doc.object();
    }

    // Extract show, tour, and master data
    QString APIShowName = obj["show"].toString();
    ui->showNameInput->setText(APIShowName);
    showName = APIShowName.toStdString();
    QString APIShowTour = obj["tour"].toString();
    ui->showLocationInput->setText(APIShowTour);
    showLocation = APIShowTour.toStdString();
    QString recordingMaster = obj["master"].toString();
    ui->showMasterInput->setText(recordingMaster);
    showDirector = recordingMaster.toStdString();

    // Extract date details
    QJsonObject apiDate = obj["date"].toObject();
    QString APIShowDate = apiDate["full_date"].toString();
    ui->showDateInput->setText(APIShowDate);

    // Extract NFT information
    QJsonObject nftInfo = obj["nft"].toObject();
    QString nftDate = nftInfo["nft_date"].toString();
    bool nftForever = nftInfo["nft_forever"].toBool();
    QString nftDateShorter = nftDate.left(10);
    QDate nftDateAsDate = QDate::fromString(nftDateShorter, "yyyy-MM-dd");
    QDate currentDate = QDate::currentDate();

    // Update NFT UI elements
    if(currentDate < nftDateAsDate || nftForever == true) {
        isNFT = true;
        ui->isNFTCheckbox->setChecked(true);
        ui->isNFTCheckbox->setDisabled(true);
    }

    QString headshotsFilePath = QStandardPaths::writableLocation((QStandardPaths::AppDataLocation)) + "/" + headshotsFileName;
    QJsonObject headshots = getHeadshotsFile(headshotsFilePath);

    // Extract cast information
    QJsonArray castArray = obj["cast"].toArray();
    for (int i = 0; i < castArray.size() && i < ui->castTable->rowCount(); ++i) {
        QJsonObject castObj = castArray[i].toObject();

        // Extract performer and character details
        QJsonObject performer = castObj["performer"].toObject();
        QString performerName = performer["name"].toString();

        QJsonObject character = castObj["character"].toObject();
        QString characterName = character["name"].toString();

        QString statusLabel = "";
        if (castObj.contains("status") && !castObj["status"].isNull()) {
            statusLabel = castObj["status"].toObject()["abbreviation"].toString();
            if (!statusLabel.isEmpty()) {
                characterName = statusLabel + " " + characterName;
            }
        }

        // Populate the castTable with performer, character, and status
        ui->castTable->item(i, 0)->setText(performerName);
        ui->castTable->item(i, 1)->setText(characterName);
        if(headshots.keys().contains(performerName)) {
            QJsonValueRef headshot = headshots[performerName];
            ui->castTable->item(i, 2)->setText(headshot.toString());
        }
        QString googleSearchUrl = "https://google.com/search?tbm=isch&q=actor+headshot+-+" + performerName;
        ui->castTable->item(i, 3)->setText(googleSearchUrl);
    }

    // Auto-check Genres

    // Extract recording type and update checkboxes
    QJsonObject metadata = obj["metadata"].toObject();
    QString recordingType = metadata["recording_type"].toString();

    if (recordingType == "bootleg") {
        ui->checkbox_bootleg->setChecked(true);
    }
    if (recordingType == "pro-shot") {
        ui->checkbox_proshot->setChecked(true);
    }

}


void MainWindow::on_castTable_cellClicked(int row, int column)
{
    string urlToOpen = "";
    if(column == 3){
        urlToOpen = ui->castTable->item(row,column)->text().toStdString();
    }
    if (urlToOpen != ""){
        QDesktopServices::openUrl(QUrl(QString::fromStdString(urlToOpen)));
    }
}

