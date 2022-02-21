/*
 ============================================================================
 Name        : example-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int stringLenght(char str[]);
void stringTrim(char str[]);
int extractSubstring(const char* inStr, char* outStr, int beginning, int end);
int concateStrings(char* str1, const char* str2);

int main(void) {


	char* str = "!!!Hello World!!!";
	char str2[20];
	printf("Length of string: %s is: %d\n",str, stringLenght(str));
	char str1[] = "    Remove white spaces     ";
	char str3[100]="First string";
	printf("%s", str1);
	stringTrim(str1);
	printf(" trimed: %s", str1 );
	printf("Added to see removed trailing white spaces.");
	int result = extractSubstring(str, str2, 5, 12);
	if(result)
		printf("\nSubstring from %s is %s", str, str2);
	else
		printf("Check the parameters of function! Something is wrong!");


	if(concateStrings(str3, str2))
		printf("\n%s", str3);
	return 0;

}



int stringLenght(char str[])
{
	int lenght=1;
	int i = 0;
	while(str[i]!= '\0')
	{
		lenght++;
		i++;
	}
	return lenght;
}

void stringTrim(char str[])
{

	int count, i;


	    count = 0;
	    while(str[count] == ' ')
	    {
	        count++;
	    }
	    i = 0;
	    while(str[i + count] != '\0')
	    {
	        str[i] = str[i + count];
	        i++;
	    }
	    str[i] = '\0';


	    i = 0;
	    count = -1;
	    while(str[i] != '\0')
	    {
	        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	        {
	            count = i;
	        }

	        i++;
	    }

	    str[count + 1] = '\0';
}

int extractSubstring(const char* inStr, char* outStr, int beginning, int end)
{
	int lenght = stringLenght((char*)inStr), i,j;
	if((end-beginning) < lenght && beginning < end)
	{
		for (i = beginning, j=0; i < end ; i++,j++)
		{
			outStr[j] = inStr[i];
		}
		outStr[j+1] = '\0';
		return 1;
	}
	else
		return 0;
}

int concateStrings(char* str1, const char* str2)
{
	int i,j;
	int lenght1 = stringLenght(str1);
	int lenght2 = stringLenght((char*)str2);
	int new_size = lenght1 + lenght2 -1;

	for(i = lenght1-1, j = 0; i < new_size; i++, j++)
	{
		str1[i] = str2[j];
	}
	return new_size;
}
