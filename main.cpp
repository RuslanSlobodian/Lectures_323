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
};

int main() {
    Student student1("Andrii", 18);
    cout << "Student's name is " << student1.getName() << " and age is " << student1.getAge() << endl;

    Student* student2 = new Student();
    student2->setName("John");
    student2->setAge(19);
    cout << "Student's name is " << student2->getName() << " and age is " << student2->getAge() << endl;
    Student student3("Ivan");
    delete student2;
    return 0;
}
