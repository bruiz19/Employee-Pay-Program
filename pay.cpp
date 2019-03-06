#include <iostream>
#include <fstream>
#include "person.h"
#include "person.cpp"

void readData(Person employees[], int &size);
void writeData(Person employees[], int size);

int main() {
int size = 0;
Person employees[20];
  
readData(employees, size);
writeData(employees, size); 
  
return 0;
}

void readData(Person employees[], int &size) {
string fname;
string lname;
double workedHours;
double payRate;

ifstream myFile;

myFile.open("input.txt");

if(myFile.fail()) {
   cout << "Cannot open the file.";
exit (EXIT_FAILURE);
}

else {
while(myFile >> fname >> lname >> workedHours >> payRate) {

Person p;
p.setFirstName(fname);
p.setLastName(lname);
p.setHoursWorked(workedHours);
p.setPayRate(payRate);
employees[size] = p;
size++;
}

myFile.close();
}

}


void writeData(Person employees[], int size) {

ofstream myFile2;

myFile2.open("output.txt");
for(int i = 0; i < size; i++) {

myFile2 << employees[i].fullName() << " " << employees[i].totalPay() << endl;
}

myFile2.close();
}
