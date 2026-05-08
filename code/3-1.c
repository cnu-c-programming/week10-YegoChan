#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[64];
    int score;
    struct Student *next;
};

struct Student *head = NULL;

void add(const char *name, int score) {
    struct Student *node = (struct Student *)malloc(sizeof(struct Student));
    strcpy(node->name, name);
    node->score = score;
    node->next = NULL;

    if (head == NULL) {
        head = node;
    } else {
        struct Student *cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = node;
    }
}

void delete(const char *name) {
    struct Student *cur = head;
    struct Student *prev = NULL;

    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            if (prev == NULL) {
                head = cur->next;
            } 
            else {
                prev->next = cur->next;
            }
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void print_list() {
    struct Student *cur = head;
    while (cur != NULL) {
        printf("%s %d\n", cur->name, cur->score);
        cur = cur->next;
    }
}

void quit() {
    struct Student *cur = head;
    while (cur != NULL) {
        struct Student *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    head = NULL;
}

int main() {
    char cmd[16];
    char name[64];
    int score;

    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "add") == 0) {
            scanf("%s %d", name, &score);
            add(name, score);
        } else if (strcmp(cmd, "delete") == 0) {
            scanf("%s", name);
            delete(name);
        } else if (strcmp(cmd, "print") == 0) {
            print_list();
        } else if (strcmp(cmd, "quit") == 0) {
            quit();
            break;
        }
    }
    return 0;
}
