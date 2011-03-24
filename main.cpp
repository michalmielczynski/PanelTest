/******************************************************************************
* Copyright 2010 by Klik Michal Mielczynski, 
* klik@klik.pl
* os. Przyjazni 7/25, 61-684 Poznan, Poland.
******************************************************************************/
/******************************************************************************
* Content of this file is copyrighted. Unauthorized use and distribution is not allowed.
* For licencing information, please contact us at klik@klik.pl
******************************************************************************/

#include <QtGui/QApplication>
#include "mainwindow.h"
#include "qgraphicsbloomfilter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
