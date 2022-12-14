#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <fstream>
#include <iostream>
#include <memory.h>

using namespace std;

#define INPUTPATH "mipi_1920x1080.raw"
#define OUTPUTPATH "output_1920x1080.raw"

static const int Success   = 0;
static const int Failed    = 1;
static const int NoMemory  = 2;

int ReadMipi10BitRawData(char* path, uint8_t* buffer, size_t bufferSize)
{
    int result = Success;
    /* Write your code here */
    std::ifstream ifs(path, std::ios::binary);
    if (!ifs || !ifs.good()) {
        std::cerr << "open failed for file:" << path << std::endl;
        return Failed;
    }
    ifs.read((char *)buffer, bufferSize);
    ifs.close();

    return result;
}

int WriteImageData(char* path, uint8_t* buffer, size_t bufferSize)
{
    int result = Success;
    /* Write your code here */
    std::ofstream ofs(path, std::ios::trunc);
    if (!ofs || !ofs.is_open()) {
        return Failed;
    }
    ofs.write((char *)buffer, bufferSize);
    ofs.close();

    return result;
}


int Mipi10decode(void* src, void* dst, int32_t rawSize) {
    int result = Success;
    /* TODO: Write your code here */
    uint8_t *src_ptr = (uint8_t *)src;
    uint16_t *dst_ptr = (uint16_t *)dst;
    int j = 0;
    for (int bytes = 0;bytes < rawSize;bytes += 5) {
        for (int i = 0;i < 4;i++) {
            dst_ptr[j++] = (((uint16_t)src_ptr[bytes + i]) << 8) | ((src_ptr[bytes + 4] << i) & 0xC0);
        }
    }

    return result;
}

void Compress10to8(uint16_t* src, unsigned char* dst, int32_t size)
{
    /* Write your code here */
    int j = 0;
    for (int i = 0;i < size;i++, j++) {
        unsigned char val = (src[i] & 0xff00) >> 8;
        if (val >= 255) {
            dst[j] = 255;
            continue;
        }
        unsigned char low_val = (src[i] & 0x00C0) >> 6;
        if (low_val >= 128) {
            dst[j] = val + 1;
        }
        else {
            dst[j] = val;
        }
        /* code */
    }
}

int main() {
    int result = Success;

    string inputPath  = INPUTPATH;
    string outputPath = OUTPUTPATH;

    int32_t width  = 1920;
    int32_t height = 1080;

    size_t numPixel = width * height;
    uint8_t* mipiRawData = new uint8_t[numPixel * 5 / 4];
    uint16_t* rawData = new uint16_t[numPixel];
    uint8_t* rawData8bit = new uint8_t[numPixel];
    memset(rawData8bit, 0x0, numPixel);

    cout  << "Prepare to read MIPI RAW image from disk." << endl;
    result = ReadMipi10BitRawData(const_cast<char*>(inputPath.c_str()), mipiRawData, numPixel * 5 / 4);
    cout  << "Read MIPI RAW image from disk success." << endl;
    if (result == Success) {
        //Mipi10 decode
        cout  << "Prepare to decode MIPI RAW to RAW," << endl;
        result = Mipi10decode((void*)mipiRawData, (void*)rawData, numPixel * 5 / 4);
        cout  << "Decode MIPI RAW to RAW success." << endl;

        cout  << "Prepare to compress 10bit RAW to 8bit RAW." << endl;
        Compress10to8(rawData, rawData8bit, numPixel);
        cout  << "Compress 10bit RAW to 8bit RAW success." << endl;

        cout  << "Prepare to save 8bit RAW to disk." << endl;
        WriteImageData(const_cast<char*>(outputPath.c_str()), rawData8bit, numPixel);
        cout  << "Save 8bit RAW to disk success." << endl;

        delete[] mipiRawData;
        delete[] rawData;
        delete[] rawData8bit;
    }

    return 0;
}
