#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001); // Устанавливаем кодировку вывода в UTF-8
    SetConsoleCP(65001);       // Устанавливаем кодировку ввода в UTF-8
    setlocale(LC_ALL, "ru_RU.UTF-8"); // Локаль для корректной работы с русским текстом
