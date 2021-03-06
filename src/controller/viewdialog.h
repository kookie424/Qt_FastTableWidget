#ifndef VIEWDIALOG_H
#define VIEWDIALOG_H

#include <QDialog>

#include "../fasttable/fasttablewidget.h"

#define VIEWDIALOG_BASE_CONSTRUCTOR ui->setupUi(this);\
                                    \
                                    setWindowFlags(Qt::Window);\
                                    \
                                    mFastTableWidget=new FastTableWidget(this);\
                                    ui->fastTableLayout->addWidget(mFastTableWidget);\
                                    \
                                    mFastTableWidget->setSizes(1, 1);



namespace Ui {
    class ViewDialog;
}

class ViewDialog : public QDialog
{
    Q_OBJECT

public:
    FastTableWidget* mFastTableWidget;

    explicit ViewDialog(QWidget *parent = 0);
    explicit ViewDialog(int aValue, QWidget *parent = 0);
    explicit ViewDialog(bool aValue, QWidget *parent = 0);
    explicit ViewDialog(CustomFastTableWidget::MouseLocation aValue, QWidget *parent = 0);
    explicit ViewDialog(QPoint aValue, QWidget *parent = 0);
    explicit ViewDialog(QRect aValue, QWidget *parent = 0);
    explicit ViewDialog(QList<qint16> *aValues, bool isVertical = false, QWidget *parent = 0);
    explicit ViewDialog(QList<int> *aValues, bool isVertical = false, QWidget *parent = 0);
    explicit ViewDialog(QList<bool> *aValues, bool isVertical = false, QWidget *parent = 0);
    explicit ViewDialog(QList<QPoint> *aValues, QWidget *parent = 0);
    explicit ViewDialog(QList<QRect> *aValues, QWidget *parent = 0);
    explicit ViewDialog(QList<QList<int> > *aValues, QWidget *parent = 0);
    explicit ViewDialog(QList<QList<bool> > *aValues, QWidget *parent = 0);
    explicit ViewDialog(QList<QStringList> *aValues, QWidget *parent = 0);
    ~ViewDialog();

private:
    Ui::ViewDialog *ui;

    inline QString valueToString(int aValue);
    inline QString valueToString(bool aValue);
    inline QString valueToString(CustomFastTableWidget::MouseLocation aValue);
    inline QString valueToString(QString aValue);

public slots:
    int exec();
};

#endif // VIEWDIALOG_H
