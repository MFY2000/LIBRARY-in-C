#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>


struct books// to call in program
{
	char student_id[14]; // declare the integer data type
	char book_id[20];// declare the charecter data type
	char b_name[20];// declare the character data type
	char add[15];// declare the character data type
	int days;// declare the integer data type
	int yr; // declare the integer data type
	
}your;



//void welcome(); 
int menu();
int check_way();
int display_name(int);
int Get_name(int);

void welcome(); // to display the welcome screen
void take_books();// to display the add books screen
void delete_books();// to display the delete function
int Return_books(); // to display the edit function
void search_books(); // to display the search function
void view_books();// too display the view books function



int main(){

welcome();
	
}

void welcome()
{


printf("\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
printf("\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
printf("\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
printf("\t        |                 WELCOME                   |\n");
printf("\t        |                   TO                      |\n");
printf("\t        |                  MAJU                     |\n");
printf("\t        |                 LIBRARY                   |\n");
printf("\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
printf("\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
printf("\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");


printf("Press any key: \b ");
fflush(stdin);
getch();

menu();



}




int menu(){
	while(1){
	system("cls");
		printf("\n   -----------------------------------------------------------------------\n");

		printf("\t\t\t\tMAIN MENU");
		printf("\n   -----------------------------------------------------------------------\n");

		printf("\tT -->>> Take Book\n");

		printf("\tR -->>> Return Book\n");

		printf("\tV -->>> View Books\n");

		printf("\tD -->>> Defaulter List\n");

		printf("\tE -->>> Close Application\n");
		check_way();	
}
}


int check_way(){
	printf("\n\nPress to Continue: \b ");
	fflush(stdin);
	int press = toupper(getch());

	switch(press){
			case 84:
				take_books();
				break;
			case 68://d
	//		    search_books();
				break;
			case 86:
				view_books();
				break;
			case 82:
				Return_books();
				break;
			case 69:
				printf("\nAs you wise");
				exit(0);
				break;
			
			default:
				printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
				check_way();
	}
	
	return 0;
}

void take_books(){
	system("cls");
	printf("\n\t\t*********************************************");
	printf("\n\t***************		Take BOOKS	  ***************");
	printf("\n\t\t*********************************************");
	
	printf("\n\nEnter Your Details Here");
	printf("\n---------------------------------------------\n");
	
	printf("Enter Your Id: \b ");
	fflush(stdin);
	gets(your.student_id);
	
	printf("Enter Your Taken Book ID: \b ");
	fflush(stdin);
	gets(your.book_id);
	
	printf("Enter Your Taken Book Name: \b ");
	fflush(stdin);
	gets(your.b_name);	
	
	printf("How many days you want to take it: \b ");
	fflush(stdin);
	scanf(" %d",&your.days);	
	
	FILE *ptr = fopen("BookRecord.txt","a");
	fprintf(ptr,"%s \t %s\t%s\t%d\n",your.student_id,your.book_id,your.b_name,your.days);
	fclose(ptr);
	
	printf("\n SUCCESFULLY RECORDED.\n");
	
	printf("\n\nDo you want to add enters : \b ");
	getch() == 'Y'? take_books() : 0;
	
	
}


void view_books(){
int i,e;

	system("cls");
	printf("\n\t*********************************************************");
	printf("\n   **************** 	VIEW ALL BOOK RECORDS 	*****************");
	printf("\n\t*********************************************************");
	
	FILE *ptr = fopen("BookRecord.txt","r");
	
	if(ptr==NULL)
	{
		printf("\n\n\tNO VIEW EMPTY RECORDS");
	}
	else
	{
		
		printf("\n Your_Id_NO.\t\tBook_Id_NO.\tBook Name\tDue_Days\n");

		for(i=0;i<24;i++)
		{
			printf("-+-");
		}
		
		while(fscanf(ptr,"%s %s %s %d\n",your.student_id ,your.book_id ,your.b_name ,&your.days )!=EOF)
		{
			printf("\n %s\t\t%s\t\t%s\t\t%d\n",your.student_id,your.book_id,your.b_name,your.days);
			e++;
		}
		
		
		printf("\n");
		for(i=0;i<24;i++){
			printf("-+-");
		}
	}
	

	printf("\nPress any key for main menu........\b ");
	getch();
	fclose(ptr);
	
	}
	
int Return_books(){
	
	int flage=0;
	char id[40];
	system("cls");
	FILE *ptr = fopen("BookRecord.txt","r+");
	FILE *temp =fopen("temp.txt","a");
	
	
	printf("\n\t\t******************************************************");
	printf("\n\t*****************	 Return BOOKS LIST	 *******************");
	printf("\n\t\t******************************************************\n\n");

	if(ptr==NULL){
		printf("\nNo Record in File!");
		printf("\nPress any key to Main Menu......");
		getch();
		menu();
	}

	printf("\nEnter Your id to search: \b ");
	fflush(stdin);
	gets(id);
	id[strlen(id)] = '.';
	 
	printf("\n");
			printf("\n Your_Id_NO.\t\tBook_Id_NO.\tBook Name\tDue_Days\n");
	printf("\n===================================================================\n");
	while(fscanf(ptr,"%s %s %s %d\n",your.student_id ,your.book_id ,your.b_name ,&your.days )!=EOF)
	{

		if(strcmp(id,your.student_id)==0)
		{
			flage=1;
			printf("\n %s\t\t%s\t\t%s\t\t%d\n",your.student_id,your.book_id,your.b_name,your.days);
		}
		else{
			fprintf(temp,"%s. \t %s\t%s\t%d\n",your.student_id,your.book_id,your.b_name,your.days);
		}
	}

		
		
		
	if(!flage){
		printf("NO RECORD FOUND BACK TO MENU........... \b ");
		fclose(ptr);
		fclose(temp);
		remove("temp.txt");
	}else{
		

	
	char ch;
	
	printf("Do you wants to return it Press(Y to continue): \b ");
	ch = toupper(getch());
	if(ch == 'Y'){		
		printf("\nRecord deleted successfully.....");
		fclose(ptr);
		fclose(temp);
		remove("BookRecord.txt");
		rename("temp.txt","BookRecord.txt");
	}
}
	
	
	
	getch();
	
}




int yourFunc(){
	printf("\n\n%s",your.student_id);	
	getch();
}

	
	
//	FILE *ptr = fopen("book_name.txt","r");
//		
//	int i;
//	for(i=0;i<1;i++){
//		do{
//			fgets(str,200,ptr);
//			printf("%s",str);
//			if(i == 0 && str[0] != ' '){
//				strcpy(Type1[i].book_name,str);
////				printf("\n%s",str);
//			}	
//			else if(i==1 && str[0] != '$' && str[0] != ' '){
//				strcpy(Type2[i].book_name,str);
//			}
//			else if(i==2 && str[0] != '$' && str[0] != ' '){
//				strcpy(Type3[i].book_name,str);
//			}
//			else if(i==3 && str[0] != '$' && str[0] != ' '){
//				strcpy(Type4[i].book_name,str);
//			}
//			else{
//				strcpy(Type5[i].book_name,str);
//			}
			
//		}while(str[0] != '$');
//			
//	}
	
//		printf("\n%s THIS IS",Type1[0].book_name);
	
//	fclose(ptr);	
//	
//	}
//	
////		printf("\n1\tAnoton\t10\t\$180.3\n");
//
//
//

//int display_name(int x){
//	int i=0;
//	printf("\nS.NO\tID\t Book\tQuanity\t Price\n");	
//	
//
//	
//	for(i=0;i<x;i++){
////		printf(" %d\t%s\n",i+1,Type1[i].book_name);	
//	}
//}

