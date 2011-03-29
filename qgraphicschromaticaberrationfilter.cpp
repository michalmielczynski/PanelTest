#include "qgraphicschromaticaberrationfilter.h"
#include <QPixmap>
#include "qmath.h"



//QImage bilinearSampleImage(QImage img,
//	const int xResolution, const int yResolution,
//	const float x, const float y)
//{
//	int x1 = Clamp(Floor2UInt(x), 0U, xResolution - 1);
//	int y1 = Clamp(Floor2UInt(y), 0U, yResolution - 1);
//	int x2 = Clamp(x1 + 1, 0U, xResolution - 1);
//	int y2 = Clamp(y1 + 1, 0U, yResolution - 1);
//	float tx = Clamp(x - static_cast<float>(x1), 0.f, 1.f);
//	float ty = Clamp(y - static_cast<float>(y1), 0.f, 1.f);


//	c.AddWeighted((1.f - tx) * (1.f - ty), pixels[y1 * xResolution + x1]);
//	c.AddWeighted(tx         * (1.f - ty), pixels[y1 * xResolution + x2]);
//	c.AddWeighted((1.f - tx) * ty,         pixels[y2 * xResolution + x1]);
//	c.AddWeighted(tx         * ty,         pixels[y2 * xResolution + x2]);

//	return c;
//}



QGraphicsChromaticAberrationFilter::QGraphicsChromaticAberrationFilter(QObject *parent) :
    QObject(parent)
{
}

QPixmap QGraphicsChromaticAberrationFilter::filter(QPixmap pixmap, int size)
{

    QImage img = pixmap.toImage();
    QImage outp = img;

    int xResolution = img.width();
    int yResolution = img.height();
    float aberrationAmount = size;

    const float invxRes = 1.f / xResolution;
    const float invyRes = 1.f / yResolution;
    //for each pixel in the source image
    for(int y = 0; y < yResolution; ++y) {
	    for(int x = 0; x < xResolution; ++x) {
		    const float nPx = x * invxRes;
		    const float nPy = y * invyRes;
		    const float xOffset = nPx - 0.5f;
		    const float yOffset = nPy - 0.5f;
		    const float tOffset = sqrtf(xOffset * xOffset + yOffset * yOffset);


			    const float rb_x = (0.5f + xOffset * (1.f + tOffset * aberrationAmount)) * xResolution;
			    const float rb_y = (0.5f + yOffset * (1.f + tOffset * aberrationAmount)) * yResolution;
			    const float g_x =  (0.5f + xOffset * (1.f - tOffset * aberrationAmount)) * xResolution;
			    const float g_y =  (0.5f + yOffset * (1.f - tOffset * aberrationAmount)) * yResolution;

			    const float redblue[] = {1.f, 0.f, 1.f};
			    const float green[] = {0.f, 1.f, 0.f};

			    QRgb pixel = outp.pixel(x,y);


			    outp.setPixel(x,y,qRgb(     qRed(pixel)+ 1.f*size, qGreen(pixel), qBlue(pixel)+1 *size ));
			     outp.setPixel(x,y,qRgb(     qRed(pixel), qGreen(pixel)+1*size, qBlue(pixel) ));
			    //outp[xResolution * y + x] += RGBColor(redblue) * bilinearSampleImage<RGBColor>(rgbpixels, xResolution, yResolution, rb_x, rb_y);
			    //outp[xResolution * y + x] += RGBColor(green) * bilinearSampleImage<RGBColor>(rgbpixels, xResolution, yResolution, g_x, g_y);
		    }
	    }
    return pixmap.fromImage(outp);
}



