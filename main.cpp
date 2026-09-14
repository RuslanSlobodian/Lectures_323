#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Student {
private: // специфікатор доступу, оголошує закриті члени класу
    int age;
    string name;
    char* str;

public: // специфікатор доступу, оголошує відкриті члени класу

    // конструктор по замовчуванню (дефолтний)
    Student() {
        this->age = 0;
        this->name = "";
        this->str = new char[100];
        strcpy(this->str,"default constructor!");
        cout << "Default constructor!" << endl;
    }

    // Параметризований конструктор
    Student(string name, int age) {
        this->name = name;
        this->age = age;
        this->str = new char[100];
        strcpy(this->str,"parametrized constructor!");
        cout << "Parametrized constructor!" << endl;
    }

    // Параметризований конструктор
    Student(string name) {
        this->name = name;
        this->age = 0;
        this->str = new char[100];
        strcpy(this->str,"parametrized constructor!");
        cout << "Parametrized constructor!" << endl;
    }

    // Параметризований конструктор
    Student(int age) {
        this->name = "no name";
        this->age = age;
        this->str = new char[100];
        strcpy(this->str,"parametrized constructor!");
        cout << "Parametrized constructor!" << endl;
    }

    // Конструктор копіювання
    Student(const Student& student) {
        this->age = student.age;
        this->name = student.name;
        this->str = new char[100];
        // strcpy(this->str, student.str);
        strcpy(this->str,"copy constructor!");
        cout << "Copy constructor!" << endl;
    }

    // Деструктор
    ~Student() {
        cout << "Destructor! This object was created by " << str << endl;
        delete[] this->str;
    }

    // Сеттер для атрибуту age
    void setAge(int age) {
        this->age = age;
    }

    // Гетер для атрибуту age
    int getAge() {
        return age;
    }

    string getName() {
        return this->name;
    }

    void setName(string name) {
        this->name = name;
    }

    // Оголошення функції functionFriend дружньою для класу Student
    friend void functionFriend(const Student& student);
};

// Дружня функція
void functionFriend(const Student& student) {
    if (student.age < 12) {
        cout << "Student is too young!" << endl;
    }
}

Student function(Student student) {
    student.setAge(30);
    cout << "Student's name is " << student.getName() << " and age is " << student.getAge() << endl;
    return student;
}


int main() {
    Student student1("Andrii", 18);
    cout << "Student's name is " << student1.getName() << " and age is " << student1.getAge() << endl;

    // Виклик дружньої функції
    functionFriend(student1);
    // Student* student2 = new Student();
    // student2->setName("John");
    // student2->setAge(19);
    // cout << "Student's name is " << student2->getName() << " and age is " << student2->getAge() << endl;

    Student student5 = function(student1);

    cout << "Student's name is " << student1.getName() << " and age is " << student1.getAge() << endl;

    return 0;
}
