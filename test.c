#include <stdio.h>   
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    char name[20];
    char no[10];
    int Mscore;
    int Escore;
    struct s_data *next;
}s_data;

int main()
{
    s_data *ptr;
    s_data *head;
    s_data *new_data;
    head = malloc(sizeof(s_data));
    ptr=head;
    ptr->next=NULL;
    int select=0;
    do
    {
        printf("(1)新增(2)離開=>");
        scanf("%d",&select);
        if(select!=2)
        {
            printf("姓名 學號 數學成績 英文成績\n");
            scanf("%s%s%d",ptr->name,ptr->no,ptr->Mscore,ptr->Escore);
            new_data=malloc(sizeof(s_data));
            ptr->next=new_data;
            new_data->next=NULL;
            ptr=ptr->next;
        }

    }while(select!=2);
}
