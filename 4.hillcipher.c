#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX_SIZE 100

int is_valid_key(int key[MAX_SIZE][MAX_SIZE],int size)
{
    int det=0;
    if(size==2)
    {
        det=key[0][0]*key[1][1]-key[0][1]*key[1][0];
    }
    else if(size==3)
    {
        det=key[0][0]*(key[1][1]*key[2][2]-key[1][2]*key[2][1])-
        key[0][1]*(key[1][0]*key[2][2]-key[1][2]*key[2][0])+
        key[0][2]*(key[1][0]*key[2][1]-key[1][1]*key[2][0]);
    }
    return det!=0;
}

void preprocess(char *message)
{
    int len=strlen(message);
    int j=0;
    for(int i=0;i<len;i++)
    {
        if(isalpha(message[i]))
        {
            message[j++]=toupper(message[i]);
        }
    }
    message[j]='\0';
}

void hillencrypt(char *message,int key[MAX_SIZE][MAX_SIZE],int size)
{
    int len=strlen(message);
    int i,j,k,sum;
    int plain[MAX_SIZE];
    
    while(len % size!=0)
    {
        message[len++]='X';
    }
    message[len]='\0';
    
    for(i=0;i<len;i+=size)
    {
        for(j=0;j<size;j++)
        {
            plain[j]=message[i+j]-'A';
        }
        
        for(j=0;j<size;j++)
        {
            sum=0;
            for(k=0;k<size;k++)
            {
                sum+=key[j][k]*plain[k];
            }
            message[i+j]=(sum % 26)+'A';
        }
        
    }
}

int main()
{
    int key[MAX_SIZE][MAX_SIZE];
    char message[100];
    int size,i,j,k;
    
    printf("enter the size of the matrix\n");
    scanf("%d",&size);
    
    printf("enter the key matrix\n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            scanf("%d",&key[i][j]);
        }
    }
    if(!is_valid_key(key,size))
    {
        printf("please enter a valid matrix\n");
        return 1;
    }
    
    printf("enter the message that you want to encrypt\n");
    getchar();
    fgets(message,sizeof(message),stdin);
    message[strcspn(message,"\n")]='\0';
    
    preprocess(message);
    hillencrypt(message,key,size);
    printf("the encrypted message is %s\n",message);
    return 0;
}


















