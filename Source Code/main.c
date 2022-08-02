#include <stdio.h>
#include <stdlib.h>



const int maxSize=32;
int main()
{
    menu();
}
void menu(){
    int length;
    char c;
         printf("\t\t----------------Hello To Password Generator----------------\n");
     do{
        printf("\t\tEnter length of your password (must be between 16 and 32):");
        scanf("%d",&length);
    }while(length<16 || length>32);
    PasswordGenerator(length);
    printf("\t\tDo you want to generate another password?(y:yes or n:no):");
    do{
    scanf("%c",&c);
    }while(c!='y' && c!='n');
        if(c=='y')
        {
            system("cls");
            main();
        }else system("EXIT");
}
void PasswordGenerator(int l){
    FILE *fp;
    char Password[maxSize];
    char Account[maxSize];
    srand(time(0));
    for(int i=0;i<l;i++)
      {
      int k=rand()%128;
       if((k>=48&&k<=57)||(k>=65&&k<=90)||(k>=97&&k<=122)||(k>=35&&k<=37)||k==64)
       {
        Password[i]=k;
        }
        else
        {
         i--;
        }
        Password[l]='\0';
      }
      printf("\t\tEnter Name of Account for this password:");
        scanf("%s",&Account);
      fp = fopen("password.txt","a+");
      fprintf(fp, "%s:%s\n",Account,Password);
      printf("\t\tPassword generate successfully :)\n");
}
