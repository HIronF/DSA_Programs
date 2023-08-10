#include<stdio.h>

struct time_struct{
	int hour;
	int m;
	int se;
}s;

void main(){
	int i ,j ;
	// taking Input
	printf("Enter Hour:");
	scanf("%d",&s.hour);
	printf("Enter Minutes:");
	scanf("%d",&s.m);
	printf("Enter Seconds:");
	scanf("%d",&s.se);
	// If input Is Wrong
	if( s.hour>24 || s.m > 60 || s.se > 60)
	printf("Please Enter right Time");
	// For increments of Values
	else
	{
		for(i=0;i<1;i++)
		{	
			s.se = s.se + 1;
			if(s.se>60)
			{	s.se=0;
				s.m = s.m +1;
				if(s.m > 60)
				{
					s.m=0;					
					s.hour = s.hour + 1;
				}
				if(s.hour>24)
				s.hour=1;	
			}
	
		}
	}

	// For Giving Output
	printf("The time is %d:%d:%d",s.hour,s.m,s.se);
	
	// For The suffix of time
	if(s.hour>12)
	printf(" pm\n");
	else 
	printf(" am\n");
}