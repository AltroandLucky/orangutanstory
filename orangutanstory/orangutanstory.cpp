#include <iostream>
#include <string>
using namespace std;

// Базовый класс Animal (абстрактный класс)
class Animal
{
protected:
    string name;        // Имя животного
    string type;        // Тип животного
    double weight;      // Вес животного
    string environment; // Среда обитания животного

public:
    // Метод для ввода данных о животном
    void Input()
    {
        cout << "Enter the animal's name: ";
        getline(cin, name);

        cout << "Enter the animal's type: ";
        getline(cin, type);

        cout << "Enter the animal's weight: ";
        cin >> weight;

        cin.ignore(); // Игнорируем остаток ввода после числа
        cout << "Enter the animal's habitat: ";
        getline(cin, environment);
    }

    // Метод для вывода информации о животном
    void Print() const
    {
        cout << "Name: " << name << "\n";
        cout << "Type: " << type << "\n";
        cout << "Weight: " << weight << " kg\n";
        cout << "Habitat: " << environment << "\n";
    }

    // Виртуальный метод Eat() для описания того, что ест животное
    virtual void Eat() const
    {
        cout << name << " eats food.\n";
    }

    // Чисто виртуальный метод Sound(), который должен быть реализован в наследниках
    virtual void Sound() const = 0;
};

// Класс Parrot наследуется от Animal
class Parrot : public Animal
{
public:
    // Конструктор для задания типа животного
    Parrot()
    {
        type = "Parrot";
    }

    // Переопределение метода Eat()
    void Eat() const override
    {
        cout << name << " eats seeds.\n";
    }

    // Реализация метода Sound()
    void Sound() const override
    {
        cout << name << " says: Squawk!\n";
    }
};

// Класс Elephant наследуется от Animal
class Elephant : public Animal
{
public:
    Elephant()
    {
        type = "Elephant";
    }

    void Eat() const override
    {
        cout << name << " eats grass and fruits.\n";
    }

    void Sound() const override
    {
        cout << name << " makes a loud trumpet sound!\n";
    }
};

// Класс Dog наследуется от Animal
class Dog : public Animal
{
public:
    Dog()
    {
        type = "Dog";
    }

    void Eat() const override
    {
        cout << name << " eats meat and dog food.\n";
    }

    void Sound() const override
    {
        cout << name << " barks: Woof-woof!\n";
    }
};

// Класс Cat наследуется от Animal
class Cat : public Animal
{
public:
    Cat()
    {
        type = "Cat";
    }

    void Eat() const override
    {
        cout << name << " eats fish and cat food.\n";
    }

    void Sound() const override
    {
        cout << name << " purrs: Meow!\n";
    }
};

int main()
{
    // Создаем массив указателей на объекты Animal
    Animal* animals[4];

    // Инициализируем элементы массива разными подклассами
    animals[0] = new Parrot();
    animals[1] = new Elephant();
    animals[2] = new Dog();
    animals[3] = new Cat();

    // Вводим информацию о каждом животном
    for (int i = 0; i < 4; ++i)
    {
        cout << "\n--- Enter information for animal #" << (i + 1) << " ---\n";
        animals[i]->Input();
    }

    // Выводим информацию о каждом животном и вызываем методы Eat() и Sound()
    cout << "\n--- Animal Information ---\n";
    for (int i = 0; i < 4; ++i)
    {
        animals[i]->Print(); // Вывод данных о животном
        animals[i]->Eat();   // Переопределённый метод Eat()
        animals[i]->Sound(); // Реализованный метод Sound()
        cout << "-----------------------\n";
    }

    // Удаляем объекты из памяти
    for (int i = 0; i < 4; ++i)
    {
        delete animals[i];
    }

    return 0; //тик так

}
