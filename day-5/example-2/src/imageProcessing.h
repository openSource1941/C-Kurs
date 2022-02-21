/*
 * imageProcessing.h
 *
 *  Created on: Feb 11, 2022
 *      Author: sgojkovic
 */

#ifndef IMAGEPROCESSING_H_
#define IMAGEPROCESSING_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "bmp.h"

int darkenImage(unsigned char* imageData, int imageWidth, int imageHeight);

int adjustImageBrightness(unsigned char* iData, int iWidth, int iHeight,
		bool brighten, unsigned char adjustmentValue);

void effect(unsigned char* iData, int iWidth, int iHeight);

RGB average_RGB(unsigned char* iData, int iWidth, int iHeight);

void mean_3x3(unsigned char* iData, int iWidth, int iHeight);
#endif /* IMAGEPROCESSING_H_ */
