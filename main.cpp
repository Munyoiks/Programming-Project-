
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct Student {
    std::string firstname;
    std::string surname;
    std::string gender;
    int age{};
    int group{};
    std::vector<std::string> activities;
};

struct Activity {
    std::string name;
    int max_capacity;
    std::vector<Student> members;
};

std::vector<Student> students;
std::vector<Activity> sports = {{"Rugby", 20}, {"Athletics", 20}, {"Swimming", 20}, {"Soccer", 20}};
std::vector<Activity> clubs = {{"Journalism Club", 60}, {"Red Cross Society", 60}, {"AISEC", 60}, {"Business Club", 60}, {"Computer Science Club", 60}};

void addStudent() {
    Student student;
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

    int choice;
    do {
        std::cout << "Select activity type: 1. Sport 2. Club/Society 3. Done: ";
        std::cin >> choice;

//part of a for loop that iterates over the sports vector. This loop allows you to access each sport in the vector by its index.
        if (choice == 1) {
            std::cout << "Select a sport: ";
            for (size_t i = 0; i < sports.size(); ++i) {
                //i + 1 is used to display sport numbers starting from 1
                std::cout << i+1 << ". " << sports[i].name << " (" << sports[i].members.size() << "/" << sports[i].max_capacity << ")\n";
            }
            int sport_choice;
            std::cin >> sport_choice;
            if (sport_choice >= 1 && sport_choice <= sports.size()) {
                if (sports[sport_choice-1].members.size() < sports[sport_choice-1].max_capacity) {
                    student.activities.push_back(sports[sport_choice-1].name);
                    sports[sport_choice-1].members.push_back(student);
                } else {
                    std::cout << "Sport is at maximum capacity.\n";
                }
            }
