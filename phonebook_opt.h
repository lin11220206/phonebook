#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define RED 0
#define BLACK 1

/* original version */
struct __PHONE_BOOK_DETAIL {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
};

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    int color;
    struct __PHONE_BOOK_ENTRY *pLeft, *pRight;
    struct __PHONE_BOOK_ENTRY *parent;
    struct __PHONE_BOOK_DETAIL *detail;
} entry;

entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *root);
void check(entry *node);
void left_rotate(entry *e);
void right_rotate(entry *e);
entry *traceRoot(entry *node);

#endif
