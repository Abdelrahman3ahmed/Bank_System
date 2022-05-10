#include <stdio.h>
#include <string.h>
#include <time.h>
#include "LinkedList.c"

int main()
{
    int window;
    int admin_options;
        Client client1;
    int count_ID = 0;
    int lower_case_count = 0;
    int upper_case_count = 0;
    int digit_count = 0;
    int i = 0;
    int p = 0;
    int count_spaces = 0;
    Client temp;
    List LS;
    List_Init(&LS);
mainmenu:
    printf("\n1.Admin window \n2.client window \n0.Exit\n");
    scanf("%d", &window);
    if (window == 1)
    {
    aa:
        printf("1.Create new account \n2.Open existig account \n0.Go back \n ");
        scanf("%d", &admin_options);
        if (admin_options == 1)
        {
            printf("Enter full name\n  ");
            scanf(" %[^\t\n]s", &client1.name);
            char *split = strtok(client1.name, " ");
            while (split != NULL)
            {
                count_spaces = count_spaces + 1;
                split = strtok(NULL, " ");
            }
            if (count_spaces < 4)
            {

                printf("invalid name\n\n\n\n");
                goto aa;
            }
            else
            {

                printf("Enter your National_ID\n  ");
                scanf("%lli", &client1.ID);
                // printf("%lli",client1.ID);
                count_ID = (client1.ID == 0) ? 1 : log10(client1.ID) + 1;
<<<<<<< HEAD
                printf("%d",count_ID);
=======
                // printf("%d",count_ID);
>>>>>>> 6f529d6fcdce7b02ff0001b859a1e59c6b5c7fbd
                 if (count_ID != 14)

                 {
                     printf("invalid National ID\n\n\n\n");
                     goto aa;
                 }

                printf("Enter Age\n  ");
                scanf("%d", &client1.Age);
                if (client1.Age < 21)
                {
                    count_ID = 0;
                    printf("enter your gaurdian name\n ");
                    scanf("%s", client1.gaurdian);

                    printf("enter your gaurdian ID\n ");
                    scanf("%lli", &client1.gardiuan_national_ID);
                    count_ID = (client1.gardiuan_national_ID == 0) ? 1 : log10(client1.gardiuan_national_ID) + 1;
<<<<<<< HEAD
                   // printf("%d", count_ID);
=======
>>>>>>> 6f529d6fcdce7b02ff0001b859a1e59c6b5c7fbd
                    if (count_ID != 14)
                    {
                        printf("invalid National ID\n\n\n\n");
                        goto aa;
                    }
                }

                printf("Enter Adress\n  ");
                scanf("%s", &client1.Address);

                printf("Enter accountID\n  ");
                scanf("%lli", &client1.accountID);
                count_ID = 0;
                count_ID = (client1.accountID == 0) ? 1 : log10(client1.accountID) + 1;
                if (count_ID != 10)
                {
                    printf("invalid Account ID\n\n\n\n");
                    goto aa;
                }
                for (i = 0; i < List_GetSize(&LS); i++)
                {
                    List_RetriveFromList(i, &LS, &temp);

                    if (temp.accountID == client1.accountID)
                    {
                        printf("This account id exists, try another id\n");
                        goto aa;
                    }
                }

                printf("Enter balance\n  ");
                scanf("%f", &client1.balance);

                printf("Enter status:\n1.Active \n2.Restricted  \n3.Closed  \n   ");
                scanf("%d", &client1.acc_status);
                
                            printf("Enter password\n  ");
                            int i=0;

                do{
                    client1.password[i]=getch();
                    if(client1.password[i]!='\r'){
                        printf("*");
                     if (client1.password[i] >= 'a' && client1.password[i] <= 'z')
                        ++lower_case_count;
                    if (client1.password[i] >= 'A' && client1.password[i] <= 'Z')
                        ++upper_case_count;
                    if (client1.password[i] >= '0' && client1.password[i] <= '9')
                       ++digit_count;
                    }
                    i++;
                }while(client1.password[i-1]!='\r');
                client1.password[i-1]='\0';
                getch();
                 p = strlen(client1.password);
                if (lower_case_count > 0 && upper_case_count > 0 && digit_count > 0 && p >= 8)
                {
                    // printf("Strong\n");
                    List_Insertinto(List_GetSize(&LS), &LS, client1);
                    printf("\nAccount created successfully\n\n\n\n");
                    goto aa;
                }
                else
                {
                    printf("invalid password\n\n\n\n");
                    goto aa;
                }
            }
        }
        else if (admin_options == 2)
        {
            long long int id;
            int flag = 0;
            Client user, receive;
            float money;
            int account_option;
            printf("Enter account ID\n");
            scanf("%lli", &id);
            int userpos = -1;
            for (i = 0; i < List_GetSize(&LS); i++)
            {
                List_RetriveFromList(i, &LS, &user);

                if (user.accountID == id)
                {
                    userpos = i;
                    flag = 1;
                    break;
                }
            }
            if (flag != 1)
            {
                printf("Account ID does not exist\n\n\n\n");
                goto aa;
            }
            else
            {
                printf("1.Make transaction \n2.Get Cash \n3.Make Deposit \n4.Change account status \n0.Go back press 0\n");
                scanf("%d", &account_option);
                if (account_option == 1)
                {
                    int receiverpos = -1;
                    flag = 0;
                    printf("Enter account ID you want to transfer money to\n");
                    scanf("%lli", &id);

                    for (i = 0; i < List_GetSize(&LS); i++)
                    {
                        List_RetriveFromList(i, &LS, &receive);

                        if (receive.accountID == id)
                        {
                            receiverpos = i;
                            flag = 1;
                            break;
                        }
                    }
                    if (flag != 1)
                    {
                        printf("Account ID does not exist\n\n\n\n");
                        goto aa;
                    }
                    else
                    {
                        if (receive.acc_status != 1 || user.acc_status != 1)
                        {
                            printf("Account status is not active\n\n\n\n");
                            goto aa;
                        }
                        else
                        {
                            printf("Enter amount of money:\n");
                            scanf("%f", &money);
                            if (money > user.balance)
                            {
                                printf("Balance is less than amount of money\n\n\n\n");
                                goto aa;
                            }
                            else
                            {
                                user.balance = user.balance - money;
                                receive.balance = receive.balance + money;
                                printf("%s%f", "Your new balance is ", user.balance);
                                List_Replaceintolist(userpos, &LS, user);
                                List_Replaceintolist(receiverpos, &LS, receive);
                                printf("\n\n\n\n");
                                goto aa;
                            }
                        }
                    }
                }
                else if (account_option == 2)
                {
                    if (user.acc_status != 1)
                    {
                        printf("Account status is not active\n\n\n\n");
                        goto aa;
                    }
                    else
                    {
                        printf("Enter amount of money:\n");
                        scanf("%f", &money);
                        if (money > user.balance)
                        {
                            printf("Balance is less than amount of money\n\n\n\n");
                            goto aa;
                        }
                        else
                        {
                            user.balance = user.balance - money;
                            printf("%s%f", "Your new balance is ", user.balance);
                            List_Replaceintolist(userpos, &LS, user);
                            printf("\n\n\n\n");
                            goto aa;
                        }
                    }
                }
                else if (account_option == 3)
                {
                    if (user.acc_status != 1)
                    {
                        printf("Account status is not active\n\n\n\n");
                        goto aa;
                    }
                    else
                    {
                        printf("Enter amount of money:\n");
                        scanf("%f", &money);
                        user.balance = user.balance + money;
                        printf("%s%f", "Your new balance is ", user.balance);
                        List_Replaceintolist(userpos, &LS, user);
                        printf("\n\n\n\n");
                        goto aa;
                    }
                }
                else if (account_option == 4)
                {
                    printf("your account status is ");
                    if (user.acc_status == 1)
                        printf("Active\n");
                    else if (user.acc_status == 2)
                        printf("Restricted\n");
                    else
                        printf("Closed\n");
                    printf("Enter status:\n1.Active \n2.Restricted  \n3.Closed  \n   ");
                    scanf("%d", &user.acc_status);
                    List_Replaceintolist(userpos, &LS, user);
                    printf("\n\n\n\n");
                    goto aa;
                }
                else if (account_option == 0)
                {
                    goto aa;
                }
                else
                {
                    printf("Please enter a valid option\n");
                    printf("\n\n\n\n");
                    goto aa;
                }
            }
        }
        else if (admin_options == 0)
        {
            goto mainmenu;
        }
        else
        {
            printf("Please enter a valid option\n");
            printf("\n\n\n\n");
            goto aa;
        }
    }
    else if (window == 2)
    {
        // client window
        printf("client");
        long long int id;
        int flag = 0;
        Client user, receive;
        float money;
        int account_option;
        printf("Enter account ID\n");
        scanf("%lli", &id);
        int userpos = -1;
        for (i = 0; i < List_GetSize(&LS); i++)
        {
            List_RetriveFromList(i, &LS, &user);

            if (user.accountID == id)
            {
                userpos = i;
                flag = 1;
                break;
            }
        }
        if (flag != 1)
        {
            printf("Account ID does not exist\n\n\n\n");
            goto aa;
        }
        else
        {
            printf("1.Make transaction \n2.Get Cash \n3.Make Deposit \n4.Change password \n0.Go back press 0\n");
            scanf("%d", &account_option);
            if (account_option == 1)
            {
                int receiverpos = -1;
                flag = 0;
                printf("Enter account ID you want to transfer money to\n");
                scanf("%lli", &id);

                for (i = 0; i < List_GetSize(&LS); i++)
                {
                    List_RetriveFromList(i, &LS, &receive);

                    if (receive.accountID == id)
                    {
                        receiverpos = i;
                        flag = 1;
                        break;
                    }
                }
                if (flag != 1)
                {
                    printf("Account ID does not exist\n\n\n\n");
                    goto aa;
                }
                else
                {
                    if (receive.acc_status != 1 || user.acc_status != 1)
                    {
                        printf("Account status is not active\n\n\n\n");
                        goto aa;
                    }
                    else
                    {
                        printf("Enter amount of money:\n");
                        scanf("%f", &money);
                        if (money > user.balance)
                        {
                            printf("Balance is less than amount of money\n\n\n\n");
                            goto aa;
                        }
                        else
                        {
                            user.balance = user.balance - money;
                            receive.balance = receive.balance + money;
                            printf("%s%f", "Your new balance is ", user.balance);
                            List_Replaceintolist(userpos, &LS, user);
                            List_Replaceintolist(receiverpos, &LS, receive);
                            printf("\n\n\n\n");
                            goto aa;
                        }
                    }
                }
            }
            else if (account_option == 2)
            {
                if (user.acc_status != 1)
                {
                    printf("Account status is not active\n\n\n\n");
                    goto aa;
                }
                else
                {
                    printf("Enter amount of money:\n");
                    scanf("%f", &money);
                    if (money > user.balance)
                    {
                        printf("Balance is less than amount of money\n\n\n\n");
                        goto aa;
                    }
                    else
                    {
                        user.balance = user.balance - money;
                        printf("%s%f", "Your new balance is ", user.balance);
                        List_Replaceintolist(userpos, &LS, user);
                        printf("\n\n\n\n");
                        goto aa;
                    }
                }
            }
            else if (account_option == 3)
            {
                if (user.acc_status != 1)
                {
                    printf("Account status is not active\n\n\n\n");
                    goto aa;
                }
                else
                {
                    printf("Enter amount of money:\n");
                    scanf("%f", &money);
                    user.balance = user.balance + money;
                    printf("%s%f", "Your new balance is ", user.balance);
                    List_Replaceintolist(userpos, &LS, user);
                    printf("\n\n\n\n");
                    goto aa;
                }
            }
            else if (account_option == 4)
            {
                char password[50];
                printf("Enter your password\n");
                scanf("%s", &password);
                if (!strcmp(password, user.password))
                {
                    printf("Enter new password\n");
                    scanf("%s", &password);
                    p = strlen(password);
                    for (i = 0; i < p; i++)
                    {
                     
                        if (password[i] >= 'a' && password[i] <= 'z')
                            ++lower_case_count;
                        if (password[i] >= 'A' && password[i] <= 'Z')
                            ++upper_case_count;
                        if (password[i] >= '0' && password[i] <= '9')
                            ++digit_count;
                    }
                    if (lower_case_count > 0 && upper_case_count > 0 && digit_count > 0 && p >= 8)
                    {
                        strcpy(user.password,password);
                        List_Insertinto(List_GetSize(&LS), &LS, client1);
                        printf("Password updated successfully\n\n\n\n");
                        goto mainmenu;
                    }
                    else
                    {
                        printf("invalid password\n\n\n\n");
                        goto mainmenu;
                    }
                }
                else
                {
                    printf("The password you entered is incorrect\n");
                    goto mainmenu;
                }

                // List_Replaceintolist(userpos, &LS, user);
                printf("\n\n\n\n");
                goto mainmenu;
            }
            else if (account_option == 0)
            {
                goto aa;
            }
            else
            {
                printf("Please enter a valid option\n");
                printf("\n\n\n\n");
                goto aa;
            }
        }
    }
    else if (window == 0)
    {
        return 0;
    }
    else
    {
        printf("Please enter a valid option\n");
        printf("\n\n\n\n");
        goto mainmenu;
    }

    return 0;
}
