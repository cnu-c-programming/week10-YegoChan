#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    char name[32];
    int score;
    struct Student* next;
};

struct SList {
    struct Student head;
    struct Student* tail;
};

void addStudent(struct SList* list, char name[], int score) {
    struct Student* newStudent;

    newStudent = (struct Student*)malloc(sizeof(struct Student));

    strcpy(newStudent->name, name);
    newStudent->score = score;
    newStudent->next = NULL;

    list->tail->next = newStudent;
    list->tail = newStudent;
}

void deleteStudent(struct SList* list, char name[]) {
    struct Student* prev;
    struct Student* cur;

    prev = &(list->head);
    cur = list->head.next;

    while (strcmp(cur->name, name) != 0) {
        prev = cur;
        cur = cur->next;
    }

    prev->next = cur->next;

    if (cur == list->tail) {
        list->tail = prev;
    }

    free(cur);
}

void printList(struct SList* list) {
    struct Student* cur;

    cur = list->head.next;

    while (cur != NULL) {
        printf("%s %d\n", cur->name, cur->score);
        cur = cur->next;
    }
}

int main(void) {
    struct SList list;

    list.head.next = NULL;
    list.tail = &(list.head);

    char command[7]; // 가장 긴 명령 "delete"
    char name[32];
    int score;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            addStudent(&list, name, score);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            deleteStudent(&list, name);
        } else if (strcmp(command, "print") == 0) {
            printList(&list);
        } else if (strcmp(command, "quit") == 0) {
            struct Student* cur = list.head.next;
            struct Student* next;

            while (cur != NULL) {
                next = cur->next;
                free(cur);
                cur = next;
            }

            list.head.next = NULL;
            list.tail = &(list.head);
            break;
        }
    }

    return 0;
}