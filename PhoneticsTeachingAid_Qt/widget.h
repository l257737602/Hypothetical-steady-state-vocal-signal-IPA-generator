#ifndef WIDGET_H
#define WIDGET_H
#include "qcheckbox.h"
#include <QButtonGroup>
#include <QAbstractButton>
#include <QTextBrowser>
#include <QObject>
#include <QMetaObject>
#include <QWidget>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QString* p_resultToOutput; //要输出到文本框的内容,即用户输入的音素的IPA表示
    QButtonGroup *uliy;
    QButtonGroup *iyii;
    QButtonGroup *uejm;
    QButtonGroup *ykee;
    QButtonGroup *eeyh;
    QButtonGroup *rree;
    QButtonGroup *xnue;
    QButtonGroup *uegf;
    QButtonGroup *ugmf;
    QButtonGroup *ugdd;
    QButtonGroup *ulii;
    QButtonGroup *bi;
    QButtonGroup *yriy;
    QCheckBox *igybjp;
    QMap<int,QString> *mapOfUnroundedVowels;
    QMap<int,QString> *mapOfRoundedVowels;
public slots:
    void anyClick();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
