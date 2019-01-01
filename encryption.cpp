//
// Created by georgy on 31.12.18.
//
#include "header.h"

void encrypting(unsigned char * str1, unsigned char * str2);

void encryption(const std::string& in, const std::string& out)
{
    itemCounter(in);
    std::ifstream input(in, std::ios::binary);
    std::ofstream output(out, std::ios::binary);
    if (input.is_open() && output.is_open())
    {
        while (true)
        {
            auto * ch = new char[8];
            input.read(ch, 8);
            if (input.eof())
            {
                delete[] ch;
                break;
            }
            auto * str1 = new unsigned char[4];
            auto * str2 = new unsigned char[4];
            for (size_t i = 0; i < 4; i++)
            {
                str1[i] = ch[i];
                str2[i] = ch[i + 4];
            }
            encrypting(str1, str2);
            output << str1 << str2;
            delete[] str1;
            delete[] str2;
        }
    }
}

void encrypting(unsigned char * str1, unsigned char * str2)
{
    std::bitset<32> bits1 = strToBits(str1);
    std::bitset<32> bits2 = strToBits(str2);
    for (size_t i = 0; i < N; i++)
    {
        bits1 ^= K; // XOR
        leftShift(bits2); // побитовый сдвиг влево
        // операция сложения bits1 и bits2 по модулю M
        bits2 = (bits2.to_ulong() + bits1.to_ulong()) % M;
        leftShift(bits1);
        bits2 ^= K;
        bits1 = (bits1.to_ulong() + bits2.to_ulong()) % M;
    }
    bitsToStr(str1, bits1);
    bitsToStr(str2, bits2);
}