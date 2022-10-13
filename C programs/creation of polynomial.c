#include<stdio.h>
struct node
{
float coefficient;
int exponent;
struct node*link;
};
int main()
{
struct node*head=NULL;
printf("Enter the polynomial :");
head=create(head);
print(head);
return 0;
}
struct node *create(struct node*head)
{
    int n,i;
    float coeff;
    int expo;
    printf("Enter no of terms:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter coefficient for term %d",i+1);
        scanf("%d",&coeff);
        printf("Enter exponent for term %d",i+1);
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;
}
struct node*insert(struct node*head,float co,int ex)
{
struct node*temp;
struct node*new=malloc(sizeof(struct node));
new->coefficient=co;
new->exponent=ex;
new->link=NULL;
if(head==NULL||ex >head->exponent)
{
    new->link=head;
    head=new;
}
else
{

    temp=head;
    while(temp->link!=NULL && temp->link->expo>ex)
        temp=temp->link;
    new->link=temp->link;
    temp->link=new;
}
return head;
}
void print(struct node*head)
{
    if(head==NULL)
        printf("No polynomial");
    else{
        struct node*temp=head;
        while(temp!=NULL)
        {
            printf("(%.1fx^%d)",temp->coefficient,temp->exponent);
            temp=temp->link;
            if(temp!=NULL)
                printf("+");
            else
                printf("\n");
        }
    }
}
