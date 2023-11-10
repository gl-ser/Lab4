//----------------------------------------------------------------------------//
//                       *** ЛАБОРАТОРНАЯ РАБОТА № 4 ***                      //
//                                                                            //
// Файл MainWindow.h                                                          //
//                                                                            //
// Автор ГЛУЩЕНКО Сергей Юрьевич                                              //
//                                                                            //
//                                                   Москва, НИИ ТП, 2023 год //
//----------------------------------------------------------------------------//


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_MainWindow.h"
#include "TelemetricFile.h"


class MainWindow : public QMainWindow, private Ui::MainWindow
{
  Q_OBJECT

  private slots:
    //Читать файл
    void on_pushButton_clicked();

  private:
    QStringList Data;
    TTelemetricFile *TF;

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow(void);
};


#endif
