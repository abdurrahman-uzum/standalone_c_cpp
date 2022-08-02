#include <stdlib.h>
#include<stdio.h>

int main(void){

	int number;
	char name[20];
	float balance;
	FILE * fptr;

	fptr=fopen("client.txt","w");//opens a file

	printf("Enter your number ,name and balance\n");
	printf("Enter EOF to quit\n");
	printf("==>");

	scanf("%d%s%f",&number,&name,&balance);

	while(!feof(stdin))
	{//loop goes until control z command
		fprintf(fptr,"%d %s %2.f",number,name,balance);//to get values
		printf("==>");
		scanf("%d %s %f",&number,&name,&balance);
	}
	 fclose(fptr); //closes the file

	 FILE *cfptr;

	cfptr=fopen("client.txt","r");


	printf("%s\t%s\t%s\n","Accountnum","name","balance");
	fscanf(fptr,"%d%s%f",&number,name,&balance);



	while(!feof(cfptr)){
		printf("%d\t%s\t %.2f",number,name,balance);
		fscanf(fptr,"%d %s %f",&number,name,&balance);
	}
	fclose(fptr);






}
