#ifndef NODE_H
#define NODE_H
#include <vector>

class AccessRecords
{
	private: 
		//Declare struct for Binary Tree
		struct node
		{
			int acct_number;  //Account Number
			string last_name; //Last Name
			string first_name; //First Name
			char middle_initial; //Middle Initial
			unsigned int month; //Month in Number Form
			unsigned int day; //Day in Number Form
			unsigned int year; //Year in Number Form
			float annual_salary; // Annual Salary
			char dept_code; //Department Code (Can be entered as UpperCase/Lower)
			string phone_number; //Phone Number in String Form
			node *left_child; //Pointer to left child node in tree
			node *right_child; //Pointer to right child node in tree
			node(){}           //First Constructor
			node(int acct_number1, string last_name1, char middle_initial1, string first_name1, 
				 unsigned int month1, unsigned int day1, unsigned int year1, float annual_salary1, 
				 char dept_code1, string phone_number1, node *left_child1 = NULL, 
				 node *right_child1 = NULL)
			{
				acct_number = acct_number1;
				last_name = last_name1;
				first_name = first_name1;
				middle_initial = middle_initial1;
				month = month1;
				day = day1;
				year = year1;
				annual_salary = annual_salary1;
				dept_code = dept_code1;
				phone_number = phone_number1;
				left_child = left_child1;
				right_child = right_child1;
			}//2nd Constructor
	};//end struct node
	int TotalRecords; // Total Records Processed Counter
	double TotalSalary; // Total Salary Counter
	vector <string> Last_Name; //Vector To Hold Last Name For 4th Print Report
	vector <char> First_Initial; //Vector To Hold First Initial For 4th Print Report
	vector <float> Annual_Salary; //Vector To Hold Annual Salary For 4th Print Report
	vector <string> Phone_Number; //Vector To Hold Phone Number For 4th Print Report
	vector <char> Department_Code; //Vector To Hold Department Code For 4th Print Report
	node *Root; //Root Pointer for Binary Tree
	
	public:
			//Initialize Root Node & Read Records From File & Send Data to Insert Function
			void ReadRecord();
			//Insert Recieved Data into Binary Tree by Account #
			void Insert(node *& PtrRoot,int acct_number2, string last_name2, char middle_initial2, 
			            string first_name2, unsigned int month2, unsigned int day2, unsigned int year2, 
						float annual_salary2, char dept_code2, string phone_number2);
			//Convert The Month # into Abbreviation
			string DateConversion(int);
			//Print Subtitles for Out Files
			void PrintSubtitles(ostream& OutF);
			//Print Total Records Processed
			void TotalRecordsProcessed(ostream& OutF);
			//Print Report in In-Order Form
			void PrintInOrder(ostream& OutF, node *PtrRoot);
			//Print Report in Pre-Order Form
			void PrintPreOrder(ostream& OutF, node *);
			//Print Report in Post-Order Form
			void PrintPostOrder(ostream& OutF, node *);
		    //QuickSort Function
		    void QuickSort(vector<string> &Last_Name3, vector<char> &First_Initial3, vector<float> &Annual_Salary3, 
						   vector<string> &Phone_Number3, vector<char> &Department_Code3, int low, int high);
			//Partition sorts the vectors according to the Last Names
            int Partition(vector<string>&, vector<char>&, vector<float>&, vector<string>&, vector<char>&, int, int);
			//Print Report That Used The QuickSort Algorithm
			void PrintQuickSort(ostream& OutF);
};//class AccessRecords
#endif