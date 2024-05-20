#include<stdio.h>
#include<ctype.h>
#include<string.h>

void encrypt(char text[], int key);
void decrypt(char text[],int key);
char text[500],ch;
    int key;
int main()
{
   
    int choice;
    printf("enter the message that you want to encrypt or decrypt  \n");
    fgets(text,sizeof(text),stdin);
    fflush(stdin);
    printf("enter the shift value \n");
    scanf("%d",&key);
    
    printf("choose an option:\n");
    printf("1.encrypt\n");
    printf("2.decrypt\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        encrypt(text,key);
        break;
        case 2:
        decrypt(text,key);
        break;
        default:
        printf("please enter a valid choice \n");
    }
    return 0;
}  
void encrypt(char text[],int key)
{
    
    for(int i=0;text[i]!='\0';++i)
    {
        ch=text[i];
        if(isalnum(ch))
        {
            if(islower(ch))
            {
                ch=(ch-'a'+key)%26+'a';
            }
            if(isupper(ch))
            {
                ch=(ch-'A'+key)%26+'A';
            }
            if(isdigit(ch))
            {
                ch=(ch-'0'+key)%10+'0';
            }
        }
        
        text[i]=ch;
    }
    printf("the encrypted message is %s",text);
    
}

void decrypt(char text[],int key)
{
    for(int i=0;text[i]!='\0';++i)
    {
        ch=text[i];
        if(isalnum(ch))
        {
            if(islower(ch))
            {
                ch=(ch-'a'-key+26)%26+'a';
            }
            if(isupper(ch))
            {
                ch=(ch-'A'-key+26)%26+'A';
            }
            if(isdigit(ch))
            {
                ch=(ch-'0'-key+26)%10+'0';
            }
        }
        
        text[i]=ch;
    }
    printf("the decrypted message is %s",text);
    
}
    
    
    
