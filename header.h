//
// Created by georgy on 31.12.18.
//

#ifndef ANDREEVG_DZ_HEADER_H
#define ANDREEVG_DZ_HEADER_H

#include <string>
#include <iostream>
#include <fstream>

// global constants

const unsigned long long int K = 0xffffffff - 0xfffffff;

const size_t R = 15;

const size_t N = 24;

const unsigned long long int M = 0xffffffff;

// main sources

void encryption(const std::string&, const std::string&);

void decryption(const std::string&, const std::string&);

// other sources

void itemCounter(const std::string&);

unsigned int strToBits(const unsigned char[]);

void bitsToStr(unsigned char[], unsigned int);

void leftShift(unsigned int& bits);

void rightShift(unsigned int& bits);


#endif //ANDREEVG_DZ_HEADER_H
