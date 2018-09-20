#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QStack>
#include<QGridLayout>
#include<QPushButton>
#include <QLabel>
#include <QtAlgorithms>

class Calculator : public QWidget
{
    Q_OBJECT
private:
    QLabel* m_plcd;
    QStack<QString> m_stk;
    QString m_strDisplay;
public:
    Calculator(QWidget *parent = nullptr);
    QPushButton* createButton(const QString& str);
    void calculate();

public slots:
    void slotButtonClicked ();
};


#endif // CALCULATOR_H
