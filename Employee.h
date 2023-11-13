#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <iostream>
#include <string>


class Employee {

    private:
        int id {0};
        std::string name {""};
        std::string post {""};
        std::string department {""};
        int salary {0};

    public:
        // Getters and Setters
        void set_id(int emplyee_id);
        int get_id();
        void set_name(std::string employee_name);
        std::string get_name();
        void set_post(std::string employee_post);
        std::string get_post();
        void set_department(std::string employee_department);
        std::string get_department();
        void set_salary(int employee_salary);
        int get_salary();

        // Constructor
        Employee(int id, std::string name, std::string post, std::string department, int salary);

        // Display
        void display();
};







#endif //_EMPLOYEE_H_