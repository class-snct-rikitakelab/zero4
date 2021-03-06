#include "mymath.h"

/*
 *	各種定義
*/

#define PI 3.141592


float deg2rad(float degree){
	float radian = PI / 180.0 * degree;
	return radian;
}

float rad2deg(float radian){
	float degree = 180.0 / PI * radian;
	return degree;
}

float abs(float value)
{
	float result=0;

	if (value>=0){
	result=value;
	}
	else {
	result = -value;
	}
	
	return result;
}


double mysin(double x)
{
double EPS = 1e-08; /* 項の値がこれより小さくなったらループ終了 */
double s = 0.0; /* 求める sin 値 */
int k; /* 項数 */
int n; /* 級数（1, 3, 5, 7, ...） */
int sign = 1; /* 加算か減算かのための変数。1項ごとに符号が反転 */
double diff; /* 項の値 (x^n/n!)*sign */
int i; /* ループ用の変数 */

k = 1;
for (; ;) {
n = 2 * k - 1;
diff = 1.0;
/* x^n / n! */
for (i = 1; i <= n; i++)
{
diff *= x / i;
}
if(diff < EPS) {
break;
}
/* + or - */
diff *= sign;
s += diff;
k++;
sign *= -1;
}
return s;
}

double mycos(double x)
{
	return my_sin(PI / 2 - x);
}



double my_sin(double x)
{
  double result1, result2, result;
  int n;

  result1 = 0;
  result2 = 0;

  //ループを回す回数(ここでは5)を大きくすると精度が上がります
  for(n = 1;n <= 3;n++)
    {
      result1 += my_pow(x, 4 * n - 3) / fact(4 * n - 3);
    }


  //ループを回す回数(ここでは5)を大きくすると精度が上がります
  for(n = 1; n <= 3;n++)
    {
      result2 += my_pow(x, 4 * n - 1) / fact(4 * n - 1);
    }

  result =  result1 - result2;

  return result;
}

//xのn乗を計算する関数
double my_pow(double x, int n)
{
  int i;
  double pow_result = 1;

  if(n == 0)
    return 1;
  else
    {
      for(i = 0;i < n;i++)
	{
	  pow_result *= x;
	}
      return pow_result;
    }
}

//xの階乗を計算する関数

int fact(int n)
{
  int i, result = 1;

  if(n == 0)
    return 1;
  else
    {
      for(i = 1;i <= n;i++)
	{
	  result *= i;
	}
      return result;
    }
}
