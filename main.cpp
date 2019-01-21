#include "header.h"

int main()
{
    encryption("input.txt", "cipher.txt");
    decryption("cipher.txt", "output.txt");
    /*setlocale(LC_ALL, "ru");
    std::cout << "Выберите действие:" << std::endl;
    std::cout << "1. Шифрование файла" << std::endl;
    std::cout << "2. Расшифрование файла" << std::endl;
    std::cout << "3. Помощь" << std::endl;
    std::cout << "4. Выход" << std::endl;
    int choice = 0;
    std::cin >> choice;
    // очистка консоли
    switch (choice)
    {
        case 1: {
            std::string fromFile;
            std::string toFile;
            std::cout << "Введите путь до файла:" << std::endl;
            std::cin >> fromFile;
            std::cout << "Введите путь до выходного файла:" << std::endl;
            std::cin >> toFile;
            encryption(fromFile, toFile);
            // очистка консоли
            std::cout << "Шифрование завершено! Проверьте " << toFile << std::endl;
            main();
            break;
        }

        case 2: {
            std::string fromFile;
            std::string toFile;
            std::cout << "Введите путь до зашифрованного файла:" << std::endl;
            std::cin >> fromFile;
            std::cout << "Введите путь до выходного файла:" << std::endl;
            std::cin >> toFile;
            decryption(fromFile, toFile);
            // очистка консоли
            std::cout << "Файл зашифрован! Проверьте " << toFile << std::endl;
            main();
            break;
        }

        case 3: {
            std::cout << "выберите один из пунктов меню:" << std::endl;
            main();
            break;
        }

        case 4: {
            return 0;
        }

        default: {
            std::cout << "выберите один из пунктов меню:" << std::endl;
            main();
        }
    }*/
    return 0;
}
