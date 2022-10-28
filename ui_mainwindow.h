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
        castTable->setItem(1, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        castTable->setItem(2, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        castTable->setItem(3, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        castTable->setItem(4, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        castTable->setItem(5, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        castTable->setItem(6, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        castTable->setItem(7, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        castTable->setItem(8, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        castTable->setItem(9, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        castTable->setItem(10, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        castTable->setItem(11, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        castTable->setItem(12, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        castTable->setItem(13, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        castTable->setItem(14, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        castTable->setItem(15, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        castTable->setItem(16, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        castTable->setItem(17, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        castTable->setItem(18, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        castTable->setItem(19, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        castTable->setItem(20, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        castTable->setItem(21, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        castTable->setItem(22, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        castTable->setItem(23, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        castTable->setItem(24, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        castTable->setItem(25, 0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        castTable->setItem(26, 0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        castTable->setItem(27, 0, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        castTable->setItem(28, 0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        castTable->setItem(29, 0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        castTable->setItem(30, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        castTable->setItem(31, 0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        castTable->setItem(32, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        castTable->setItem(33, 0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        castTable->setItem(34, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        castTable->setItem(35, 0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        castTable->setItem(36, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        castTable->setItem(37, 0, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        castTable->setItem(38, 0, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        castTable->setItem(39, 0, __qtablewidgetitem43);
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
