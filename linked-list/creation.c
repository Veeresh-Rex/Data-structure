/*creation of a linked list*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	
}*start=NULL;
 void create(void );
void disp(void );
void count();
void search();
void insertbeg();
void insertend();
void insertper();
void insertpb();
void deletebeg();
void deleteper();
void deletelt();
void shorting();
void reverse();
int main()
{
    int n,c,i,h;
  
    do {
    	printf("1: Create a node :\n");
        printf("2:Traverese nodes:\n");
        printf("3: Search an element\n");
        printf("4: Count the nodes in linked list\n");
        printf("5: Insertion\n");
        printf("6: Deletetion\n");
        printf("7:Short in assending\n");
        printf("8:Reverse linked list\n");
        printf("8:exit\n");
    	printf("Enter your choice:\n");
    	
    	scanf("%d",&n);
    	switch(n)
		{
    		case 1: create();
    		     break;
    		case 2: disp();
			     break;
			case 3: search();
			     break;
			case 4: count();
			     break;     
			case 5: printf("1: At beginning\n ");
			        printf("2: At end \n");
					printf ("3: After a perticular node\n");
					printf("4:before a node:\n");
					scanf("%d",&i);
					switch(i){
						case 1: insertbeg();
						break;
						case 2: insertend();
						break;
						case 3: insertper();
						break;
						case 4: insertpb();
						break;
						default: printf("Worng Entered\n");
					}  
					break;
			case 6: printf("1:First node\n");
			        printf("2:Particular node\n");
					printf("3:Last node\n");
					scanf("%d",&h);
					switch(h){
						case 1: deletebeg();
					    break;
					    case 2:deleteper();
					    break;
					    case 3: deletelt();
					    break;
					    default:printf("Worng Entered\n");
					    
					}	
			break;
			case 7:shorting();		
			       break;
			case 8:reverse();
			break;
			case 9: exit;	
			default : printf("Enter correct choice :\n");
				       
		}
		printf("Do you want to continue:\n");
		printf("1: for yes \n 0: for no\n");
		scanf("%d",&c);
		
	}while(c==1);
    return 0;

}
void create()
{
	struct node *temp,*temp1;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the node data:\n");
	scanf("%d",&temp->data);
	if(start==NULL)
	{
		start=temp;
		temp->next=NULL;
	}
	else {
	temp1=start;
	int i=1;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
		
	}
	temp1->next=temp;
	temp->next=NULL;
	
	}

}

	

void disp()
{ struct node *temp1;
	temp1=start;
	printf("Nodes data=\n");
	int i=0;
	while(temp1->next!=NULL)
	{
		printf("   %d ",temp1->data);
		temp1=temp1->next;
		i++;
		printf("\nNode No. %d\n",i);
	}
	
	printf("\n");
}
void search()
{ 
     struct node *temp;
     int x,pos=1;
	printf("Enter the element which do you want to search\n");
    scanf("%d",&x);
	temp=start;
	while(temp!=NULL)
	{
		if(x==temp->data)
		{
			printf("Element found at position=%d \n",pos);
			return;
		}
		temp=temp->next;
		pos++;
		}	
		printf("Element not found.\n");
}
void count(){
	struct node *temp;
	int count=1;
	temp=start;
	if(start==NULL)
	{
		printf("There is no linked list :\n");
		printf("No of nodes=0\n");
		return;
		
	}
	else 
	{
	
	while(temp->next!=NULL)
	{
		temp=temp->next;
		count++;
		
	}
	printf("No of nodes =%d  \n",count);
}
}
void insertbeg()
{
	struct node *temp1;
	temp1=(struct node* )malloc(sizeof(struct node));
	printf("Enter new node data\n ");
	scanf("%d",&temp1->data);
	temp1->next=NULL;
   if(start==NULL)
      start=temp1;
      else 
      {
	  
	temp1->next=start;
	start=temp1;
   }	
}
void insertend()
{
	struct node *temp1,*temp;
	temp1=(struct node*)malloc(sizeof(struct node));
	printf("Enter new node data\n");
	scanf("%d",&temp1->data);
	temp=start;
	temp1->next=NULL;
	if(start==NULL)
	{
		start=temp1;
		
	}
	else{
                                    //   	int i=2;
	while(temp->next!=NULL)
	{
      temp=temp->next;
	}
	temp->next=temp1;
}
}
void insertper(){
	struct node *temp,*temp1,*x;
	int n;
	temp1=(struct node*)malloc(sizeof(struct node));
	printf("Enter new node data\n");
	scanf("%d",&temp1->data);
	temp->next=NULL;
	printf("Enter node data after which do you want do insert:");
	scanf("%d",&n);
	temp=start;
	while(temp->data!=n)
	temp=temp->next;
	temp1->next=temp->next;
	temp->next=temp1;
	
}
void insertpb()
{
	struct node *temp,*temp1,*x;
	int n;
	temp1=(struct node*)malloc(sizeof(struct node));
	printf("Enter new node data\n");
	scanf("%d",&temp1->data);
	printf("Enter node data before which do you want do insert:\n");
	scanf("%d",&n);
	temp=start;
	while(temp->data!=n)
	{
		x=temp;
		temp=temp->next;
	}
	temp1->next=temp;
	x->next=temp1;
}
void deletebeg(){
	struct node *temp;
	temp=start;
	start=start->next;	
	free(temp);
}
void deleteper(){
	struct node *temp,*t;
	int e;
	printf("which element do you want to delete\n");
	scanf("%d",&e);
	temp=start;
	while(temp->data!=e){
		t=temp;
			temp=temp->next;
		
		}
	t->next=temp->next;
       free(temp);
	
	
	}

void deletelt(){
	struct node *temp,*x;
	temp=start;
	while(temp->next!=NULL)
	{
	x=temp;
	temp=temp->next;
}
x->next=NULL;
free(temp);
}

void shorting(){
	struct node *temp,*temp1;
	int e;
	temp=start;
	while(temp!=NULL)
	{
		temp1=temp->next;
         while(temp1!=NULL)
		 {
		 	if(temp->data>temp1->data)
		 	{
		 		e=temp1->data;
		 		temp1->data=temp->data;
		 		temp->data=e;
		 		
			 }
			 temp1=temp1->next;
				 }	
		temp=temp->next;		 	
	}
}
void reverse(){
	struct node *next,*ptr,*prev;
    prev=NULL;
    ptr=start;
    while(ptr!=NULL){
    	next=ptr->next;
    	ptr->next=prev;
    	prev=ptr;
    	ptr=next;
	}
	start=prev;
}
