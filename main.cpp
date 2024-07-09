
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
        } else if (choice == 2) {
            std::cout << "Select club/society: ";
            //a for loop that iterates over the clubs vector. This loop allows you to access each club in the vector by its index.
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
                    std::cout << "Club/Society is at max capacity.\n";
                }
            }
        }
    } while (choice != 3);

    students.push_back(student);
}
//void means that the function does not have a return value
void viewStudents() {
    //
    for (const auto& student : students) {
        std::cout << "Name: " << student.firstname << " " << student.surname << ", Gender: " << student.gender << ", Age: " << student.age << ", Group: " << student.group << "\n";
        std::cout << "Activities: ";
        for (const auto& activity : student.activities) {
            std::cout << activity << " ";
        }
        std::cout << "\n";
    }
}

void viewActivities(const std::vector<Activity>& activities) {
    for (const auto& activity : activities) {
        std::cout << "Activity: " << activity.name << ", Capacity: " << activity.members.size() << "/" << activity.max_capacity << "\n";
    }
}

void saveToFile() {
    std::ofstream file("students.csv");
    file << "Firstname,Surname,Gender,Age,Group,Activities\n";
    for (const auto& student : students) {
        file << student.firstname << "," << student.surname << "," << student.gender << "," << student.age << "," << student.group << ",";
        for (const auto& activity : student.activities) {
            file << activity << " ";
        }
        file << "\n";
    }
    file.close();
    //Closing a file is important because it ensures that all data is properly saved to the disk and that resources are freed.
    std::cout << "Data is saved to students.csv\n";
}


