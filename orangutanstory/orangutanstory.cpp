#include <iostream>
#include <string>
using namespace std;

// ������� ����� Animal (����������� �����)
class Animal
{
protected:
    string name;        // ��� ���������
    string type;        // ��� ���������
    double weight;      // ��� ���������
    string environment; // ����� �������� ���������

public:
    // ����� ��� ����� ������ � ��������
    void Input()
    {
        cout << "Enter the animal's name: ";
        getline(cin, name);

        cout << "Enter the animal's type: ";
        getline(cin, type);

        cout << "Enter the animal's weight: ";
        cin >> weight;

        cin.ignore(); // ���������� ������� ����� ����� �����
        cout << "Enter the animal's habitat: ";
        getline(cin, environment);
    }

    // ����� ��� ������ ���������� � ��������
    void Print() const
    {
        cout << "Name: " << name << "\n";
        cout << "Type: " << type << "\n";
        cout << "Weight: " << weight << " kg\n";
        cout << "Habitat: " << environment << "\n";
    }

    // ����������� ����� Eat() ��� �������� ����, ��� ��� ��������
    virtual void Eat() const
    {
        cout << name << " eats food.\n";
    }

    // ����� ����������� ����� Sound(), ������� ������ ���� ���������� � �����������
    virtual void Sound() const = 0;
};

// ����� Parrot ����������� �� Animal
class Parrot : public Animal
{
public:
    // ����������� ��� ������� ���� ���������
    Parrot()
    {
        type = "Parrot";
    }

    // ��������������� ������ Eat()
    void Eat() const override
    {
        cout << name << " eats seeds.\n";
    }

    // ���������� ������ Sound()
    void Sound() const override
    {
        cout << name << " says: Squawk!\n";
    }
};

// ����� Elephant ����������� �� Animal
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

// ����� Dog ����������� �� Animal
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

// ����� Cat ����������� �� Animal
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
    // ������� ������ ���������� �� ������� Animal
    Animal* animals[4];

    // �������������� �������� ������� ������� �����������
    animals[0] = new Parrot();
    animals[1] = new Elephant();
    animals[2] = new Dog();
    animals[3] = new Cat();

    // ������ ���������� � ������ ��������
    for (int i = 0; i < 4; ++i)
    {
        cout << "\n--- Enter information for animal #" << (i + 1) << " ---\n";
        animals[i]->Input();
    }

    // ������� ���������� � ������ �������� � �������� ������ Eat() � Sound()
    cout << "\n--- Animal Information ---\n";
    for (int i = 0; i < 4; ++i)
    {
        animals[i]->Print(); // ����� ������ � ��������
        animals[i]->Eat();   // ��������������� ����� Eat()
        animals[i]->Sound(); // ������������� ����� Sound()
        cout << "-----------------------\n";
    }

    // ������� ������� �� ������
    for (int i = 0; i < 4; ++i)
    {
        delete animals[i];
    }

    return 0; //��� ���

}
