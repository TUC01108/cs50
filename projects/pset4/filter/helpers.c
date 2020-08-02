#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // get average of 3 numbers and round
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp;

    for (int i = 0; i < height; i++)
    {
        int n = width - 1;
        for (int j = 0; j < n; j++)
        {
            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][n].rgbtBlue;
            image[i][n].rgbtBlue = temp;
            temp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][n].rgbtGreen;
            image[i][n].rgbtGreen = temp;
            temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][n].rgbtRed;
            image[i][n].rgbtRed = temp;
            n--;
        }
    }
    return;
}

#include <stdbool.h>
#define MAX_BLUR (height * width)

bool validIndex();

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int blur1;
    int i = 0, j = 0;

    RGBTRIPLE image2[height][width];

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            int counter = 0;
            int red = 0;
            int green = 0;
            int blue = 0;
            //
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if (validIndex(i + k, j + l, height, width))
                    {
                        counter++;
                        blue += image[i + k][j + l].rgbtBlue;
                        green += image[i + k][j + l].rgbtGreen;
                        red += image[i + k][j + l].rgbtRed;
                    }
                }
            }
            image2[i][j].rgbtBlue = round(blue / (float)counter);
            image2[i][j].rgbtGreen = round(green / (float)counter);
            image2[i][j].rgbtRed = round(red / (float)counter);
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = image2[i][j].rgbtBlue;
            image[i][j].rgbtGreen = image2[i][j].rgbtGreen;
            image[i][j].rgbtRed = image2[i][j].rgbtRed;
        }
    }
    return;
}









bool validIndex(int i, int j, int height, int width)
{
    if (i < 0 || j < 0 || i == height || j == width)
    {
        return false;
    }
    return true;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
