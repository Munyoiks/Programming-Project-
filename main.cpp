#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_STUDENTS_PER_GROUP = 50;
const int MAX_STUDENTS_PER_SPORT = 20;
const int MAX_STUDENTS_PER_CLUB = 60;

struct students {
    std::string firstname;
    std::string surname;
    std::string gender;
    int age;
    int group;
    std::vector<std::string> activities;

};

struct Activity {
    std::string name;
    int max_capacity;
    std::vector<std::string> students;
};

void addStudent() {
    student student;
    std::cout << "Enter first name: ";
    std::cin >> student.firstname;
    std::cout << "Enter surname: ";
    std::cin >> student.surname;
    std::cout << "Enter gender (Male/Female): ";
    std::cin >> student.gender;
    std::cout << "Enter age: ";
    std::cin >> student.age;
    std::cout << "Enter group (1-3): ";
    std::cin >> student.group;


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
