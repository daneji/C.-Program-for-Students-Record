#include<stdlib.h>        //Header files imported via hash includes
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
namespace life;
{
    const bool change = true;
}

void add_customer(void);
void display_customer(void);
void list_customer(void);
void search_customer(void);
void delete_customer(void);
void purchase_product(void);
void validatechar(char string[]);
int validatenum(void);

char Name[25],address[30],product[25]; //Global variables
int ID=0, Found=0, qty;
char Target[40];
int Amt;
FILE *customer_file;
char option;
int choice;

void main(void)  //main function starts here
{
do{     			  //main looping

		printf("\n\t\t###############################################");
      printf("\n\t\tV-INFORMATION TECHNOLOGY & MANAGEMENT INSTITUTE");
		printf("\n\t\t###############################################");
      printf("\n\n\t\t1- ADD STUDENT RECORD\n\n");
      printf("\t\t2- DISPLAY STUDENT RECORD\n\n");
      printf("\t\t3- SEARCH STUDENT RECORD\n\n");
      printf("\t\t4- DELETE ALL STUDENT RECORD\n\n");
      printf("\t\t5- PURCHASE OUR ITEM\n\n");
      printf("\t\t0- EXIT PROGRAM\n\n");
      printf("\t\tENTER YOUR CHOICE:");
		choice=validatenum();
		//scanf("%i",&choice);
         switch(choice){
         case 1:           		//Case for adding STUDENT records

					printf("\n\t\t###############################################");
					printf("\n\t\tV-INFORMATION TECHNOLOGY & MANAGEMENT INSTITUTE");
					printf("\n\t\t###############################################");
               add_customer();
             break;

         case 2:                //Case for displaying list of STUDENT records
                
                   display_customer();
              break;
         case 3:                //Case for searching STUDENT records
              

					printf("\n\t\t  \t#*#*#*#*#**#**#*#*#*#*#*#**#*#*#\t\n\n\n\n");
          		printf("\n\t\t   DISPLAYING STUDENTS RECORD \t");
					printf("\n\t\t  \t*#*#*#*#**#*#*#*#*#*#*#*#*#*#*#*#*t\n\n\n\n");
               search_customer();
                       break;
         case 4:              //Case for deleting STUDENT records
               
					printf("\n\t\t  \t#*#*#*#*#*#**#*#*#*#*#*#*#*#*#*#*#*#**#\t");
          		printf("\n\t\t  \tTO SEARCH STUDENTS RECORD \t");
					printf("\n\t\t  \t#*#*#*#*#*#*#*#*#*#*#*#*#*#*#**#*#*#*#*#*#\t\n\n\n\n");
               delete_customer();
                       break;
         case 5:             //Case for calculating purchase of products
               

					//printf("\n\t\t###############################################");
					//printf("\n\t\tV-INFORMATION TECHNOLOGY & MANAGEMENT INSTITUTE");
					//printf("\n\t\t###############################################");
               purchase_product();
               getch();
			 
                       break;
                             default :  //Default for exiting from program from main menu
							  printf("\n\t\t|| V * I * T *M * I||");
                       getch();
					   
   }

          }while(choice);
   }
   void add_customer(void) //  adding OF customer record function begins here
  {

       if ((customer_file = fopen("customer_rec.dat", "a+")) == NULL)		//open files for new records
                     ID = 1;
          else
   {
             do{
               fscanf(customer_file,"%i %[^/]%*c %[^/]%*c %[^/]%*c %i%*c %i%*c", &ID, Name, address,product, &qty,&Amt);
          }while (!feof(customer_file));
       ID += 1;
   }
                printf("\nStudent ID NO: %04i", ID);	//Inputing customer particulars
                printf("\nStudent Name:       ");
                fflush(stdin);
                validatechar(Name);             //calling character validation
                //gets(Name);
                printf("Address:     ");
                //scanf(" %s", &address);
                validatechar(address);
                printf("Payment' Purpose:     ");
                validatechar(product);              //calling number validation
                //scanf("%f", &sal);
                printf("Payment' Date:     ");
                qty=validatenum();              //calling number validation
                //scanf("%f", &all);
                printf("Amount Paid:     ");
                Amt=validatenum();              //calling number validation

                printf("\n%s Record Was Saved Into Our STUDENT File!",Name);
                fprintf(customer_file,"%i %s/ %s/ %s/ %i %i\n", ID, Name, address, product, qty,Amt); //Saves customer details to files
                fclose(customer_file);                 //closing file
                getch();
  }                                            //calling function for displaying list of customer
      void display_customer(void)
  {
     if ((customer_file = fopen("customer_rec.dat", "a+")) == NULL)	//open files for displaying
        printf("File Empty!");
        else
  {
              while (!feof(customer_file))
  {
       fscanf(customer_file,"%i %[^/]%*c %[^/]%*c %[^/]%*c %i%*c %i%*c", &ID, Name, address, product,&qty,&Amt);
	         if (feof(customer_file))
                break;
                  
					printf("\n\t  \t#*#*#*#**#*#*#*#*#*#*#*#*#*#*#*#**#*#**#*##\t");
          		printf("\n\t  \t THE STUDENT RECORD \t");
					printf("\n\t  \t#*#*#*#*#*#*#**#**#*#*#**#*#*#*#*#*#*#**#*#*#*\t\n\n");

               printf("\n\tStudent ID:         %04i\n", ID);	//Displaying list of customer's records
              	printf("\tName:             %s\n",Name);
              	printf("\tAddress:           %s\n",address);
              	printf("\tPayment' Purpose:  %s\n",product);
               printf("\tPayment' Date:      %i\n",qty);
               printf("\tAmount Paid:        %i\n",Amt);
               printf("\n\t%s Record was Displayed\n",Name);
               getch();
  }
  }
					printf("\nEnd of file, press any key to esc.");
               fclose(customer_file);        //closing file
               getch();							//wait for user to press any key

  }


       void search_customer(void)            //Searching function start records here

{
      		
           if ((customer_file = fopen("customer_rec.dat", "r")) == NULL) 	//opens file for reading purposes
            printf("Error ! The File Is Empty");            //if file is empty display error message
           else
            {
          
              
				  printf("\n\t\t  \t#*##*#*#*#*#*#*#*#*#*#*#*#*#**#*#*#*#*#*#*#\t");
              printf("\n\t\t  \t SEARCH STUDENTS RECORD  \t");
				  printf("\n\t\t  \t#*#*#*#*#*#*#*#*#*#**#*#*#*#*#*#*#*#*#*#*#*\t\n\n");
              printf("\n\tEnter Name to search: ");
              fflush(stdin);
              gets(Target);
              while(!feof(customer_file))

               {
       	  		fscanf(customer_file,"%i %[^/]%*c %[^/]%*c %[^/]%*c %i%*c %i%*c", &ID, Name, address, product,&qty,&Amt); //Read contents from files
	        		if (strcmpi(Target, Name)== 0)
               {
               printf("\n\tStudent ID:         %04i\n", ID);	//Displaying list of customer's records
              	printf("\tName:             %s\n",Name);
              	printf("\tAddress:           %s\n",address);
              	printf("\tPayment' Purpose:  %s\n",product);
               printf("\tPayment' Date:      %i\n",qty);
               printf("\tAmount Paid:        %i\n",Amt);
               printf("\n\t%s Record was Displayed\n",Name);

               break;
            
           			}
           		}
               }
				  printf("\n\n\tPress Any Key to esc");
              getch();
            }


    void purchase_product(void)        // function for displaying list of customer
  {

                   

					printf("\n\t\t###############################################");
					printf("\n\t\tV-INFORMATION TECHNOLOGY & MANAGEMENT INSTITUTE");
					printf("\n\t\t###############################################");


               printf("\n\t\tTHIS IS REQEST  NOT AVAILABLE YET!\n\n");



               printf("\n\t\tpress any key to Main Menu");
               fclose(customer_file);                //closing file
               getch();

  }

 void delete_customer(void) // delete function start here
  {
      char Name[40], Target[40];
      int ID, Found = 0;
      //char Gender;
      //float sal;
       FILE *customer_file, *temp;     						//creating STUDENT record file and temporary file
            temp = fopen("temp.dat", "w");		//Creating temporary file for keeping unwanted STUDENT records
     if ((customer_file = fopen("customer_rec.dat", "r")) == NULL)	//file is empty
   	      printf("File Empty!");					//display file empty
   else
   {


				printf("\n\t#*#**#*#**#*#*#**#*#*#*#**#*#*#*#**#*\t");
            printf("\n\t\tDELETE ALL STUDENTS RECORDS\t");
            printf("\n\t\t#*#**#*#*#**#*#*#*#*#*#*#**##**#*##*\t\n\n");
            printf("\t\tEnter Name to delete: ");
            fflush(stdin);
            gets(Target);
      while (!feof(customer_file))
       {
       	 //  fscanf(customer_file,"%i %[^/]%*c %c %f%*c %f%*c %i", &ID, Name, &Gender, &sal,&all,&age);
          	fscanf(customer_file,"%i %[^/]%*c %[^/]%*c %[^/]%*c %i%*c %i%*c", &ID, Name, address, product,&qty,&Amt); //Read contents from files
           if (feof(customer_file))
              break;
	        if (strcmpi(Target, Name)!= 0)
               //fprintf(temp, "%i %s/ %c %.2f %.2f %i\n", ID, Name, Gender, sal,all,age);
           		fscanf(customer_file,"%i %[^/]%*c %[^/]%*c %[^/]%*c %i%*c %i%*c", &ID, Name, address, product,&qty,&Amt); //Read contents from files
           else
           {
               Found = 1;
             //printf("ID:     %04i\n", ID);
             //printf("Name:   %s\n",  Name);
            ///if (toupper(Gender) == 'F')
             //       printf("Gender:   Female\n");
              // else

               printf("\n\tStudent ID:         %04i\n", ID);	//Displaying list of customer's records
              	printf("\tName:             %s\n",Name);
              	printf("\tAddress:           %s\n",address);
              	printf("\tPayment' Purpose:  %s\n",product);
               printf("\tPayment' Date:      %i\n",qty);
               printf("\tAmount Paid:        %i\n",Amt);
               printf("\n\t%s Record was Displayed\n",Name);

               printf("\n\t\t\tPress any key to continue.. ");
               getch();
            }
       }
            if (!Found)    	//if records not found
              printf("Record not found!\n"); //display record not found
   }          getch();

              fclose(customer_file);   	//closing file Master File
              fclose(temp);                     //closing temporary file
              remove("customer_rec.dat");               //removing master record
              rename("temp.dat", "customer_rec.dat");   //renaming temporary file with the master file
   }



   void validatechar(char string[]) //character validation function start here
	{
   int n=0,k,val;		//declare variables

   do{

   fflush(stdin);
	gets(string);
   k=strlen(string);

   do{
   if(isalpha(string[n])||isspace(string[n]))	//if input is not alphebet or contain space
   val=1;

   else{

   break;
   }

   ++n;

   }while(val == 1  && n < (k-1));

   }while(val == 0);

   return;
	}


    int validatenum(void)				//number validation function starts here
  {
   int number,s,n=0,valid;          //declare variables for validating numbers
   char name[100];
     do{
         scanf("%s",name);
  			s=strlen(name);
         do{
      		if(isdigit(name[n]))    //check if number inputted is a numberic value
      			valid=1;             //check if valid is true
            else{
                valid=0;            //check if valid is false
               printf("\nInvalid Entry Accepts Numbers[0 to 9] only!");
               printf("\n\nEnter Correct Record Please : ");
                        break;
                 }
                 ++n;
           }while(valid==1 && n<(s-1));
       }while(valid==0||(s>100));
       number=atoi(name);
     return(number);
  }