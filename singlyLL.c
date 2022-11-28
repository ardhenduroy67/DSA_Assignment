
// write a progframme to perform the following operation of single Dynamic Linked List:
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
} nd;

nd *creat()
{
    char c;
    nd *head = NULL;
    nd *ptr = (nd *)malloc(sizeof(nd));
    head = ptr;
    int n;
    printf("please enter a data- ");
    scanf("%d", &n);
    ptr->data = n;
    printf("if continue enter y else n - ");
    fflush(stdin);
    scanf("%c", &c);
    while (c == 'y')
    {
        nd *temp = (nd *)malloc(sizeof(nd));
        printf("please enter a data- ");
        scanf("%d", &n);
        temp->data = n;
        ptr->next = temp;
        ptr = ptr->next;
        printf("if continue enter y else n- ");
        fflush(stdin);
        scanf("%c", &c);
        if (c == 'n')
            break;
    }
    ptr->next = NULL;
    return head;
}
void display(nd *ptr)
{
    if (!ptr)
        return;
    printf("->%d", ptr->data);
    display(ptr->next);
}
void search(nd *head)
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
    return;
}
nd *reverse(nd *head)
{
    nd *prev = NULL;
    nd *cur = head;
    nd *nextnode = head;
    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        cur->next = prev;
        prev = cur;
        cur = nextnode;
    }
    return prev;
}
nd *delete (nd *head)
{
    printf("please enter a the value you want to delete---");
    int n;
    scanf("%d", &n);
    if (head->data == n)
    {
        head = head->next;
        return head;
    }
    nd *ptr = head;
    while ((ptr->next) && ptr->next->data != n)
    {
        ptr = ptr->next;
    }
    if (ptr->next)
    {
        nd *temp = ptr->next;
        ptr->next = ptr->next->next;
        free(temp);
        return head;
    }
    else
        printf("not found!!!!!");
    return head;
}
int main()
{
    nd *head = NULL;
    while (1)
    {
        printf("\n1.creat ll\n2.display\n3.search\n4.exit\n5.reverse\n6.delete\n");
        printf("please choose what you want-");
        int choise;
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            head = creat();
            break;
        case 2:
            printf("start");
            display(head);
            break;
        case 3:
            search(head);
            break;
        case 4:
            exit(0);
        case 5:
            head = reverse(head);
            break;
        case 6:
            if (head == NULL)
                printf("please creat a linked list first!!!!");
            else
                head = delete (head);
            break;
        default:
            printf("choose currect number----");
        }
    }
    return 0;
}