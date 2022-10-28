#ifndef IMAGE_SEARCH_H
#define IMAGE_SEARCH_H

#include <QDialog>


namespace Ui {
class image_search;
}

class image_search : public QDialog
{
    Q_OBJECT

public:
    explicit image_search(QString actorName, QString URL, QWidget *parent = nullptr);
    ~image_search();

private slots:
    void loadImage();

    QString getHtmlSource(QString URL);

    void on_buttonBox_accepted();

signals:
    void linkChanged(QString actorName, QString downloadLink);

private:
    Ui::image_search *ui;
};

#endif // IMAGE_SEARCH_H
