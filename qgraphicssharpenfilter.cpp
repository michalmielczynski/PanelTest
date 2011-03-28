#include "qgraphicssharpenfilter.h"
#include <QImage>
#include <QPixmap>
#include <QDebug>

QGraphicsSharpenFilter::QGraphicsSharpenFilter(QObject *parent) :
    QObject(parent)
{
}

QPixmap QGraphicsSharpenFilter::filter(const QPixmap pixmap, int size)
{
    QImage img = pixmap.toImage();
    QImage temp = img;
    double z= size*0.01;
    double mask[] = { 0,   -z  ,   0,
			 -z,  1+4*z,  -z,
			  0,   -z  ,   0 };
	int r,g,b;

	for(int i=1;i<(img.height()-1);i++) {
	   for(int j=1;j<(img.width()-1);j++) {
	      double linc_r=0, linc_g=0,linc_b=0;
	      for(int k=0; k<=2; k++) {
		 for(int l=0; l<=2; l++) {

		    QRgb pixel = img.pixel(j+l-1,i+k-1);


		    linc_r +=( qRed(pixel)  * mask[ k*3 + l] );
		    linc_g +=( qGreen(pixel)* mask[ k*3 + l] );
		    linc_b +=( qBlue(pixel) * mask[ k*3 + l] );
		 }
	      }
		linc_r=qMin(int(linc_r),255);
		linc_g=qMin(int(linc_g),255);
		linc_b=qMin(int(linc_b),255);

		linc_r=qMax(int(linc_r),0);
		linc_g=qMax(int(linc_g),0);
		linc_b=qMax(int(linc_b),0);



	      r = linc_r;
	      g = linc_g;
	      b = linc_b;

	      img.setPixel(j,i,qRgb(r,g,b));

	   }
	}
    return pixmap.fromImage(img);
 }

