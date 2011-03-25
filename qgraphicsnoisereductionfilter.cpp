#include "qgraphicsnoisereductionfilter.h"
#include <QRgb>
#include <qmath.h>
QGraphicsNoiseReductionFilter::QGraphicsNoiseReductionFilter(QObject *parent) :
    QObject(parent)
{
}

QPixmap QGraphicsNoiseReductionFilter::filter(QPixmap inPixmap, int size)
{
   QImage img = inPixmap.toImage();
   QImage temp = img;
   size=100-size*5;

   for(int x=1; x<img.width()-1;x++)
   {
       for(int y=1; y<img.height()-1; y++)
       {
	   QColor p5(img.pixel(x,y));

	   QColor p1(img.pixel(x-1,y-1));
	   QColor p2(img.pixel(x,y-1));
	   QColor p3(img.pixel(x+1,y-1));
	   QColor p4(img.pixel(x-1,y));

	   QColor p6(img.pixel(x+1,y));
	   QColor p7(img.pixel(x-1,y+1));
	   QColor p8(img.pixel(x,y+1));
	   QColor p9(img.pixel(x+1,y+1));

	   QList<int> rList;
	   rList << p1.red() << p2.red() << p3.red() << p4.red()
		    <<p6.red() << p7.red() <<p8.red() <<p9.red();


	   QList<int> gList;
	   gList <<p1.green() <<p2.green() <<p3.green() <<p4.green() <<p6.green()
		    <<p7.green() <<p8.green() <<p9.green();

	   QList<int> bList;
	   bList << p1.blue() << p2.blue() << p3.blue() << p4.blue()
		    << p6.blue() << p7.blue() << p8.blue() << p9.blue();

	   qSort(rList);
	   qSort(gList);
	   qSort(bList);

	   int minMedianPointDiffR = qMax(rList[rList.count()/2]-size,0);
	   int maxMedianPointDiffR = qMin(rList[rList.count()/2]+size,255);

	   int minMedianPointDiffG = qMax(gList[gList.count()/2]-size,0);
	   int maxMedianPointDiffG = qMin(gList[gList.count()/2]+size,255);

	   int minMedianPointDiffB = qMax(bList[bList.count()/2]-size,0);
	   int maxMedianPointDiffB = qMin(bList[bList.count()/2]+size,255);



	    if( minMedianPointDiffR>p5.red() || maxMedianPointDiffR<p5.red() ||
		minMedianPointDiffG>p5.green() || maxMedianPointDiffG<p5.green() ||
		minMedianPointDiffB>p5.blue() || maxMedianPointDiffB<p5.blue())
		{
		    temp.setPixel(x,y,qRgb(rList[rList.count()/2],gList[gList.count()/2],bList[bList.count()/2]));
		}

       }
   }

//   QImage temp = img;

//   int ApetureMin = -(size/2);
//   int ApetureMax = (size/2);

//   for(int x = 0; x<img.width();++x)
//   {
//       for(int y = 0;y<img.height();++y)
//       {
//	   QList<int> RValues;
//	   QList<int> GValues;
//	   QList<int> BValues;

//	   for(int x2 = ApetureMin;x2<ApetureMax;++x2)
//	   {
//	       int TempX = x+x2;
//	       if(TempX>=0 && TempX < img.width())
//	       {
//		   for(int y2 = ApetureMin; y2 <ApetureMax;++y2)
//		   {
//		       int TempY = y+y2;
//		       if(TempY >= 0 && TempY < img.height())
//		       {
//			   QRgb pixel = temp.pixel(TempX,TempY);
//			   RValues.append(qRed(pixel));
//			   GValues.append(qGreen(pixel));
//			   BValues.append(qBlue(pixel));
//		       }
//		   }
//	       }
//	   }
//	   qSort(RValues);
//	   qSort(GValues);
//	   qSort(BValues);

//	 //  img.setPixel(x,y,qRgb(RValues[RValues.count()/2],GValues[GValues.count()/2],BValues[BValues.count()/2]));
//       }
//   }

return inPixmap.fromImage(temp);
}
