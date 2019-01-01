#include "header.h"

int main()
{
    encryption("input.txt", "cipher.txt");
    decryption("cipher.txt", "output.txt");
    return 0;
}