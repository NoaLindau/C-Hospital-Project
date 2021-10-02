#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Patient.h"
void printMenu() {
	printf("Welcome to Noa Hospital.\n Please choose an option:\n");
	printf("1.Show Patients in hospital.\n");
	printf("2.Show Doctors in hospital.\n");
	printf("3.Add a new doctor employee.\n");
	printf("4.Add a new patient, and associate a treating doctor.\n");
	printf("5.Release a patient.\n");
	printf("6.Fire a doctor.\n");
	printf("7.Exit Program and lose all data saved\n");
}
int main() {
	Hospital NoaHospital; //Made a local variable in Main, the moment we exit main, it gets deleted, so no need to worry about any malloc.
	Hospital* NoaPointerHospital = &NoaHospital;
	int EndValue = 0;
	Node FinalNode;
	Node* EndNode = &FinalNode; // Made an arbitrary node, that signifies the end of both lists.
	EndNode->data = &EndValue;
	NoaPointerHospital->DoctorHead = EndNode;
	NoaPointerHospital->PatientHead = EndNode;
	bool flag = true;
	int Conditions;
	while (flag) {
		printMenu();
		scanf("%d", &Conditions);
		switch (Conditions) {
		case 1:
			ShowPatientInHospital(&(NoaPointerHospital->PatientHead));
			break;
		case 2:
			ShowDoctorsInHospital(&(NoaPointerHospital->DoctorHead));
			break;
		case 3:
			AddTreatingDoctor(&(NoaPointerHospital->DoctorHead));
			break;
		case 4:
			AddPatient(&(NoaPointerHospital->PatientHead), &(NoaPointerHospital->DoctorHead));
			break;
		case 5:
			ReleasePatientFromHospital(&(NoaPointerHospital->PatientHead));
			break;
		case 6:
			ReleaseDoctorFromHospital(&(NoaPointerHospital->DoctorHead));
			break;
		case 7:
			exit(1);
			break;
		default:
			printf("You have chosen the wrong number.\n");
			break;
		}
	}
	
}