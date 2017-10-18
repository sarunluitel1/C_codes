/*************************************************/
/* Sarun Luitel */
/* Feb 29, 2016 0*/
/* CS-241 Section 001 */
/* Uses Backtracking recursive method to find*/
/* Solution to any sudoku puzzle. */
/*************************************************/
#include <stdio.h>
#define ERROR 1
/*declare variables and function prototype*/
char cinput;
int inputarray[9][9];
int done=0;
int error=0;
void putarray();
void printarray();
int solvearray(int row,int col);
int rulecheck(int nextint,int row,int col);
void checkarray();
int checkcol(int row);
void checkbox();


int main(void)
{
  /*loop until the EOF is met*/
  while (done==0)
  {
    error=0;
    cinput=getchar();
    /*exit program when EOF is reached*/
    if(cinput==EOF)break;
    putarray();
    /*check if the puzzle has valid numbers*/
    if(error==0) checkarray();
    /* start solving array if no errors found in input*/
    if(error==0)
    {
      /*call solve algorithm with the first row and col to get started*/
      if(solvearray(0,0)==0)
      {
        printf("No solution\n\n");
      }
      else
      {
        printarray();
      }
    }
    if(error==ERROR) printf("ERROR\n\n");/*invalid input*/
  }
  return 1;
}
/*Iterate through all the items and check the rules of sudoku*/
void checkarray()
{
  int row=0;
  int col=0;
  int nextnum=0;
  for(row=0;row<9;row++)
  {
    for(col=0;col<9;col++)
    {
      nextnum=inputarray[row][col];
      /*only check for values if the is number*/
      if(nextnum!=0)
      {  
        inputarray[row][col]=0;
        if(!(rulecheck(nextnum,row,col))){
          error=ERROR;
          
          break;
         }
       /*temporarily make the current block 0 so it doesnot
       check itself and restore value if valid*/
       inputarray[row][col]=nextnum;
      }
    }
  }
}
int solvearray(int row,int col)
{
  /*check if we have come past 81 char to row 10 then exit*/
  int nextnum;
  if(row==9)return 1;

  if(inputarray[row][col])/*check if the current block has a value or not*/
    {
      if(col==8)/*if at the end of column go to next row*/
      {
        if(solvearray(row+1,0))return 1;
      }
      else/*go to next column same row*/
      {
        if(solvearray(row,col+1)) return 1;
      }
      return 0;/*no value to put in current spot*/
    }
  /*check if all values from 1 to 9*/
  for(nextnum=1;nextnum<10;nextnum++)
  {
    /*check if the number fits in the spot. check the sudoku rules*/
    if(rulecheck(nextnum,row,col))
    {
      inputarray[row][col]=nextnum;
      if(col==8) 
      {
        if(solvearray(row+1,0)) return 1;
      }
      else
      {
        if(solvearray(row,col+1)) return 1;
      }
      inputarray[row][col]=0;
    }
  }
  /*returns false if the number from 1-9 cant fit in box resulting in puzzle
   with no solution condition*/
  return 0;	
}
int rulecheck(int nextint,int row,int col)
{
  /*declare variables to check the 4 remaining boxes after row and col check*/
  int i=0;
  int srow = 3*(row/3);
  int scol = 3*(col/3);
  int row1 = (row+2)%3;
  int row2 = (row+4)%3;
  int col1 = (col+2)%3;
  int col2 = (col+4)%3;
  /*check for row and col for the number*/
  for(i=0;i<9;i++)
  {
    if(inputarray[i][col]==nextint)return 0;
    if(inputarray[row][i]==nextint)return 0;
  }
  /*check remaining 4 boxes and return 0 if repetation found*/
  if(inputarray[row1+srow][col1+scol] == nextint) return 0;
  if(inputarray[row2+srow][col1+scol] == nextint) return 0;
  if(inputarray[row1+srow][col2+scol] == nextint) return 0;
  if(inputarray[row2+srow][col2+scol] == nextint) return 0;
  return 1;
}

/*a function with nested for loops to print 2D grid*/
void printarray()
{
  int i=0;
  int j=0;
  for(i=0;i<=8;i++)
  {
    for(j=0;j<=8;j++)
    {
      printf("%d",inputarray[i][j]);
    }
   /*printf("\n"); uncomment to print 2D grid answer*/
  }
  printf("\n\n");
}

/*convert char to int and put them in array also check for few errors*/
void putarray()
{
  int row=0;
  int col=0;
  int varcount=0;/*keep track of number of characters in line*/
  int num;
  /*loop until new line or end of file*/
  while(cinput!=('\n')&&cinput!=(EOF))
  {
    putchar(cinput);
    varcount++;
    /*convert char to int by comparing the ascii values*/
    if(cinput=='.')cinput='0';
    num=cinput-'0';
    cinput=getchar();
    /*check if the character someting besides numbers or '.'*/
    if(num<0||num>9)error=ERROR;
    inputarray[row][col]=num;
    col++;
    /*next row if the column is at the end of array jump to next row reset col*/
    if(col==9)
    {
      row++;
      col=0;
    }
  }
  printf("\n");
  /*show error if the char in a line is not equal to 81*/
  if(varcount!=81)error=ERROR;
}
