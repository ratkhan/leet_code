/*You are given two non - empty linked lists representing two non - negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 
itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output : 7 -> 0 -> 8
Explanation : 342 + 465 = 807.
*/
/*
EXAMPLE CALL:
	ListNode list1 = ListNode(9);
	list1.next = &ListNode(1);
	list1.next->next = &ListNode(6);

	ListNode list2 = ListNode(0);
	//list2.next = &ListNode(6);
	//list2.next->next = &ListNode(4);

	ListNode* result = addTwoNumbers(&list1, &list2);
*/

#pragma once
#include <vector>
#include <string>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	long int num1 = 0;
	long int num2 = 0;

	int carry = 0;
	ListNode* headNode = new ListNode();
	ListNode* temp = headNode;
	while (l1 != nullptr && l2 != nullptr) {
		temp->val = (l1->val + l2->val + carry) % 10;
		if (l1->next != nullptr && l2->next != nullptr) {
			temp->next = new ListNode();
			temp = temp->next;
		}
		if (!(l1->next == nullptr) != !(l2->next == nullptr)) {
			temp->next = new ListNode();
			temp = temp->next;
		}
		if (l1->val + l2->val + carry > 9) {
			carry = 1;
		}
		else {
			carry = 0;
		}

		l1 = l1->next;
		l2 = l2->next;
	}

	while (l1 != nullptr) {
		temp->val = (l1->val + carry) % 10;
		if (l1->next != nullptr)
		{
			temp->next = new ListNode();
			temp = temp->next;
		}
		if (l1->val + carry > 9) {
			carry = 1;
		}
		else {
			carry = 0;
		}
		l1 = l1->next;
	}

	while (l2 != nullptr) {
		temp->val = (l2->val + carry) % 10;
		if (l2->next != nullptr)
		{
			temp->next = new ListNode();
			temp = temp->next;
		}
		if (l2->val + carry > 9) {
			carry = 1;
		}
		else {
			carry = 0;
		}
		l2 = l2->next;
	}

	if (carry > 0) {
		ListNode* tail = new ListNode();
		temp->next = tail;
		tail->val = 1;
	}
	return headNode;
}

