/*
 * imageProcessing.c
 *
 *  Created on: Feb 11, 2022
 *      Author: sgojkovic
 */

#include "imageProcessing.h"
#include "bmp.h"

#define BW_TRESHOLD 128
const unsigned char darkenFactor = 192;
const int brightnessMinimum = 20;
const int brightnessMaximum = 220;


int darkenImage(unsigned char* iData, int iWidth, int iHeight)
{
	int i;
	int j;
	unsigned char* ptr = iData;

	for (i=0; i<iHeight; i++)
	{
		for (j=0; j<iWidth; j++)
		{
			*ptr = *ptr + darkenFactor;
			ptr++;
			*ptr = *ptr + darkenFactor;
			ptr += 1;
			*(ptr) = *ptr + darkenFactor;
			ptr++;
		}
		ptr+=2;
	}
	return 0;
}

int adjustImageBrightness(unsigned char* iData, int iWidth, int iHeight,
		bool brighten, unsigned char adjustmentValue)
{
	int i;
	int newValue;

	for (i=0; i<iWidth*iHeight*3; i++)
	{
		newValue = iData[i];
		if(brighten)
		{
			newValue += adjustmentValue;
		}
		else
		{
			newValue -= adjustmentValue;
		}

		if(newValue < brightnessMinimum)
		{
			newValue = brightnessMinimum;
		}
		else if(newValue > brightnessMaximum)
		{
			newValue = brightnessMaximum;
		}

		iData[i] = newValue;
	}

	return 0;
}

void effect(unsigned char* iData, int iWidth, int iHeight)
{
	unsigned char* ptr = iData;
	int i;
	int j;
	int k;

	for (i=0; i<iHeight; i++)
	{
		for (j=0; j<iWidth; j++)
		{
			for (k=0; k<3; k++)
			{
				if(*(ptr+k) > BW_TRESHOLD)
				{
					*(ptr+k) = 255;
				}
				else
				{
					*(ptr+k) = 0;
				}
			}
			ptr += 3;
		}
		ptr+=2;
	}
}

RGB average_RGB(unsigned char* iData, int iWidth, int iHeight)
{
	int i;
	RGB average_value_rgb;
//	unsigned char* ptr = iData;
	int sumR=0, sumG=0, sumB=0;
	int num_pixels = iHeight * iWidth;
	for (i = 0; i<iHeight * iWidth * 3 ; i = i+3)
	{
		sumR += iData[i];
		sumG += iData[i+1];
		sumB += iData[i+2];
	}

	average_value_rgb.R = sumR / (double)num_pixels;
	average_value_rgb.G = sumG / (double)num_pixels;
	average_value_rgb.B = sumB / (double)num_pixels;
	return average_value_rgb;
}

void mean_3x3(unsigned char* iData, int iWidth, int iHeight)
{
	int i;


	int sum_of_pixelR = 0, sum_of_pixelG =0, sum_of_pixelB = 0;

	int num_pixels = iHeight * iWidth;
	for (i = 0; i<iHeight * iWidth * 3 ; i = i+3)
	{
		if(i != 0  &&  i != (i*iHeight)/3  &&  i != (i*iWidth)/3  &&  i != num_pixels)
		{
			sum_of_pixelR = iData[i-12]+iData[i-9]+iData[i-6]+iData[i-3]+iData[i]+iData[i+3]+iData[i+6]+iData[i+9]+iData[i+12] ;
			sum_of_pixelG = iData[i-11]+iData[i-8]+iData[i-5]+iData[i-2]+iData[i+1]+iData[i+4]+iData[i+7]+iData[i+10]+iData[i+13];
			sum_of_pixelB = iData[i-10]+iData[i-7]+iData[i-4]+iData[i-1]+iData[i+2]+iData[i+5]+iData[i+8]+iData[i+11]+iData[i+14];
			iData[i] = sum_of_pixelR / 9;
			iData[i+1] = sum_of_pixelG / 9;
			iData[i+2] = sum_of_pixelB / 9;
		}
		sum_of_pixelR = 0;
		sum_of_pixelG = 0;
		sum_of_pixelB = 0;
	}

}
