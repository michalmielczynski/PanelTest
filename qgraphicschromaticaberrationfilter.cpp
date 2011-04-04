#include "qgraphicschromaticaberrationfilter.h"
#include <QPixmap>
#include "qmath.h"
#include <QtOpenGL>

#define clamp(x, low, high)  (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))


float* AddWeighted(float w, const QRgb &in) {

    float s[3];
    s[0] = w * qRed(in);
    s[1] = w * qGreen(in);
    s[2] = w * qBlue(in);
    return s;
//		c[0] += w * s.c[0];
//		c[1] += w * s.c[1];
//		c[2] += w * s.c[2];
}


float* bilinearSampleImage(QImage &img,
	const int xResolution, const int yResolution,
	const float x, const float y)
{

    //Clamp pixel position
	int x1 = clamp(x, 0, xResolution - 1);
	int y1 = clamp(y, 0, yResolution - 1);
	int x2 = clamp(x1 + 1, 0U, xResolution - 1);
	int y2 = clamp(y1 + 1, 0U, yResolution - 1);

	float tx = clamp(x - static_cast<float>(x1), 0.f, 1.f);
	float ty = clamp(y - static_cast<float>(y1), 0.f, 1.f);


	QRgb pixel1 = img.pixel(x1,y1);
	QRgb pixel2 = img.pixel(x2,y1);
	QRgb pixel3 = img.pixel(x1,y2);
	QRgb pixel4 = img.pixel(x2,y2);


	float *pixelOut;

	pixelOut = AddWeighted((1.f - tx) * (1.f - ty), pixel1);
	pixelOut = AddWeighted(tx         * (1.f - ty), pixel2);
	pixelOut = AddWeighted((1.f - tx) * ty,         pixel3);
	pixelOut = AddWeighted(tx         * ty,         pixel4);

	return pixelOut;
}


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
    float aberrationAmount = size/100.f;

    const float invxRes = 1.f / xResolution;
    const float invyRes = 1.f / yResolution;
    //for each pixel in the source image

    for(int y = 0; y < yResolution-1; ++y) {
	    for(int x = 0; x < xResolution-1; ++x) {
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
			    float *pBilinearPixel1=bilinearSampleImage(img, xResolution, yResolution, rb_x, rb_y);
			    float *pBilinearPixel2=bilinearSampleImage(img, xResolution, yResolution, g_x, g_y);

			    float addPixel1[3];
			    addPixel1[0]=pBilinearPixel1[0]*redblue[0];
			    addPixel1[0]=pBilinearPixel1[1]*redblue[1];
			    addPixel1[0]=pBilinearPixel1[2]*redblue[2];

			    float addPixel2[3];
			    addPixel2[0]=pBilinearPixel2[0]*green[0];
			    addPixel2[1]=pBilinearPixel2[1]*green[1];
			    addPixel2[2]=pBilinearPixel2[2]*green[2];

			    outp.setPixel(x,y,qRgb(     qRed(pixel)+addPixel1[0]+addPixel2[0], qGreen(pixel)+addPixel1[1]+addPixel2[1], qBlue(pixel)+addPixel1[2]+addPixel2[2] ));
			    //outp[xResolution * y + x] += RGBColor(redblue) * bilinearSampleImage<RGBColor>(rgbpixels, xResolution, yResolution, rb_x, rb_y);
			    //outp[xResolution * y + x] += RGBColor(green) * bilinearSampleImage<RGBColor>(rgbpixels, xResolution, yResolution, g_x, g_y);
		    }
	    }
    return pixmap.fromImage(outp);
}
