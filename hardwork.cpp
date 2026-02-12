#include "hardwork.h"
#include <QDir>

HardWork::HardWork(QString _path,QString _mask, bool _timerMode, bool _modifyMode, bool _deleteOriginal, QByteArray _key, int _count, QObject *parent)
    : QObject{parent}
{
    path = _path;
    mask = _mask;
    timerMode = _timerMode;
    modifyMode = _modifyMode;
    deleteOriginal = _deleteOriginal;
    key = _key;
    count = _count;
}

void HardWork::Working()
{
    emit starting();
    if(!timerMode)
    {
        emit timerstop();
    }
    if (path.trimmed().isEmpty()) {
        emit message("Путь не указан");
        return;
    }
    QDir dir(path.trimmed());
    if (!dir.exists()) {
        emit message("Директория не найдена");
        return;
    }
    QStringList masking;
    if (mask.isEmpty()) {
        emit message("Маска пуста");
        return;
    }
    masking.push_back(mask);
    QStringList files = dir.entryList(masking.toList(), QDir::Files | QDir::NoSymLinks);
    if(!files.isEmpty()) {
        if(timerMode) {
            emit InitPrBar(files.size());
        }
        else {
            emit wInitPrBar(files.size());
        }
        int counter = 0;
        for(auto name : files) {
            if(timerMode) {
                emit filePrBarValue(counter);
                emit prBarValue(0);
            }
            else {
                emit wFilePrBarValue(counter);
                emit wPrBarValue(0);
            }
            QFile file(dir.absoluteFilePath(name));
            QFile newFile;

            if (!file.open(QIODevice::ReadWrite)) {
                emit message("Не удалось открыть файл");
                return;
            }

            if (key.isEmpty()) {
                emit message("Ключ неверный");
                return;
            }

            QByteArray data = file.readAll();
            long double lastPercent = -1.0;
            for (long long i = 0; i < data.size(); ++i) {
                data[i] = data[i] ^ key[i % key.size()];
                if(timerMode) {
                    long double percent = (i * 100) / data.size();
                    if (percent != lastPercent) {
                        lastPercent = percent;
                        emit prBarValue(percent);
                    }
                }
                else {
                    long double percent = (i * 100) / data.size();
                    if (percent != lastPercent) {
                        lastPercent = percent;
                        emit wPrBarValue(percent);
                    }
                }


            }
             ++counter;
            if(timerMode) {
                emit filePrBarValue(counter);
                emit prBarValue(100);
            }
            else {
                emit wFilePrBarValue(counter);
                emit wPrBarValue(100);
            }


            if(!modifyMode) {
                QString format = name.mid(name.indexOf("."));
                name = name.mid(0,name.indexOf("."));
                name+="_Mod_" + QString::number(count);
                name+=format;
                newFile.setFileName(path + "/" + name);
                if (newFile.open(QIODevice::WriteOnly)) {
                    newFile.write(data);
                    newFile.close();
                    if(!deleteOriginal) {
                        file.close();
                    }
                    else {
                        file.close();
                        file.remove();
                    }

                }
                else {
                    emit message("Не удалось создать файл");
                    return;
                }
            }
            else {
                if(!deleteOriginal) {
                    file.resize(0);
                    file.write(data);
                    file.close();
                }
                else {
                    file.close();
                    file.remove();
                    emit message("Невозможно перезаписать. Файл удален");
                    return;
                }
            }
        }
    }
    else {
        emit message("Файлов не найдено");
        return;
    }
    if(!timerMode)
    {
        emit timerStart();
    }
    emit finished();
}
