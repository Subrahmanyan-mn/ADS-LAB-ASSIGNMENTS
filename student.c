#include<string.h>
#include<stdio.h>
#include "student.h"


Program program_seats(int8_t ml, int8_t bda, int8_t es){

    Program prg = {ml,bda,es,35,30,40};
   // printf("%d",prg.bigdata_seats);

    return prg;

}

Student student_new(char name[],char prg[],char mail[],int examrank,float grade,int reg,char state[]){


        Student std ;
        strcpy(std.name,name);
        strcpy(std.program,prg);
        strcpy(std.email,mail);
        std.entranceRank=examrank;
        std.UGgrade=grade;
        if(grade < 5.0){
            std.regnumber=0;
            strcpy(std.admissionState,"rejected");
        }
        else if (grade>=5.0){
            if(filled_seat(std.program)<40){
                strcpy(std.admissionState,"allotted");
                std.regnumber=2020+std.entranceRank;
            }
            else{
                std.regnumber=0;
                strcpy(std.admissionState,"waiting");
            }
        }

        return std;

}


int8_t filled_seat(char program[]){
    Program pg = program_seats(40,40,40);
    if(!strcmp(program,"ML"))
        return pg.ml_seats_filled;
    else if(!strcmp(program,"BDA"))
        return pg.bda_seats_filled;
    else if(!strcmp(program,"ES"))
        return pg.es_seats_filled;
}

