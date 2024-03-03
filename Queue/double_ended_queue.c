#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5
int arr[MAX];
int srr[5] = {0};
int front = -1, rear = -1;
bool isempty();
bool isfull();
void print();
// enqueue function
void enqueue(int data)
{
    if (isfull())
    {
        printf("\nsorry we can't add => %d,->queue is full", data);
        exit(1);
    }
    int n;
    printf("\nenter => 1, for add at rear end or enter => 0 for add at front end... ");
    scanf("%d", &n);
    if (n == 0)
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0 && rear != MAX - 1)
        {
            front = MAX - 1;
        }
        else if (front != rear + 1)
        {
            front--;
        }
        arr[front] = data;
    }
    else if (n == 1)
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (front != rear + 1)
        {
            if (front >= 0 && front <= MAX - 1 && rear != MAX - 1)
            {
                rear++;
            }
            else if (rear == MAX - 1 && front != 0)
            {
                rear = 0;
            }
        }
        arr[rear] = data;
    }
    else
    {
        printf("\n invalid input !");
        exit(1);
    }
    system("cls");
    print();
}

// dequeue function
void dequeue()
{
    if (isempty())
    {
        printf("\nqueue is empty");
        exit(1);
    }
    int n;
    printf("\nenter 0 for delete at front end or enter 1 for delete at rear end");
    scanf("%d", &n);
    // printf("\nrear => %d",rear);
    if (n == 0)
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
            system("cls");
            print();
        }
        if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    else if (n == 1)
    {
        if (rear == front)
        {
            front = -1;
            rear = -1;
            system("cls");
            print();
        }
        if (rear == 0)
        {
            rear = MAX - 1;
        }
        else
        {
            rear--;
        }
    }
    else
    {
        printf("\ninvalid input !");
    }
    system("cls");
    print();
}

// isempty function
bool isempty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// isfull function
bool isfull()
{
    if (front == 0 && rear == MAX - 1 || front == rear + 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// print function
void print()
{

    if (isempty())
    {
        printf("\n\n\tprinting data ...\n\n");
        printf("|-----|-----|-----|-----|-----|\n");

        printf("|  0  |  0  |  0  |  0  |  0  |");
        printf("\n|-----|-----|-----|-----|-----|");
        printf("\n\n\tqueue is empty");
        exit(1);
    }
    memset(srr, 0, sizeof(srr));
    int front1 = front, rear1 = rear;
    printf("\n");
    while (1)
    {
        srr[front1] = arr[front1];
        if (rear1 == front1)
        {
            break;
        }
        if (front1 == MAX - 1)
            front1 = -1;
        front1++;
    }

    printf("|-----|-----|-----|-----|-----|\n");

    printf("|  %d  |  %d  |  %d  |  %d  |  %d  |", srr[0], srr[1], srr[2], srr[3], srr[4]);
    printf("\n|-----|-----|-----|-----|-----|");
}

int main()
{
    char ch;
    int n;
    while (1)
    {
        printf("\n\n\tFor ENQUEUE => : press "
               "E"
               "\n\tFor DEQUEUE => : press "
               "D"
               " \n\tFor STOP => : press other keys \n\t==> ");
        fflush(stdin);
        scanf(" %c", &ch);
        if (ch == 'E' || ch == 'e')
        {
            printf("\nEnter data for ENQUEUE : ");
            fflush(stdin);
            scanf("%d", &n);
            enqueue(n);
        }
        else if (ch == 'D' || ch == 'd')
        {
            printf("\nDELETING DATA ...");
            dequeue();
        }
        else
        {
            printf("\nProgram is end...");
            exit(0);
        }
    }
    printf("\n\n\tprinting data ...");
    print();
    return 0;
}