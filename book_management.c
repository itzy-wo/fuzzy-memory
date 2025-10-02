//Books Management System
#include<stdio.h>
#include<stdlib.h>  
int n;
int i;
struct books
{
    int book_id;
    char title[50];
    char author[50];
    int copies;
    struct queue *rare;//queue for each book
    struct queue *front;//to keep in check for first student
    struct books *next;
}*list,*p,*q,*last;
struct queue
{
	int student_no;
	char name[50];
	struct queue *next;	
}*z,*y;
void add_book()
{   int node;
    printf("\nHow many books do you want to add? ");
    scanf("%d",&node);
    for(i=1;i<=node;i++)
    {
        p=(struct books*)malloc(sizeof(struct books));
        if(p!=NULL)
        {
            p->rare=p->front=NULL;
	    p->next=NULL;
            printf("\nEnter Book ID:");           
            scanf("%d",&p->book_id);      
            printf("\nEnter Title:");       
            scanf("%s",p->title);       
            printf("\nEnter Author:");           
            scanf("%s",p->author);         
            printf("\nEnter Number of Copies:");     
            scanf("%d",&p->copies);
            if(list==NULL)
            {
                list=last=p;
            }
            else
            {
                last->next=p;
                last=p;
            }
            n++;
            printf("\nBook added successfully!\n");
        }
    }
}
void delete_book(int position)//deleting book by id
{
    if(position==list->book_id)
    {
        p=list;
        if(list==last)
        {
            list=last=NULL;
        }
        else
        {
            list=p->next;
        }
    }
    else
    {
        q=list;
        for(i=1;i<position-1;i++)
        {
            q=q->next;
        }
        p=q->next;
	q->next=p->next;
	if(position==last->book_id)
	{
		last=q;
	}
     }
     printf("\nBook %s has been deleted successfully",p->title);
     p->next=NULL;
     free(p);
     p=NULL;

}
void display_books()
{
	q=list;
	printf("\nBook id\tTitle\tAuthor\tAvailable copies");
	while(q!=NULL)
	{
		printf("\n%d",q->book_id);
		printf("\t%s",q->title);
		printf("\t%s",q->author);
		printf("\t%d",q->copies);
		q=q->next;
	}
}
void enqueue()
{	
	
	z=(struct queue*)malloc(sizeof(struct queue));
	if(z!=NULL)
	{	
		printf("\nEnter your id");
		scanf("%d",&z->student_no);
		printf("\nENter your name");
		scanf("%s",z->name);
		z->next=NULL;
		if(q->front==NULL)
		{
			q->front=q->rare=z;		
		}
		else
		{
			(q->rare)->next=z;
			q->rare=z;
		}
		printf("\nYOu have been added to the queue");
	}
	else
	{
		printf("\nThere's no memory");
		exit(0);
	}
}
void display_queue()
{   printf("\nNUmber of people waiting in queue for book id %d",q->book_id);
    y=q->rare;
    printf("\nID\t\tStudent Name");
    while(y)
    {
       printf("\n%d\t\t%s",y->student_no,y->name);
       y=y->next;
    }
}
int main()
{
    int choice,position;
    int ch;
    do
    {
        printf("\nMenu\n1.Add a new book\n2.Delete a book\n3.Display all books\n4.Borrow a book\n5.Return a book\n6.Undo last operation\n7.Exit");
        printf("Please enter your choice: ");
        scanf("%d",&choice);    
        switch(choice)
        {
            case 1: printf("Adding a new book.\n");
                    add_book();
                    break;
            case 2: if(list!=NULL)
                    {   
                        printf("\nAvailable Books:");
                        display_books();
                        printf("\nWhich book do you want to delete just enter the Book ID");
                        scanf("%d",&position);
                        delete_book(position);
                    }
                    else
                    {
                        printf("No books available to delete.\n");
                    }
                    
                    break;
            case 3: if(list!=NULL)
	            {
    		    	printf("\nAvailable Books");
    			    display_books();
		        }
		    else
		    {
		    	printf("\nThere are no books available");
		    }
                    break;
	    case 4:if(list!=NULL)
		    {
    			display_books();
    			printf("\nPlease enter the book id");
    			scanf("%d",&position);
    			q=list;
    			for(i=list->book_id;i<position;i++)
    			{ 
    				q=q->next;
    			}
    			if(q->copies>0)
    			{
    				q->copies--;	
    				printf("\nBook has been borrowed sucessful");
    			}
    			else
    			{   
    				printf("\nThere are no copies available do to get into waiting list for the book?");
    				if(q->rare!=NULL)
    				{
    				    display_queue();
    				}
    				printf("\nenter the number from menu given below\n1.yes 2.no");
    				if(scanf("%d",&ch)==1)
    				{	printf("\nYou are getting added into the waiting list.....");
    					enqueue();
    				}
    				
    			}
		    }
		    break;
            case 7: printf("Exiting the program.\n");
                    break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 7);
    return 0;
}