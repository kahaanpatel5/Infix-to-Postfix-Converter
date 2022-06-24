//Author: Kahaan Patel
//Purpose: Infix to Postfix using stack
//Date: February 3rd, 2022
#include<stdio.h>
#include<malloc.h>
#include<ctype.h>

struct node
{
    char data;
    struct node *next;
};
typedef struct node NODE;
NODE *push(NODE*, char);
NODE *pop(NODE*);
NODE *isEmpty(NODE*);
NODE *postfix(NODE*, char*);
int priority(char);
NODE *top=NULL;

int main()
{
    char str[10];
    printf("Enter infix string: ");
    scanf("%s", str);
    printf("Postfix String: ");
    top=postfix(top, str);
    return 0;
}
NODE *push(NODE *top, char val)
{
    NODE *ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    ptr->data=val;
    if(top==NULL)
    {
        ptr->next=NULL;
        top=ptr;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
    return top;
}
NODE *pop(NODE *top)
{
    NODE *ptr=top;
    if(isEmpty(ptr)==NULL)
    printf("\nSTACK UNDERFLOW!");
    else
    {
        printf("%c", ptr->data);
        top=top->next;
        free(ptr);
    }
    return top;
}
NODE *isEmpty(NODE *top)
{
    if(top==NULL)
    return NULL;
    else
    return top;
}
NODE *postfix(NODE *top, char *c)
{
    for(int i=0; *(c+i)!='\0'; i++)
    {
        if(isalpha(*(c+i)))
        printf("%c", *(c+i));
        else if(*(c+i)=='(')
        top=push(top, *(c+i));
        else if(*(c+i)==')')
        {
            while(top!=NULL&&top->data!='(')
            top=pop(top);
            if(top==NULL)
            {
                printf("\nIncorrect Expression!");
                break;
            }
            top=pop(top);
            printf("\b");
        }
        else if(*(c+i)=='+'||*(c+i)=='-'||*(c+i)=='*'||*(c+i)=='/')
        {
            while((top!=NULL&&top->data!='(')&&(priority(top->data)>=priority(*(c+i))))
            top=pop(top);
            top=push(top, *(c+i));
        }
        else if(*(c+i)=='$')
        top=push(top, *(c+i));
        else
        {
            printf("\nIncorrect Expression!");
            break;
        }
    }
    while(top!=NULL)
    top=pop(top);
    return top;
}
int priority(char c)
{
    if(c=='+'||c=='-')
    return 1;
    else if(c=='*'||c=='/')
    return 2;
    else if(c=='$')
    return 3;
    else
    printf("\nIncorrect Expression!");
        
}