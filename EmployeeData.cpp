#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
#include "EmployeeData.h"

//Read Records From File & Send To Insert Insert into Binary Tree by Account #
void AccessRecords :: ReadRecord()
{
	//Declare Variables
	ifstream inF;
        int acct_number3 = 0; 
	string last_name3 = "", first_name3 = "", phone_number3 = "";
	char middle_initial3 = ' ', dept_code3 = ' '; 
	unsigned int month3 = 0, day3 = 0, year3 = 0;
	float annual_salary3 = 0.00;
	ofstream OutF("InOrder.txt");
        ofstream OutF1("PreOrder.txt");
	ofstream OutF2("PostOrder.txt");
	ofstream OutF3("QuickSort.txt");
	
	//Assign Root to NULL
	Root = NULL;
	
	//Initialize TotalRecords && TotalSalary to 0
	TotalRecords = 0;
	TotalSalary = 0.00;
	
	//Open Up File
	inF.open("binary_tree_data.txt");
	
	//Test File For Error
	if(inF.fail())
	{
	   cout << endl << "FATAL ERROR: UNABLE TO OPEN FILE \"binary_tree_data.txt\". TERMINATING..."
                << endl << endl;
           exit (1);
	}//if
	else
	{
		//Read in Data from File
		while(inF >> acct_number3 >> last_name3 >> middle_initial3 >> first_name3 >> month3 
			  >> day3 >> year3 >> annual_salary3 >> dept_code3 >> phone_number3)
		{
			//Check to see if the Account Number or the Annual Salary is Negative
			if(acct_number3 < 0 || annual_salary3 < 0.00)
				continue;
			
			//Else, add the data to its respective vector & send the data to Insert() function
			else
			{
				//Add 1 to TotalRecords
				TotalRecords++;
					
				//Capitalize dept_code3
				dept_code3 = toupper(dept_code3);
				
				//Capitalize First Letter in Last Name & First Name To Insure QuickSort Sorts The Last Names Correctly
				last_name3[0] = toupper(last_name3[0]);
				first_name3[0] = toupper(first_name3[0]);
				
				//Add Salary to TotalSalary
				TotalSalary = TotalSalary + annual_salary3;

				//Add Last Name to Last_Name vector
				Last_Name.push_back(last_name3);
				
				//Add First Initial to First_Initial vector
				First_Initial.push_back(first_name3[0]);
				
				//Add Annual Salary to Annual_Salary vector
				Annual_Salary.push_back(annual_salary3);
				
				//Add Phone Number to Phone_Number vector
				Phone_Number.push_back(phone_number3);
				
				//Add Department Code to Department_Code vector
				Department_Code.push_back(dept_code3);
				
				//Send Data to Insert() Funtion
				Insert(Root, acct_number3, last_name3, middle_initial3, first_name3, month3, day3, year3, 
				       annual_salary3, dept_code3, phone_number3);
			}//else
		}//while
						
		//Close the InF File
		inF.close();
		
		//Call PrintSubtitles, PrintInOrder(OutF,node *PtrRoot), TotalRecordsProcessed & Close the OutF File
		PrintSubtitles(OutF);
		PrintInOrder(OutF,Root);
		TotalRecordsProcessed(OutF);
		OutF.close();
		
		//Call PrintSubtitles, PrintPreOrder(OutF1, node *PtrRoot), TotalRecordsProcessed & Close the OutF1 File
		PrintSubtitles(OutF1);
		PrintPreOrder(OutF1,Root);
		TotalRecordsProcessed(OutF1);
		OutF1.close();
		
		//Call PrintSubtitles, PrintPostOrder(OutF2, node *PtrRoot), TotalRecordsProcessed & Close the OutF2 File
		PrintSubtitles(OutF2);
		PrintPostOrder(OutF2,Root);
		TotalRecordsProcessed(OutF2);
		OutF2.close();
		
		//Call QuickSort, PrintQuickSort(OutF3) & Close the OutF3 File
		QuickSort(Last_Name, First_Initial, Annual_Salary, Phone_Number, Department_Code, (0), (TotalRecords-1));
		PrintQuickSort(OutF3);
		OutF3.close();
	}//else
}//ReadRecord

//Insert Recieved Data into Binary Tree by Account #
void AccessRecords :: Insert(node *& PtrRoot,int acct_number2, string last_name2, char middle_initial2,
			     string first_name2, unsigned int month2, unsigned int day2, unsigned int year2, 
			     float annual_salary2, char dept_code2, string phone_number2)
{
	//if Root == NULL, create new node with Data
	if(PtrRoot == NULL)
		PtrRoot = new node(acct_number2, last_name2, middle_initial2, first_name2,  month2, day2, year2, annual_salary2, 
				   dept_code2, phone_number2);

	//else if, given acct_number2 is less than the root node, then, call for left subtree, else, call for right subtree
	else if(acct_number2 < PtrRoot->acct_number)
		Insert(PtrRoot->left_child, acct_number2, last_name2, middle_initial2, first_name2, month2, day2, year2, annual_salary2, 
		       dept_code2, phone_number2);
	
	else if(acct_number2 > PtrRoot->acct_number)    //acct_number2 >= PtrRoot->acct_number
		Insert(PtrRoot->right_child, acct_number2, last_name2, middle_initial2, first_name2, month2, day2, year2, annual_salary2, 
		       dept_code2, phone_number2);
}//Insert

//Convert The Month # into Abbreviation
string AccessRecords :: DateConversion(int Month)
{
	//Declare Array of Month Abbreviations
	const string DateAbbr[12] = {"Jan. ", "Feb. ", "Mar. ", "Apr. ", 
		                     "May ", "Jun. ", "Jul. ", "Aug. ", 
				     "Sep. ", "Oct. ", "Nov. ", "Dec. "};
	
   //Use Switch to return the respective Date Abbreviation
   switch(Month)
   {
	   case 1: return DateAbbr[0];
		           break;
	   case 2: return DateAbbr[1];
		           break;
	   case 3: return DateAbbr[2];
		           break;
	   case 4: return DateAbbr[3];
			   break;
	   case 5: return DateAbbr[4];
		           break;
	   case 6: return DateAbbr[5];
			   break;
	   case 7: return DateAbbr[6];
			   break;
	   case 8: return DateAbbr[7];
			   break;
	   case 9: return DateAbbr[8];
		           break;
	   case 10: return DateAbbr[9];
			   break;
	   case 11: return DateAbbr[10];
			   break;
	   case 12: return DateAbbr[11];
			   break;
	   default: return ("Wrong Month Inserted....");
		           break;
   }//Switch
}//DateConversion

//Print Subtitles for Out Files
void  AccessRecords :: PrintSubtitles(ostream& OutF)
{
	    //Print Title & Subtitles
	    OutF << setw(50) << "Employee Report" << endl << endl;
	    OutF << left << setw(6) << "Acct#" << right << setw(12) << "Last Name" 
		 << right << setw(13) << "First Name" << right << setw(17) << "Date of birth"
		 << right << setw(19) << "Annual Salary" << right << setw(22) << "Department Code" << endl; 
		
}//PrintSubtitles
	
//Print Total Records Processed
void AccessRecords :: TotalRecordsProcessed(ostream& OutF)
{
	OutF << endl << endl << endl << endl << endl << left << "Total Records Processed: " << TotalRecords;
}//TotalRecordsProcessed

//Print Report in In-Order Form
void AccessRecords :: PrintInOrder(ostream& OutF, node *PtrRoot)
{
	//Print The Contents in the B-Tree in InOrder
	if(PtrRoot != NULL)
	{
		//Traverse through left-subtree
		PrintInOrder(OutF, PtrRoot->left_child);
			
		//Visit the Root
		OutF << setfill('0') << setw(3) << PtrRoot->acct_number;
		OutF << setfill(' ') << right << setw(12) << PtrRoot->last_name << right << setw(12) 
		     << PtrRoot->first_name << right << setw(12) << DateConversion(PtrRoot->month)
		     << PtrRoot->day << ", " << PtrRoot->year << right << setw(7) << '\t' << '$' 
		     << fixed << setprecision(2)  << PtrRoot->annual_salary << right << setw(14) 
		     << '\t' << PtrRoot->dept_code << endl;
			
		//Traverse through the right-subtree
		PrintInOrder(OutF, PtrRoot->right_child);
	}//if
}//PrintInOrder

//Print Report in Pre-Order Form
void AccessRecords :: PrintPreOrder(ostream& OutF, node *PtrRoot)
{
	//Print The Contents in the B-Tree in PreOrder
	if(PtrRoot != NULL)
	{
		//Visit the Root
		OutF << setfill('0') << setw(3) << PtrRoot->acct_number;
		OutF << setfill(' ') << right << setw(12) << PtrRoot->last_name << right << setw(12) 
		     << PtrRoot->first_name << right << setw(12) << DateConversion(PtrRoot->month)
		     << PtrRoot->day << ", " << PtrRoot->year << right << setw(7) << '\t' << '$' 
		     << fixed << setprecision(2)  << PtrRoot->annual_salary << right << setw(14) 
		     << '\t' << PtrRoot->dept_code << endl;
				
		//Traverse through left-subtree
		PrintPreOrder(OutF, PtrRoot->left_child);
				
		//Traverse through the right-subtree
		PrintPreOrder(OutF, PtrRoot->right_child);
	}//if
}//PrintPreOrder

//Print Report in Post-Order Form
void AccessRecords :: PrintPostOrder(ostream& OutF, node *PtrRoot)
{
	 //Print The Contents in the B-Tree in PostOrder
	 if(PtrRoot != NULL)
	 {
								
		//Traverse through left-subtree
		PrintPreOrder(OutF, PtrRoot->left_child);
				
		//Traverse through the right-subtree
		PrintPreOrder(OutF, PtrRoot->right_child);
				
		//Visit the Root
		OutF << setfill('0') << setw(3) << PtrRoot->acct_number;
		OutF << setfill(' ') << right << setw(12) << PtrRoot->last_name << right << setw(12) 
	             << PtrRoot->first_name << right << setw(12) << DateConversion(PtrRoot->month)
		     << PtrRoot->day << ", " << PtrRoot->year << right << setw(7) << '\t' << '$' 
		     << fixed << setprecision(2)  << PtrRoot->annual_salary << right << setw(14) 
          	     << '\t' << PtrRoot->dept_code << endl;
	 }//if
}//PrintPostOrder

//QuickSort Function
void AccessRecords :: QuickSort(vector<string> &Last_Name3, vector<char> &First_Initial3, vector<float> &Annual_Salary3, 
				vector<string> &Phone_Number3, vector<char> &Department_Code3, int low, int high)
{
	//Termination Condition (if low > high)
	if(low < high)
	{
		//Create a Partitioning Index
		int partitionIndex = Partition(Last_Name3, First_Initial3, Annual_Salary3, Phone_Number3, Department_Code3, low, high);
		
		//Seperately sort the elements before partition and after partition
		QuickSort(Last_Name3, First_Initial3, Annual_Salary3, Phone_Number3, Department_Code3, low, (partitionIndex-1));
		
		QuickSort(Last_Name3, First_Initial3, Annual_Salary3, Phone_Number3, Department_Code3, (partitionIndex+1), high);
	}//if
}//QuickSort

//Partition sorts the vectors according to the Last Names
int AccessRecords :: Partition(vector<string> &Last_Name2, vector<char> &First_Initial2, vector<float> &Annual_Salary2, 
			       vector<string> &Phone_Number2, vector<char> &Department_Code2, int low, int high)
{
	//Declare & Assign Variables
	string pivot = Last_Name2[high]; //pivot
	int smallerElement = (low - 1); //Index of smaller element
	
	//Swap the Parallel Arrays
	for(int k = low; k <= (high-1); k++)
	{
		//If the current element is smaller that or equal to the pivot, then, the sorting sequence condition
		//fails, if the condition becomes true. (Using two indices to swap the values: smallerElement & k)
		if(Last_Name2[k] <= pivot)
		{
			//Increment index of smaller element
			smallerElement++;
			
			//Swap the values of smallerElement & k in all of the arrays
			
			//Swap the Last Names
			string temp = Last_Name2[smallerElement];
			Last_Name2[smallerElement] = Last_Name2[k];
			Last_Name2[k] = temp;
			
			//Swap the First Initials
			char temp2 = First_Initial2[smallerElement];
			First_Initial2[smallerElement] = First_Initial2[k];
			First_Initial2[k] = temp2;
			
			//Swap the Annual Salary
			float temp3 = Annual_Salary2[smallerElement];
			Annual_Salary2[smallerElement] = Annual_Salary2[k];
			Annual_Salary2[k] = temp3;
			
			//Swap the Phone Numbers
			string temp4 = Phone_Number2[smallerElement];
			Phone_Number2[smallerElement] = Phone_Number2[k];
			Phone_Number2[k] = temp4;
			
			//Swap the Department Code
			char temp5 = Department_Code2[smallerElement];
			Department_Code2[smallerElement] = Department_Code2[k];
			Department_Code2[k] = temp5;
		}//if
	}//for
	
		//Swap the Rest of the Elements
		//Swap the Rest of the Last Name Elements
		string temp = Last_Name2[smallerElement + 1];
		Last_Name2[smallerElement + 1] = Last_Name2[high];
		Last_Name2[high] = temp;
		
		//Swap the Rest of the First Initials Elements
		char temp2 = First_Initial2[smallerElement + 1];
		First_Initial2[smallerElement + 1] = First_Initial2[high];
		First_Initial2[high] = temp2;
		
		//Swap the Rest of the Annual Salary Elements
		float temp3 = Annual_Salary2[smallerElement + 1];
		Annual_Salary2[smallerElement + 1] = Annual_Salary2[high];
		Annual_Salary2[high] = temp3;
		
		//Swap the Rest of the Phone Number Elements
		string temp4 = Phone_Number2[smallerElement + 1];
		Phone_Number2[smallerElement + 1] = Phone_Number2[high];
		Phone_Number2[high] = temp4;
		
		//Swap the Rest of the Department Code Elements
		char temp5 = Department_Code2[smallerElement + 1];
		Department_Code2[smallerElement + 1] = Department_Code2[high];
		Department_Code2[high] = temp5;
		
		//Return the smaller Element + 1
		return (smallerElement + 1);
}//Partition

//Print Report That Used The QuickSort Algorithm
void AccessRecords :: PrintQuickSort(ostream& OutF)
{
	 //Print Title & Subtitles
	 OutF << setw(55) << "Employee Salary Report" << endl << endl;
         OutF << left << setw(6) << "Last Name" << right << setw(17) << "First Init." 
	      << right << setw(13) << "Salary" << right << setw(22) << "Phone_Number"
	      << right << setw(19) << "Department Code" << endl; 
	
	//Print Out The Contents From The Arrays/Vectors
	for(int i = 0; i < TotalRecords; i++)
	{
		OutF << left << setw(9) << Last_Name[i] << right << setw(12) << First_Initial[i]
		     << '.' << right << setw(12) << '$' << fixed << setprecision(2)
		     << Annual_Salary[i] << right << setw(20) << Phone_Number[i] << right << setw(13)   
		     << Department_Code[i] << endl;
	}//for
	
	//Print the Total Salary
	OutF << endl << endl << endl << endl << "Total Salary" << setw(10) << '$' << fixed << setprecision(2) << TotalSalary; 
}//PrintQuickSort
