#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listnode
{
    int data;
    struct Node *next;
}Node;

void genList(Node **currentptr)
{
    printf("請輸入要增加的資料=> ");
    scanf("%d",&(*currentptr)->data);
    (*currentptr)->next=malloc(sizeof(Node));
    *currentptr=(*currentptr)->next;
    (*currentptr)->next=NULL;

}
void printList(Node *head)
{
    Node *current;
    current=head;
    while(current->next!=NULL)
    {
        printf("data=%d\n",current->data);
        current=current->next;
    }
}

void DelList(Node **headptr)
{
    //Node *head ;
    //head=*headptr;
    printf("刪除=> ");
    int find;
    scanf("%d",&find);
    Node *temp,*follow;
    temp=*headptr;

    //刪除第一個位置的節點(head)
    if((*headptr)->data==find)
    {
        *headptr=(*headptr)->next;
        free(temp);
    }
    else
    {
        while(temp!=NULL)//刪除中間的節點
        {
            if(temp->data==find)
            {
                follow->next=temp->next;
                free(temp);
                break;
            }
            follow=temp;
            temp=temp->next;
        }
        if(temp==NULL)
            printf("Can't Find!!\n");
    }
}
/*
Node *SearchList(Node *head)
{
    int num=0;
    printf("請輸入想搜尋的數");
    scanf("%d",&num);
    Node *current;
    current=head;
    while(current!=NULL)
    {
        if(current->data==num)
        {
            printf("address=%p\n",&current);
            return current;
            break;
        }
        else
            current=current->next;
    }
    if(current==NULL)
        printf("NOT Find!!\n");
}
*/
void InserList(Node *head)
{
    int target=0;
    printf("請輸入想放在哪個數的後面=> ");
    scanf("%d",&target);
    Node *node;
    node=head;
    while(node!=NULL)
    {
        if(node->data==target)
        {
            printf("address=%p\n",&node);
            break;
        }
        else
            node=node->next;
    }
    if(node==NULL)
        printf("NOT Find!!\n");

    int num=0;
    Node * newnode=malloc(sizeof(Node));
    printf("請輸入想插入的資料=> ");
    scanf("%d",&num);
    newnode->data=num;
    newnode->next=node->next;
    node->next=newnode;

}

void freeList(Node* node)
{
    if(node==NULL)
    {
        printf("記憶體全釋放");
    }
    freeList(node->next);
    free(node);
}

int main()
{
    //建立第一個節點
    Node *head;
    head=malloc(sizeof(Node));
    //建立目前所在的指標
    Node *current=head;
    int n=0;
    do
    {
        printf("(1)新增(2)列印(3)刪除(4)搜尋並插入(5)離開=>");
        scanf("%d",&n);
        Node *node;
        switch(n)
        {
            case 1:
                genList(&current);
                break;
            case 2: //printf(指回到head)
                printList(head);
                break;
            case 3:
                DelList(&head);
                break;
            case 4:
                InserList(head);
                break;
            case 5:
                break;
            default:
                printf("不在選項內\n");

        }
    }while(n!=5);
    freeList(head);

}


