#ifndef _EMANAGER_H_
#define _EMANAGER_H_
#include <vector>
#include <string>
#include "employee.h"

class EManager {

    private:
        std::vector<Employee> employee_data;

    public:
        void set_employee_data_csv();
        bool add_new_record();
        void list_employee_with_id() ;
        void list_employee_department() const;
        void display_all_employee() const;
        void update_record_of_employee();
        void delete_record_of_employee();
        void update_csv();
        void update_csv(int ids_to_remove);
        void continue_or_not() const;

        // Constructor
        EManager();
};



#endif // _EMANAGER_H_