#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <QAction>
#include <QDir>
#include <QFileInfo>
#include <QMessageBox>
#include <QDesktopServices>
#include <QDebug>
#include <QFileDialog>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSettings>
#include <QStandardPaths>
#include <QXmlStreamReader>
#include <QStyledItemDelegate>
#include <QPainter>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filedownloader.h"

using std::vector;
using std::string;
using std::endl;
using std::copy;

//global strings
string encoraID;
string encoraIDURL;
string showName;
string showPoster;
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

class CustomDelegate : public QStyledItemDelegate {
public:
    CustomDelegate(QObject* parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        QStyledItemDelegate::paint(painter, option, index);

        if (index.column() == 2) {
            QString nameValue = index.model()->data(index.siblingAtColumn(0)).toString();
            QString headshotValue = index.data().toString();

            if (!nameValue.isEmpty() && headshotValue.isEmpty()) {
                painter->save();
                painter->setPen(QPen(Qt::red, 1));
                painter->drawRect(option.rect.adjusted(0, 0, -1, -1));
                painter->restore();
            }
        }
    }
};

// Set up the MainWindow UI
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
    // set the delegate
    ui->castTable->setItemDelegate(new CustomDelegate(ui->castTable));
}

// On close, delete the UI
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionReset_API_Key_triggered()
{
    // Reset API key logic
    ui->encoraAPIKey->setText("");
    QSettings mySettings;
    mySettings.remove("encora-apikey");

    ui->encoraAPIKey->show();
    ui->encoraAPIKeyLabel->show();

    if(encoraID.length() > 0 && encoraAPIKey.length() > 0) {
        ui->encoraLookupButton->setEnabled(true);
    } else {
        ui->encoraLookupButton->setEnabled(false);
    }
}

void MainWindow::on_actionLoad_NFO_triggered()
{
    clearAllValues();
    // open file choose dialog
    QString fileName = QFileDialog::getOpenFileName(this, "Open NFO File", "", "NFO Files (*.nfo)");
    // with the file, extract data from the NFO XML and populate the UI
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QXmlStreamReader xml(&file);
    while(!xml.atEnd() && !xml.hasError()) {
        xml.readNext();
        if(xml.isStartElement()) {
            if(xml.name() == QStringLiteral("title")) {
                showName = xml.readElementText().toStdString();
                ui->showNameInput->setText(QString::fromStdString(showName));
            }
            if(xml.name() == QStringLiteral("thumb")) {
                showPoster = xml.readElementText().toStdString();
                ui->showPosterInput->setText(QString::fromStdString(showPoster));
            }
            if(xml.name() == QStringLiteral("premiered")) {
                showDate = xml.readElementText().toStdString();
                ui->showDateInput->setText(QString::fromStdString(showDate));
            }
            if(xml.name() == QStringLiteral("director")) {
                showDirector = xml.readElementText().toStdString();
                ui->showMasterInput->setText(QString::fromStdString(showDirector));
            }
            if(xml.name() == QStringLiteral("studio")) {
                showLocation = xml.readElementText().toStdString();
                ui->showLocationInput->setText(QString::fromStdString(showLocation));
            }
            if(xml.name() == QStringLiteral("plot")) {
                showPlot = xml.readElementText().toStdString();
                ui->showSynopsisInput->setText(QString::fromStdString(showPlot));
            }
            if(xml.name() == QStringLiteral("genre")) {
                QString genreText = xml.readElementText();
                if (genreText == "Ballet") {
                    ui->checkbox_ballet->setChecked(true);
                } else if (genreText == "Bootleg") {
                    ui->checkbox_bootleg->setChecked(true);
                } else if (genreText == "Musical") {
                    ui->checkbox_musical->setChecked(true);
                } else if (genreText == "Play") {
                    ui->checkbox_play->setChecked(true);
                } else if (genreText == "Pro-Shot") {
                    ui->checkbox_proshot->setChecked(true);
                }
            }
            if(xml.name() == QStringLiteral("certification")) {
                QString certificationText = xml.readElementText();
                if (certificationText.contains("NFT")) {
                    ui->isNFTCheckbox->setChecked(true);
                    ui->isNFTCheckbox->setDisabled(true);
                }
            }
            if(xml.name() == QStringLiteral("actor")) {
                string actorName = "";
                string characterName = "";
                string headshot = "";
                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == QStringLiteral("actor"))) {
                    if(xml.isStartElement()) {
                        if(xml.name() == QStringLiteral("name")) {
                            actorName = xml.readElementText().toStdString();
                        }
                        if(xml.name() == QStringLiteral("role")) {
                            characterName = xml.readElementText().toStdString();
                        }
                        if(xml.name() == QStringLiteral("thumb")) {
                            headshot = xml.readElementText().toStdString();
                        }
                    }
                    xml.readNext();
                }
                for(int i = 0; i < ui->castTable->rowCount(); ++i) {
                    if(ui->castTable->item(i, 0)->text().isEmpty()) {
                        ui->castTable->item(i, 0)->setText(QString::fromStdString(actorName));
                        ui->castTable->item(i, 1)->setText(QString::fromStdString(characterName));
                        ui->castTable->item(i, 2)->setText(QString::fromStdString(headshot));
                        break;
                    }
                }
            }
        }
    }
}

// Query Encora API for the recording data
QString MainWindow::getDataFromURL(){
    QNetworkAccessManager manager;
    QNetworkRequest request = QNetworkRequest(QUrl(QString::fromStdString(encoraIDURL)));
    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer " + QByteArray::fromStdString(encoraAPIKey)));
    QString userAgent = QString("NFOBuilder/%1").arg(APP_VERSION);
    request.setRawHeader("User-Agent", userAgent.toUtf8());
    QNetworkReply *response = manager.get(request);
    QEventLoop event;
    connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    QString source = response->readAll();

    // handle incorrect encora ID
    if (source.contains("Call to a member function getFormattedRecording() on null")) {
        QMessageBox::warning(this, "Error", "Encora ID lookup failed. Please check the ID and try again.");
    }
    return source;
}

// Build the XML file
string buildXML(){
    string xmlPart1 =   "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"yes\"?>\n"
                        "<movie>\n"
                        "   <title>" + showName + "</title>\n"
                        "   <originaltitle>" + showName + "</originaltitle>\n"
                        "   <sorttitle>" + showName + "</sorttitle>\n"
                        "   <thumb aspect=\"poster\">" + showPoster + "</thumb>\n"
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

// Test that the NFO has been created successfully
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

// Create the NFO file
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
    }
  }
  // Reset the form
  clearAllValues();
}

// When EncoraID text is changed, set variables ready for the API call
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

// When API key is set, set the variable and allow the lookup button to be enabled
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

// Remove the stored API key and reset UI elements
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

// set variables upon textChanged events for each form entry
void MainWindow::on_showNameInput_textChanged(const QString &arg1)
{
    showName = arg1.toStdString();
}

void MainWindow::on_showPosterInput_textChanged(const QString &arg1)
{
    showPoster = arg1.toStdString();
    ui->showPosterInput->setStyleSheet("");
}

void MainWindow::on_showDateInput_textChanged(const QString &arg1)
{
    std::string arg1Str = arg1.toStdString(); // Convert once
    showDate = arg1Str;
    if (arg1Str.length() >= 6) {
        showYear = arg1Str.substr(0, arg1Str.length() - 6);
    } else {
        showYear = "";
    }
}

void MainWindow::on_showLocationInput_textChanged(const QString &arg1)
{
    showLocation = arg1.toStdString();
}

void MainWindow::on_showMasterInput_textChanged(const QString &arg1)
{
    showDirector = arg1.toStdString();
}

void MainWindow::on_showSynopsisInput_textChanged()
{
    showPlot = ui->showSynopsisInput->toPlainText().toStdString();
    ui->showSynopsisInput->setStyleSheet("");
}

void MainWindow::on_outputFolderInput_textChanged(const QString &arg1)
{
    outputFolder = arg1.toStdString();
}

void MainWindow::on_outputFolderInput_editingFinished()
{
    char last = outputFolder.back();
    if(last != '/') {
        outputFolder = outputFolder + '/';
        ui->outputFolderInput->setText(QString::fromStdString(outputFolder));
    }
}

void MainWindow::clearAllValues(){

    //clear global strings
    showName = "";
    showPoster = "";
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
    ui->showPosterInput->setText("");
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
    ui->castTable->scrollToTop();
}


void MainWindow::on_castTable_cellChanged(int row, int column)
{
    string test;
    // When actor/actress name changed, update URL for google search
    if(column == 0) {
        for (int i = 0; i < ui-> castTable -> rowCount(); i++) {
            if (i == row && column != 3) {
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
    ui->castTable->viewport()->update();
}

// Genre Checkbox functions
void MainWindow::modifyGenre(const std::string& genre, bool checked) {
    std::cout << "Genre: " << genre << std::endl;
    std::cout << "Checked: " << (checked ? "true" : "false") << std::endl;

    if (checked) {
        // Add genre to showGenre
        showGenre += genre + "\n"; // Ensure genre is followed by a newline for separation
    } else {
        // Remove genre from showGenre
        size_t pos = showGenre.find(genre);
        while (pos != std::string::npos) {
            showGenre.erase(pos, genre.length());
            pos = showGenre.find(genre); // Find the next occurrence
        }

        // Remove extra newlines
        showGenre.erase(std::unique(showGenre.begin(), showGenre.end(),
                                    [] (char a, char b) { return a == '\n' && b == '\n'; }),
                        showGenre.end());
    }
}

void MainWindow::on_checkbox_musical_toggled(bool checked)
{
    string genre = "   <genre>Musical</genre>\n";
    ui->checkbox_musical->setStyleSheet("");
    ui->checkbox_play->setStyleSheet("");
    ui->checkbox_ballet->setStyleSheet("");
    modifyGenre(genre, checked);
}

void MainWindow::on_checkbox_play_toggled(bool checked)
{
    string genre = "   <genre>Play</genre>\n";
    ui->checkbox_musical->setStyleSheet("");
    ui->checkbox_play->setStyleSheet("");
    ui->checkbox_ballet->setStyleSheet("");
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

// NFT checkbox function
void MainWindow::on_isNFTCheckbox_toggled(bool checked)
{
    if (checked) {
        isNFT = true;
    } else {
        isNFT = false;
    }
}

// API buttons
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
    QString APIShowTour = obj["tour"].toString();
    QString recordingMaster = obj["master"].toString();
    QString APIShowDescription = obj.value("metadata").toObject().value("show_description").toString();
    showName = APIShowName.toStdString();
    showLocation = APIShowTour.toStdString();
    showDirector = recordingMaster.toStdString();
    showPlot = APIShowDescription.toStdString();
    ui->showNameInput->setText(APIShowName);
    ui->showMasterInput->setText(recordingMaster);
    ui->showLocationInput->setText(APIShowTour);
    ui->showSynopsisInput->setText(APIShowDescription);

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

        // Add the status to the character name if it exists
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

    // highlight fields which need looking at red
    ui->showPosterInput->setStyleSheet("border: 1px solid red");
    ui->checkbox_musical->setStyleSheet("border: 1px solid red");
    ui->checkbox_play->setStyleSheet("border: 1px solid red");
    ui->checkbox_ballet->setStyleSheet("border: 1px solid red");

    if (ui->showSynopsisInput->toPlainText() == "") {
        ui->showSynopsisInput->setStyleSheet("border: 1px solid red");
    }

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

// Handle opening google for actor headshots
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
