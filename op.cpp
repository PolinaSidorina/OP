#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX  10

struct  lnode {
    int  data;
    struct  lnode* next;
} *head, * visit;

void llist_add(struct lnode** q, int num);
void llist_selection_sort(void);
void llist_print(void);
int main(void) {
    setlocale(LC_ALL, "Russian");
    struct lnode* newnode = NULL;
    int i = 0;  
    for (int i = 0; i < MAX; i++)
    {
        llist_add(&newnode, (rand() % 100));
    }
    head = newnode;
    cout << "�� ����������: \n";
    llist_print();
    cout << "�����:\n";
    llist_selection_sort();
    llist_print();
    return 0;
}

void  llist_add(struct  lnode** q, int num)
{
    struct  lnode* temp;
    if (*q == NULL)
    {
        temp = (lnode*)malloc(sizeof(lnode));
        temp->data = num;
        temp->next = *q;
        *q = temp;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = (lnode*)malloc(sizeof(struct  lnode));
        temp = temp->next;
    }
    temp->data = num;
    temp->next = NULL;
}
void llist_print(void)
{
    visit = head;
    while (visit != NULL)
    {
        cout << visit->data << " ";
        visit = visit->next;
    }
    printf("\n");
}
void  llist_selection_sort(void)
{
    struct lnode* a = NULL;
    struct lnode* b = NULL;
    struct lnode* c = NULL;
    struct lnode* d = NULL;
    struct lnode* tmp = NULL;
    a = c = head;
    while (a->next != NULL)
    {
        d = b = a->next;
        while (b != NULL)
        {
            if (a->data > b->data)
            {
                if (a->next == b)
                {
                    if (a == head)
                    {
                        a->next = b->next;
                        b->next = a;
                        tmp = a;
                        a = b;
                        b = tmp;
                        head = a;
                        c = a;
                        d = b;
                        b = b->next;
                    }
                    else
                    {
                        a->next = b->next;
                        b->next = a;
                        c->next = tmp;
                        tmp = a;
                        a = b;
                        b = tmp;
                        d = b;
                        b = b->next;
                    }
                }
                else
                {
                    if (a == head)
                    {
                        tmp = b->next;
                        b->next = a->next;
                        a->next = tmp;
                        d->next = a;
                        tmp = a;
                        a = b;
                        b = tmp;
                        d = b;
                        b = b->next;
                        head = a;
                    }
                    else {
                        tmp = b->next;
                        b->next = a->next;
                        a->next = tmp;
                        c->next = b;
                        d->next = a;
                        tmp = a;
                        a = b;
                        b = tmp;
                        d = b;
                        b = b->next;
                    }
                }
            }
            else
            {
                d = b;
                b = b->next;
            }

            c = a;
            a = a->next;
        }
    }
}