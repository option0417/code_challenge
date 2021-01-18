/*
 * Source: https://leetcode.com/problems/valid-parentheses/description/
 * Author: W.D Su
 * Date:   10/03/2017
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct node Node;
struct node {
    char* ch;
    struct node* next;
};

bool isValid(char* s) {
    if (*(s+1) == '\0') return false;

    Node* root = malloc(sizeof(Node));
    root->ch = '\0';
    root->next = 0;

    while (*s) {
      if (*s == '(' || *s == '[' || *s == '{') {
        Node* tmp = malloc(sizeof(Node));
        tmp->ch = *s;
        tmp->next = root;
        root = tmp;
        s++;
      } else if (*s == ')' || *s == ']' || *s == '}') {
        if ((*s)-1 == root->ch || (*s)-2 == root->ch) root = root->next;
        else return false;
        s++;  
      }
    }  
    return root->next == 0 ? true : false;
}

int main(int argv, char* argc[]) {
  printf("%s is %d\n", "[", isValid("["));                      // 0
  printf("%s is %d\n", "[]", isValid("[]"));                    // 1
  printf("%s is %d\n", "()[]{}", isValid("()[]{}"));            // 1
  printf("%s is %d\n", "([])", isValid("([])"));                // 1
  printf("%s is %d\n", "([))", isValid("([)]"));                // 0
  printf("%s is %d\n", "[[(({{}}))]]",isValid("[[(({{}}))]]")); // 1
  printf("%s is %d\n", "(()[])", isValid("(()[])"));            // 1
  printf("%s is %d\n", "((", isValid("(("));                    // 0
  return 0;
}
