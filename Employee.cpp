#include <iostream>
#include "employee.h"
#include <string>

Employee::Employee(int id, std::string name, std::string post, std::string department, int salary) 
    :id {id}, name{name}, post{post}, department{department}, salary{salary} {

}

void Employee::display() {
    std::cout << "\t\tEmployee ID: " << this->id << std::endl;
    std::cout << "\t\tEmployee Name: " << this->name << std::endl;
    std::cout << "\t\tEmployee's Post: " << this->post << std::endl;
    std::cout << "\t\tEmployee's Department: " << this->department << std::endl;
    std::cout << "\t\tSalary : " << this->salary << std::endl << std::endl;
}


void Employee::set_id(int employee_id) {
    this->id = employee_id;
}

int Employee::get_id() {
    return this->id;
}


void Employee::set_name(std::string employee_name) {
    this->name = employee_name;
}


std::string Employee::get_name() {
    return this->name;
}


void Employee::set_post(std::string employee_post) {
    this->post = employee_post;
}


std::string Employee::get_post() {
    return this->post;
}


void Employee::set_department(std::string employee_department) {
    this->department = employee_department;
}

std::string Employee::get_department() {
    return this->department;
}

void Employee::set_salary(int employee_salary) {
    this->salary = employee_salary;
}

int Employee::get_salary() {
    return this->salary;
}