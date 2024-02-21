#include <stdio.h>
#include <stdlib.h>

// Define the structure of each node in the singly linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    printf("\nNode inserted successfully at beginning\n");
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete the first node of the list
void deleteAtBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete the last node of the list
void deleteAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL)
    {
        prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }
    free(temp);
}

// Function to print the singly linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Inserting elements into the singly linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 0);

    // Printing the singly linked list
    printf("Singly Linked List: ");
    printList(head);

    // Deleting nodes from the beginning and end of the list
    deleteAtBeginning(&head);
    deleteAtEnd(&head);

    // Printing the updated singly linked list
    printf("Singly Linked List after deletion: ");
    printList(head);

    return 0;
}
