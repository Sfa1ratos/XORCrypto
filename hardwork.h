#ifndef HARDWORK_H
#define HARDWORK_H

#include <QObject>

class HardWork : public QObject
{
    Q_OBJECT
public:
    explicit HardWork(QString _path, QString _mask, bool _timerMode, bool _modifyMode, bool _deleteOriginal, QByteArray _key, int _count, QObject *parent = nullptr);

private:
    QString path;
    QString mask;
    bool timerMode;
    bool modifyMode;
    bool deleteOriginal;
    QByteArray key;
    int count;

public slots:
    void Working();

signals:
    void timerstop();
    void timerStart();
    void starting();
    void finished();
    void InitPrBar(int);
    void wInitPrBar(int);
    void filePrBarValue(int);
    void prBarValue(double);
    void wFilePrBarValue(int);
    void wPrBarValue(double);
    void message(QString);
};

#endif // HARDWORK_H
