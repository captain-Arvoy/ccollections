#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int data;
  struct node *next;
} Node;
Node *head = NULL;
Node *tail = NULL;
extern int count = 0;
void insertAhead(int);
// 1. Insert new node ahead of head
void insertAhead(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode != NULL) {
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
      head = newNode;
      tail = head;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }
}
// 2. Insert new node behind of head
void insertBehind(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  if (head == NULL) {
    newNode->next = head;
    head = newNode;
    tail = head;
  } else {
    newNode->next = head;
    head = newNode;
  }
}
// 3. search through the linked list
void search(int data) {
  Node *ptr = head;
  if (ptr == NULL) {
    printf("Null linked list\n");
  }
  while (ptr != NULL) {
    if (ptr->next != NULL) {
      if (ptr->data == data) {
        printf("element is present");
        return;
      }
    }
    ptr = ptr->next;
  }
}
// 4. delete node from the linked list
void deleteNode(int delData) {
  Node *left = head;
  Node *mid = head;
  Node *right = NULL;
  int deleteStatus = 0;
  while (mid != NULL && !deleteStatus) {
    if (mid->data == delData) {
      deleteStatus = 1;
      left->next = right;
      free(mid);
      head = NULL;
      printf("Node deletion successful\n");
      return;
    }
    left = mid;
    mid = mid->next;
    if (mid != NULL) {
      right = mid->next;
    }
  }
}
// 5. print Linked List
void printll() {
  Node *ptr = head;
  if (ptr == NULL) {
    printf("Null linked list\n");
  }
  while (ptr != NULL) {
    if (ptr->next != NULL) {

      printf("%d->", ptr->data);
    } else {
      printf("%d", ptr->data);
    }
    ptr = ptr->next;
  }
  printf("\n");
}
// int getMiddle() {
//   Node *ptr = head;
//   int count_ptr;
//   if (count_ptr)
// }
void printMenu() {
  printf(
      "1. Insert new node ahead of head\n2. Insert new node behind of head\n3. "
      "search through the linked list\n4. delete node from the linked list\n5. "
      "print Linked List\n:");
}
// int main() {
//   int options;
//   int inputSize = 1;
//   while (inputSize == 1) {
//     printMenu();
//     inputSize = scanf("%d", &options);
//     switch (options) {
//     case 1:
//       int data;
//       printf("Enter the data to insert: ");
//       scanf("%d", &data);
//       insertAhead(data);
//       break;
//     case 2:
//       // 2. Insert new node behind of head
//       int data2;
//       printf("Enter the data to insert: ");
//       scanf("%d", &data2);
//       insertBehind(data2);
//       break;
//     case 3:
//       // 3. search through the linked list
//       int data3;
//       printf("Enter the data to search: ");
//       scanf("%d", &data3);
//       break;
//     case 4:
//       // 4. delete node from the linked list
//       int delData;
//       printf("Enter the data to be deleted: ");
//       int inputSize = scanf("%d", &delData);
//       if (inputSize == 1) {
//         deleteNode(delData);
//       }
//       break;
//     case 5:
//       // 5. print linked list
//       printll();
//       break;
//     default:
//       printf("Not valid option");
//     }
//   }
// }
