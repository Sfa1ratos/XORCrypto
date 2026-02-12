#include "widget.h"
#include "hardwork.h"

#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QFileDialog>
#include <QTimer>
#include <QFile>
#include <QDir>
#include <QCoreApplication>
#include <QMessageBox>
#include <QProgressBar>
#include <QThread>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(500,400);
    maskCombo = new QComboBox(this);
    maskCombo->setDuplicatesEnabled(false);
    maskCombo->addItem("*.txt");
    maskCombo->addItem("*.bin");
    maskCombo->addItem("*.mp4");

    QLabel* maskLabelInsert = new QLabel("Введите маску: ");
    QLineEdit* maskLine = new QLineEdit(this);
    QHBoxLayout* maskLay = new QHBoxLayout;
    maskLay->addWidget(maskLabelInsert);
    maskLay->addWidget(maskLine);
    QLabel* maskLabel = new QLabel("Выберите маску: ");
    QHBoxLayout* _maskLay = new QHBoxLayout;
    _maskLay->addWidget(maskLabel);
    _maskLay->addWidget(maskCombo);

    QLabel* checkLabel = new QLabel("Удалить исходный файл?",this);
    checkDelete = new QCheckBox(this);
    checkDelete->setChecked(false);
    QHBoxLayout* checkLay = new QHBoxLayout;
    checkLay->addWidget(checkLabel);
    checkLay->addWidget(checkDelete);

    QLabel* pathLab = new QLabel("Введите путь: ");
    pathLine = new QLineEdit(this);
    pathLine->setText(QCoreApplication::applicationDirPath());
    QPushButton* selectBtn = new QPushButton("Выбрать папку", this);
    QHBoxLayout* pathLay = new QHBoxLayout;
    pathLay->addWidget(pathLab);
    pathLay->addWidget(pathLine);
    pathLay->addWidget(selectBtn);

    renameModeBtn = new QPushButton("Модификация", this);
    renameModeBtn->setCheckable(true);
    timerModeBtn = new QPushButton("Таймер", this);
    timerModeBtn->setCheckable(true);
    QHBoxLayout* btnLay = new QHBoxLayout;
    btnLay->addWidget(renameModeBtn);
    btnLay->addWidget(timerModeBtn);

    QLabel* bitLabel = new QLabel("Введите 8 байт: ");
    bitLine = new QLineEdit(this);
    bitLine->setText("11111111");
    bitLine->setMaxLength(8);
    QHBoxLayout* bitLay = new QHBoxLayout;
    bitLay->addWidget(bitLabel);
    bitLay->addWidget(bitLine);

    QPushButton* okBtn = new QPushButton("Применить", this);
    QPushButton* closeBtn = new QPushButton("Закрыть", this);
    QHBoxLayout* setButLay = new QHBoxLayout;
    setButLay->addWidget(okBtn);
    setButLay->addWidget(closeBtn);

    QWidget* w = new QWidget();
    QPushButton* startBtn = new QPushButton("Старт",w);
    QPushButton* stopBtn = new QPushButton("Стоп",w);
    stopBtn->setEnabled(false);
    QPushButton* wCloseBtn = new QPushButton("Закрыть", w);
    QHBoxLayout* setTimerButLay = new QHBoxLayout;
    QVBoxLayout* wMainLay = new QVBoxLayout;
    wfilePrBar = new QProgressBar(w);
    wfilePrBar->setTextVisible(false);
    wPrBar = new QProgressBar(w);
    wPrBar->setRange(0, 100);
    wPrBar->setValue(0);
    wPrBar->setTextVisible(true);
    wPrBar->setFormat("%p%");
    setTimerButLay->addWidget(startBtn);
    setTimerButLay->addWidget(stopBtn);
    setTimerButLay->addWidget(wCloseBtn);
    wMainLay->addWidget(wfilePrBar);
    wMainLay->addWidget(wPrBar);
    wMainLay->addLayout(setTimerButLay);
    timer = new QTimer(this);
    timer->setInterval(60000);
    w->setLayout(wMainLay);
    prBar = new QProgressBar(this);
    prBar->setRange(0, 100);
    prBar->setValue(0);
    prBar->setTextVisible(true);
    prBar->setFormat("%p%");
    filePrBar = new QProgressBar(w);
    filePrBar->setTextVisible(false);

    connect(wCloseBtn, &QPushButton::clicked, w, [=]() {
        timer->stop();
        w->hide();
        show();
    });

    connect(startBtn, &QPushButton::clicked, this, [=]() {
        timer->start();
        startBtn->setDisabled(true);
        stopBtn->setEnabled(true);
    });

    connect(stopBtn, &QPushButton::clicked, this, [=]() {
        timer->stop();
        startBtn->setDisabled(false);
        stopBtn->setEnabled(false);
    });


    QVBoxLayout* mainLay = new QVBoxLayout(this);
    mainLay->addLayout(maskLay);
    mainLay->addLayout(_maskLay);
    mainLay->addLayout(checkLay);
    mainLay->addLayout(pathLay);
    mainLay->addLayout(btnLay);
    mainLay->addLayout(bitLay);
    mainLay->addWidget(filePrBar);
    mainLay->addWidget(prBar);
    mainLay->addLayout(setButLay);


    setLayout(mainLay);
    connect(timer, &QTimer::timeout, this, [=]() {
        ++count;
        QString path = pathLine->text();
        QString mask = maskCombo->currentText();
        QByteArray key  = QByteArray::fromHex(bitLine->text().toUtf8());
        bool deleteOriginal = checkDelete->isChecked();
        bool modifyMode = renameModeBtn->isChecked();
        bool timerMode = timerModeBtn->isChecked();

        worker = new HardWork(path, mask,timerMode, modifyMode, deleteOriginal, key, count);
        QThread *thread = new QThread(this);
        worker->moveToThread(thread);
        connect(thread, &QThread::started, worker, &HardWork::Working);
        connect(worker, &HardWork::finished, thread, &QThread::quit);
        connect(worker, &HardWork::starting, this, [=](){
            startBtn->setEnabled(false);
            stopBtn->setEnabled(false);
            wCloseBtn->setEnabled(false);
        });
        connect(worker, &HardWork::timerstop,this, [=](){
            qDebug() << "timerStop";
            timer->stop();
        });
        connect(worker, &HardWork::timerStart,this, [=](){
            qDebug() << "timerStart";
            timer->start();
        });
        connect(worker, &HardWork::wInitPrBar,this, [=](int size){
            wfilePrBar->setValue(0);
            wfilePrBar->setTextVisible(true);
            wfilePrBar->setFormat("%v из %m");
            wfilePrBar->setRange(0,size);
        });
        connect(worker, &HardWork::wFilePrBarValue,this, [=](int value){
            wfilePrBar->setValue(value);
        });
        connect(worker, &HardWork::wPrBarValue,this, [=](double value){
            wPrBar->setValue(value);
        });
        connect(worker, &HardWork::message,this, [=](QString value){
            QMessageBox::warning(this,
                                 tr("Внимание"),
                                 value,
                                 QMessageBox::Ok);
        });
        connect(worker, &HardWork::finished, this, [=](){
            startBtn->setEnabled(false);
            stopBtn->setEnabled(true);
            wCloseBtn->setEnabled(true);
        });
        connect(worker, &HardWork::finished, worker, &QObject::deleteLater);
        connect(thread, &QThread::finished, this, [=]() {

        });
        connect(thread, &QThread::finished, thread, &QObject::deleteLater);
        thread->start();
    });

    connect(maskLine, &QLineEdit::editingFinished, this, [=]() {
        QString mask = maskLine->text().trimmed();
        if (!mask.isEmpty() && maskCombo->findText(mask) == -1) {
            maskCombo->addItem(mask);
        }
        maskLine->clear();
    });

    connect(selectBtn, &QPushButton::clicked, this, [=]() {
        QString dir = QFileDialog::getExistingDirectory(
            this,
            tr("Выберите папку"),
            QDir::currentPath(),
            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
            );

        if (!dir.isEmpty()) {
            pathLine->setText(dir);
        }
    });

    connect(renameModeBtn, &QPushButton::clicked, this, [=]() {
        if(renameModeBtn->isChecked()) {
            renameModeBtn->setText("Перезапись");
        }
        else {
            renameModeBtn->setText("Модификация");
        }
    });

    connect(timerModeBtn, &QPushButton::clicked, this, [=]() {
        if(timerModeBtn->isChecked()) {
            timerModeBtn->setText("Разовый запуск");
        }
        else {
            timerModeBtn->setText("Таймер");
        }
    });

    connect(closeBtn, &QPushButton::clicked, this, [=]() {
        close();
    });

    connect(okBtn, &QPushButton::clicked, this, [=]() {
        if(timerModeBtn->isChecked()) {
            ++count;
            QString path = pathLine->text();
            QString mask = maskCombo->currentText();
            QByteArray key  = QByteArray::fromHex(bitLine->text().toUtf8());
            bool deleteOriginal = checkDelete->isChecked();
            bool modifyMode = renameModeBtn->isChecked();
            bool timerMode = timerModeBtn->isChecked();

            worker = new HardWork(path, mask,timerMode, modifyMode, deleteOriginal, key, count);
            QThread *thread = new QThread(this);
            worker->moveToThread(thread);
            connect(thread, &QThread::started, worker, &HardWork::Working);
            connect(worker, &HardWork::finished, thread, &QThread::quit);
            connect(worker, &HardWork::InitPrBar,this, [=](int size){
                filePrBar->setValue(0);
                filePrBar->setTextVisible(true);
                filePrBar->setFormat("%v из %m");
                filePrBar->setRange(0,size);
            });
            connect(worker, &HardWork::filePrBarValue,this, [=](int value){
                filePrBar->setValue(value);
            });
            connect(worker, &HardWork::prBarValue,this, [=](double value){
                prBar->setValue(value);
            });
            connect(worker, &HardWork::message,this, [=](QString value){
                QMessageBox::warning(this,
                                     tr("Внимание"),
                                     value,
                                     QMessageBox::Ok);
            });
            connect(worker, &HardWork::finished, this, &QWidget::close);
            connect(worker, &HardWork::finished, worker, &QObject::deleteLater);
            connect(thread, &QThread::finished, thread, &QObject::deleteLater);
            thread->start();
        }
        else {
            hide();
            w->show();
        }
    });
}

Widget::~Widget() {}
