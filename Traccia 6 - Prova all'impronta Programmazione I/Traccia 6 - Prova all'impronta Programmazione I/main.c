//
//  main.c
//  Traccia 6 - Prova all'impronta Programmazione I
//
//  Created by Roberto Vecchio on 11/02/2019.
//  Copyright © 2019 Roberto Vecchio. All rights reserved.
//

#include <stdio.h>

typedef struct student{
    char *name;
    char *surname;
    int matricola;
}student_struct;

//definisco tre struct, due uguali e una diversa per pochi elementi, per testing.

student_struct students_computer_science[] = {
    {"Roberto","Vecchio", 12401871},
    {"Alessandro","D'Auria", 12401841},
    {"Lucio","Cocorullo", 12401879},
    {"Valeria","Esposito", 12401859}
};

student_struct students_economy[] = {
    {"Francesco","Mabilia", 12401891},
    {"Gaetano","Ippolito", 12401861},
    {"Marika","Vecchio", 12401829}
};

//template funzioni
void swapArray(student_struct *, student_struct *);
void selctionSort(student_struct *, int);
void printStudents(student_struct *, int);
void merge(student_struct *, int, student_struct *, int, student_struct *);

int main(int argc, const char * argv[]) {
    
    student_struct merged_array[(sizeof(students_computer_science) / sizeof(students_computer_science[0])) +(sizeof(students_economy)/sizeof(students_economy[0]))];
    selctionSort(students_computer_science, 4);
    selctionSort(students_economy, 3);
    printf("\n\n\n\n==========================================================\n");
    merge(students_computer_science, 4, students_economy, 3, merged_array);
    
    printStudents(merged_array, 7);
    
    
    return 0;
}

//funzioni
void swapArray(student_struct *first, student_struct *second){
    student_struct temp = *first;
    *first = *second;
    *second = temp;
}
void selctionSort(student_struct *students_array, int n){
    int i,j = 0,min = 0;
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (students_array[j].matricola < students_array[min].matricola) {
                min = j;
            }
        }
        swapArray(&students_array[min], &students_array[i]);
    }
}

void printStudents(student_struct *students, int n){
    int i;
    for (i = 0; i < n; i++) {
        printf(" Nome = %s \n Cognome = %s, \n Matricola = %d\n", students[i].name, students[i].surname, students[i].matricola);
            printf("==========================================================\n");
    }
}

void merge(student_struct *fist_student_list, int size_a, student_struct *second_student_list, int size_b, student_struct * empty_array){
    int index_a = 0, index_b = 0, index_c = 0;
    
    while (index_a < size_a && index_b < size_b) {
        
        if (fist_student_list[index_a].matricola < second_student_list[index_b].matricola) {
            
            empty_array[index_c++] = fist_student_list[index_a++];
            
        }else{
            
            empty_array[index_c++] = second_student_list[index_b++];
            
        }
    }
    while (index_a < size_a) {
        
        empty_array[index_c++] = fist_student_list[index_a++];
        
    }
    while (index_b < size_b) {
        
        empty_array[index_c++] = second_student_list[index_b++];
        
    }
}
