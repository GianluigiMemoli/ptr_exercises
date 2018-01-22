#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee{ /* Definition of employee datatype structure */
  int age;
  char name[20];
  char surname[20];
} employee;

void initStruct(employee *, int); //
//void update(FILE *, employee *, int );//
void countRecords(FILE *, int *);
void checkInput(int);
void checkFile(FILE *f, char []);
void fillRecord(employee *,FILE *, int );//
void printDArray(employee *, int);

int main(int argc, char *argv[]){
  int n = 0;
  employee *emps;
  FILE *fimp;
  checkInput(argc);
  fimp = fopen(argv[1], "r");
  checkFile(fimp, argv[1]);
  countRecords(fimp, &n);
  printf("%d RECORDS \n\n", n);
  initStruct(emps, n);
  fillRecord(emps, fimp, n);
  printDArray(emps, n);
  free(emps);
  fclose(fimp);
  return 0;
}

void initStruct(employee *emp, int n){
  emp
  if(!emp) {
    printf("Memoria non allocata");
    exit(1);
  }
}

void countRecords(FILE *f, int *n){
  int x;
  char y[20], z[20];
  while(EOF != fscanf(f, "%d %s %s ", &x, y, z)){
     printf("%d %s %s\n", x, y, z );
     (*n)++;
   }
}

void checkInput(int n){
  if(n!=2){
    printf("Numero di input errato \n \n ");
    exit(1);
  }
}

void checkFile(FILE *f, char fname[]){
  if(!f){
    printf("Il file %s non è stato aperto \n \n");
    exit(1);
  }
}

void fillRecord(employee *emp, FILE *f, int n){
  int i;
  rewind(f);
  for(i = 0; i < n; i++){
    fscanf(f, "%d %s %s\n", &emp[i].age, emp[i].name, emp[i].surname);
  }
}

void printDArray(employee *emp, int n){
  int i;
  for(i = 0; i < n; i++) printf("Record %d:\n\tAge:%d\n\tName:%s\n\tSurname:%s\n", i, emp[i].age, emp[i].name, emp[i].surname);
}
