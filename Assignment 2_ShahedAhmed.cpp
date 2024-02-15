// Name: Shahed Ahmed
// Date: 2 / 16 / 2023
// Assignment 2
// loan estimator


// library
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

// All function prototype

void table_function (double &loan_get, double &interest_get,double & payable_Balance_get,double M_get, double interest_Holder_get, int loan_term_get);

double amortization (double P, double r, int n );

void promote_function ( double & get_loan_amount, double &get_interest ,int &get_month);

void total_funtion (double &add_month, double & hold_month , double &hold_interest, double add_interest);

void output_function ( int Month, double payments, double interest, double principle, double Balance);

void output_function (ofstream &table_File);

void output_total(double Montly_due,double  total_Payment, double total_Interest );







int main()
{
    // declare variable
    int loan_Term_Monthly, loan_Term_yearly;
    double loan_Amount , interest_Rate, M, payable_Balance, interest_Holder;
    char command;


    // calculate user loan as many time as they wanted
    do
    {

    // Asking user if they wanted to calculate interest
         cout << "Please Enter Y or y to calculate you payment. "
        << "Else press anything to end\n";

        // code will if they enter y only
        cin >> command ;

        if (!(command == 'y' || command == 'Y'))
            // break if they don,t want to run
            break;
        // user input
        promote_function (loan_Amount, interest_Holder, loan_Term_Monthly);
        // calculate monthly payment
        M = amortization ( loan_Amount,interest_Holder, loan_Term_Monthly);
        // All call calculation
        // files
        // print
        // function inside function
        table_function  ( loan_Amount, interest_Rate, payable_Balance, M, interest_Holder, loan_Term_Monthly);




    } while ( command == 'y' || command == 'Y' );

    return 0;


}










// print the table
// print the table in a file
// pass value to table_function

void output_function (int month, double payments, double interest, double principle, double Balance, ofstream &table_File)
{

table_File.width(3);
table_File<< month << setw(20) << payments<< setw(20) << interest << setw(20) <<  principle <<setw(20)<< Balance << endl;
    cout.width(3);
  cout << month << setw(20) << payments<< setw(20) << interest << setw(20) <<  principle <<setw(20)<< Balance << endl;

}




// print table
// Each row unique name in a table
// print in a file
// pass print to table_function

void output_function (ofstream &table_File)
{;

    table_File << setw(22) <<"Start Balance"
     << setw(22) << "Interest"
     << setw(22) << "Principle"
     << setw(22) << "End Balance \n";


  cout << setw(22) <<"Start Balance"
     << setw(22) << "Interest"
     << setw(22) << "Principle"
     << setw(22) << "End Balance \n";

}




// calculate total interest paid
// calculate total payment paid
// pass value to table_function
void total_funtion (double &add_month, double & hold_month , double &hold_interest, double add_interest)

{

          hold_month += add_month;
          hold_interest += add_interest;

}





// calculate interest each month
// calculate monthly principle
// calculate Ending Balance
// pass value and print to main

void table_function (double &loan_get, double &interest_get,double & payable_Balance_get,double M_get, double interest_Holder_get, int loan_term_get)

{
    // declare variable
    int i, j;
    double payment, Interest, principal,Balance;
    double total_Pay = 0, total_Interest_Paid = 0, loan_holder =0;
    char file_Name [20];


        // file declare
        ofstream table_File;

        // set flag to input and file input


        // citation from lecture 9 slide 20//
        table_File.setf(ios::fixed);
        table_File.setf(ios::showpoint);
        table_File.precision(2);
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        // Asking user for file name. create a file
        cout << "Please type your Filename\n";
        cin >> file_Name;

        // opening file and creating file
        table_File.open(file_Name);
        // row unique name
        output_function (table_File);


            // calculate interest each month
            // calculate monthly principle
            // calculate Ending Balance

            for (j = 1, i = 1; i <= loan_term_get; ++i)
        {

            loan_holder = loan_get;
            Interest = ((interest_Holder_get * 12)* loan_get ) / 12;
           interest_get = Interest;
            payment = M_get - Interest;
            payable_Balance_get= payment;
            Balance = (loan_get - ( payable_Balance_get + Interest)) + Interest;
            loan_get = Balance;

            // accumulate total payment and total interest
            total_funtion (M_get, total_Pay,total_Interest_Paid,interest_get);

            // print month, payments, interest, principle, ending balance
            // print in a file
            output_function ( i, loan_holder, interest_get,  payable_Balance_get ,loan_get, table_File);

            // print year after 12 month
            // print year after 12 month in a file

          if ( i == 12 || (i / j) == 12)
            {

                cout <<endl;
                 table_File <<endl;
                table_File << "\n" << setw(50)<< j << " year"<<setw(50) <<endl;
                table_File <<endl;
                cout<< "\n" << setw(50)<< j << " year"<<setw(50) <<endl;
                cout <<endl;
                j++;
            }

        }

        // close file
        table_File.close();
// print total
output_total(M_get ,total_Pay, total_Interest_Paid );

}

//  print total interest paid
// print total payment paid
// print Monthly payment
// pass print to table_function
void output_total(double Montly_due,double  total_Payment, double total_Interest )
{
     cout << "\n";
    cout << "Monthly Paid: " <<"$"<< Montly_due << endl;
    cout << "Total Paid: " <<"$" << total_Payment <<endl;
    cout << "Total Interest Paid: " <<"$"<< total_Interest <<endl;

}



//Getting input from user. Converting year to month
// converting interest rate monthly interest
// used if function for error input
// pass value to main
void promote_function ( double & get_loan_amount, double &get_interest ,int &get_month)
{
    // declare variable

    double interest_rate, loan_length;

     cout << "Please Enter loan amount \n";
     cin >> get_loan_amount;
     if (!(get_loan_amount > 0 ))
     {
         cout << "invalid output\n";
        exit(1);
     }
     cout << "Please enter interest rate \n";
     cin >> interest_rate;
      if (!(interest_rate > 0  ))
     {
         cout << "invalid output\n";
        exit(1);
     }
     cout << "Please Enter years of loan \n";
     cin >> loan_length;
      if (!(loan_length > 0 ))
     {
         cout << "invalid output\n";
        exit(1);
     }

    get_interest = ( 1 / interest_rate) / 12 ;
    get_month = loan_length * 12;
}






// calculating monthly payments.
//  p for loan amount
//r for  monthly interest rate
// n for loan monthly term
// pass value to main
double amortization (double  P, double r, int n )
{
    //declare variable
    double Calculate ;

    Calculate = P*((r*(pow((1+r),n)) / (pow((1+r),n) - 1)));

return Calculate;
}

