#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "student.h"

size_t input_all(STUDENT* arr, size_t nmax) {
    char name[NSIMB];
    size_t i;
    for (i = 0; i < nmax && (std::cin >> name, strcmp(name, "*")); ++i) {
        strcpy(arr[i].name, name);
        for (size_t j = 0; j < NMARK; ++j)
            std::cin >> arr[i].mark[j];
    }
    return i;
}

void comput_avr(STUDENT& st) {
    int sum{ 0 };
    for (size_t i{ 0 }; i < NMARK; ++i) {
        sum += st.mark[i];
    }
    st.avr = float(sum) / NMARK;
}

void comput_avr(STUDENT* arr, size_t n) {
    for (size_t i{ 0 }; i < n; ++i) {
        comput_avr(arr[i]);
    }
}

void sort(STUDENT* arr, size_t n, int (*compare)(const STUDENT&, const STUDENT&)) {
    comput_avr(arr, n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j)
            if (compare(arr[j], arr[j + 1]) > 0) {
                STUDENT temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    }
}

size_t to_file(FILE* output, const STUDENT* arr, size_t n) {
    if (!output)
        return -1;
    return fwrite(arr, sizeof(STUDENT), n, output);
}

size_t from_file(FILE* input, STUDENT* arr) {
    if (!input)
        return -1;
    return fread(arr, sizeof(STUDENT), NSTUDENT, input);
}

STUDENT* search(const STUDENT& sample, STUDENT* arr, size_t n, int (*compare)(const STUDENT&, const STUDENT&)) {
    size_t i;
    comput_avr(arr, n);

    for (i = 0; (i < n) && (compare(sample, arr[i])); ++i);
    if (i == n)
        return NULL;
    return arr + i;
}

void print_one(STUDENT& s) {
    comput_avr(s);
    std::cout << s.name << ":\n";
    for (size_t i = 0; i < NMARK; ++i)
        std::cout << s.mark[i] << " ";
    std::cout << "avr: " << s.avr;
}

void print_all(STUDENT* arr, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        print_one(arr[i]);
        std::cout << "\n";
    }
}

int cmp_name(const STUDENT& s1, const STUDENT& s2) {
    return strcmp(s1.name, s2.name);
}
