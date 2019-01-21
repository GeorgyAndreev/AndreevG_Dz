//
// Created by georgy on 31.12.18.
//
#include "header.h"

void decrypting(unsigned char str1[4], unsigned char str2[4]);

void decryption(const std::string& in, const std::string& out)
{
    std::ifstream input(in, std::ios::binary);
    std::ofstream output(out, std::ios::binary);
    if (input.is_open() && output.is_open())
    {
        char ch[8];
        while (true)
        {
            input.read(ch, 8);
            if (input.eof())
            {
                break;
            }
            unsigned char str1[4];
            unsigned char str2[4];
            for (size_t i = 0; i < 4; i++)
            {
                str1[i] = (unsigned char)ch[i];
                str2[i] = (unsigned char)ch[i + 4];
            }
            decrypting(str1, str2);
            for (auto item : str1)
            {
                output << item;
            }
            for (auto item : str2)
            {
                output << item;
            }
        }
        input.close();
        output.close();
    }
}

void decrypting(unsigned char str1[4], unsigned char str2[4])
{
    unsigned int bits1 = strToBits(str1);
    unsigned int bits2 = strToBits(str2);
    for (size_t i = 0; i < N; i++)
    {
        bits1 = bits1 - bits2;
        bits2 ^= K;
        rightShift(bits1);
        bits2 = bits2 - bits1;
        rightShift(bits2);
        bits1 ^= K;
    }
    bitsToStr(str1, bits1);
    bitsToStr(str2, bits2);
}
