#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int age;
    string name;

public: // специфікатор доступу, описує відкриті члени класу

    // конструктор по замовчуванню (дефолтний)
    Student() {
        this->age = 0;
        this->name = "";
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

    ~Student() {
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

    friend void function(const Student& student);
};

void function(const Student& student) {
    if (student.age < 12) {
        cout << "Student is too young!" << endl;
    }
}

int main() {
    Student student1("Andrii", 10);
    cout << "Student's name is " << student1.getName() << " and age is " << student1.getAge() << endl;

    function(student1);

    return 0;
}
