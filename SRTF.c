#include<stdio.h>
#include<conio.h>
#include <limits.h>
#include<stdlib.h>
struct Node
{
	int pro;
	int arri;
	int bur;
	struct Node *next;
}*start=NULL,*tail=NULL,*start1=NULL,*tail1=NULL;
struct Node1
{
	int  init;
	int data;
	int com;
	struct Node1 *next;
}*head=NULL,*tail2=NULL;
void add_to_result_list(int ,int ,int );
void display(int pro[],int arr[],int bur[],int comp[],int tat[],int wt[],int d,double avg_wt,double avg_tat){
 	int i;
 	printf("\nprocess no\tArrival time\tBurst time\tcompletion time\ttat\twt\n");
 	for(i=0;i<d;i++)
 	{
 		printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d\n",pro[i],arr[i],bur[i],comp[i],tat[i],wt[i]);
	 }
	 printf("\naverage wating time =%lf",avg_wt);
	 printf("\nturn around time=%lf",avg_tat);
 }
int tat_find(int tat[],int comp[],int arr[],int d)
 {
 	int i;
 	double sum=0.0;
 	for(i=0;i<d;i++)
 	{
 		tat[i]=comp[i]-arr[i];
 		sum=sum+(double)(comp[i]-arr[i]);
	 }

	 return sum;
 }
 int wt_find(int wt[],int bur[],int tat[],int d)
 {
 	int i=0;
 double sum=0.0;
 	for(i=0;i<d;i++)
 	{
 		wt[i]=tat[i]-bur[i];
 		sum=sum+(double)(tat[i]-bur[i]);
	 }
	 return sum;
 }
struct Node * deleteNode_ready(struct Node *head1,struct Node* del) 
{ 
   if(head1==NULL)
   {
   	return;
   }
   else
   {
   	struct Node *temp=head1;
   	struct Node *temp1=NULL;
   	while(temp!=NULL && temp!=del)
   	{
   		temp1=temp;
   		temp=temp->next;
	}
	if(temp==head1)
	{
		head1=head1->next;
		free(temp);
	}
	else
	{
	temp1->next=temp->next;
	free(temp);	
	}
   }
   return head1;
}
void add_to_ready(int p,int a,int b)
{
	struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
	ptr->pro=p;
	ptr->arri=a;
	ptr->bur=b;
	ptr->next=NULL;
	if(start1==NULL)
	{
	start1=ptr;
	tail1=start1;	
	}
	else
	{
			tail1->next=ptr;
			tail1=tail1->next;
	}
	return;
}
void search()
{
	if(start1==NULL)
	{
		return;
	}
	else
	{
		if(start!=NULL)
		{
			struct Node *temp=start;
			while(temp!=NULL)
			{
				if(tail2->com>=temp->arri)
				{
				
					add_to_ready(temp->pro,temp->arri,temp->bur);
					start=deleteNode_ready(start,temp);
				}
				temp=temp->next;
			}
		}
	
			struct Node *temp1=start1;
			struct Node *temp2=NULL;
			while(temp1!=NULL)
			{
				if(temp1->bur==0)
				{
					start1=deleteNode_ready(start1,temp1);
				}
				temp1=temp1->next;
			}
	
			struct Node *temp=start1;
			int small=INT_MAX;
			while(temp!=NULL)
			{
			if(temp->bur<small)
			{
			small=temp->bur;
			temp2=temp;
		
			}	
			temp=temp->next;
			}
			temp=start1;
			int t;
			while(temp!=NULL)
			{
				if(temp==temp2)
				{
				t=temp->pro;
			
				temp->bur=temp->bur-1;
				
				add_to_result_list(tail2->com,1,t);
				break;
				}
				else
				{
					temp=temp->next;
				}
			}
	}
	search();
}
void add_to_result_list(int i,int c,int p)
{
	if(head==NULL)
	{
	struct Node1 *ptr=(struct Node1 *)malloc(sizeof(struct Node1));
	ptr->data=p;
	ptr->init=i;
	ptr->com=i+c;
	ptr->next=NULL;
		head=ptr;
		tail2=head;
	}
	else
	{
	struct Node1 *ptr=(struct Node1 *)malloc(sizeof(struct Node1));
	ptr->data=p;
	ptr->init=i;
	ptr->com=ptr->init+c;
	ptr->next=NULL;
		tail2->next=ptr;
		tail2=tail2->next;
	}
}
void completion()
{
	if(start==NULL)
	{
		return;
	}
	else
	{
		struct Node *temp=start;
		if(temp->arri!=start->next->arri)
		{
		add_to_ready(temp->pro,temp->arri,temp->bur-1);
		add_to_result_list(temp->arri,1,temp->pro);
		start=deleteNode_ready(start,temp);
		search();
		}
		else
		{
			temp=start->next;
struct Node  *temp1=NULL;
int small=start->bur;
while(temp!=NULL)
{
	if(temp->bur<small && start->arri==temp->arri)
	{
		temp1=temp;
		small=temp->bur;
	}
	temp=temp->next;
}
if(temp1!=NULL){
if(start->arri==temp1->arri)
{
if(start->bur>temp1->bur)	
{
	add_to_ready(temp1->pro,temp1->arri,temp1->bur-1);
		add_to_result_list(temp1->arri,1,temp1->pro);
		start=deleteNode_ready(start,temp1);
		search();
}
else
{
	add_to_ready(start->pro,start->arri,start->bur-1);
		add_to_result_list(start->arri,1,start->pro);
		start=deleteNode_ready(start,start);
		search();
}
}
		}
	}
}
}
void find_completion_time(int comp[],int n)
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		int i;
		struct Node1 *temp=head;
		for(i=0;i<n;i++)
		{
			temp=head;
		while(temp!=NULL)
		{
			if(temp->data==i+1)
			{
				comp[i]=temp->com;	
			}	
			temp=temp->next;
		}	
		}
	}
}
void  sort(struct Node *head)
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		struct Node *temp=head;
		struct Node *temp1=NULL;
		int t;
		while(temp!=NULL)
		{
			temp1=temp->next;
			while(temp1!=NULL)
			{
				if(temp->arri>temp1->arri)
				{
					//swap the arrival time
					t=temp->arri;
					temp->arri=temp1->arri;
					temp1->arri=t;
					//swap the process
					t=temp->pro;
					temp->pro=temp1->pro;
					temp1->pro=t;
					//swap the burst time
					t=temp->bur;
					temp->bur=temp1->bur;
					temp1->bur=t;
				}
				temp1=temp1->next;
			}
			temp=temp->next;
		}
	}
}void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}   
void selectionSort(int arri[],int pro[],int bur[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (pro[j] < pro[min_idx]) 
            min_idx = j; 
        swap(&arri[min_idx], &arri[i]); 
        swap(&pro[min_idx],&pro[i]);
        swap(&bur[min_idx],&bur[i]);
    } 
} 
void main()
{
	int n,i,a,b;
	printf("enter the number of process\n");
	scanf("%d",&n);
	int arr[n],burs[n],tat[n],wt[n];
	for(i=0;i<n;i++)
	{
		printf("enter the arrival time of process %d\n",i+1);
		scanf("%d",&a);
		printf("enter the burst time of the process %d\n",i+1);
		scanf("%d",&b);
		struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
		ptr->pro=i+1;
		ptr->arri=a;
		ptr->bur=b;
		ptr->next=NULL;
		if(start==NULL)
		{
			start=ptr;
			tail=start;
		}
		else
		{
			tail->next=ptr;
			tail=tail->next;
		}
	}
	sort(start);
	struct Node *temp=start;
	i=0;
	int pro[n];
	while(temp!=NULL)
	{
		pro[i]=temp->pro;
		arr[i]=temp->arri;
		burs[i]=temp->bur;
		temp=temp->next;
		i++;
	}
	selectionSort(arr,pro,burs,n);
	completion();
	int comp[n];
	find_completion_time(comp,n);
double avg_tat=tat_find(tat,comp,arr,n);
double avg_wt=wt_find(wt,burs,tat,n);
double avg_w=(avg_wt/(double)n);
double avg_t=(avg_tat/(double)n);
display(pro,arr,burs,comp,tat,wt,n,avg_w,avg_t);
	return;
	getch();
}
