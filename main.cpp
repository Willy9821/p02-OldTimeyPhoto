#include <iostream>
#include <vector>
#include "bitmap.h"
 
using namespace std;

int rows;
int columns;

int main()
{
/* 
  Program 2 Functional Decomposition
 1. Ask user to enter the file name of an image in BMP format.
 2. Make sure user has submitted correct format if not let them know and ask to submit again.
 3. Assign rows and columns for each pixel.
 4. Create a increment so that it goes to each colum of every row.
 5. Find the average value of the three colors: red, blue, green.
 6. Then assign the three colors to the average value.
 7. Change the rest of the  colors in the original pixel into a greyscale.
 8. Once every pixel has been changed save as a new file.
 9. Display the new image to the user.
*/
    Bitmap image;
    vector< vector <Pixel> > bmp;
    Pixel rgb;

    image.open("machupicchu.bmp");
    bmp = image.toPixelMatrix();

    cout<<"Machu Picchu has been loaded. It is "<<bmp[0].size()<<" pixels wide and "<<bmp.size()<< " pixels high."<<endl;

    rgb = bmp[0][0];
    rgb.red = 0;

    bmp[0][0] = rgb;
    image.fromPixelMatrix(bmp);
    image.save("machupicchu.bmp");


return 0;
}






