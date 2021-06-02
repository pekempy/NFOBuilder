#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "mainwindow.h"
#include "ui_mainwindow.h"

using std::cout; using std::vector;
using std::string; using std::endl;
using std::copy;

string showName;
string showDate;
string showYear;
string showLocation;
string showTag;
string showPlot;
string showPosterURL;
string castList;
string actorXmlString;
string castMember = "<actor>\n"
                    "   <name>str1</name>\n"
                    "   <role>str2</role>\n"
                    "   <thumb>str3</thumb>\n"
                    "   <type>Actor</type>\n"
                    "</actor>\n";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

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
    string xmlPart2 = "<actor><name>Bob</name><role>Derek</role><thumb>https://upload.wikimedia.org/wikipedia/commons/f/fe/Michelle_Borromeo_Actor_Headshots_30.jpg</thumb><type>Actor</type></actor>\n";
    string xmlPart3 =   "</movie>";
    return xmlPart1 + xmlPart2 + xmlPart3;
}



void MainWindow::on_CreateNFO_clicked()
{
    //ui->showNameInput->setText("Hello World");

    //Loop to create XML for cast
    for (int i=0; i < ui->castTable->rowCount(); i++) {
        for (int j = 0; j < ui->castTable->columnCount(); j++){
            QTableWidgetItem *item =  ui->castTable->item(i,j);
            if(j==0) {
                castMember.find("str1");
                castMember.replace(castMember.find("str1"),4,item->text().toStdString());
            }
            else if (j==1) {
                castMember.find("str2");
                castMember.replace(castMember.find("str2"),4,item->text().toStdString());
            }
            else if (j==2) {
                castMember.find("str3");
                castMember.replace(castMember.find("str3"),4,item->text().toStdString());
                actorXmlString.append(castMember + "\n");
            }
        }
        castMember = "<actor>\n"
                    "   <name>str1</name>\n"
                    "   <role>str2</role>\n"
                    "   <thumb>str3</thumb>\n"
                    "   <type>Actor</type>\n"
                    "</actor>\n";
    }


    string output = buildXML();
    if (showName != ""){
        cout << output;
        ui->outputTextArea->setText(QString::fromStdString(output));
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

void MainWindow::clearAllValues(){
    ui->showNameInput->setText("");
    ui->showDateInput->setText("");
    ui->showLocationInput->setText("");
    ui->showTaglineInput->setText("");
    ui->showSynopsisInput->setText("");
    ui->showPosterInput->setText("");
    showName = "";
    showDate = "";
    showYear = "";
    showLocation = "";
    showTag = "";
    showPlot = "";
    showPosterURL = "";
    actorXmlString = "";
}
