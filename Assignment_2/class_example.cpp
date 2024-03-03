#include <iostream>
#include <string>
#include <vector>

class Employee {
private:
    std::string name;
    double salary;
    static std::vector<Employee*> allEmployees; // Static member variable to store all employees

public:
    // Constructor
    Employee(std::string empName, double empSalary) {
        name = empName;
        salary = empSalary;
        allEmployees.push_back(this); // Add this employee to the list
    }

    // Method to set employee name
    void setName(std::string empName) {
        name = empName;
    }

    // Method to set employee salary
    void setSalary(double empSalary) {
        salary = empSalary;
    }

    // Method to get employee name
    std::string getName() {
        return name;
    }

    // Method to get employee salary
    double getSalary() {
        return salary;
    }

    // Method to display employee information
    void displayInfo() {
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Employee Salary: $" << salary << std::endl;
    }

    // Static method to add an employee
    static void addEmployee(std::string empName, double empSalary) {
        Employee* newEmployee = new Employee(empName, empSalary);
    }

    // Static method to display all employees
    static void displayAllEmployees() {
        std::cout << "All Employees:\n";
        for (Employee* emp : allEmployees) {
            emp->displayInfo();
            std::cout << std::endl;
        }
    }
};

// Initialize static member variable
std::vector<Employee*> Employee::allEmployees;

int main() {
    // Adding employees
    Employee::addEmployee("John", 50000);
    Employee::addEmployee("Alice", 60000);

    // Displaying all employees
    Employee::displayAllEmployees();

    return 0;
}
