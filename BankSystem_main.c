#include <stdio.h>
#include <string.h>

typedef struct client {
  char  name [50];
  long long int ID; //national ID
  char Address [50];
  int Age ;
  long accountID ;
  char gaurdian [50] ;
  long long int gardiuan_national_ID ;
  int acc_status ;
  float balance ;
  char password [50] ;
} Client ;

int main ()
{
    int window ;
    int admin_options ;
    Client client1 ;
    int count_ID=0 ;
    int lower_case_count = 0;
    int upper_case_count = 0;
    int digit_count = 0;
    int i=0 ;
    int p=0 ;
    int count_spaces=0 ;
    printf("Admin window press1 \nclient window press 2 \n");
    scanf("%d", &window);
    if(window==1)
        {
        printf("Create new account press1 \nOpen existig account press2\n Exit the system  press3 ");
        scanf("%d", &admin_options);
         if(admin_options==1)
         {
          printf("Enter full name\n  ")  ;
          //fgets(client1.name, 100, stdin) ;
          scanf(" %[^\t\n]s",&client1.name);
          char *split = strtok (client1.name," ");
       while (split != NULL)
       {
         count_spaces=count_spaces+1 ;
         split = strtok (NULL, " ");
       }
       if(count_spaces<4)
       {

           printf("invalid name") ;
           exit(0) ;
       }
       else
       {


          printf("Enter your National_ID\n  ")  ;
          scanf("%lli", &client1.ID);
          //printf("%lli",client1.ID);
          count_ID=(client1.ID==0)?1:log10(client1.ID)+1;
          //printf("%d",count_ID);
          if(count_ID != 14)

          {
              printf("invalid National ID") ;
              exit(0);
          }




          printf("Enter Age\n  ")  ;
          scanf("%d", &client1.Age);
          if (client1.Age<21)
          {
              count_ID=0 ;
              printf("enter your gaurdian name\n ") ;
              scanf("%s",client1.gaurdian) ;

              printf("enter your gaurdian ID\n ") ;
              scanf("%lli",&client1.gardiuan_national_ID) ;
              count_ID=(client1.gardiuan_national_ID==0)?1:log10(client1.gardiuan_national_ID)+1;
              printf("%d",count_ID) ;
             if(count_ID != 14)
          {
              printf("invalid National ID") ;
              exit(0) ;
          }
          }

          printf("Enter Adress\n  ")  ;
          scanf("%s", &client1.Address);

          printf("Enter accountID\n  ")  ;
          scanf("%ld", &client1.accountID);

          printf("Enter balance\n  ")  ;
          scanf("%f", &client1.balance);

        // printf("Enter status\n Active   press1 \n Restricted    press2 \n closed   press3\n   ")  ;
        // scanf("%d", &client1.acc_status);



        printf("Enter pass\n  ")  ;
        scanf("%s", &client1.password);
        p=strlen(client1.password);
        for (i = 0; i < p; i++) {
            if (client1.password[i] >= 'a' && client1.password[i] <= 'z') ++lower_case_count;
            if (client1.password[i] >= 'A' && client1.password[i] <= 'Z') ++upper_case_count;
            if (client1.password[i] >= '0' && client1.password[i] <= '9') ++digit_count;

        }
        if (lower_case_count > 0 && upper_case_count > 0 && digit_count > 0 && p>8) {
            printf("Strong\n");
        }
        else
        {
            printf("invalid pass") ;
            return 0;
        }







         }


         }


        }
    return 0;
}
