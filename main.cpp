#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int age;
    string name;
    char* str;

public: // специфікатор доступу, описує відкриті члени класу

    // конструктор по замовчуванню (дефолтний)
    Student() {
        this->age = 0;
        this->name = "";
        this->str = new char[100];
        cout << "Default constructor!" << endl;
    }
    // Параметризований конструктор
    Student(string name, int age) {
        this->name = name;
        this->age = age;
        cout << "Parametrized constructor!" << endl;
    }
    // Параметризований конструктор
    Student(string name) {
        this->name = name;
        this->age = 0;
        cout << "Parametrized constructor!" << endl;
    }
    // Параметризований конструктор
    Student(int age) {
        this->name = "no name";
        this->age = age;
        cout << "Parametrized constructor!" << endl;
    }

    Student(const Student& student) {
        this->age = student.age;
        this->name = student.name;
        this->str = new char[100];
        strcpy(this->str, student.str);
        cout << "Copy constructor!" << endl;
    }


    ~Student() {
        delete[] this->name;
        cout << "Destructor!" << endl;
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
};

Student function(Student student) {
    student.setAge(30);
    cout << "Student's name is " << student.getName() << " and age is " << student.getAge() << endl;
    return student;
}


int main() {
    Student student1("Andrii", 18);
    cout << "Student's name is " << student1.getName() << " and age is " << student1.getAge() << endl;

    // Student* student2 = new Student();
    // student2->setName("John");
    // student2->setAge(19);
    // cout << "Student's name is " << student2->getName() << " and age is " << student2->getAge() << endl;

    Student student5 = function(student1);

    cout << "Student's name is " << student1.getName() << " and age is " << student1.getAge() << endl;



    // Student array[10];
    // array[0].setName("Andrii");
    // array[0].setAge(10);
    // array[1].setName("Andrii");
    // array[1].setAge(10);

    // cout << "Student's name is " << array[1].getName() << " and age is " << array[1].getAge() << endl;

    return 0;
}
