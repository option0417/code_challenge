/*
 * Source: https://leetcode.com/problems/merge-two-sorted-lists/description/
 * Author: W.D Su
 * Date:   10/05/2017
*/
#include "stdio.h"
#include "stdlib.h"

struct ListNode {
 int val;
 struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (!l1 || !l2) return l1 ? l1 : l2;
    
    struct ListNode *head, *list;
    if (l1->val <= l2->val) {
        head = list = l1;
        l1 = l1->next;
    } else {
        head = list = l2;
        l2 = l2->next;
    }
    
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            list->next = l1;
            list = l1;
            l1 = l1->next;
        } else {
            list->next = l2;
            list = l2;
            l2 = l2->next;
        }
    }
    
    if (l1) {
      list->next = l1;
    } else if (l2) {
      list->next = l2;
    }
    
    return head;
}

struct ListNode* createListNode(int val) {
  struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
  node->val = val;
  node->next = 0;
  return node;
}

struct ListNode* createList(int vals[], int length) {
  struct ListNode* node = createListNode(vals[0]);
  struct ListNode* head = node;

  for (int idx = 1; idx < length; idx++) {
    struct ListNode* tmpNode = createListNode(vals[idx]);
    node->next = tmpNode;
    node = tmpNode;
  }
  return head;
}

void showList(struct ListNode* listNode) {
  printf("[");

  while (listNode) { 
    printf("%d", listNode->val);
    if (listNode->next)
      printf(", ");
    listNode = listNode->next;
  }

  printf("]\n");
  return;
}

int main(int argv, char* argc[]) {
  int vals1[3] = {1, 2, 3};
  int vals2[3] = {4, 5, 6};
  struct ListNode* list1 = createList(vals1, 3);
  struct ListNode* list2 = createList(vals2, 3);
  showList(list1);
  showList(list2);
  struct ListNode* result1 = mergeTwoLists(list1, list2);
  printf("Merged: "); showList(result1);                  // [1, 2, 3, 4, 5, 6]

  int vals3[3] = {4, 5, 6};
  int vals4[3] = {1, 2, 3};
  struct ListNode* list3 = createList(vals3, 3);
  struct ListNode* list4 = createList(vals4, 3);
  showList(list3);
  showList(list4);
  struct ListNode* result2 = mergeTwoLists(list3, list4);
  printf("Merged: "); showList(result2);                  // [1, 2, 3, 4, 5, 6]

  int vals5[3] = {1, 4, 5};
  int vals6[3] = {2, 3, 6};
  struct ListNode* list5 = createList(vals5, 3);
  struct ListNode* list6 = createList(vals6, 3);
  showList(list5);
  showList(list6);
  struct ListNode* result3 = mergeTwoLists(list5, list6);
  printf("Merged: "); showList(result3);                  // [1, 2, 3, 4, 5, 6]

  int vals7[2] = {1, 2};
  int vals8[3] = {3, 4, 5};
  struct ListNode* list7 = createList(vals7, 2);
  struct ListNode* list8 = createList(vals8, 3);
  showList(list7);
  showList(list8);
  struct ListNode* result4 = mergeTwoLists(list7, list8);
  printf("Merged: "); showList(result4);                  // [1, 2, 3, 4, 5]

  int vals9[2] = {1, 2};
  int vals10[2] = {1, 2};
  struct ListNode* list9 = createList(vals9, 2);
  struct ListNode* list10 = createList(vals10, 2);
  showList(list9);
  showList(list10);
  struct ListNode* result5 = mergeTwoLists(list9, list10);
  printf("Merged: "); showList(result5);                  // [1, 1, 2, 2]

  int vals11[2] = {1, 1};
  int vals12[2] = {2, 2};
  struct ListNode* list11 = createList(vals11, 2);
  struct ListNode* list12 = createList(vals12, 2);
  showList(list11);
  showList(list12);
  struct ListNode* result6 = mergeTwoLists(list11, list12);
  printf("Merged: "); showList(result6);                  // [1, 1, 2, 2]
  return 0;
}
