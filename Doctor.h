#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Hospital.h"
struct Doctor {
	char DoctorName[50];
	char Specialty[20];
};
void ShowDoctorsInHospital(Node** DoctorHead) {
	Node* TempPointer = *DoctorHead;
	int i = 0;
	printf("\n Doctor Name\t Specialty\n");
	while (*((int*)(TempPointer->data)) != 0)
	{
		i++;
		printf("%d.%s\t", i, ((Doctor*)(TempPointer->data))->DoctorName);
		printf("%s\n", ((Doctor*)(TempPointer->data))->Specialty);
		TempPointer = TempPointer->next;
	}
	printf("\n");

}

void AddTreatingDoctor(Node** head) {
	char Name[50];
	char specialty[20];
	Node* NewDoctorNode = (Node*)malloc(sizeof(Node));
	Doctor* NewDoctor = (Doctor*)malloc(sizeof(Doctor));
	printf("Please enter the doctor's name:\n");
	scanf("%s", Name);
	printf("Please enter the doctor's Specialty:\n");
	scanf("%s", specialty);
	strcpy(NewDoctor->DoctorName, Name);
	strcpy(NewDoctor->Specialty, specialty);
	NewDoctorNode->data = NewDoctor;
	NewDoctorNode->next = *head;
	*head = NewDoctorNode;
	printf("Doctor was created successfully\n\n");
}

void ReleaseDoctorFromHospital(Node** DoctorHead) {
	int NumberOnTheList;
	Node* PrevNode;
	Node* FreeNode;
	ShowDoctorsInHospital(DoctorHead);
	printf("Please choose a Doctor\n");
	scanf("%d", &NumberOnTheList);
	if (NumberOnTheList == 1) { // Checking if you want to delete the first entry on the list.
		FreeNode = *DoctorHead; // if so, then I designate the pointer to be the first member on the list.
		*DoctorHead = (*DoctorHead)->next; // then, I procede to make it that the new first member of the list, is the one that was second, since the first is going to be deleted.
		free(FreeNode->data); // I delete the struct it is holding.
		free(FreeNode); // I delete the node.
	}
	else {
		PrevNode = ReturnNodeFromList(DoctorHead, NumberOnTheList - 2);
		FreeNode = PrevNode->next;
		PrevNode->next = FreeNode->next;
		free(FreeNode->data);
		free(FreeNode);
	}
		printf("Goodbye Doctor!\n");
}
