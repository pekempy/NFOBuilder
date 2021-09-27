#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QWebElementCollection>
#include <QWebFrame>
#include <QWebPage>
#include <QWebElement>
#include <QList>
#include <string>
#include <QUrl>
#include <QPixmap>
#include <QWebSettings>
#include <QFile>
#include <QLabel>
#include <QObject>
#include <QByteArray>
#include <QNetworkRequest>


#include "image_search.h"
#include "filedownloader.h"
#include "ui_image_search.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

FileDownloader * img;
int currentImg = 0;
QList<QString> imgResults;
QList<QByteArray> imgBytes;
QString globActorName;

image_search::image_search(QString actorName, QString URL, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::image_search)
{
    connect(this, SIGNAL(linkChanged(QString,QString)), parent, SLOT(linkChangedHandler(QString,QString)));
    ui->setupUi(this);
    QWidget::setWindowTitle(actorName);
    globActorName = actorName;
    //load the results
    QString source = getHtmlSource(URL);
    QWebPage page;
    QWebFrame *frame = page.mainFrame();
    frame->setHtml(source);
    QWebElement document = frame->documentElement();
    QWebElementCollection coll = document.findAll("img");
    QTextStream out(stderr);
    foreach (QWebElement elem, coll){
        imgResults += elem.attribute("src");
    }

    QNetworkAccessManager manager;
    for(int i = 0; i < 20; ++i){
        QNetworkReply *response = manager.get(QNetworkRequest(QUrl(imgResults[i])));
        QEventLoop event;
        QObject::connect(response, SIGNAL(finished()), &event, SLOT(quit()));
        event.exec();
        if(response->isFinished()){
            QByteArray data = response->readAll();
            imgBytes += data;
        }
    }
    loadImage();
}

void image_search::loadImage() {
    QPixmap image;
    QLabel* imgs[] = {ui->img1, ui->img2, ui->img3, ui->img4, ui->img5, ui->img6, ui->img7, ui->img8, ui->img9, ui->img10,
                      ui->img11, ui->img12, ui->img13, ui->img14, ui->img15, ui->img16, ui->img17, ui->img18, ui->img19, ui->img20};
    for(int i = 0; i < imgBytes.length(); ++i) {
        image.loadFromData(imgBytes[i]);
        imgs[i]->setPixmap(image);
    }
    //ui->img1->setPixmap(image.scaled(ui->img1->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

image_search::~image_search()
{
    imgResults.clear();
    imgBytes.clear();
    img = NULL;
    currentImg = 0;
    delete ui;
}

QString image_search::getHtmlSource(QString URL){
    //get html source of URL
    QNetworkAccessManager manager;
    QNetworkReply *response = manager.get(QNetworkRequest(QUrl(URL)));
    QEventLoop event;
    connect(response, SIGNAL(finished()), &event, SLOT(quit()));
    event.exec();
    QString source = response->readAll();
    return source;
}


void image_search::on_buttonBox_accepted()
{
    int checkedButton = 0;
    if(ui->btn1->isChecked()) { checkedButton = 0; }
    if(ui->btn2->isChecked()) { checkedButton = 2; }
    if(ui->btn3->isChecked()) { checkedButton = 3; }
    if(ui->btn4->isChecked()) { checkedButton = 4; }
    if(ui->btn5->isChecked()) { checkedButton = 5; }
    if(ui->btn6->isChecked()) { checkedButton = 6; }
    if(ui->btn7->isChecked()) { checkedButton = 7; }
    if(ui->btn8->isChecked()) { checkedButton = 8; }
    if(ui->btn9->isChecked()) { checkedButton = 9; }
    if(ui->btn10->isChecked()) { checkedButton = 10; }
    if(ui->btn11->isChecked()) { checkedButton = 11; }
    if(ui->btn12->isChecked()) { checkedButton = 12; }
    if(ui->btn13->isChecked()) { checkedButton = 13; }
    if(ui->btn14->isChecked()) { checkedButton = 14; }
    if(ui->btn15->isChecked()) { checkedButton = 15; }
    if(ui->btn16->isChecked()) { checkedButton = 16; }
    if(ui->btn17->isChecked()) { checkedButton = 17; }
    if(ui->btn18->isChecked()) { checkedButton = 18; }
    if(ui->btn19->isChecked()) { checkedButton = 19; }
    if(ui->btn20->isChecked()) { checkedButton = 20; }
    QString url = imgResults[checkedButton];
    QString actor = globActorName;
    emit linkChanged(actor, url);
}

