//
// Created by georgy on 31.12.18.
//
#include "header.h"

void decrypting(unsigned char * str1, unsigned char * str2);

void decryption(const std::string& in, const std::string& out)
{
    std::ifstream input;
    std::ofstream output;
    input.open(in, std::ios::binary);
    output.open(out, std::ios::binary);
    if (input.is_open() && output.is_open())
    {
        auto * ch = new unsigned char[8];
        while (true)
        {
            for (size_t i = 0; i < 8; i++)
            {
                input >> ch[i];
            }
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
            decrypting(str1, str2);
            output << str1 << str2;
            delete[] str1;
            delete[] str2;
        }
    }
}

void decrypting(unsigned char * str1, unsigned char * str2)
{
    std::bitset<32> bits1 = strToBits(str1);
    std::bitset<32> bits2 = strToBits(str2);
    std::cout << "bits1(decryp., begin):" << std::endl << bits1 << std::endl;
    std::cout << "bits2(decryp., begin):" << std::endl << bits2 << std::endl << std::endl;
    for (size_t i = 0; i < N; i++)
    {
        bits1 = (bits1.to_ulong() - bits2.to_ulong()) % M;
        bits2 ^= K;
        rightShift(bits1);
        bits2 = (bits2.to_ulong() - bits1.to_ulong()) % M;
        rightShift(bits2);
        bits1 ^= K;
    }
    std::cout << "bits1(decryp., end):" << std::endl << bits1 << std::endl;
    std::cout << "bits2(decryp., end):" << std::endl << bits2 << std::endl << std::endl;
    bitsToStr(str1, bits1);
    bitsToStr(str2, bits2);
}