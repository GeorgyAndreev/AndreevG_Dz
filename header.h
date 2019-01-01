//
// Created by georgy on 31.12.18.
//

#ifndef ANDREEVG_DZ_HEADER_H
#define ANDREEVG_DZ_HEADER_H

#include <iostream>
#include <string>
#include <bitset>
#include <fstream>

// global constants

const size_t K = 0xffffffff - 0xfffffff;

const size_t R = 15;

const size_t N = 24;

const size_t M = 0xffffffff;

// main sources

void encryption(const std::string&, const std::string&);

void decryption(const std::string&, const std::string&);

// other sources

void itemCounter(const std::string&);

std::bitset<32> strToBits(unsigned char*);

void bitsToStr(unsigned char*, std::bitset<32>&);

void leftShift (std::bitset<32>&);

void rightShift (std::bitset<32>&);

#endif //ANDREEVG_DZ_HEADER_H
