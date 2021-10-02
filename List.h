#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node {
	void *data;
	struct Node* next;
};

Node* ReturnNodeFromList(Node** Head, int LocationInList);