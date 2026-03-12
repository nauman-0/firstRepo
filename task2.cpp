#include <iostream>
#include <string>

using namespace std;

class Employee {
public:
    virtual int calculateSalary() = 0;
};

class FullTimeEmployee : public Employee {
private:
    int monthlySalary;

public:
    void setSalary(int salary) {
        monthlySalary = salary;
    }

    int calculateSalary() {
        return monthlySalary;
    }
};

class PartTimeEmployee : public Employee {
private:
    int hoursWorked;
    int hourlyRate;

public:
    void setWorkDetails(int hours, int rate) {
        hoursWorked = hours;
        hourlyRate = rate;
    }

    int calculateSalary() {
        return hoursWorked * hourlyRate;
    }
};

int main() {
    FullTimeEmployee fullTime;
    fullTime.setSalary(4500);

    PartTimeEmployee partTime;
    partTime.setWorkDetails(30, 20);

    cout << "Full time salary is: " << fullTime.calculateSalary() << endl;
    cout << "Part time salary is: " << partTime.calculateSalary() << endl;

    return 0;
}