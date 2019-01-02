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
            srand(time(NULL));
            for (size_t i = 0; i < 8 - (count % 8); i++)
            {
                out << (rand() % 10);
            }
            out.close();
        }
    }
}

std::bitset<32> strToBits(unsigned char str[4])
{
    std::bitset<32> bits;
    for (size_t i = 0; i < 4; i++) {
        bits <<= 8;
        int symId = str[i];
        std::bitset<32> tempBits(symId);
        bits = bits | tempBits;
    }
    return bits;
}

void bitsToStr(unsigned char str[4], std::bitset<32>& bits)
{
    for (int i = 3; i >= 0; i--)
    {
        str[i] = (bits.to_ulong()) % 0x100;
        bits >>= 8;
    }
}

void leftShift (std::bitset<32>& bits)
{
    std::bitset<32> tmpBits = bits;
    tmpBits >>= (32 - R);
    bits <<= R;
    bits |= tmpBits;
}

void rightShift (std::bitset<32>& bits)
{
    std::bitset<32> tmpBits = bits;
    tmpBits <<= (32 - R);
    bits >>= R;
    bits |= tmpBits;
}
