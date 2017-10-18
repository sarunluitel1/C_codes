/*************************************************/
/* Sarun Luitel */
/* March 20, 2016 0*/
/* CS-241 Section 001 */
/* Performs number conversion */
/*************************************************/
#include<stdio.h>
#include<math.h>
/*decaration of the prototype of the functions*/
int dectobin(unsigned long number,int bits);
int bintodec(unsigned long number,int bits);
void usage();
int bitsindec(int n);
/*main functions that has argc that counts the paramerters and args[] that has adresses*/
int main(int argc, char *args[])
{
  int bits=0;
  unsigned long number=0;
  int i=1,temp=0,count=0,index=0;
  /*checking if the parameter numbers are correct*/
  if(argc!=4)
  {
    printf("ERROR: incorrect number of arguments\n");
    usage();
    return 0;
  }/*return from main to terminate program once error is found*/

  /*go through the elements of the arrays as 2d arrays*/
  /*loop through the elements until null pointer convert the char to ints*/
  while(args[1][i]!='\0')
  {
    bits=bits*10+(args[1][i]-'0');
    i++;
  }
  /*check for the arguement validity*/
  if(bits!=8&&bits!=16&&bits!=32&&bits!=64)
  {
    printf("ERROR: argument 1 must be: -8 | -16 | -32 | -64\n");
    usage();
    return 0;
  }
  i=0;
  while(args[3][i]!=0)
  {
    temp=args[3][i]-'0';
    if(temp<0||temp>9) 
    {
      printf("ERROR: argument 3 is not a decimal integer\n");
      usage();
      return 0;
    }
    /*convert the char binary character to decimal*/
    if(args[2][1]=='b')
    {
      number=number*2+temp;          ;
      if(temp!=0&&temp!=1)
      {
        printf("ERROR: argument 3 is not a binary integer\n");
        usage();
        return 0;         
    }
  }  
  if(args[2][1]=='d')number=number*10+temp;
  count--;   
  i++;
  }
  /*Go to the function according to the poarameters*/
  if(args[2][1]=='b')bintodec(number,bitsindec(bits));
  if(args[2][1]=='d')dectobin(number,bits);
  if(args[2][1]!='d'&&args[2][1]!='b')
  {
    printf("ERROR: argument 2 must be -b | -d\n");
    usage();
    return 0;
  }
  return 0;
}
/*decimal to binary returns int takes in parameters unsigned long and int*/
int dectobin(unsigned long number,int bits)
{
  /*an array to hold the converted numbers with blank spaces for easy formatting*/
  int array[bits+1]; 
  int rem=0, index=1,output=0,j,i;
  for(j=0;j<bits;j++)array[j]=0;
  j=bits-1;
  /*convert decimal to binary and store it in an array*/
  while(number!=0)
  {
    rem=number%2;
    number=number/2;
    output=output+rem*index;
    array[j]=rem;
    index=index*10;
    j--;
  }
  i=0;
  for(j=0;j<bits;j++)
  {
    if (i==4)
    {
      printf(" ");
      i=0;
    }
    i++;
    printf("%d",array[j]);
  }
  printf("\n");
  return output;
}
/*function binary to decimal takes the input number and bits capacity*/
int bintodec(unsigned long number,int bits)
{
  int array[bits+1];
  int rem=0,output=0,j,temp;
  for(j=0;j<bits;j++)array[j]=0;

  temp=number;
  j=bits-1;
  while(temp!=0)
  {
    rem=temp%10;
    temp=temp/10;
    array[j]=rem;
    j--;
  }
  temp=0;
  /*This loop prints out the calclated numbers from the array and puts spaces until a number is*/
  /*found and puts commas when the mod 3 is 0 after the number is found*/
  for(j=0;j<bits;j++)
  {
    if(array[j]!=0)temp=j;
    if(array[j]==0&&temp==0)printf(" ");
    if(array[j]!=0||temp!=0)printf("%d",array[j]);
    if(temp!=0&&(bits-1-j)%3==0&&(bits-1-j)>0)printf(",");  
  }
  printf("\n");
  return output;
}
/*This bits in decimals returns the possible digits place for a decimal number given the */
/*binary capasity of the input*/
int bitsindec(int n)
{
  if(n==8) return 3;
  if(n==16) return 5;
  if(n==32) return 10;
  if(n==64) return 20;
  return 0;
}
/*void procedure that takes no parameters and prints out the usage text*/
void usage()
{
  printf("usage:\n");
  printf("./binary SIZE OPTION NUMBER\n");
  printf("  SIZE:\n");
  printf("    -8    input is an unsigned 8-bit integer.\n");
  printf("    -16   input is an unsigned 16-bit integer.\n");
  printf("    -32   input is an unsigned 32-bit integer.\n");
  printf("    -64   input is an unsigned 64-bit integer.\n");
  printf("\n");
  printf("  OPTION:\n");
  printf("    -b    NUMBER is binary and output will be in decimal.\n");
  printf("    -d    NUMBER is decimal and output will be in binary.\n");
  printf("\n");
  printf("  NUMBER:\n");
  printf("    number to be converted.\n");
}
