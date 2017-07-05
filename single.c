#include<stdio.h>
#include<stdlib.h>
struct node
{
 int element;
 struct node *next;
}*a,*b,*t,*x,*r,*p,*q;
int isempty();
int create();
int ins_front();
int ins_end();
int ins_pos();
int del_front();
int del_end();
int del_pos();
int del_search();
int find();
int display();
int print_rev();
int mid();
int main()
{
 int ch,z;
 do
 {
  printf("\n1.create linked list");
  printf("\n2.Insert at front");
  printf("\n3.Insert at end");
  printf("\n4.Insert at position");
  printf("\n5.Delete at front");
  printf("\n6.Delete at end");
  printf("\n7.Delete at position");
  printf("\n8.Search and delete");
  printf("\n9.Find");
  printf("\n10.Display");
  printf("\n11.print reverse");
  printf("\n12.Middle value");
  printf("\nEnter ur choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
    if(isempty())
    create();
    else
    printf("List contains node");
   break;
   case 2:
    ins_front();
   break;
   case 3:
    ins_end();
   break;
   case 4:
    ins_pos();
   break;
   case 5:
    del_front();
   break;
   case 6:
    del_end();
   break;
   case 7:
    del_pos();
   break;
   case 8:
    del_search();
   break;
   case 9:
    find();
   break;
   case 10:
    display();
   break;
   case 11:
    print_rev();
   break;
   case 12:
    mid();
   break;
   default:
    printf("Enter the correct choice");
   break;
  }
  printf("\nPress 1 to contn:");
  scanf("%d",&z);
 }while(z==1);
return 0;
}

int isempty()
{
 if(a==NULL)
 return 1;
 else
 return 0;
}

int create()
{
 int num;
  a=malloc(sizeof(struct node));
  printf("\nEnter the element:");
  scanf("%d",&num);
  a->element=num;
  a->next=NULL;
  display();
}

int ins_front()
{
 int num;
 if(!isempty())
 {
  t=malloc(sizeof(struct node));
  printf("\nEnter the element:");
  scanf("%d",&num);
  t->element=num;
  t->next=a;
  a=t;
  display();
 }
 else
 printf("List is empty");
}

int ins_end()
{
 int num;
 if(!isempty())
 {
  b=a;
  while(b->next!=NULL)
  b=b->next;
  t=malloc(sizeof(struct node));
  printf("\nEnter the element:");
  scanf("%d",&num);
  t->element=num;
  t->next=NULL;
  b->next=t;
  display();
 }
 else
 printf("\nList is empty");
}

int ins_pos()
{
 int num,pos,i;
 if(!isempty())
 {
  b=a;
  printf("\nEnter the position and element:");
  scanf("%d %d",&pos,&num);
  for(i=0;i<pos;i++)
  b=b->next;
  t=malloc(sizeof(struct node));
  t->element=num;
  t->next=b->next;
  b->next=t;
  display();
 }
 else
 printf("List is empty");
}

int del_front()
{
 if(!isempty())
 {
  x=a;
  a=a->next;
  free(x);
  display();
 } 
 else
 printf("\nList is empty");
}

int del_end()
{
 if(!isempty())
 {
  b=a;
  r=b;
  while(b->next!=NULL)
  {
   r=b;
   b=b->next;
  }
  if(a==b)
  {
   free(b);
   a=NULL;
  }
  else
  {
   r->next=NULL;
   free(b);
  }
  display();
 }
 else
 printf("\nList is empty");
}

int del_pos()
{
 int pos,i;
 printf("\nEnter the position");
 scanf("%d",&pos);
 if(!isempty())
 {
  b=a;
  r=b;
  for(i=0;i<pos;i++)
  {
   r=b;
   b=b->next;
  }
  r->next=b->next;
  free(b);
  display();
 }
 else
 printf("\nList is empty");
}

int del_search()
{
 int num;
 printf("\nEnter the element:");
 scanf("%d",&num);
 if(!isempty())
 {
  b=a;
  if(b->element==num)
  {
   x=a;
   a=a->next;
   free(x);
  }
  else
  {
   while(b->next=NULL)
   {
    r=b;
    b=b->next;
    if(b->element==num)
    {
     r->next=b->next;
     free(r);
     break;
    }
   }
  }
  display();
 }
 else
 printf("\nElement is not found");
}

int find()
{
 int num;
 printf("\nEnter the element:");
 scanf("%d",&num);
 if(!isempty())
 {
  b=a;
  while(b!=NULL)
  {
   if(b->element==num)
   {
    printf("\nElement is found");
    break;
   }
   b=b->next;
  }
  if(b==NULL)
  printf("\nElement is not found");
 }
}

int display()
{
 if(!isempty())
 {
  b=a;
  while(b!=NULL)
  {
   printf("%d\t",b->element);
   b=b->next;
  }
 }
}

int print_rev()
{
 int a1[10],i;
 if(!isempty())
 {
  b=a;
  i=0;
  while(b!=NULL)
  {
   a1[i]=b->element;
   b=b->next;
   i++;
  }
  i=i-1;
  while(i>=0)
  {
   printf("%d\t",a1[i]);
   i--;
  }
 }
 else
 printf("\nList is empty");
}

int mid()
{
 p=q=a;
 if(a!=NULL)
 {
  while(q!=NULL && q->next!=NULL)
  {
   q=q->next->next;
   p=p->next;
  }
  printf("%d",p->element);
 }
}
