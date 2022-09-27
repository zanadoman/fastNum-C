#include<stdio.h>

double fastNum(char value[]); //fastNum("") serves as a replacement of confusing converting functions for string -> int/double.
double fastNum(char value[])
{   
    double result = 0, powskip = 1; //powskip: local value multiplier (used to skip the pow function). 
    int size = 0, floatingpoint = 1;
    for(;(int)value[size] != 0; size++) powskip *= 10; //Counting digits in the string while setting up the multiplier for the first local value.
    for(int i = 0; i < size; i++)
        if(47 < (int)value[i] && (int)value[i] < 58) //Abusing ascii table.
        {
            powskip /= 10; //Multiplier handling.
            result += ((int)value[i] - 48)*powskip; //Giving real value to the char digit in decimal numbersystem.
        }
        else
            if((int)value[i] == 46) floatingpoint = powskip; //Setting floating divisor if exist.
            else {result = 0; break;} //Invalid character handling.
    return result / floatingpoint; //Applying floating divisor.
}

int main() //Testing fastNum("") function.
{
    char a[11];
    scanf("%s", &a);

    printf("%lf", fastNum(a));

    return 0; 
}