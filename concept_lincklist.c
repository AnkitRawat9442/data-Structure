#include <stdio.h>
#include <stdlib.h>

/******   declaration of the linklist using strcuture  ***/
typedef struct node
{
    int data;
    struct node *next;
} Linklist;

// to create a linklist
void create_linklist(Linklist **head_ref, int n)
{
    Linklist *temp = *head_ref, *new_node;
    printf("Enter the %d data : ", n);
    for (int i = 1; i <= n; i++)
    {
        // allocation of the memory for a new element
        new_node = (Linklist *)malloc(sizeof(Linklist));

        // printf("Enter the data : ");
        // taking the data to the new element
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        // if head is not initialised then first add the address of the new element to the head
        if (*head_ref == NULL)
        {
            *head_ref = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }
}

//     add the link in squenctial order
void push_end(Linklist **head_ref)
{
    Linklist *temp = *head_ref, *new_node;
    // allocation of the memory for a new element
    new_node = (Linklist *)malloc(sizeof(Linklist));

    printf("Enter the data : ");
    // taking the data to the new element
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    // if head is not initialised then first add the address of the new element to the head
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

//    function to insert of the begin of the linklist
void insert_At_start(Linklist **head_ref)
{
    Linklist *new_node, *temp;
    // memory allocation to the new element
    new_node = (Linklist *)malloc(sizeof(Linklist));
    printf("Enter the data : ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    // if head is not initialised then first add the address of the new element to the head
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
    }
    // re intialise the head
    else
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
}

// function to insert at a given position
void insert_At_Position(Linklist **head_ref, int n)
{
    Linklist *temp = *head_ref, *new_node, *prelink_ref;

    if (n == 1)
    {
        new_node = (Linklist *)malloc(sizeof(Linklist));
        printf("Enter the  data : ");
        scanf("%d", &new_node->data);
        new_node->next = NULL;

        prelink_ref = *head_ref;
        *head_ref = new_node;
        new_node->next = prelink_ref;

        return;
    }

    for (int i = 1; i < n - 1; i++)
        temp = temp->next;

    if (temp == NULL || n == 0)
    {
        printf("Invalid postion\n");
        return;
    }

   
     prelink_ref = temp->next;

    new_node = (Linklist *)malloc(sizeof(Linklist));
     printf("Enter the  data : ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    temp->next = new_node;

    new_node->next = prelink_ref;
}

//   delwtion of the link by the vlaue
void delete_link(Linklist **head_ref)
{
    int val;
    Linklist *temp = *head_ref, *pre_ref;
    printf("Enter the value of the element to delete : ");
    scanf("%d", &val);
    // if the value is found in the head then delte that element
    if (temp != NULL && temp->data == val)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // if element not found in the head then searching it further
    while (temp != NULL && temp->data != val)

    {
        pre_ref = temp;
        temp = temp->next;
    }
    // if temp = null that means temp has reach the null link of the last element/node, i.e element not found in the linklist
    if (temp == NULL)
    {
        printf("Value is not found in the linklist\n");
    }
    else
    {
        pre_ref->next = temp->next;
        free(temp);
    }
}

// function to display  the linklist
void display(Linklist *head_ref)
{
    while (head_ref != NULL)
    {
        printf("%d ", head_ref->data);
        head_ref = head_ref->next;
    }
    printf("\n");
}

// function to find the lenght of the linklist
void link_len(Linklist *head_ref)
{
    int count = 0;
    Linklist *temp = head_ref;
    if (head_ref == NULL)
    {
        printf("0\n");
        return;
    }
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("%d\n", count);
}

// function to reverse the linklist
void reverse_linklist(Linklist **head_ref)
{
    Linklist *current_node = *head_ref, *pre_node = NULL, *temp;

    while (current_node != NULL)
    {
        temp = current_node->next;
        current_node->next = pre_node;
        pre_node = current_node;
        current_node = temp;
    }
    *head_ref = pre_node;
}

int main()
{
    Linklist *head = NULL, *new_node, *temp;
    int choice = 1;
    printf("Enter\n5 for creating linklist\n1 for link at the start\n2 for link at the end\n3 for display link\n4 for dselete the link\n6 to find lenght of the linklist\n7 to Reverse the linklist\n8 to insert link at given position\n0 for exit\n");
    printf("Enter the choice : ");
    scanf("%d", &choice);
    while (choice)
    {
        switch (choice)
        {
        case 5:
        {
            int n;
            printf("Enter the number of element to store : ");
            scanf("%d", &n);
            create_linklist(&head, n);
        }

        break;
        case 1:
            insert_At_start(&head);

            break;
        case 2:
            push_end(&head);
            break;
        case 0:
            exit(1);
            break;
        case 6:
            link_len(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            delete_link(&head);
            break;
        case 7:
            reverse_linklist(&head);

            break;
        case 8:
        {
            int n;
            printf("Enter the Position to insert : ");
            scanf("%d", &n);
            insert_At_Position(&head, (n));
            break;
        }

        default:
            printf("Wrong choice");
        }

        printf("Enter the choice : ");
        scanf("%d", &choice);
    }

    return 0;
}
