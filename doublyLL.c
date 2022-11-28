
// write a progframme to perform the following operation of single Dynamic Double Linked List:
// 1.Creation
// 2.Display
// 3.Display using recursive function
// 4.Searching
// 5.Insertion
// 6.Deletion
// 7.Reverse print
// 8.Reverse the linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} nd;
nd *head = NULL;
nd *tail = NULL;
void creat()
{
    char c = 'y';

    // head = ptr;
    int n;
    while (c == 'y')
    {
        printf("please enter a data- ");
        scanf("%d", &n);
        nd *ptr = (nd *)malloc(sizeof(nd));
        if (head == NULL)
        {
            head = ptr;
            tail = ptr;
            ptr->data = n;
            ptr->prev = NULL;
            ptr->next = NULL;
        }
        else
        {
            ptr->data = n;
            tail->next = ptr;
            ptr->prev = tail;
            ptr->next = NULL;
            tail = ptr;
        }
        printf("if continue enter y else n- ");
        fflush(stdin);
        scanf("%c", &c);
    }
}
int length()
{
    if (head == NULL)
        return 0;
    int k = 1;
    nd *temp = head;
    while (temp != tail)
    {
        temp = temp->next;
        k++;
    }
    return k;
}
void insert()
{
    int pos, d;
    printf("Enter pos and data mam--");
    scanf("%d %d", &pos, &d);
    int l = length();
    if (pos > l + 1)
    {
        printf("Please enter valid position!!!!!");
        return;
    }
    nd *new = (nd *)malloc(sizeof(nd));
    new->data = d;
    if (pos == 1)
    {
        new->next = head;
        new->prev = NULL;
        head = new;
    }
    else if (pos == l + 1)
    {
        new->next = NULL;
        new->prev = tail;
        tail->next = new;
        tail = new;
    }
    else
    {
        nd *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        new->next = temp->next;
        new->prev = temp;
        temp->next = new;
        new->next->prev = new;
    }
}
void display()
{
    if (head == NULL)
    {
        printf("it is empty");
        return;
    }
    nd *temp = head;
    do
    {
        printf("->%d ", temp->data);
        temp = temp->next;
    } while (temp != NULL);
}
void search()
{
    printf("\nplease enter which value you search- ");
    int n, c = 0;
    scanf("%d", &n);
    nd *ptr = head;
    while (ptr)
    {
        c++;
        if (ptr->data == n)
        {
            printf("\nThe index is %d ", c);
            return;
        }
        ptr = ptr->next;
    }
    printf("sorry sir not found!!!");
}
void reverse_print()
{
    if (tail == NULL)
        printf("Empty!!!!");
    else
    {
        nd *temp = tail;
        printf("start");
        do
        {
            printf("->%d ", temp->data);
            temp = temp->prev;
        } while (temp != NULL);
    }
}
void reverse()
{
    printf("chole6e");
    nd *cur = head;
    nd *nextnode = head;
    while (cur != NULL)
    {
        nextnode = cur->next;
        cur->next = cur->prev;
        cur->prev = nextnode;
        cur = nextnode;
    }
    cur = head;
    head = tail;
    tail = head;
}
void delete ()
{
    printf("Please enter the value you want to delete---");
    int n;
    scanf("%d", &n);
    if (head == tail && head->data == n)
    {
        head = NULL;
        tail = NULL;
        return;
    }
    else if (head->data == n)
    {
        head = head->next;
        head->prev = NULL;
        return;
    }
    else if (tail->data == n)
    {
        tail = tail->prev;
        tail->next = NULL;
        return;
    }
    nd *ptr = head;
    while ((ptr->next) && ptr->next->data != n)
    {
        ptr = ptr->next;
    }
    if (ptr->next)
    {
        nd *temp = ptr->next;
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(temp);
    }
    else
        printf("not found!!!!!");
}
int main()
{
    while (1)
    {
        printf("\n1.creat ll\n2.display\n3.search\n4.reverse_print\n5.delete\n6.reverse\n7.length\n8.insert val by pos\n9.exit\n");
        printf("please choose what you want-");
        int choise;
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            creat();
            break;
        case 2:
            printf("start");
            display();
            break;
        case 3:
            search();
            break;

        case 4:
            reverse_print();
            break;
        case 5:
            if (head == NULL)
                printf("please creat a linked list first!!!!");
            else
                delete();
            break;
        case 6:
            reverse();
            break;
        case 7:
            printf("%d", length());
            break;
        case 8:
            insert();
            break;
        case 9:
            exit(0);
        default:
            printf("choose currect number----");
        }
    }
    return 0;
}