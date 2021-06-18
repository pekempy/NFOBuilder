#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <QFileInfo>
#include <QMessageBox>
#include <QDesktopServices>

#include "mainwindow.h"
#include "ui_mainwindow.h"

using std::vector; using std::string;
using std::endl; using std::copy;

//global strings
string showName;
string showDate;
string showYear;
string showLocation;
string showTag;
string showPlot;
string showPosterURL;
string castList;
string actorXmlString;
string castMember = "  <actor>\n"
                    "       <name>str1</name>\n"
                    "       <role>str2</role>\n"
                    "       <thumb>str3</thumb>\n"
                    "       <type>Actor</type>\n"
                    "   </actor>";
string outputFolder;

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Build the XML and return
string buildXML(){
    string xmlPart1 =   "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"yes\"?>\n"
                        "<movie>\n"
                        "   <title>" + showName + "</title>\n"
                        "   <originaltitle>" + showName + "</originaltitle>\n"
                        "   <sorttitle>" + showName + "</sorttitle>\n"
                        "   <premiered>" + showDate + "</premiered>\n"
                        "   <releasedate>" + showDate + "</releasedate>\n"
                        "   <year>" + showYear + "</year>\n"
                        "   <studio>" + showLocation + "</studio>\n"
                        "   <outline>" + showTag + "</outline>\n"
                        "   <tagline>" + showTag + "</tagline>\n"
                        "   <plot>" + showPlot + "</plot>\n"
                        "   <lockdata>false</lockdata>\n"
                        "   <genre>Musical</genre>\n"
                        "   <genre>Musical Theatre</genre>\n"
                        "   <art>\n"
                        "       <poster>" + showPosterURL + "</poster>\n"
                        "   </art>\n";
    string xmlPart2 = actorXmlString;
    string xmlPart3 =   "</movie>";
    return xmlPart1 + xmlPart2 + xmlPart3;
}

bool fileExists(QString handle){
    QFileInfo check_file(handle);
    if(check_file.exists() && check_file.isFile())
       { return true; } else { return false; }
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
          actorXmlString.append(castMember + "\n");
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
     string fileName = outputFolder + showName + "-" + showDate + ".nfo";
     QString qsFileName = QString::fromStdString(fileName);
     myfile.open(fileName);
     myfile << output;
     myfile.close();
     if (fileExists(qsFileName)) {
        QMessageBox msg;
        msg.setText("Successfully created: " + qsFileName);
        msg.exec();
    }
  }
  clearAllValues();
}

//Set variables upon text changed for each section.
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

void MainWindow::on_showTaglineInput_textChanged(const QString &arg1)
{
    showTag = arg1.toStdString();
}

void MainWindow::on_showSynopsisInput_textChanged()
{
    showPlot = ui->showSynopsisInput->toPlainText().toStdString();
}

void MainWindow::on_showPosterInput_textChanged(const QString &arg1)
{
    showPosterURL = arg1.toStdString();
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
    showTag = "";
    showPlot = "";
    showPosterURL = "";
    actorXmlString = "";

    //clear UI values
    ui->showNameInput->setText("");
    ui->showDateInput->setText("");
    ui->showLocationInput->setText("");
    ui->showTaglineInput->setText("");
    ui->showSynopsisInput->setText("");
    ui->showPosterInput->setText("");
    ui->castTable->clearContents();

    //set column 0 in cast table contents to ""
    for (int i = 0; i < ui->castTable->rowCount(); i++) {
        //i = row
        QTableWidgetItem * actorCell = ui->castTable->item(i,0);
        if(!actorCell){
            actorCell = new QTableWidgetItem();
            ui->castTable->setItem(i, 0, actorCell);
            ui->castTable->setItem(i, 3, NULL);
        }
    }

    //jump to top of cast table
    ui->castTable->scrollToTop();
}

void MainWindow::on_castTable_cellChanged(int row, int column)
{
    //when each row, column a changed, update link in column 4 for that row.
    if(column == 0) {
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
}


void MainWindow::on_castTable_cellClicked(int row, int column)
{
    string urlToOpen = "";
    QString actorName = "";
    QTableWidgetItem * actor = ui -> castTable -> item(row, 0);
    actorName = actor->text();
        if (actorName != QString::fromStdString("")) {
            if(column == 3){
                urlToOpen = ui->castTable->item(row,column)->text().toStdString();
            }
            if (urlToOpen != ""){
                QDesktopServices::openUrl(QUrl(QString::fromStdString(urlToOpen)));
            }
        }
}

