//------------------------------------------------------------------
// File name:   EmployeeBTree.cpp
// Assign ID:   Project 3 
// Due Date:    2/13/18 at 12:30 pm
//
// Purpose:     Write a C++ program that inputs an unknown number of records stroed on a sequential file.
//              Write a C++ program to insert the records into a Binary Tree by account number. Then, print 
//              the records in 4 seperate reports: Report 1 - is printed in InOrder, Report 2 - is printed in 
//              PreOrder, and Report 3 - is printed in PostOrder. The 4th Report will print the records sorted
//              (implement the quick sort algorithm) by lastname, the format for this report.
//       
// Author:      Tishauna Wilson
//------------------------------------------------------------------
#include "EmployeeData.cpp"
using namespace std;

int main()
{
   //Declare Variables
   AccessRecords Data; 

   //-| ----------------------------------------------------------------------
   //-| Print the copyright notice declaring authorship.
   //-| ----------------------------------------------------------------------
   cout << endl << "(c) 2018, Tishauna Wilson" << endl << endl; 

   //-| ----------------------------------------------------------------------
   //-| 1. Call ReadRecord() Function
   //-| ----------------------------------------------------------------------
   Data.ReadRecord();

   //-| ----------------------------------------------------------------------
   //-| Print the copyright notice declaring authorship again.
   //-| ----------------------------------------------------------------------
   cout << endl << "(c) 2018, Tishauna Wilson" << endl << endl; 

   return 0;
}//main
