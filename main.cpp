#include "header.h"

int main()
{
    setlocale(LC_ALL, "ru");
    encryption("input.txt", "cipher.txt");
    decryption("cipher.txt", "output.txt");
    return 0;
}