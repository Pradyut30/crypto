#include<stdio.h>

long long int power(long long int base,long long int exp,long long int modulus)
{
    long long result=1;
    while(exp>0)
    {
        if(exp%2==1)
        result=(result * base)%modulus;
        base=(base * base)%modulus;
        exp=exp/2;
    }
    return result;
}

long long int encrypt(long long int plaintext,long long int e,long long int n)
{
    return power(plaintext,e,n);
}

long long int decrypt(long long int ciphertext,long long int d,long long int n)
{
    return power(ciphertext,d,n);
}

int main()
{
   long long int p,q,e,d=1;
    printf("enter the first prime number\n");
    scanf("%lld",&p);
    
    printf("enter the second prime numer\n");
    scanf("%lld",&q);
    
    long long int n=p*q;
    long long int phi=(p-1)*(q-1);
    
    printf("enter the public exponent \n");
    scanf("%lld",&e);
    
    while((d*e)%phi!=1)
    {
        d++;
    }
    long long plaintext;
    printf("enter the plaintext\n");
    scanf("%lld",&plaintext);
    
    long long int ciphertext=encrypt(plaintext,e,n);
    
    printf("the encrypted text is %lld \n",ciphertext);
    
    long long int decryptedtext=decrypt(ciphertext,d,n);
    
     printf("the dncrypted text is %lld",decryptedtext);
    return 0;
    
}
