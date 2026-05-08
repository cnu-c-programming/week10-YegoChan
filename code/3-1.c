#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[100];
    int score;
    struct Node* next;
};

struct Node* head = NULL;

void add(char* name, int score) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void delete_node(char* name) {
    if (head == NULL) return;

    if (strcmp(head->name, name) == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* curr = head;
    while (curr->next != NULL && strcmp(curr->next->name, name) != 0) {
        curr = curr->next;
    }

    if (curr->next != NULL) {
        struct Node* temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }
}

void print() {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%s %d\n", curr->name, curr->score);
        curr = curr->next;
    }
}

void quit() {
    struct Node* curr = head;
    while (curr != NULL) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    head = NULL;
}

int main() {
    char command[20];
    char name[100];
    int score;

    while (1) {
        if (scanf("%s", command) != 1) {
            break;
        }

        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            add(name, score);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete_node(name);
        } else if (strcmp(command, "print") == 0) {
            print();
        } else if (strcmp(command, "quit") == 0) {
            quit();
            break;
        }
    }

    return 0;
}
