#define STB_IMAGE_IMPLEMENTATION
#include "include/stb/stb_image.h"
#include <iostream>
#include <fstream> 
using namespace std;


int RGBtoHex(int r, int g, int b) {
    return (r << 16) + (g << 8) + b;
}

int main() {
    int width, height, channels_in_file;
    unsigned char *image = stbi_load(
    "images/test.png",      // filename
    &width,           // output for width
    &height,          // output for height
    &channels_in_file, // output for original channels in file
    0                 // desired number of channels
    );
    
    ofstream MyFile("output/output.txt");
    for (int i = 0; i < width * height * channels_in_file; i += 4) {
        int hexValue = RGBtoHex(image[i], image[i+1], image[i+2]);
        //std::cout << "[ " << (int)image[i] << ", " << (int)image[i+1] << ", " << (int)image[i+2] << " ]"  << std::endl;
        //std::cout << (i+4) / 4 << std::endl;

        
        MyFile << "0x" <<std::hex << hexValue << ", ";
        if (((i+4) / 4) % width == 0) {
            MyFile << std::endl;
        }
    }
    MyFile.close();

    //std::cout << std::endl << channels_in_file << std::endl;
}