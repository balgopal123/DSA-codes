#include <stdio.h>
#include <stdlib.h>

//creating the node
struct node
{
    int info;
    struct node* next;
};

//adding node at the last of linked list
void append(struct node* head, int x)
{
    struct node *p, *q;
    p = head;
    q = (struct node*)malloc(sizeof(struct node));
    q->info = x;
    q->next = NULL;
    while(p->next != NULL)
        p = p->next;
    p->next = q;
}

//adding a node at the begining
void push(struct node** head, int x)
{
    struct node* q = (struct node*) malloc(sizeof(struct node));
    q->info  = x;
    q->next = *head;
    *head    = q;
}

//**inserting any element, x at any given position, pos
void insert(struct node **head, int x, int pos)
{
    int i;
    struct node *p, *q;
    q = (struct node*)malloc(sizeof(struct node));
    q->info = x;
    p = *head;
    if(pos == 0)
    {
        q->next = *head;
        *head = q;          //or simply push(line 25) function would have been used here
    }
    else if(pos == 1)
    {
        q->next = p->next;
        p->next = q;
    }
    else
    {
        for(i=0 ; i <= pos-2 ; i++)
        {
            p = p->next;
        }
        q->next = p->next;
        p->next = q;
    }
}

//** to remove any node of given position
void remoov(struct node **head, int pos)
{
    struct node *p, *q;
    p = *head;
    if(pos == 0)
    {
        *head = p->next;
        free(p);
    }
    else if(pos == 1)
    {
        q = p->next;
        p->next = p->next->next;
        free(q);
    }
    else
    {
        for(int i=0; i<=pos-2 ; i++)
            p = p->next;
        q = p->next;
        p->next = p->next->next;
        free(q);
    }
}

//** displaying the list
void display(struct node* head)
{
    struct node* p;
    p = head;
    printf("The List is : ");
    while(p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

//** converting an array into linked list
struct node* create_list(int a[], int n)
{
    int i;
    struct node *p, *head;
    p = (struct node*)malloc(sizeof(struct node));
    p->info = a[0];
    p->next = NULL;
    head = p;
    for(i=1 ; i<n ; i++)
    {
        append(head, a[i]);
    }
    return head;
}

//** getting the list from user
struct node* get_list(int n)
{
    int i, a[n];
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    return create_list(a, n);
}

//** to reverse a linked list
// p - current node
// q - next node
// prev - previous node
struct node* reverse(struct node* head)
{
    struct node *p, *q, *prev;
    p = head;
    prev = NULL;
    while(p != NULL)
    {
        q = p->next;
        p->next = prev;
        prev = p;
        p = q;
    }
    return prev;
}

// //**creating a simple linked list
// void main()
// {
//     struct node* head;
//     struct node* n1 = (struct node*)malloc(sizeof(struct node));
//     struct node* n2 = (struct node*)malloc(sizeof(struct node));
//     struct node* n3 = (struct node*)malloc(sizeof(struct node));
//     n1->info = 1;
//     n1->next = n2;
//     n2->info = 2;
//     n2->next = n3;
//     n3->info = 3;
//     n3->next = NULL;
//     head = n1;
//     append(head, 4);
//     display(head);
// }

// //** using the functions
// void main()
// {
//     struct node *head, *p;
//     p = (struct node*)malloc(sizeof(struct node));
//     p->info = 2;
//     p->next = NULL;
//     head = p;
//     append(head, 3);
//     append(head, 5);
//     append(head, 7);
//     display(head);
//     insert(&head, 4, 0);
//     display(head);
// }

// //** converting array into linked list
// void main()
// {
//     int a[] = {2, 3, 5, 7, 11};
//     int n = sizeof(a)/sizeof(a[0]);
//     struct node *head = create_list(a, n);
//     display(head);
//     insert(&head, 4, 0);
//     display(head);
//     struct node* p;
//     p = reverse(head);
//     display(p);
// }

void main()
{
    int n, i;
    printf("*****Create a linked list*****\nEnter the number of elements : ");
    scanf("%d", &n);
    struct node *lst = get_list(n);
    while(i != 5)
    {
        printf("*****MAIN MENU*****\nPress\n");
        printf("1. To insert any element in the list\n");
        printf("2. To delete any element from the list\n");
        printf("3. To display the list\n");
        printf("4. To reverse the list\n");
        printf("5. To Exit the main menu\n");
        scanf("%d", &i);
        switch (i)
        {
            case 1:
                printf("Enter the element and the position : ");
                int x, pos;
                scanf("%d%d", &x, &pos);
                insert(&lst, x, pos);
                break;
            case 2:
                printf("Enter the position of the node : ");
                int pos1;
                scanf("%d", &pos1);
                remoov(&lst, pos1);
                break;
            case 3:
                display(lst);
                break;
            case 4:
                lst = reverse(lst);
        }
    }
}
