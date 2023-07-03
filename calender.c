#include <stdio.h>
int getfirstdayofyear(int year)
{
    int day=(year*365+((year-1)/4)-((year-1)/100)+((year-1)/400))%7;
    return day;
}
int main()
{
    char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int i, j, totaldays, weekday = 0, spacecounter,year;
    int daysinmonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   printf("enter your favourite year : ");
    scanf("%d",&year);
   //check leap year
   if((year%4==0&&year%100!=0)||(year%400==0))
    {
        daysinmonth[1]=29;
    }
    weekday=getfirstdayofyear(year);
    for (i = 0; i < 2; i++)
    {
        printf("\n\n\n------------------ %s ---------------------\n", month[i]);//19-22space
        printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n"); // spaces 3 between sun and mon .and 3 space + sun =6 space total.
        for (spacecounter = 1; spacecounter <= weekday; spacecounter++)
        {
            printf("      ");//here is 6 spaces
        }

        totaldays = daysinmonth[i];
        for (j = 1; j <= totaldays; j++)
        {
            printf("%6d", j);///it will print the date (dd) after every 6 spaces
            weekday++;
            if (weekday > 6)
            {
                weekday = 0;
                printf("\n");
            }
        }
    }
    return 0;
}