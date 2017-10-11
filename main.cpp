#include <iostream>
#include <fstream>
#include <vector>
#include "bitmap.h"
#include <cstdlib>
#include <string>

using namespace std;

int row, column, color, average;
string fileName;

int main()
{
/* 
  Program 2 Functional Decomposition
 1. Ask user to enter the file name of an image in BMP format.
 2. Make sure user has submitted correct format if not let them know.
 3. Assign rows and columns for each pixel.
 4. Create a increment so that it goes to each colum of every row.
 5. Find the average value of the three colors: red, blue, green.
 6. Then assign the three colors to the average value.
 7. Change the rest of the  colors in the original pixel into a greyscale.
 8. Once every pixel has been changed save as a new file.
 9. Display the new image to the user.
*/
 cout<< "Hello, please enter the file name of an image."<<endl;
 cin>>fileName;

  if (fileName == "fileName.bmp")
   {
    Bitmap image;
    vector< vector <Pixel> > bmp;
    Pixel rgb;

    image.open(fileName);
    bmp = image.toPixelMatrix();

    cout<<" "<<fileName<<" has been loaded. It is "<<bmp[0].size()<<" pixels wide and "<<bmp.size()<<" pixels high."<<endl;

     for(int row = 0; row < bmp.size(); row ++)
       {  
          for(int column = 0; column < bmp[0].size(); column ++)
            {
             rgb = bmp[0][0];
             color = rgb.red + rgb.green + rgb.blue / 3;
             rgb.red = rgb.green = rgb.blue;
            }  
       }

     bmp[0][0] = rgb;
     image.fromPixelMatrix(bmp);
     image.save(fileName);        
   }
 else 
  {
   cout<<"The file must be a BMP format"<<endl;
  } 

return 0;
}






