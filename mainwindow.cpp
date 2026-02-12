#include "mainwindow.h"
#include "widget.h"
#include <QPushButton>
#include <QLayout>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QWidget{parent}
{
    QPushButton* btn = new QPushButton("Шифрование");
    QTextEdit* text = new QTextEdit;
    QVBoxLayout* mainlay = new QVBoxLayout();
    mainlay->addWidget(text);
    mainlay->addWidget(btn);
    setLayout(mainlay);

    connect(btn, &QPushButton::clicked, this, [=](){
        w = new Widget();
        w->setAttribute(Qt::WA_DeleteOnClose);
        w->show();
        btn->setDisabled(true);

        connect(w, &QWidget::destroyed, this, [=](){
            btn->setEnabled(true);
        });
    });
}
