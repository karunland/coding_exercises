#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;
            int mu = round((green + red + blue) / 3);
            image[i][j].rgbtBlue = mu;
            image[i][j].rgbtGreen = mu;
            image[i][j].rgbtRed = mu;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // uint8_t temp = 0;
    float origred, origblue, origgreen;
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // first we make a copy of vaiables of image for each of its color
            origred = image[i][j].rgbtRed;
            origblue = image[i][j].rgbtBlue;
            origgreen = image[i][j].rgbtGreen;
            // next, multiply by neccessary values for sepia red
            sepiaRed = round(0.393 * origred + 0.769 * origgreen + 0.189 * origblue);
            sepiaGreen = round(0.349 * origred + 0.686 * origgreen + 0.168 * origblue);
            sepiaBlue = round(0.272 * origred + 0.534 * origgreen + 0.131 * origblue);
            // check if they exceed
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            // And finally update the image array
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int c = 0; c < width / 2; c++)
        {
            // create var that it's compatible
            RGBTRIPLE t = image[i][c];
            image[i][c] = image[i][width - (c + 1)];
            image[i][width - (c + 1)] = t;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    // printf("aaa\n");
    return;
}
