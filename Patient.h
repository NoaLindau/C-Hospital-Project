#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Doctor.h"
struct Patient {
	char PatientName[50];
	int YearOfBirth;
	Doctor* TheDoctorWhoTreats;
};
void ShowPatientInHospital(Node** PatientHead) {
	int i = 1;
	Node* TempPointer = *PatientHead;
	printf("\n Patient Name   Patient Year    treating Doctor\n");
	while (*((int*)(TempPointer->data)) != 0)
	{
		printf("%d.%s\t", i, ((Patient*)(TempPointer->data))->PatientName);
		printf("%d\t", ((Patient*)(TempPointer->data))->YearOfBirth);
		printf("%s\n", ((Patient*)(TempPointer->data))->TheDoctorWhoTreats->DoctorName);
		TempPointer = TempPointer->next;
		i++;
	}
	printf("\n");	
}

void AddPatient(Node** head, Node** DoctorList) {
	Node* NewPatient = (Node*)malloc(sizeof(Node));
	Patient* Patient1 = (Patient*)malloc(sizeof(Patient));
	Node* DoctorNode;
	char Patientname[50];
	int NumberOnList;
	printf("Please enter a Patient name:\n ");
	scanf("%s", Patientname);
	printf("Please enter patient's year of birth:\n ");
	scanf("%d", &(Patient1->YearOfBirth));
	strcpy(Patient1->PatientName, Patientname); //so it doesnt make a new string and also makes sure there is a string stop symbol at the end //
	ShowDoctorsInHospital(DoctorList);
	printf("Please choose a doctor\n");
	scanf("%d", &NumberOnList);
	DoctorNode = ReturnNodeFromList(DoctorList, NumberOnList - 1);
	Patient1->TheDoctorWhoTreats = (Doctor*)(DoctorNode->data);
	NewPatient->data = Patient1;
	NewPatient->next = *head;
	*head = NewPatient;
}

void ReleasePatientFromHospital(Node** PatientHead) {
	int NumberOnTheList;
	Node* PrevNode;
	Node* FreeNode;
	ShowPatientInHospital(PatientHead);
	printf("Please choose a Patient\n");
	scanf("%d", &NumberOnTheList);
	if (NumberOnTheList == 1) {
		FreeNode = *PatientHead;
		*PatientHead = (*PatientHead)->next;
		free(FreeNode->data);
		free(FreeNode);
	}
	else {
		PrevNode = ReturnNodeFromList(PatientHead, NumberOnTheList - 2);
		FreeNode = PrevNode->next;
		PrevNode->next = FreeNode->next;
		free(FreeNode->data);
		free(FreeNode);
	}
	printf("Goodbye Patient!\n");
}

