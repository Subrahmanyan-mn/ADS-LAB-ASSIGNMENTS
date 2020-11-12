#include <stdlib.h>
#include<stdio.h>
#include "student.h"
#include <assert.h>

void test_program_seats(){


    int mlCount=0;
    int bdaCount=0;
    int esCount=0;
    int n=80;
    Student stud[n];
    stud[0]= student_new("Subrahmanyan","BDA","Subrahmanyan@mit.edu",1,8.9,0,NULL);
    stud[1]=student_new("Gaurav","ML","Gaurav@mit.edu",10,4.9,0,NULL);
    stud[2] = student_new("varun","BDA","varun@mit.edu",11,7.9,0,NULL);
    stud[3]= student_new("Tejas","ES","Tejas@mit.edu",15,5.9,0,NULL);
    stud[4] = student_new("Arnab","BDA","Arnab@mit.edu",12,7.4,0,NULL);
    stud[5] = student_new("Kumar","ES","Kumar@mit.edu",19,7.0,0,NULL);


    assert (stud[0].entranceRank==1);
    assert (strcmp(stud[1].name,"Gaurav")==0);
    assert (strcmp(stud[1].admissionState,"rejected")==0);
    assert (stud[1].regnumber==0);
    assert (strcmp(stud[2].admissionState,"allotted")==0);
    assert (stud[3].regnumber==0);
    assert (strcmp(stud[3].admissionState,"waiting")==0);

    for(int i = 0;i<80;i++){
        if(strcmp(stud[i].program,"ML")==0){
            ++mlCount;
        }
        else if(strcmp(stud[i].program,"BDA")==0){
            ++bdaCount;
        }
        else if(strcmp(stud[i].program,"ES")==0){
            ++esCount;
        }
    }

    assert(mlCount+bdaCount+esCount==6);

    assert(filled_seat("ML")==35);
    assert(filled_seat("BDA")==30);
    assert(filled_seat("ES")==40);

    for(int j=0;j<80;j++){
        if(strcmp(stud[j].admissionState,"waiting")==0){
            strcpy(stud[j].program,"ES");
            strcpy(stud[j].admissionState,"allotted");
            stud[j].regnumber=2020+stud[j].entranceRank;

        }
    }

    assert(strcmp(stud[3].admissionState,"allotted")==0);
    assert(stud[3].regnumber==2035);


}


int main()
{

    test_program_seats();

    return 0;
}


