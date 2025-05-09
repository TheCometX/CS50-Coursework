#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            int grey = round((image[x][y].rgbtBlue + image[x][y].rgbtGreen + image[x][y].rgbtRed) / 3.0);
            image[x][y].rgbtBlue = image[x][y].rgbtGreen = image[x][y].rgbtRed = grey;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            int newBlue = round(0.272 * image[x][y].rgbtRed + 0.534 * image[x][y].rgbtGreen + 0.131 * image[x][y].rgbtBlue);
            int newGreen = round(0.349 * image[x][y].rgbtRed + 0.686 * image[x][y].rgbtGreen + 0.168 * image[x][y].rgbtBlue);
            int newRed = round(0.393 * image[x][y].rgbtRed + 0.769 * image[x][y].rgbtGreen + 0.189 * image[x][y].rgbtBlue);
            if (newBlue > 255) {
                image[x][y].rgbtBlue = 255;
            }
            else {
                image[x][y].rgbtBlue = newBlue;
            }
            if (newGreen > 255) {
                image[x][y].rgbtGreen = 255;
            }
            else {
                image[x][y].rgbtGreen = newGreen;
            }
            if (newRed > 255) {
                image[x][y].rgbtRed = 255;
            }
            else {
                image[x][y].rgbtRed = newRed;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int x = 0; x < height; x++) {
        float halfWidth = width / 2.0;
        for (int y = 0; y < halfWidth; y++) {
            RGBTRIPLE temp = image[x][y];
            image[x][y] = image[x][width - 1 - y];
            image[x][width - 1 - y] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            float totalBlue = 0;
            float totalGreen = 0;
            float totalRed = 0;
            float pixels = 0.0;
            for (int z = x - 1; z < x + 2; z++) {
                if (z > height - 1 || z < 0) {
                    continue;
                }
                for (int c = y - 1; c < y + 2; c++) {
                    if (c < 0 || c > width - 1) {
                        continue;
                    }
                    totalBlue += image[z][c].rgbtBlue;
                    totalGreen += image[z][c].rgbtGreen;
                    totalRed += image[z][c].rgbtRed;
                    pixels++;
                }
            }
            temp[x][y].rgbtRed = round(totalRed / pixels);
            temp[x][y].rgbtGreen = round(totalGreen / pixels);
            temp[x][y].rgbtBlue = round(totalBlue / pixels);
        }
    }
    for (int s = 0; s < height; s++) {
        for (int g = 0; g < width; g++) {
            image[s][g].rgbtBlue = temp[s][g].rgbtBlue;
            image[s][g].rgbtGreen = temp[s][g].rgbtGreen;
            image[s][g].rgbtRed = temp[s][g].rgbtRed;
        }
    }
    return;
}
