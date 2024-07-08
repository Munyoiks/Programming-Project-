#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithim>

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


int choice;
        int choice;
    do {
        std::cout << "Choose activity type: 1. Sport 2. Club/Society 3. Done: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Choose sport: ";
            for (size_t i = 0; i < sports.size(); ++i) {
                std::cout << i+1 << ". " << sports[i].name << " (" << sports[i].members.size() << "/" << sports[i].max_capacity << ")\n";
            }
            int sport_choice;
            std::cin >> sport_choice;
            if (sport_choice >= 1 && sport_choice <= sports.size()) {
                if (sports[sport_choice-1].members.size() < sports[sport_choice-1].max_capacity) {
                    student.activities.push_back(sports[sport_choice-1].name);
                    sports[sport_choice-1].members.push_back(student);
                } else {
                    std::cout << "Sport is at full capacity.\n";
                }
            }
        } else if (choice == 2) {
            std::cout << "Choose club/society: ";
            for (size_t i = 0; i < clubs.size(); ++i) {
                std::cout << i+1 << ". " << clubs[i].name << " (" << clubs[i].members.size() << "/" << clubs[i].max_capacity << ")\n";
            }
            int club_choice;
            std::cin >> club_choice;
            if (club_choice >= 1 && club_choice <= clubs.size()) {
                if (clubs[club_choice-1].members.size() < clubs[club_choice-1].max_capacity) {
                    student.activities.push_back(clubs[club_choice-1].name);
                    clubs[club_choice-1].members.push_back(student);
                } else {
                    std::cout << "Club/Society is at full capacity.\n";
                }
            }
        }
    } while (choice != 3);

    students.push_back(student);
}

void viewStudents() {
    for (const auto& student : students) {

    
    return 0;
}
