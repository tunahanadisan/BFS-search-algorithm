#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int graph[8][8];
bool visited[7];
struct node{
    int data;
    struct node *next;
};
struct node* front = NULL;
struct node* rear= NULL;

struct node* createNode(int x)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void enQueue(int x)
{
    struct node* newyNode = createNode(x);
    if(front == NULL)
    {
        front = newyNode;
        rear = newyNode;
    }
    else
    {
        rear->next = newyNode;
        rear = newyNode;
    }
}
void deQueue()
{
    if(front == NULL)
    {
        printf("\n Your Queue is already empty please enqueue an item");
        return;
    }
 
    if(front->next == NULL)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        struct node* secondNode = front->next;
        free(front);
        front = secondNode;
    }
 
}
bool isEmpty()
{
    if(front == NULL)
        return true;
    else
        return false;
}

void BFS(int root)
{
    int i;
     for(i = 0; i < 8; i++)
    {
        visited[i] = false;
    }
 visited[root]  = true;
    enQueue(root);
    while(isEmpty() == false)
    { 
	root = front->data;
        printf("%d ", root);
        deQueue();
        for( i = 0; i < 8; i++)
        {if(visited[i] == false && graph[root][i] == 1)
            {
                visited[i] = true;
                enQueue(i);
            }
        }
    }
}
    
void readGraph()
{
    int i = 0;
    FILE *fp = fopen("matrix.txt", "r");
    while(fscanf(fp, "%d %d %d %d %d %d %d %d ",
                 &graph[i][0],
                 &graph[i][1],
                 &graph[i][2],
                 &graph[i][3],
                 &graph[i][4],
                 &graph[i][5],
                 &graph[i][6],
                 &graph[i][7]) !=EOF){
        i = i + 1;
    }
 
}
 

int main () 
{
	readGraph();
    BFS(0);
	return 0;
}
