#include "MyString.h"
int pow_10(int n);
double pow_10_inverse(int n);

float my_atof(char *string){

	int i, j, temp1, temp2, sa;
  int figure1, figure2, number1 = 0;
  double number, number2 = 0;

  sa = '0' - 0;
  figure1 = 0;
  figure2 = 0;

 //®”•”•ª‚ÌŒ…”‚ð”‚¦‚é
  for(i = 0;string[i] != '\0';i++)
    {
      if(string[i] >= '0' && string[i] <= '9')
	figure1++;
      else
	break;
    }

  temp1 = figure1;

  if(string[i] == '.')
    {
	//¬”•”•ª‚ÌŒ…”‚ð”‚¦‚é
      for(i += 1;string[i] != '\0';i++)
	{
	  if(string[i] >= '0' && string[i] <= '9')
	    figure2++;
 	  else
	    break;
	}
    }

  temp2 = figure2;

//•¶Žš—ñ‚Ì®”•”•ª‚ð®”‚É•ÏŠ·‚·‚é
  for(i = 0;i < figure1;i++, temp1--)
    {
      string[i] -= sa;
      number1 += string[i] * pow_10(temp1 - 1);
    }

  //•¶Žš—ñ‚Ì¬”•”•ª‚ð¬”‚É•ÏŠ·‚·‚é
  for(i = figure1 + 1 , j = 1;i < figure1 + figure2 + 1;i++, j++)
    {
      string[i] -= sa;
      number2 += string[i] * pow_10_inverse(j);
    }

//®”‚Æ¬”‚ð‰Á‚¦,•‚“®¬”“_”‚Ì•¶Žš—ñ‚ð”Žš‚É•ÏŠ·‚·‚é
  number = number1 + number2;
  
  return number;

}

//0.1‚Ìnæ‚ðŒvŽZ‚·‚éŠÖ”
double pow_10_inverse(int n)
{
  int i;
  double result = 1;

  if(n == 0)
    return 1;
  else
    {
      for(i = 0; i < n;i++)
	{
	  result *= 0.1;
	}
      return result;
    }
}

//10‚Ìnæ‚ðŒvŽZ‚·‚éŠÖ”
int pow_10(int n)
{
  int i, result = 1;

  if(n == 0)
    return 1;
  else
    {
      for(i = 0; i < n;i++)
	{
	  result *= 10;
	}
      return result;
    }
}


int my_strcmp(char *str1, char *str2)
{

  int i;



  for(i = 0;*(str1 + i) == *(str2 + i);i++)

    {

      if(*(str1 + i) == '\0')

        return 0;

    }

  

  return *(str1 + i) - *(str2 + i);

} 