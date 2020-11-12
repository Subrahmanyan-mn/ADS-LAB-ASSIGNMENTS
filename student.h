#include<stdint.h>
#include "appconst.h"

#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

typedef struct _student_ Student;

struct _student_ {

    char name[STUDENT_NAME_LEN];
    char program[PROGRAM_NAME_LEN];
    char email[EMAIL_LEN];
    int entranceRank;
    float UGgrade;
    int32_t regnumber;
    char admissionState[ADMISSION_STATE];
};

typedef struct _program_ Program;

struct _program_ {
    int8_t machine_learning_seats;
    int8_t bigdata_seats;
    int8_t embedded_seats;

    int8_t ml_seats_filled;
    int8_t bda_seats_filled;
    int8_t es_seats_filled;
};

Program program_seats(int8_t ml,int8_t bda,int8_t es);
Student student_new(char name[],char prg[],char mail[],int examrank,float grade,int reg,char state[]);
int32_t test_admission_status(int s);
int8_t filled_Seats_machine_learnig();
int8_t filled_seat(char pr[]);

#endif // STUDENT_H_INCLUDED

