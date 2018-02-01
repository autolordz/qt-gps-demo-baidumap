#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QTextBrowser;
class QWebPage;
class QWebFrame;
class QLabel;
QT_END_NAMESPACE


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWebPage *webpage;
    QWebFrame *mainframe;
private slots:
    void on_pushButton_9_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();
    void on_dingwei_clicked();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
