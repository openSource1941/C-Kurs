/*
 ============================================================================
 Name        : example-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "imageProcessing.h"

int main()
{
	int err = 0;
	BITMAPFILEHEADER bitmapFileHeader;
	BITMAPINFOHEADER bitmapInfoHeader;
	unsigned char* bitmapData;

	printf("Applying brightness\n");
	bitmapData = LoadBitmapFile("ubuntu.bmp",&bitmapFileHeader, &bitmapInfoHeader);
	// Apply image brightness to image
	adjustImageBrightness(bitmapData, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight, false, 70);
	err = SaveBitmapFile("out_brightness.bmp", &bitmapFileHeader,
		&bitmapInfoHeader, bitmapData);
	if (err)
	{
		printf("Error trying to save bitmap\n");
	}
	free(bitmapData);

	printf("Applying dark image\n");
	bitmapData = LoadBitmapFile("ubuntu.bmp",&bitmapFileHeader, &bitmapInfoHeader);
	darkenImage(bitmapData, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight);
	err = SaveBitmapFile("out_dark.bmp", &bitmapFileHeader,
		&bitmapInfoHeader, bitmapData);
	if (err)
	{
		printf("Error trying to save bitmap\n");
	}
	free(bitmapData);

	printf("Applying effect\n");
	bitmapData = LoadBitmapFile("ubuntu.bmp",&bitmapFileHeader, &bitmapInfoHeader);
	effect(bitmapData, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight);
	err = SaveBitmapFile("out_bw.bmp", &bitmapFileHeader,
		&bitmapInfoHeader, bitmapData);
	if (err)
	{
		printf("Error trying to save bitmap\n");
	}
	free(bitmapData);

	bitmapData = LoadBitmapFile("Image.bmp",&bitmapFileHeader, &bitmapInfoHeader);
	RGB average_values;
	average_values = average_RGB(bitmapData, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight);
	free(bitmapData);
	printf("Average values of R: %.2f G: %.2f B: %.2f\n",average_values.R, average_values.G, average_values.B );

	printf("Removing noise \n");
	bitmapData = LoadBitmapFile("Image_with_noise.bmp",&bitmapFileHeader, &bitmapInfoHeader);

	mean_3x3(bitmapData, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight);
	err = SaveBitmapFile("out_without_noise.bmp", &bitmapFileHeader,
		&bitmapInfoHeader, bitmapData);
	if (err)
	{
		printf("Error trying to save bitmap\n");
	}
	free(bitmapData);



	return 1;
}
