//----------------------------------------------------------------------------//
//                       *** ЛАБОРАТОРНАЯ РАБОТА № 4 ***                      //
//                                                                            //
// Файл MainWindow.cpp                                                        //
//                                                                            //
// Автор ГЛУЩЕНКО Сергей Юрьевич                                              //
//                                                                            //
//                                                   Москва, НИИ ТП, 2023 год //
//----------------------------------------------------------------------------//


#include <QFileDialog>
#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
  setupUi(this);

  TF = new TTelemetricFile();
  Data.clear();
}


MainWindow::~MainWindow()
{
  delete TF;
  Data.clear();
}


void MainWindow::on_pushButton_clicked()
{
QString FilePathName;  //Путь и имя к текстовому файлу

  FilePathName = QFileDialog::getOpenFileName(this, QString::fromUtf8("Читать файл"),
                                              qApp->applicationDirPath(), QString::fromUtf8("*.txt"));
  if (FilePathName != "")
  {
    #ifdef __unix__
    FilePathName = FilePathName + ".txt";
    #endif

    TF->ReadFile(FilePathName);
    Data = TF->Print();

    TextProtocol->clear();
    TextProtocol->append(QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss") + " Протокол очищен\n");

    TextProtocol->append("Содержимое телеметрического файла:\n");

    for(int i=0; i<Data.size(); i++)
      TextProtocol->append("Запись № " + QString::number(i+1) + "  " + Data[i]);

    TextProtocol->append("\nВсего записей: " + QString::number(Data.size()));
  }
}
