#include <iostream>
#include <string>
using namespace std;
class Employee {
private:
    int id;
    string name;
    string department;
    double baseSalary;
public:
    Employee() {
        id = 0;
        name = "Unknown";
        department = "Unassigned";
        baseSalary = 0.0;
    }
    Employee(int empId, string empName) {
        id = empId;
        name = empName;
        department = "Unassigned";
        baseSalary = 0.0;
    }
    Employee(int empId, string empName, string dept, double salary) {
        id = empId;
        name = empName;
        department = dept;
        baseSalary = salary;
    }
    Employee(const Employee &other) {
        id = other.id;
        name = other.name;
        department = other.department;
        baseSalary = other.baseSalary;
    }
    double calculatePay() {
        return baseSalary;
    }
    double calculatePay(double flatBonus) {
        return baseSalary + flatBonus;
    }
    double calculatePay(int hoursWorked, double hourlyRate) {
        return baseSalary + (hoursWorked * hourlyRate);
    }
    double calculatePay(double bonusAmount, float taxPercentage) {
        double totalWithBonus = baseSalary + bonusAmount;
        double taxDeduction = totalWithBonus * (taxPercentage / 100.0);
        return totalWithBonus - taxDeduction;
    }
    void updateProfile(string newDept) {
        department = newDept;
    }
    void updateProfile(double newSalary) {
        baseSalary = newSalary;
    }
    void updateProfile(string newDept, double newSalary) {
        department = newDept;
        baseSalary = newSalary;
    }
    void displayProfile() const {
        cout << "ID: " << id 
             << " | Name: " << name 
             << " | Department: " << department 
             << " | Base Salary: $" << baseSalary << endl;
    }
};

int main() {
    cout << "=== DEMONSTRATING CONSTRUCTORS ===" << endl;
    Employee e1;
    cout << "e1 (Default): ";
    e1.displayProfile();

    Employee e2(101, "Alice Smith");
    cout << "e2 (Minimal): ";
    e2.displayProfile();
    Employee e3(102, "Bob Jones", "Engineering", 75000.0);
    cout << "e3 (Full):    ";
    e3.displayProfile();


    Employee e4(e3);
    cout << "e4 (Copy of e3): ";
    e4.displayProfile();

    cout << "\n=== DEMONSTRATING calculatePay() OVERLOADS (Using e3) ===" << endl;
    cout << "Base salary only: $" << e3.calculatePay() << endl;
    cout << "With flat bonus ($5,000): $" << e3.calculatePay(5000.0) << endl;
    cout << "With overtime (10 hours @ $50/hr): $" << e3.calculatePay(10, 50.0) << endl;
    cout << "With bonus ($4,000) & tax deduction (15%): $" << e3.calculatePay(4000.0, 15.0f) << endl;

    cout << "\n=== DEMONSTRATING updateProfile() OVERLOADS (Using e2) ===" << endl;
    cout << "Before updates:" << endl;
    e2.displayProfile();

  
    e2.updateProfile("Marketing");
    cout << "After updating department only:" << endl;
    e2.displayProfile();

    
    e2.updateProfile(60000.0);
    cout << "After updating salary only:" << endl;
    e2.displayProfile();

   
    e2.updateProfile("Human Resources", 68000.0);
    cout << "After updating department & salary simultaneously:" << endl;
    e2.displayProfile();

    return 0;
}