//
// Created by georgy on 31.12.18.
//
#include "header.h"

void itemCounter(const std::string& file)
{
    std::ifstream in;
    in.open(file, std::ios::binary);
    if (in.is_open())
    {
        char *ch = new char;
        size_t count = 0;
        while (true)
        {
            in.read(ch, 1);
            if (in.eof())
            {
                delete ch;
                in.close();
                break;
            }
            count++;
        }
        if (count % 8 != 0)
        {
            std::ofstream out;
            out.open(file, std::ios::app | std::ios::binary);
            for (size_t i = 0; i < 8 - (count % 8); i++)
            {
                out << ' ';
            }
            out.close();
        }
    }
}

unsigned int strToBits(const unsigned char str[4])
{
    unsigned int bits = 0;
    for (size_t i = 0; i < 4; i++)
    {
        bits <<= 8;
        unsigned int tmp = str[i];
        bits |= tmp;
    }
    return bits;
}

void bitsToStr(unsigned char str[4], unsigned int bits)
{
    for (int i = 3; i >= 0; i--)
    {
        str[i] = (unsigned char)(bits % 0x100);
        bits >>= 8;
    }
}

void leftShift(unsigned int& bits)
{
    auto tmpBits = bits;
    tmpBits >>= (32 - R);
    bits <<= R;
    bits |= tmpBits;
}

void rightShift(unsigned int& bits)
{
    auto tmpBits = bits;
    tmpBits <<= (32 - R);
    bits >>= R;
    bits |= tmpBits;
}
