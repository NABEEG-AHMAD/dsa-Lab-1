//#pragma once
//#include <iostream>
//using namespace std;
//
//    // Abstract Class
//    class Employee {
//    public:   
//        virtual void calculateSalary() = 0;
//    };
//
//    // derived class 1
//
//    class FullTimeEmployee : public Employee {
//    private:
//        double fixedSalary;
//
//    public:
//        void setSalary(double salary) {
//            fixedSalary = salary;
//        }
//
//        void calculateSalary() override {
//            cout << "Full-Time Employee Salary: "
//                << fixedSalary << endl;
//        }
//    };
//
//    // derived class 2
//
//    class PartTimeEmployee : public Employee {
//    private:
//        int hoursWorked;
//        double hourlyRate;
//
//    public:
//        void setDetails(int hours, double rate) {
//            hoursWorked = hours;
//            hourlyRate = rate;
//        }
//
//        void calculateSalary() override {
//            double salary = hoursWorked * hourlyRate;
//            cout << "Part-Time Employee Salary: "
//                << salary << endl;
//        }
//    };