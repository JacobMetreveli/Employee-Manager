#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "EManager.h"


int main() {
    EManager *employee_manager = new EManager();
    std::cout << "hello........\n";

    int option {0};
    char answer {};
    bool result {};
    std::string department {};

    system("cls");
    do {
        std::cout << "\t\t*********************MENU*********************\n";
        std::cout << "\t\tEnter your option\n";
        std::cout << "\t\t1 => Add a new record\n";
        std::cout << "\t\t2 => Search record from employee id\n";
        std::cout << "\t\t3 => List Employee of particular department\n";
        std::cout << "\t\t4 => Display all employee\n";
        std::cout << "\t\t5 => Update record of an employee\n";
        std::cout << "\t\t6 => Delete record of particular employee\n";
        std::cout << "\t\t7 => Exit from the program\n";
        std::cout << "\t\t***********************************************\n\t\t";

        std::cin >> option;

        switch (option)
        {
            case 1:
                result = employee_manager->add_new_record();
                if (result) {
                    employee_manager->continue_or_not();
                } else {
                    std::cout << "User with this current ID already exists.\n\n" << std::endl;
                }
                break;
            
            case 2:
                employee_manager->list_employee_with_id();
                break;

            case 3:
                employee_manager->list_employee_department();
                break;

            case 4:
                employee_manager->display_all_employee();
                break;

            case 5:
                employee_manager->update_record_of_employee();
                break;

            case 6:
                employee_manager->delete_record_of_employee();
                break;

            case 7:
                std::cout << "\t\tThank you for using our system, have a nice day!\n\n";
                return 0;

            default:
                std::cout << "\t\tUnknown command, please try again..." << std::endl;
                break;
        }
    } while (option != 7);
    
}