#pragma once
const size_t NMARK = 5;
const size_t NSIMB = 10;
const size_t NSTUDENT = 100;

struct STUDENT {
    char name[NSIMB];
    int mark[NMARK];
    float avr;
};

size_t input_all(STUDENT* arr, size_t nmax);
void comput_avr(STUDENT& st);
void comput_avr(STUDENT* arr, size_t n);
void sort(STUDENT* arr, size_t n, int (*compare)(const STUDENT&, const STUDENT&));
size_t to_file(FILE* output, const STUDENT* arr, size_t n);
size_t from_file(FILE* input, STUDENT* arr);
STUDENT* search(const STUDENT& sample, STUDENT* arr, size_t n, int (*compare)(const STUDENT&, const STUDENT&));
void print_one(STUDENT& s);
void print_all(STUDENT* arr, size_t n);
int cmp_name(const STUDENT& s1, const STUDENT& s2);
