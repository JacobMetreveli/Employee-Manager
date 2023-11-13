#include <iostream>
#include <vector>
#include <string>
#include "EManager.h"
#include "employee.h"
#include <fstream>
#include <sstream>


EManager::EManager() {
    set_employee_data_csv();
}


void EManager::set_employee_data_csv() {
    
    std::ifstream file("records.csv");
    if (!file.is_open()) {
        std::cerr << "Error: Failed to retrieve old data." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::istringstream lineStream(line);
        std::string cell;

        while (std::getline(lineStream, cell, ',')) {
            row.push_back(cell);
        }

        this->employee_data.push_back(Employee(std::stoi(row.at(0)), row.at(1), row.at(2), row.at(3), std::stoi(row.at(4))));
        std::cout << "hello........\n";

    }
}


bool EManager::add_new_record() {
    int user_id, salary;
    std::string user_name, user_post, user_department;

    std::cout << "\t\t\tEmployee ID: ";
    std::cin >> user_id;
    std::cout << "\t\t\tEmployee Name and Lastname: ";
    std::cin >> user_name;
    std::cout << "\t\t\tEmployee's Post: ";
    std::cin >> user_post;
    std::cout << "\t\t\tEmployee's Department: ";
    std::cin >> user_department;
    std::cout << "\t\t\tSalary: ";
    std::cin >> salary;

    for (auto employee: employee_data) {
        if (user_id == employee.get_id()) {
            return false;
        }
    }

    this->employee_data.push_back(Employee(user_id, user_name, user_post, user_department, salary));
    update_csv();
    return true;
}


void EManager::list_employee_with_id() {
    system("cls");
    int id {0};
    std::cout << "\t\tEnter ID of an employee to be searched: ";
    std::cin >> id;

    for (auto &worker: this->employee_data) {
        if (worker.get_id() == id) {
            std::cout << "\t\tThe record found....\n\n"; 
            std::cout << "\t\tID\t\tName\t\tPost\t\tDepartment\t\tSalary\n\n";
            std::cout << "\t\t-------------------------------------------------------------------------------------------------\n";
            std::cout << "\t\t" << worker.get_id() << "\t\t" << worker.get_name() << "\t\t" << worker.get_post() << "\t\t" << worker.get_department() << "\t\t" << worker.get_salary() << std::endl << std::endl;
            std::cout << std::endl;
            continue_or_not();
            return;
        }
    }

    std::cout << "\n\t\tEmployee with this ID has not been found, please try again...\n\n";
}


void EManager::list_employee_department() const {
    system("cls");
    std::string department {};
    std::cout << "\t\tEnter a department to list the employees: ";
    std::cin >> department;
    system("cls");
    
    bool department_exists {false};

    for (auto row: employee_data) {
        if (row.get_department() == department) {
            if (department_exists != true) {
                std::cout << "\t\tEmployees found in this department: \n\n";
                department_exists = true;
            }

            std::cout << "\t\t\tEmployee ID: " << row.get_id() << std::endl;
            std::cout << "\t\t\tEmployee Name: " << row.get_name() << std::endl;
            std::cout << "\t\t\tEmployee's Post: " << row.get_post() << std::endl;
            std::cout << "\t\t\tSalary: " << row.get_salary() << std::endl;
            std::cout << std::endl << std::endl;
            
        }
    }

    if (department_exists == false) {
        std::cout << "\t\tNo employees have been found in this department." << std::endl;
    } 

    continue_or_not();
}


void EManager::display_all_employee() const {
    system("cls");
    std::cout << "\t\t****************Employees*****************\n\n\n";

    for (auto row: employee_data) {
        std::cout << "\t\tEmployee ID: " << row.get_id() << std::endl;
        std::cout << "\t\tEmployee Name and Lastname: " << row.get_name() << std::endl;
        std::cout << "\t\tEmployee's Post: " << row.get_post() << std::endl;
        std::cout << "\t\tEmployee's Department: " << row.get_department() << std::endl;
        std::cout << "\t\tSalary: " << row.get_salary() << std::endl;
        std::cout << "\n\n";
    }

    continue_or_not();
}


void EManager::update_record_of_employee() {
    int e_id, new_salary;
    int choice {0};
    std::string new_department, new_post;
    bool found_id {false};

    system("cls");
    std::cout << "\t\tEnter the employee ID: ";
    std::cin >> e_id;

    for (auto &employee: employee_data) {

        if (employee.get_id() == e_id) {
            
            found_id = true;
            do {
                std::cout << "\t\tPlease pick one of the options: \n";
                std::cout << "\t\t_______________________________\n\n";
                std::cout << "\t\t1 => Change the department\n";
                std::cout << "\t\t2 => Change the salary\n";
                std::cout << "\t\t3 => Change the post\n";
                std::cout << "\t\t4 => Quit...\n";

                std::cin >> choice;
                switch (choice) {
                    case 1:
                        std::cout << "\t\tPlease enter the name of a new department: ";
                        std::cin >> new_department;
                        employee.set_department(new_department);
                        std::cout << "\t\tThe employee's department with id: " << e_id << " has been updated successfully\n\n"; 
                        break;

                    case 2:
                        std::cout << "\t\tPlease enter the new salary of the Employee: ";
                        std::cin >> new_salary;
                        employee.set_salary(new_salary);
                        std::cout << "\t\tThe employee's salary with id: " << e_id << " has been updated successfully\n\n"; 
                        break;

                    case 3:
                        std::cout << "\t\tPlease enter the new post of the Employee: ";
                        std::cin >> new_post;
                        employee.set_post(new_post);
                        std::cout << "\t\tThe employee's post with id: " << e_id << " has been updated successfully\n\n";
                        break;

                    case 4:
                        continue;
                        break;

                    default:
                        std::cout << "\t\tUnknown command please try again...\n";
                }
            } while (choice != 4);
        }
    }

    if (!found_id) {
        std::cout << "\t\tThis current id hasn't been found in our data, please try again.\n\n";
        continue_or_not();
    } else {
        update_csv();
        continue_or_not();
    }  
}


void EManager::delete_record_of_employee() {
    system("cls");
    
    int id {0};
    std::cout << "\t\tPlease enter an id of an employee, that you wish to remove from the system: ";
    std::cin >> id;

    auto isEmployeeWithId = [id](Employee &employee) {
        return employee.get_id() == id;
    };

    for (auto employee: employee_data) {
        if (employee.get_id() == id) {
            update_csv(id);
            set_employee_data_csv();
            std::cout << "\t\tSuccessfully removed employee with this id.\n\n";
            continue_or_not();
            return;
        }
    }

    std::cout << "\t\tNo employee data has been found with this particular ID...\n\n";
    continue_or_not();
}


void EManager::update_csv() {
    std::ofstream outputFile("records.csv");

    if (outputFile.is_open()) {
        for (auto &row: this->employee_data) {
            outputFile << row.get_id() << "," << row.get_name() << "," << row.get_post() << "," << row.get_department() << "," << row.get_salary() << std::endl;
        }

        outputFile.close();
    }
}


void EManager::update_csv(int ids_to_remove) {
    std::ofstream outputFile("records.csv");

    if (outputFile.is_open()) {
        for (auto &row: this->employee_data) {
            if (row.get_id() == ids_to_remove) {
                continue;
            } else {
                outputFile << row.get_id() << "," << row.get_name() << "," << row.get_post() << "," << row.get_department() << "," << row.get_salary() << std::endl;
            }
        }

        outputFile.close();
    }
}


void EManager::continue_or_not() const {
    std::string dummy{""};
    std::cout << "\t\tDo you wish to continue? y/n ";
    std::cin >> dummy;

    if (dummy == "N" || dummy == "n") {
        std::cout << "\t\tGoodbye...\n";
        exit(0);
    } 
    else {
        system("cls");
    }
}