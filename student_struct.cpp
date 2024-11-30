// student_struct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "student.h"

//const size_t NMARK = 5;
//const size_t NSIMB = 10;
//const size_t NSTUDENT = 100;
//
//struct STUDENT {
//    char name[NSIMB];
//    int mark[NMARK];
//    float avr;
//};

int main(){
    {
        STUDENT arr[NSTUDENT];
        std::cout << "Enter students:\nStudent name\nM1 ... M" << NMARK << "\n* - end of input\n";
        size_t n = input_all(arr, NSTUDENT);
        FILE* f = fopen("students", "wb");
        to_file(f, arr, n);
        fclose(f);
    }
    {
        STUDENT arr[NSTUDENT];
        size_t n;
        FILE* f = fopen("students", "rb");
        n = from_file(f, arr);
        fclose(f);
        std::cout << "From file:\n";
        print_all(arr, n);

        sort(arr, n, cmp_name);
        std::cout << "Sort:\n";
        print_all(arr, n);

        STUDENT sample_stud;
        std::cout << "Search:\nName: ";
        std::cin >> sample_stud.name;
        print_one(*search(sample_stud, arr, n, cmp_name));
    }
}
