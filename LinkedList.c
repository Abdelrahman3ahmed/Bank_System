/*  Author :    Abdelrahman Ahmed Ragab  */
/*  Implement List Linked Based     */
/* Version : 1    Last Modified :   28-12-2021  */

#include <stdio.h>
#include <stdlib.h>

typedef struct client {
  char  name [50];
  long long int ID; //national ID
  char Address [50];
  int Age ;
  long long int accountID;
  char gaurdian [50] ;
  long long int gardiuan_national_ID ;
  int acc_status ;
  float balance ;
  char password [50] ;
} Client ;

typedef Client Data_Type;

typedef struct listNode
{
    Data_Type Data;
    struct listNode * Nextptr;
}ListNode;

typedef struct list
{
    struct listNode * Head;
    int Size_ofList;

}List;

void List_Init(List* PtrList);
void List_Insertinto(int Pos, List* PtrList, Data_Type InsertedVal);
void List_RetriveFromList(int Pos, List* PtrList, Client* RetrivedVal);
void List_Replaceintolist(int Pos, List* PtrList, Client ReplcedVal);
void List_DeleteFromList(int Pos, List* PtrList, Client* DeletedVal);
int  List_isfull(List* PtrList);
int  List_isempty(List* PtrList);
int  List_GetSize(List* PtrList);
void Print_List(List* PtrList);
void Destroy_wholeList(List* PtrList);




/*int main()
{
    List LS;
    List_Init(&LS);
    int x=5; int y=0;
    List_Insertinto(y , &LS ,x); 
    Print_List(&LS);
    printf("\n\n\n");
    x = 2;
    List_Insertinto(y , &LS , x); 
    x = 4;
    y=1;
    Print_List(&LS);
    printf("\n\n\n");
    List_Insertinto(y , &LS ,x);
     x =3;
    Print_List(&LS);
    printf("\n\n\n");
    List_Insertinto(y , &LS ,x);
    Print_List(&LS);

    y=2;
    List_RetriveFromList(y , &LS , &x);
    printf("ret  %d\n" , x);



    y=0; x=10;
    List_Replaceintolist(y , &LS , x);
    Print_List(&LS);
    
    printf("\n\n\n");

    y=1; 
    List_DeleteFromList(y , &LS , &x);
    Print_List(&LS);
    printf("del  %d\n" , x);


    printf("\n\n\n");
    Destroy_wholeList(&LS);
    Print_List(&LS);

    return 0;
}*/


void List_Init(List* PtrList)
{
    PtrList->Head = NULL;
    PtrList->Size_ofList = 0;
}
void List_Insertinto(int Pos, List* PtrList, Data_Type InsertedVal)
{
    
    ListNode *NewNode = (ListNode *)malloc(sizeof(ListNode));
    NewNode->Data = InsertedVal;
    NewNode->Nextptr = NULL;
    

    if(Pos == 0 )
    {
        NewNode->Nextptr = PtrList->Head;
        PtrList->Head = NewNode;

    }
    else
    {
        ListNode *Tmp;
        Tmp = PtrList->Head;
        for(int i=0;i<Pos-1;i++)
        {
            Tmp = Tmp->Nextptr;
        }
        NewNode->Nextptr = Tmp->Nextptr;
        Tmp->Nextptr = NewNode;

        
    }
    PtrList->Size_ofList++;

}
void List_RetriveFromList(int Pos, List* PtrList, Client* RetrivedVal)
{
    //Different Implementations
    /*int i;
    ListNode* tmp;

    for(i=0 , tmp= PtrList->Head; i< Pos; i++)
    {
        tmp = tmp->Nextptr;
    }
    *RetrivedVal= tmp->Data;*/


    if(Pos == 0 )
    {
        *RetrivedVal = PtrList->Head->Data;
        
    }
    else
    {
        ListNode *Tmp;
        Tmp = PtrList->Head;
        for(int i=0;i<Pos-1;i++)
        {
            Tmp = Tmp->Nextptr;
        }
        *RetrivedVal = Tmp->Nextptr->Data;

        
    }
}
void List_Replaceintolist(int Pos, List* PtrList, Client ReplcedVal)
{
    int i;
    ListNode* tmp;

    for(i=0 , tmp= PtrList->Head; i< Pos; i++)
    {
        tmp = tmp->Nextptr;
    }
    tmp->Data = ReplcedVal;

    /*if(Pos == 0 )
    {
        PtrList->Head->Data = ReplcedVal;
        
    }
    else
    {
        ListNode *Tmp;
        Tmp = PtrList->Head;
        for(int i=0;i<Pos-1;i++)
        {
            Tmp = Tmp->Nextptr;
        }
        Tmp->Nextptr->Data = ReplcedVal;

        
    }*/
}
void List_DeleteFromList(int Pos, List* PtrList, Client* DeletedVal)
{

    ListNode *Tmp , *Tmp1;
    
    if(Pos == 0 )
    {
        *DeletedVal = PtrList->Head->Data;
        Tmp = PtrList->Head->Nextptr;
        free(PtrList->Head);
        PtrList->Head = Tmp;
        
    }
    else
    {
        
        Tmp = PtrList->Head;
        for(int i=0;i<Pos-1;i++)
        {
            Tmp = Tmp->Nextptr;
        }
        *DeletedVal = Tmp->Nextptr->Data;
        Tmp1 = Tmp->Nextptr->Nextptr;
        free(Tmp->Nextptr);
        Tmp->Nextptr = Tmp1;
        
    }
    PtrList->Size_ofList--;
}
int  List_isfull(List* PtrList)
{
    return 0;
}
int  List_isempty(List* PtrList)
{
    return (PtrList->Head == NULL);
}
int  List_GetSize(List* PtrList)
{
    return PtrList->Size_ofList;
}
void Print_List(List* PtrList)
{
    if(List_isempty(PtrList))
    {

        printf("List is empty no elments to print \n");
    }
    else
    {
        ListNode *Tmp;
        Tmp = PtrList->Head;
        for(;Tmp != NULL ;)
        {
            printf("Element of list is %d\n", Tmp->Data);
            Tmp = Tmp->Nextptr;
        }
    }
    
    

}
void Destroy_wholeList(List* PtrList)
{
    if(List_isempty(PtrList))
    {

        printf("List is empty no elments to Delete \n");
    }
    else
    {
        ListNode *Tmp;
        Tmp = PtrList->Head;
        while(PtrList->Head != NULL)
        {
            Tmp = Tmp->Nextptr;
            free(PtrList->Head);
            PtrList->Head = Tmp;
            
        }
        PtrList->Head = NULL;
        PtrList->Size_ofList = 0;
    }
}