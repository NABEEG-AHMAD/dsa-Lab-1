//#pragma once
//#include <iostream>
//using namespace std;
//
//// abstract base class
//
//class Course {
//public:
//    virtual void duration() = 0;
//};
//
//// derived class 1
//
//class OnlineCourse : public Course {
//private:
//    int weeks;
//    int hoursPerWeek;
//
//public:
//    OnlineCourse(int w, int h) {
//        weeks = w;
//        hoursPerWeek = h;
//    }
//
//    void duration() override {
//        int totalHours = weeks * hoursPerWeek;
//        cout << "Online Course Duration: " << totalHours
//            << " hours  in " << weeks << " weeks " << endl;
//    }
//};
//
//// derived class 2
//
//class OfflineCourse : public Course {
//private:
//    int months;
//    int hoursPerDay;
//
//public:
//    OfflineCourse(int m, int h) {
//        months = m;
//        hoursPerDay = h;
//    }
//
//    void duration() override {
//        int totalHours = months * 30 * hoursPerDay;  
//        cout << "Offline Course Duration: " << totalHours
//            << " hours (" << months << " months)" << endl;
//    }
//};