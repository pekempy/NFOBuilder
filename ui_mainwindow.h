/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QHBoxLayout *encoraIDLayout;
    QLineEdit *encoraIDText;
    QPushButton *encoraLookupButton;
    QFrame *line_2;
    QFrame *line;
    QLabel *label_4;
    QLabel *showNameLabel;
    QLineEdit *showNameInput;
    QLabel *showDateLabel;
    QLineEdit *showDateInput;
    QLabel *showLocationLabel;
    QLineEdit *showLocationInput;
    QLabel *showTaglineLabel;
    QLineEdit *showTaglineInput;
    QLabel *showSynopsisLabel;
    QTextEdit *showSynopsisInput;
    QLabel *showPosterLabel;
    QLineEdit *showPosterInput;
    QLabel *CastLabel;
    QTableWidget *castTable;
    QHBoxLayout *horizontalLayout;
    QLineEdit *outputFolderInput;
    QPushButton *CreateNFO;
    QLabel *outputFolderLabel;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(850, 899);
        MainWindow->setMaximumSize(QSize(1500, 1500));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/plex-nfo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        centralwidget->setAutoFillBackground(false);
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_3);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        encoraIDLayout = new QHBoxLayout();
        encoraIDLayout->setObjectName(QString::fromUtf8("encoraIDLayout"));
        encoraIDLayout->setContentsMargins(1, 0, 0, -1);
        encoraIDText = new QLineEdit(centralwidget);
        encoraIDText->setObjectName(QString::fromUtf8("encoraIDText"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(encoraIDText->sizePolicy().hasHeightForWidth());
        encoraIDText->setSizePolicy(sizePolicy);

        encoraIDLayout->addWidget(encoraIDText);

        encoraLookupButton = new QPushButton(centralwidget);
        encoraLookupButton->setObjectName(QString::fromUtf8("encoraLookupButton"));
        encoraLookupButton->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(encoraLookupButton->sizePolicy().hasHeightForWidth());
        encoraLookupButton->setSizePolicy(sizePolicy1);

        encoraIDLayout->addWidget(encoraLookupButton);


        formLayout->setLayout(3, QFormLayout::FieldRole, encoraIDLayout);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(4, QFormLayout::LabelRole, line_2);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(100);
        sizePolicy2.setVerticalStretch(5);
        sizePolicy2.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy2);
        line->setMinimumSize(QSize(100, 10));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(4, QFormLayout::FieldRole, line);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(5, QFormLayout::FieldRole, label_4);

        showNameLabel = new QLabel(centralwidget);
        showNameLabel->setObjectName(QString::fromUtf8("showNameLabel"));

        formLayout->setWidget(6, QFormLayout::LabelRole, showNameLabel);

        showNameInput = new QLineEdit(centralwidget);
        showNameInput->setObjectName(QString::fromUtf8("showNameInput"));

        formLayout->setWidget(6, QFormLayout::FieldRole, showNameInput);

        showDateLabel = new QLabel(centralwidget);
        showDateLabel->setObjectName(QString::fromUtf8("showDateLabel"));

        formLayout->setWidget(8, QFormLayout::LabelRole, showDateLabel);

        showDateInput = new QLineEdit(centralwidget);
        showDateInput->setObjectName(QString::fromUtf8("showDateInput"));

        formLayout->setWidget(8, QFormLayout::FieldRole, showDateInput);

        showLocationLabel = new QLabel(centralwidget);
        showLocationLabel->setObjectName(QString::fromUtf8("showLocationLabel"));

        formLayout->setWidget(9, QFormLayout::LabelRole, showLocationLabel);

        showLocationInput = new QLineEdit(centralwidget);
        showLocationInput->setObjectName(QString::fromUtf8("showLocationInput"));
        showLocationInput->setFrame(true);

        formLayout->setWidget(9, QFormLayout::FieldRole, showLocationInput);

        showTaglineLabel = new QLabel(centralwidget);
        showTaglineLabel->setObjectName(QString::fromUtf8("showTaglineLabel"));

        formLayout->setWidget(10, QFormLayout::LabelRole, showTaglineLabel);

        showTaglineInput = new QLineEdit(centralwidget);
        showTaglineInput->setObjectName(QString::fromUtf8("showTaglineInput"));

        formLayout->setWidget(10, QFormLayout::FieldRole, showTaglineInput);

        showSynopsisLabel = new QLabel(centralwidget);
        showSynopsisLabel->setObjectName(QString::fromUtf8("showSynopsisLabel"));

        formLayout->setWidget(11, QFormLayout::LabelRole, showSynopsisLabel);

        showSynopsisInput = new QTextEdit(centralwidget);
        showSynopsisInput->setObjectName(QString::fromUtf8("showSynopsisInput"));

        formLayout->setWidget(11, QFormLayout::FieldRole, showSynopsisInput);

        showPosterLabel = new QLabel(centralwidget);
        showPosterLabel->setObjectName(QString::fromUtf8("showPosterLabel"));

        formLayout->setWidget(12, QFormLayout::LabelRole, showPosterLabel);

        showPosterInput = new QLineEdit(centralwidget);
        showPosterInput->setObjectName(QString::fromUtf8("showPosterInput"));

        formLayout->setWidget(12, QFormLayout::FieldRole, showPosterInput);

        CastLabel = new QLabel(centralwidget);
        CastLabel->setObjectName(QString::fromUtf8("CastLabel"));

        formLayout->setWidget(13, QFormLayout::LabelRole, CastLabel);

        castTable = new QTableWidget(centralwidget);
        if (castTable->columnCount() < 4)
            castTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        castTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        castTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        castTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        castTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (castTable->rowCount() < 40)
            castTable->setRowCount(40);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsEnabled);
        castTable->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        castTable->setItem(0, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        castTable->setItem(0, 2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        castTable->setItem(0, 3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        castTable->setItem(1, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        castTable->setItem(1, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        castTable->setItem(1, 2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        castTable->setItem(1, 3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        castTable->setItem(2, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        castTable->setItem(2, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        castTable->setItem(2, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        castTable->setItem(2, 3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        castTable->setItem(3, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        castTable->setItem(3, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        castTable->setItem(3, 2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        castTable->setItem(3, 3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        castTable->setItem(4, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        castTable->setItem(4, 1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        castTable->setItem(4, 2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        castTable->setItem(4, 3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        castTable->setItem(5, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        castTable->setItem(5, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        castTable->setItem(5, 2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        castTable->setItem(5, 3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        castTable->setItem(6, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        castTable->setItem(6, 1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        castTable->setItem(6, 2, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        castTable->setItem(6, 3, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        castTable->setItem(7, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        castTable->setItem(7, 1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        castTable->setItem(7, 2, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        castTable->setItem(7, 3, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        castTable->setItem(8, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        castTable->setItem(8, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        castTable->setItem(8, 2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        castTable->setItem(8, 3, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        castTable->setItem(9, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        castTable->setItem(9, 1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        castTable->setItem(9, 2, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        castTable->setItem(9, 3, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        castTable->setItem(10, 0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        castTable->setItem(10, 1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        castTable->setItem(10, 2, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        castTable->setItem(10, 3, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        castTable->setItem(11, 0, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        castTable->setItem(11, 1, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        castTable->setItem(11, 2, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        castTable->setItem(11, 3, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        castTable->setItem(12, 0, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        castTable->setItem(12, 1, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        castTable->setItem(12, 2, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        castTable->setItem(12, 3, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        castTable->setItem(13, 0, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        castTable->setItem(13, 1, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        castTable->setItem(13, 2, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        castTable->setItem(13, 3, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        castTable->setItem(14, 0, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        castTable->setItem(14, 1, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        castTable->setItem(14, 2, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        castTable->setItem(14, 3, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        castTable->setItem(15, 0, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        castTable->setItem(15, 1, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        castTable->setItem(15, 2, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        castTable->setItem(15, 3, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        castTable->setItem(16, 0, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        castTable->setItem(16, 1, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        castTable->setItem(16, 2, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        castTable->setItem(16, 3, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        castTable->setItem(17, 0, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        castTable->setItem(17, 1, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        castTable->setItem(17, 2, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        castTable->setItem(17, 3, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        castTable->setItem(18, 0, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        castTable->setItem(18, 1, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        castTable->setItem(18, 2, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        castTable->setItem(18, 3, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        castTable->setItem(19, 0, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        castTable->setItem(19, 1, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        castTable->setItem(19, 2, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        castTable->setItem(19, 3, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        castTable->setItem(20, 0, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        castTable->setItem(20, 1, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        castTable->setItem(20, 2, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        castTable->setItem(20, 3, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        castTable->setItem(21, 0, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        castTable->setItem(21, 1, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        castTable->setItem(21, 2, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        castTable->setItem(21, 3, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        castTable->setItem(22, 0, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        castTable->setItem(22, 1, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        castTable->setItem(22, 2, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        castTable->setItem(22, 3, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        castTable->setItem(23, 0, __qtablewidgetitem96);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        castTable->setItem(23, 1, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        castTable->setItem(23, 2, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        castTable->setItem(23, 3, __qtablewidgetitem99);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        castTable->setItem(24, 0, __qtablewidgetitem100);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        castTable->setItem(24, 1, __qtablewidgetitem101);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        castTable->setItem(24, 2, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        castTable->setItem(24, 3, __qtablewidgetitem103);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        castTable->setItem(25, 0, __qtablewidgetitem104);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        castTable->setItem(25, 1, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        castTable->setItem(25, 2, __qtablewidgetitem106);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        castTable->setItem(25, 3, __qtablewidgetitem107);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        castTable->setItem(26, 0, __qtablewidgetitem108);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        castTable->setItem(26, 1, __qtablewidgetitem109);
        QTableWidgetItem *__qtablewidgetitem110 = new QTableWidgetItem();
        castTable->setItem(26, 2, __qtablewidgetitem110);
        QTableWidgetItem *__qtablewidgetitem111 = new QTableWidgetItem();
        castTable->setItem(26, 3, __qtablewidgetitem111);
        QTableWidgetItem *__qtablewidgetitem112 = new QTableWidgetItem();
        castTable->setItem(27, 0, __qtablewidgetitem112);
        QTableWidgetItem *__qtablewidgetitem113 = new QTableWidgetItem();
        castTable->setItem(27, 1, __qtablewidgetitem113);
        QTableWidgetItem *__qtablewidgetitem114 = new QTableWidgetItem();
        castTable->setItem(27, 2, __qtablewidgetitem114);
        QTableWidgetItem *__qtablewidgetitem115 = new QTableWidgetItem();
        castTable->setItem(27, 3, __qtablewidgetitem115);
        QTableWidgetItem *__qtablewidgetitem116 = new QTableWidgetItem();
        castTable->setItem(28, 0, __qtablewidgetitem116);
        QTableWidgetItem *__qtablewidgetitem117 = new QTableWidgetItem();
        castTable->setItem(28, 1, __qtablewidgetitem117);
        QTableWidgetItem *__qtablewidgetitem118 = new QTableWidgetItem();
        castTable->setItem(28, 2, __qtablewidgetitem118);
        QTableWidgetItem *__qtablewidgetitem119 = new QTableWidgetItem();
        castTable->setItem(28, 3, __qtablewidgetitem119);
        QTableWidgetItem *__qtablewidgetitem120 = new QTableWidgetItem();
        castTable->setItem(29, 0, __qtablewidgetitem120);
        QTableWidgetItem *__qtablewidgetitem121 = new QTableWidgetItem();
        castTable->setItem(29, 1, __qtablewidgetitem121);
        QTableWidgetItem *__qtablewidgetitem122 = new QTableWidgetItem();
        castTable->setItem(29, 2, __qtablewidgetitem122);
        QTableWidgetItem *__qtablewidgetitem123 = new QTableWidgetItem();
        castTable->setItem(29, 3, __qtablewidgetitem123);
        QTableWidgetItem *__qtablewidgetitem124 = new QTableWidgetItem();
        castTable->setItem(30, 0, __qtablewidgetitem124);
        QTableWidgetItem *__qtablewidgetitem125 = new QTableWidgetItem();
        castTable->setItem(30, 1, __qtablewidgetitem125);
        QTableWidgetItem *__qtablewidgetitem126 = new QTableWidgetItem();
        castTable->setItem(30, 2, __qtablewidgetitem126);
        QTableWidgetItem *__qtablewidgetitem127 = new QTableWidgetItem();
        castTable->setItem(30, 3, __qtablewidgetitem127);
        QTableWidgetItem *__qtablewidgetitem128 = new QTableWidgetItem();
        castTable->setItem(31, 0, __qtablewidgetitem128);
        QTableWidgetItem *__qtablewidgetitem129 = new QTableWidgetItem();
        castTable->setItem(31, 1, __qtablewidgetitem129);
        QTableWidgetItem *__qtablewidgetitem130 = new QTableWidgetItem();
        castTable->setItem(31, 2, __qtablewidgetitem130);
        QTableWidgetItem *__qtablewidgetitem131 = new QTableWidgetItem();
        castTable->setItem(31, 3, __qtablewidgetitem131);
        QTableWidgetItem *__qtablewidgetitem132 = new QTableWidgetItem();
        castTable->setItem(32, 0, __qtablewidgetitem132);
        QTableWidgetItem *__qtablewidgetitem133 = new QTableWidgetItem();
        castTable->setItem(32, 1, __qtablewidgetitem133);
        QTableWidgetItem *__qtablewidgetitem134 = new QTableWidgetItem();
        castTable->setItem(32, 2, __qtablewidgetitem134);
        QTableWidgetItem *__qtablewidgetitem135 = new QTableWidgetItem();
        castTable->setItem(32, 3, __qtablewidgetitem135);
        QTableWidgetItem *__qtablewidgetitem136 = new QTableWidgetItem();
        castTable->setItem(33, 0, __qtablewidgetitem136);
        QTableWidgetItem *__qtablewidgetitem137 = new QTableWidgetItem();
        castTable->setItem(33, 1, __qtablewidgetitem137);
        QTableWidgetItem *__qtablewidgetitem138 = new QTableWidgetItem();
        castTable->setItem(33, 2, __qtablewidgetitem138);
        QTableWidgetItem *__qtablewidgetitem139 = new QTableWidgetItem();
        castTable->setItem(33, 3, __qtablewidgetitem139);
        QTableWidgetItem *__qtablewidgetitem140 = new QTableWidgetItem();
        castTable->setItem(34, 0, __qtablewidgetitem140);
        QTableWidgetItem *__qtablewidgetitem141 = new QTableWidgetItem();
        castTable->setItem(34, 1, __qtablewidgetitem141);
        QTableWidgetItem *__qtablewidgetitem142 = new QTableWidgetItem();
        castTable->setItem(34, 2, __qtablewidgetitem142);
        QTableWidgetItem *__qtablewidgetitem143 = new QTableWidgetItem();
        castTable->setItem(34, 3, __qtablewidgetitem143);
        QTableWidgetItem *__qtablewidgetitem144 = new QTableWidgetItem();
        castTable->setItem(35, 0, __qtablewidgetitem144);
        QTableWidgetItem *__qtablewidgetitem145 = new QTableWidgetItem();
        castTable->setItem(35, 1, __qtablewidgetitem145);
        QTableWidgetItem *__qtablewidgetitem146 = new QTableWidgetItem();
        castTable->setItem(35, 2, __qtablewidgetitem146);
        QTableWidgetItem *__qtablewidgetitem147 = new QTableWidgetItem();
        castTable->setItem(35, 3, __qtablewidgetitem147);
        QTableWidgetItem *__qtablewidgetitem148 = new QTableWidgetItem();
        castTable->setItem(36, 0, __qtablewidgetitem148);
        QTableWidgetItem *__qtablewidgetitem149 = new QTableWidgetItem();
        castTable->setItem(36, 1, __qtablewidgetitem149);
        QTableWidgetItem *__qtablewidgetitem150 = new QTableWidgetItem();
        castTable->setItem(36, 2, __qtablewidgetitem150);
        QTableWidgetItem *__qtablewidgetitem151 = new QTableWidgetItem();
        castTable->setItem(36, 3, __qtablewidgetitem151);
        QTableWidgetItem *__qtablewidgetitem152 = new QTableWidgetItem();
        castTable->setItem(37, 0, __qtablewidgetitem152);
        QTableWidgetItem *__qtablewidgetitem153 = new QTableWidgetItem();
        castTable->setItem(37, 1, __qtablewidgetitem153);
        QTableWidgetItem *__qtablewidgetitem154 = new QTableWidgetItem();
        castTable->setItem(37, 2, __qtablewidgetitem154);
        QTableWidgetItem *__qtablewidgetitem155 = new QTableWidgetItem();
        castTable->setItem(37, 3, __qtablewidgetitem155);
        QTableWidgetItem *__qtablewidgetitem156 = new QTableWidgetItem();
        castTable->setItem(38, 0, __qtablewidgetitem156);
        QTableWidgetItem *__qtablewidgetitem157 = new QTableWidgetItem();
        castTable->setItem(38, 1, __qtablewidgetitem157);
        QTableWidgetItem *__qtablewidgetitem158 = new QTableWidgetItem();
        castTable->setItem(38, 2, __qtablewidgetitem158);
        QTableWidgetItem *__qtablewidgetitem159 = new QTableWidgetItem();
        castTable->setItem(38, 3, __qtablewidgetitem159);
        QTableWidgetItem *__qtablewidgetitem160 = new QTableWidgetItem();
        castTable->setItem(39, 0, __qtablewidgetitem160);
        QTableWidgetItem *__qtablewidgetitem161 = new QTableWidgetItem();
        castTable->setItem(39, 1, __qtablewidgetitem161);
        QTableWidgetItem *__qtablewidgetitem162 = new QTableWidgetItem();
        castTable->setItem(39, 2, __qtablewidgetitem162);
        QTableWidgetItem *__qtablewidgetitem163 = new QTableWidgetItem();
        castTable->setItem(39, 3, __qtablewidgetitem163);
        castTable->setObjectName(QString::fromUtf8("castTable"));
        castTable->setMinimumSize(QSize(0, 300));
        castTable->setRowCount(40);
        castTable->horizontalHeader()->setCascadingSectionResizes(false);
        castTable->horizontalHeader()->setMinimumSectionSize(150);
        castTable->horizontalHeader()->setDefaultSectionSize(200);
        castTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));

        formLayout->setWidget(14, QFormLayout::SpanningRole, castTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        outputFolderInput = new QLineEdit(centralwidget);
        outputFolderInput->setObjectName(QString::fromUtf8("outputFolderInput"));

        horizontalLayout->addWidget(outputFolderInput);

        CreateNFO = new QPushButton(centralwidget);
        CreateNFO->setObjectName(QString::fromUtf8("CreateNFO"));
        CreateNFO->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(CreateNFO);


        formLayout->setLayout(19, QFormLayout::FieldRole, horizontalLayout);

        outputFolderLabel = new QLabel(centralwidget);
        outputFolderLabel->setObjectName(QString::fromUtf8("outputFolderLabel"));

        formLayout->setWidget(19, QFormLayout::LabelRole, outputFolderLabel);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 850, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "NFOBuilder for Plex", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "If you want to auto-fill show details, please enter an Encora ID here. ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "This will pull as much data as it can from Encora and auto-fill where possible.", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Encora ID Lookup", nullptr));
        encoraIDText->setPlaceholderText(QCoreApplication::translate("MainWindow", "Encora ID", nullptr));
        encoraLookupButton->setText(QCoreApplication::translate("MainWindow", "Lookup Encora ID", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "If you need to modify any information, do this below.", nullptr));
        showNameLabel->setText(QCoreApplication::translate("MainWindow", "Show Name", nullptr));
        showNameInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "The shows name", nullptr));
        showDateLabel->setText(QCoreApplication::translate("MainWindow", "Performance Date", nullptr));
        showDateInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "YYYY-MM-DD", nullptr));
        showLocationLabel->setText(QCoreApplication::translate("MainWindow", "Location", nullptr));
        showLocationInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Location/Studio", nullptr));
        showTaglineLabel->setText(QCoreApplication::translate("MainWindow", "Tag Line", nullptr));
        showTaglineInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "A tagline for the show", nullptr));
        showSynopsisLabel->setText(QCoreApplication::translate("MainWindow", "Synopsis", nullptr));
        showSynopsisInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "A brief synopsis of the show, or notes", nullptr));
        showPosterLabel->setText(QCoreApplication::translate("MainWindow", "Show Poster URL", nullptr));
        showPosterInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Full URL to image to use as Poster", nullptr));
        CastLabel->setText(QCoreApplication::translate("MainWindow", "Cast Members", nullptr));
        QTableWidgetItem *___qtablewidgetitem = castTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Actor/Actress Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = castTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Character Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = castTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Headshot URL", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = castTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "CLICK to search images", nullptr));

        const bool __sortingEnabled = castTable->isSortingEnabled();
        castTable->setSortingEnabled(false);
        castTable->setSortingEnabled(__sortingEnabled);

        outputFolderInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "e.g C:/Users/Pete/Desktop", nullptr));
        CreateNFO->setText(QCoreApplication::translate("MainWindow", "Create NFO", nullptr));
        outputFolderLabel->setText(QCoreApplication::translate("MainWindow", "Output folder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
