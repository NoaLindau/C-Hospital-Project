#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

Node* ReturnNodeFromList(Node** Head, int LocationInList) { // Everyone uses this, so I placed it here
	int number = 0;
	Node* NodeIterator = *Head; // Don't want to mess with DoctorHead, so I made a temporary pointer;
	while (*((int*)(NodeIterator->data)) != 0) {
		if (number == LocationInList) {
			return NodeIterator;
		}
		number++;
		NodeIterator = NodeIterator->next;
	}
	printf("This Didn't work!");
	return NodeIterator;
}
