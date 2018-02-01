#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtWebKit>
#include <QThread>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // setCentralWidget(ui->webView);
    mainframe=ui->webView->page()->mainFrame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    mainframe=ui->webView->page()->mainFrame();

    mainframe->evaluateJavaScript("initMap()");

}

void MainWindow::on_pushButton_4_clicked()
{
    QString position = ui->textEdit->toPlainText();

    qDebug() << position;

  //  mainframe=ui->webView->page()->mainFrame();

    mainframe->evaluateJavaScript("search(\""+position+"\")");

}



void MainWindow::on_dingwei_clicked()
{

    QString status;

  //  mainframe=ui->webView->page()->mainFrame();
    QString flag = ui->comboBox->currentText();

    if(flag == QString("北理工"))
    {
        status = "(113.552407,22.370002,\"bl\")";
    }
    else if(flag == QString("北师大"))
    {
        status = "(113.550125,22.357255,\"bs\")";
    }
    else if(flag == QString("圆明新园"))
    {
        status = "(113.544701,22.245372,\"ymxy\")";
    }
    mainframe->evaluateJavaScript("ding"+status);


//    QString js_return;
//     //ui->webView->setUrl(QUrl("qrc:/src/2.html"));

//     QFile file;
//     //file.setFileName(":/map.js");
//     file.setFileName("map.js");
//     file.open(QIODevice::ReadOnly);
//     QString jscript = file.readAll();


//     qDebug() << jscript;
//     //file.close();

//     js_return = mainframe->evaluateJavaScript(jscript).toString();

//     QWebElement doc = mainframe->documentElement();

//     qDebug() << js_return;

//     ui->textEdit->setPlainText(jscript);
//     //ui->textBrowser->setText(js_return);
//     //ui->textBrowser->setText("a");

}

void MainWindow::on_pushButton_2_clicked()
{
  //  mainframe=ui->webView->page()->mainFrame();

    mainframe->evaluateJavaScript("jiaotong()");
}


void MainWindow::on_pushButton_3_clicked()
{
    //mainframe=ui->webView->page()->mainFrame();

    //QString lineString ="113.552811|22.367722","113.552632|22.368792","113.551769|22.369962","113.551589|22.370496","113.551374|22.370496","113.55141|22.371165","113.552775|22.371766","113.552991|22.372435","113.552703|22.373237","113.551661|22.373738","113.551374|22.373838","113.551122|22.374273","113.548751|22.374808","113.548248|22.374874","113.54832|22.374173";

    QString rent;
    QStringList fonts;

    fonts << "113.552811|22.367722" << "113.552632|22.368792" << "113.551769|22.369962" << "113.551589|22.370496" << "113.551374|22.370496" << "113.55141|22.371165" << "113.552775|22.371766" << "113.552991|22.372435" << "113.552703|22.373237" << "113.551661|22.373738" << "113.551374|22.373838" << "113.551122|22.374273" << "113.548751|22.374808" << "113.548248|22.374874" << "113.54832|22.374173";

    QString lineString = fonts.join("&&");

   // qDebug() << lineString;

    mainframe->evaluateJavaScript(rent = QString("addPolyline(%1)").arg('\"'+lineString+'\"'));

   // mainframe->evaluateJavaScript(QString("addPolyline(%1)").arg(lineString));

    qDebug() << rent;
//  mainframe->evaluateJavaScript("addPolyline()");

    QMessageBox::about(NULL, "", "OK");

}

void MainWindow::on_pushButton_5_clicked()
{
    mainframe->evaluateJavaScript("addMarker()");
}


void MainWindow::on_pushButton_7_clicked()
{
    QFile file("test.txt");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream write(&file);
        write << "aaaaaaaaaaa" << "bbbbbbbb" << "aaaaaaaaaaa";
        file.close();
    }
}



//跟踪
void MainWindow::on_pushButton_8_clicked()
{
    QString rent;
    QStringList fonts;

    QString lat;
    QString lng;

    fonts << "113.552811|22.367722" << "113.552632|22.368792" << "113.551769|22.369962" << "113.551589|22.370496" << "113.551374|22.370496" << "113.55141|22.371165" << "113.552775|22.371766" << "113.552991|22.372435" << "113.552703|22.373237" << "113.551661|22.373738" << "113.551374|22.373838" << "113.551122|22.374273" << "113.548751|22.374808" << "113.548248|22.374874" << "113.54832|22.374173";



    for(int i=0;i<fonts.size();i++)
    {
        QString string = static_cast<QString>(fonts.at(i));


         lat = string.split("|")[0];
       //  qDebug() << lat;
         lng = string.split("|")[1];

        mainframe->evaluateJavaScript(rent =QString("genzong(%1,%2)").arg(lat).arg(lng));
        qDebug() << rent;

    }
    //  mainframe->evaluateJavaScript("genzong(113.552632,22.368792)");

}
class mySleep:public QThread
{
     public:
    virtual void run();

};

void mySleep::run()
{

    for( int count = 0; count < 20; count++ )
    {
              sleep( 1000 );
               qDebug( "Test!" );
     }
    exec();
}


void MainWindow::on_pushButton_9_clicked()
{
    mySleep a;
    a.start();

}
