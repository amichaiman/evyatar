#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int idNo;
    double avgGrade;
    int age;
    char *name;
} Student;

unsigned int updateBits(unsigned int n, unsigned int m, unsigned int i, unsigned int i1);
unsigned int setBit(unsigned int c, unsigned int i, unsigned int val);
void* encodeStudent(void* a);
unsigned int getBit(unsigned int c, unsigned int i);
void printStudents(Student *students[3], int size);
Student **encodeStudentArray(Student *students[3], int size);

void** encodeArray(void** a, int size, void*(*encode)(void*));

unsigned int main(){
    Student a = {0, 100, 12, "amichai"};
    Student b = {1, 150, 19, "evyatar"};
    Student c = {2, 170, 21, "daniela"};
    Student **newArray;

    Student *students[] = {
            &a,
            &b,
            &c
    };

    printStudents(students, 3);

    newArray = encodeStudentArray(students, 3);

    printStudents(newArray, 3);
}

void* encodeStudent(void* a){
    Student *s = (Student*)a;
    Student *newStudent = (Student*) malloc (sizeof(Student));

    newStudent->idNo = s->idNo;
    newStudent->avgGrade = s->avgGrade;
    newStudent->age = s->age;
    newStudent->name = (char*) malloc ((strlen(s->name)+1)*sizeof(char));
    strcpy(newStudent->name, s->name);
    newStudent->age = updateBits(newStudent->age, 0x00000016, 2, 6);

    return newStudent;
}


Student **encodeStudentArray(Student *students[3], int size) {
    return (Student **) encodeArray(students, size, encodeStudent);
}

void printStudents(Student *students[3], int size) {
    int i;

    for (i=0; i<size; i++){
        printf("\n************************************\n");
        printf("%d\n%lf\n%d\n%s", students[i]->idNo, students[i]->avgGrade, students[i]->age, students[i]->name);
    }
}

unsigned int updateBits(unsigned int n, unsigned int m, unsigned int i, unsigned int j) {
    unsigned int res = n;
    unsigned int k;

    for (k=0; k< j-i+1; k++){
        res = setBit(res ,i+k, getBit(m,k));
    }

    return res;
}




unsigned int getBit(unsigned int c,unsigned int i){
    unsigned int mask = 1 << i;
    return (c & mask) >> i;
}

unsigned int setBit(unsigned int c, unsigned int i, unsigned int val){
    unsigned int mask = 1 << i;
    if (val == 1){
        return c | mask;
    } else {
        return c & ~mask;
    }
}



void** encodeArray(void** a, int size, void*(*encode)(void*)){
    void **newArray = (void**) malloc(size*sizeof(void*));
    int i;

    for (i=0; i<size; i++){
        newArray[i] = encode(a[i]);
    }

    return newArray;
}



