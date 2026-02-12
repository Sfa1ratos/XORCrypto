#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QComboBox;
class QLineEdit;
class QCheckBox;
class QPushButton;
class QProgressBar;
class QTimer;
class HardWork;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QComboBox* maskCombo;
    QLineEdit* bitLine;
    QCheckBox* checkDelete;
    QPushButton* renameModeBtn;
    QPushButton* timerModeBtn;
    QLineEdit* pathLine;
    QProgressBar* prBar;
    QProgressBar* wPrBar;
    QProgressBar* filePrBar;
    QProgressBar* wfilePrBar;
    QTimer* timer;
    HardWork* worker;
    int count = 0;

};
#endif // WIDGET_H
