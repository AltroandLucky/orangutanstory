#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001); // ������������� ��������� ������ � UTF-8
    SetConsoleCP(65001);       // ������������� ��������� ����� � UTF-8
    setlocale(LC_ALL, "ru_RU.UTF-8"); // ������ ��� ���������� ������ � ������� �������
