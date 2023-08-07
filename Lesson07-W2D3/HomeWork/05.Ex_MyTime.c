#include <stdint.h>
#include <stdio.h>

const int SECONDS_MIN =60;
const int SECONDS_HOUR= 60*SECONDS_MIN;
const int SECONDS_DAY =24*SECONDS_HOUR;
const int DAY_YEAR =365;
const int SECONDS_YEAR =DAY_YEAR*SECONDS_DAY;


typedef struct T
{
    short type;
}T;


// Structure my time
typedef struct MyTime {
  // year
 uint16_t  year;    //unsigned short
  // month
    uint8_t month;  
  // day
     uint8_t day;   
  //hour
    uint8_t hour;   
  //minutes
    uint8_t minute; 
  //seconds
   uint8_t second; 

//Като резулта и двата типа върщат едни и същи размер 12.

} MyTime;

//Is leap year
int isLeapYear(MyTime t)
{
    return (t.year % 4 == 0 && t.year % 100!= 0) || t.year % 400 == 0;
}

//Count of days on year
int totalDaysInYear(MyTime t)
{
    return isLeapYear(t)? 366 : 365;
    //if year is leap year days are 366
    //if year is not leap year days are 365
}

//Print string month
void printMonth(MyTime t)
{
    switch (t.month)
    {
        case 1:
            printf("January\n");
            break;
        case 2:
            printf("February\n");
            break;
        case 3:
            printf("March\n");
            break;
        case 4:
            printf("April\n");
            break;
        case 5:
            printf("May\n");
            break;
        case 6:
            printf("June\n");
            break;
        case 7:
            printf("July\n");
            break;
        case 8:
            printf("August\n");
            break;
        case 9:
            printf("September\n");
            break;
        case 10:
            printf("October\n");
            break;
        case 11:
            printf("November\n");
            break;
        case 12:
            printf("December\n");
            break;
        

    }
}

//Get the seconds of the 1970 1 janyary to current date.
int secondPassed(MyTime t)
{   
    //!!!! Ако искаме резултатите да бъдат по прецизни и точни трябва да приемем месеците както са в масив (30,28,31....) като трябва да проверим  колко на борй високосни годни от дата 1970 до зададената дата.Броя на дните трябва да се предвиди че е 365,256363 дена. Както и точната стойност на един астрономически час (23 часа 56 минути 4 секунди))
    int total = 0;

    //Get seconds from years
    total += (t.year - 1970)*SECONDS_YEAR;

    //Get seconds from months
    total+=DAY_YEAR*SECONDS_DAY;

    //Get seconds from days
    total += t.day*SECONDS_DAY;

    //Get seconds from hours
    total += t.hour*SECONDS_HOUR;

    //Get seconds from minutes
    total += t.minute*SECONDS_MIN;

    //Get seconds from seconds
    total += t.second;

    return total;
    
}

int main() {
    //Input parameters in struct
    MyTime t;
    t.year = 2023;
    t.month = 12;
    t.day = 31;
    t.hour = 23;
    t.minute = 59;
    t.second = 59;

     //Print size of structure  
    printf("Size of structur: %lu\n", sizeof(MyTime));

    //Print the struct
    printf("The date is %d-%d-%d %d:%d:%d\n", t.year, t.month, t.day, t.hour, t.minute, t.second);

    //Check if the year is a leap year
    printf("Leap result: %d\n", isLeapYear(t)); //return 1 if leap year or return 0 if is not a leap year
    // if (isLeapYear(t)) {
    //     //printf("The year %d is a leap year\n", t.year);
    // } else {
    //     //printf("The year %d is not a leap year\n", t.year);
    // }

    //Print count days of the year
    printf("Total days are: %d\n", totalDaysInYear(t));

    //Print month
    printf("Month: ");
    printMonth(t);

    //Print seconds of day about range [1970, current date] приблизителна стойност за повече инф. да се прочете коментара към функцията.
    printf("Seconds passed: %d\n", secondPassed(t));

    return 0;
}


 