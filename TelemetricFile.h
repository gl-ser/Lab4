//----------------------------------------------------------------------------//
//                       *** ЛАБОРАТОРНАЯ РАБОТА № 4 ***                      //
//                                                                            //
// Файл TelemetricFile.h                                                      //
//                                                                            //
// Автор ГЛУЩЕНКО Сергей Юрьевич                                              //
//                                                                            //
//                                                   Москва, НИИ ТП, 2023 год //
//----------------------------------------------------------------------------//


#ifndef TELEMETRICFILE_H
#define TELEMETRICFILE_H

#include <QFile>
#include <QList>
#include <QString>
#include <QDateTime>


//Одна строка записи телеметрического файла
class TPoint
{
  private:
    double mValue;    //Значение
    QDateTime mTime;  //Время

  public:
    TPoint(void) = delete;
    TPoint(QString line);
    virtual ~TPoint(void);

    //Отображение состояния
    QString toString(void);
};


class TTelemetricFile
{
  private:
    QList<TPoint*> Data;  //Содержимое телеметрического файла
    QFile File;
    bool IsOpen;

    //Очистка внутреннего массива
    void DataClear(void);

    //Закрывает ранее открытый файл
    void CloseFile(void);

    //Открывает произвольный файл на чтение
    // На вход подаются:
    //   - путь и имя файла
    void OpenFile(QString FilePathName);

  public:
    TTelemetricFile(void);
    virtual ~TTelemetricFile(void);

    //Чтение содержимого телеметрического файла в память
    // На вход подается путь и имя файла
    void ReadFile(QString PathName);

    //Вывод данных телеметрического файла
    QStringList Print(void);
};


#endif
