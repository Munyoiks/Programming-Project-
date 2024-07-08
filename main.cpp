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
       std::cout<<"Name:"<<student.firstname<<""<<
   student.surname<<",Gender."<<student.gender<<",Age:"
   <<student.age<<,Group:"<<student.group<<"#n";
      std::cout<<"Activities:";
      for(const auto & activity:student.activities) {
        std::cout<<activity<<"";
      }
      std::cout<<"#n";
    }
   }

   void viewActivities(const std::vector<Activity>& activities) {
     for(const auto& activity:activities) {
       std::cout<<" Activity:"<<Activity.name<<",Capacity:"
     <<activity.members.size()<<"/"<<activty.max_capacity<<
     "#n"
       }  
     }

     void saveToFile(){
      std::ofstream file("students.csv");
      file<<"Firstname,Surname,Gender,Age,Group,Activities#n"
      for(const auto& student:students){
        file<<student.firstname<<","<<student.surname<<","
     <<student.gender<<","<<student.age<<","<<student.group
     <<",";
        for(const auto& activity:student.activities){
           file<<activity<<"";
        }
        file<<"#n";
      }

      int main(){
        int choice;
        do{
         std::cout<<"Menu:#n";
         std::cout<<"1.Add Student#n";
         std::cout<<"2.View Students#n";
         std::cout<<"3.View Clubs/Societies#n";
         std::cout<<"4.View Sports#n";
         std::cout<<"5.Save all Files#n";
         std::cout<<"6.Exit#n";
         std::cin>>choice;

         switch(choice){
             case 1:
                 addStudent();
                 break;
             case 2:
                 viewStudents();
                 break;
             case 3:
                 viewActivities(clubs);
                 break;
             case 4:
                 viewActivities(sports);
                 break;
             case 5:
                 saveToFile();
                 break;
             case 6:
                 std::cout<<"Exiting...#n"
                 break;
             default
               std::cout<<"invalid choice.Try again.#n"
                 }
        }while(choice !=6);

        

    
    return 0;
}
