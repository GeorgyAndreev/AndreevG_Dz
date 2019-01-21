//
// Created by georgy on 31.12.18.
//
#include "header.h"

void encrypting(unsigned char str1[4], unsigned char str2[4]);

void encryption(const std::string& in, const std::string& out)
{
    itemCounter(in);
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
            encrypting(str1, str2);
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

void encrypting(unsigned char str1[4], unsigned char str2[4])
{
    unsigned int bits1 = strToBits(str1);
    unsigned int bits2 = strToBits(str2);
    for (size_t i = 0; i < N; i++)
    {
        // XOR
        bits1 ^= K;
        // побитовый сдвиг влево
        leftShift(bits2);
        // операция сложения bits1 и bits2 по модулю M
        bits2 = (bits2 + bits1) % M;
        leftShift(bits1);
        bits2 ^= K;
        bits1 = (bits1 + bits2) % M;
    }
    bitsToStr(str1, bits1);
    bitsToStr(str2, bits2);
}
