#include <iostream>
#include <vector>
#include "bitmap.h"
#include <string>

using namespace std;

int row, column, average;
bool validBmp;
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

 Bitmap image;
 vector< vector <Pixel> > bmp;
 Pixel rgb;
 
 image.open(fileName);
 validBmp = image.isImage();

  if( validBmp == true ) 
   { 
    bmp = image.toPixelMatrix();

    cout<<" "<<fileName<<" has been loaded. It is "<<bmp[0].size()<<" pixels wide and "<<bmp.size()<<" pixels high."<<endl;

     for(int row = 0; row < bmp.size(); row ++)
       {  
          for(int column = 0; column < bmp[row].size(); column ++)
            {
             rgb = bmp[row][column];
             average = rgb.red + rgb.green + rgb.blue / 3;
             rgb.red = average;
             rgb.green = average;
             rgb.blue = average;
             bmp[row][column] = rgb;
            }  
       }
     image.fromPixelMatrix(bmp);
     image.save("oldtimey.bmp");        
   }
 else 
  {
   cout<<"The file must be a BMP format"<<endl;
  } 

return 0;
}






