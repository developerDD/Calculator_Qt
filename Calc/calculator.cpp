#include "calculator.h"

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    //m_plcd = new QLCDNumber(12);
    //m_plcd->setSegmentStyle(QLCDNumber::Flat);
    m_plcd = new QLabel("0");

    QFont font = m_plcd->font();
    font.setPixelSize(32);
    m_plcd->setFont(font);
    m_plcd->setStyleSheet("QLabel {"
                          "border-style: solid;"
                          "border-width: 2px;"
                          "border-color: black; "
                          "}");

    m_plcd->setAlignment(Qt::AlignRight);


    m_plcd->setMinimumSize(150,50);

    QChar aButtons[4][4] = {
        {'7','8','9','/'},
        {'4','5','6','*'},
        {'1','2','3','-'},
        {'0','.','=','+'}
    };
    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(m_plcd,0,0,1,4);
    ptopLayout->addWidget(createButton("CE"), 1, 3);
    ptopLayout->addWidget(createButton("("), 1, 1);
    ptopLayout->addWidget(createButton(")"), 1, 2);
    for (int i =0;i<4;++i)
    {
        for (int j =0;j<4;++j)
        {
           ptopLayout->addWidget(createButton (aButtons[i][j]),i+2,j);
        }
    }
    setLayout(ptopLayout);
}

QPushButton* Calculator::createButton(const QString& str)
{
    QPushButton* pcmd = new QPushButton(str);
    pcmd->setMinimumSize(40,40);
    connect(pcmd,SIGNAL(clicked()),SLOT(slotButtonClicked()));
    return pcmd;
}

void Calculator::calculate()
{
    double  dOperand2    = m_stk.pop().toDouble();
    QString strOperation = m_stk.pop();
    double  dOperand1    = m_stk.pop().toDouble();
    double  dResult      = 0;
    if (strOperation == "+") {
        dResult = dOperand1 + dOperand2;
    }
    if (strOperation == "-") {
        dResult = dOperand1 - dOperand2;
    }
    if (strOperation == "/") {
        dResult = dOperand1 / dOperand2;
    }
    if (strOperation == "*") {
        dResult = dOperand1 * dOperand2;
    }
    m_plcd->setNum(dResult);
}
// ----------------------------------------------------------------------



void Calculator::slotButtonClicked()
{
    if(((QPushButton*)sender())->text()=="CE")
    {
        m_plcd->setText("0");
        m_strDisplay="";
        return;
    }
    //m_strDisplay += ((QPushButton*)sender())->text();
    QString str = ((QPushButton*)sender())->text();
    /*if (str == "CE") {
        m_stk.clear();
        m_plcd->display("0");
        return;
    }
    if (str.contains(QRegExp("[0-9]")))
    {
        str = QString().setNum(m_plcd->value()) + str;
        m_plcd->display(str.toDouble());
    }
    else if (str == (m_strDisplay += str))
    {
    m_plcd->display(m_strDisplay);
    }
    else if (m_stk.count() >= 2)
    {
        {
            m_stk.push(QString().setNum(m_plcd->value()));
            calculate();
            m_stk.clear();
            m_stk.push(QString().setNum(m_plcd->value()));
        }
         if (str != "=")
        {
            m_stk.push(str);
        }
    }
   else {
            m_stk.push(QString().setNum(m_plcd->value()));
            m_stk.push(str);
            m_plcd->display(0);
        }*/

       m_plcd->setText(/*m_strDisplay*/str);

       //=====================================================
       // добавил привидение к обратной польской записи выражения
       /*
    QVector <QChar> vux;
    QStack<QChar> oper;
    QString str = m_strDisplay;
    for (int i =0;i<str.size();++i)
    {
        if(str[i]==")")
        {
            while (oper.top()!="("){
                vux.push_back(oper.pop());
            }
            if(oper.top()=="(")
            {
                oper.pop();
            }
            continue;
        }
        if(str[i]=="("||str[i]=="-"||str[i]=="+"||str[i]=="*"||str[i]=="/")
        {
            if(oper.isEmpty())
            {
                oper.push(str[i]);
                continue;
            }
            if(oper.top()=="+" && str[i]=="*" || oper.top()=="-" && str[i]=="/"||
               oper.top()=="-" && str[i]=="*" || oper.top()=="+" && str[i]=="/"||
               str[i]=="("||oper.top()=="(" )
            {
                oper.push(str[i]);
                continue;
            }
            if(oper.top()=="*" && str[i]=="+" || oper.top()=="/" && str[i]=="-"||
               oper.top()=="*" && str[i]=="-" || oper.top()=="/" && str[i]=="+")
            {
                vux.push_back(oper.pop());
            }
            if(oper.top()=="+"&& str[i]=="+"|| oper.top()=="+"&& str[i]=="-"||
               oper.top()=="-"&& str[i]=="+"|| oper.top()=="-"&& str[i]=="-"||
               oper.top()=="*"&& str[i]=="/" ||oper.top()=="/"&& str[i]=="*")
            {
                vux.push_back(oper.pop());
                oper.push(str[i]);
            }
        }
       else
        {
           vux.push_back(str[i]);
        }
    }
    while(!oper.isEmpty())
    {
        vux.push_back(oper.pop());
    }




*/

}


