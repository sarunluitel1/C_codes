
/* Sarun Luitel */
/* This Code counts the number of lines and characters in the total file. */
/* outputs the number of characters in a line*/
/* CS-241 Section 001 */
# include <stdio.h>
int main(void)
{
  int tLines,tWords,tChar,lChar,tempLine,tempChar;
  int tempWords,maxChar,mLword,mLchar,maxWord;
  tWords=tempWords=mLword=mLchar=maxWord=maxChar=0;
  tLines=tWords=lChar=tChar=lChar=tempLine=tempChar=0;

  printf("%i:",1);
  tLines++;
  while((tempLine=getchar()) != EOF)
	{
	  tempChar++;
      if(tempLine== '\n')
		{
		  tLines++;
           
		  printf("(%i,%i)",tempChar,tempWords);
		  maxWord=tempWords;
		  maxChar=tempChar;
		  tempChar=0;
		  tempWords=0;
		  tempChar--;
		  tChar--;
		  
        }
        if(tempLine!='\n')
          {
		    putchar(tempLine);
		    
      
            ++tChar;
          }
	
		  
         if(tempLine==' '||tempLine=='\n'||tempLine=='\t')
		   {
			 tWords++;
			 tempWords++;
		   } 
	if(tempLine=='\n')
	  {
		printf("\n%i:",tLines);
	
	  }
	if(maxWord<tempWords)maxWord=tempWords;
	if(maxChar<tempChar)maxChar=tempChar;
     }

  printf("%i lines, %i words, %i Characters\n",tLines,tWords,tChar);
  printf("Max Word %i  Max Char %i\n",maxWord,maxChar);
 
}
