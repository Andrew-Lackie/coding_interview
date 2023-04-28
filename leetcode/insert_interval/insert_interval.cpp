#include <iostream>
#include <vector>
#include <algorithm>
#include "../../data_structures/linked_list.hpp"

 struct ListNode {
		 int val;
		 ListNode *next;
		 ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			ListNode *value = NULL;
			while (headA->next != NULL) {
				while (headB->next != NULL) {
					if (headA->val == headB->val) {
						value = headA;
					}
					headB = headB->next;
				}
				headA = headA->next;
			}
			return value;
    }
};
