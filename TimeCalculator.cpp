#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include <windows.h>

using namespace std;

void printLogo()
{
   cout << "\033[33m"
        << " ______   __     __    __     ______    \n"
        << "/\\__  _\\ /\\ \\   /\\ \"-./  \\   /\\  ___\\   \n"
        << "\\/_/\\ \\/ \\ \\ \\  \\ \\ \\-./\\ \\  \\ \\  __\\   \n"
        << "   \\ \\_\\  \\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\ \n"
        << "    \\/_/   \\/_/   \\/_/  \\/_/   \\/_____/ \n"
        << "                                        \n"
        << "\033[0m";
}

void clearTerminal()
{
   system("cls");
   printLogo();
}

string printTime(int hour, int min)
{
   stringstream ss;
   ss << setfill('0') << setw(2) << hour << ":"
      << setfill('0') << setw(2) << min;
   return ss.str();
}

void GetTime(int &hour, int &min)
{
   bool isValid;

   do
   {
      clearTerminal();
      cout << "\033[33m" << "Enter the time :" << "\033[0m" << endl;
      cout << "\033[32m" << "  Hour :" << "\033[0m";
      cin >> hour;
      cout << "\033[32m" << "  Min:" << "\033[0m";
      cin >> min;

      if (hour >= 0 && hour <= 24 && min >= 0 && min <= 60)
         isValid = true;
      else
      {
         Beep(698, 500);
         isValid = false;
      }

   } while (!isValid);

   Beep(587, 100);
}

void GetOperator(int &choice)
{

   bool isValid = true;

   do
   {
      clearTerminal();
      cout
          << "\033[33m" << "Enter the choice :\n1 : Add\n2 : Subtract\n " << "\033[0m" << "\033[32m" << "Choice : " << "\033[0m";
      cin >> choice;

      if (choice == 1 || choice == 2)
         isValid = true;
      else
      {
         Beep(698, 500);
         isValid = false;
      }
   } while (!isValid);
   Beep(587, 100);
}

void calculate(int &hour, int &min, int &day, int hour1, int min1, int hour2, int min2, int choice)
{
   if (choice == 1)
   {
      hour = hour1 + hour2;
      min = min1 + min2;
      if (min >= 60)
      {
         min = 0;
         hour++;
      }
      if (hour >= 24)
      {
         hour = 0;
         day = 1;
      }
      else
         day = 0;
   }

   else
   {
      hour = hour1 - hour2;
      min = min1 - min2;
      if (min < 0)
      {
         min *= -1;
         hour--;
      }
      if (hour < 0)
      {
         hour *= -1;
         day = -1;
      }
      else
         day = 0;
   }
   Beep(1500, 200); // High beep
   Beep(800, 300);  // Mid beep
   Sleep(100);      // Brief pause
   Beep(1200, 150); // Quick high beep
   Beep(600, 500);  // Long low beep
}

void printResult(int day, int hour, int min)
{
   clearTerminal();
   cout << "\033[32m";
   switch (day)
   {
   case -1 /* constant-expression */:
      cout << "\n\nDay:- Yesterday  [";
      break;
   case 0:
      cout << "\n\nDay:- Today [";
      break;
   case 1:
      cout << "\n\nDay:- Tomorrow [";
      break;

   default:
      break;
   }

   cout << printTime(hour, min) << "]\n\n"
        << "\033[0m" << endl;

   system("pause");
}

int main()
{
   int hour1, min1, hour2, min2, choice;

   GetTime(hour1, min1);
   GetOperator(choice);
   GetTime(hour2, min2);

   int hour, min, day;

   calculate(hour, min, day, hour1, min1, hour2, min2, choice);
   printResult(day, hour, min);
}