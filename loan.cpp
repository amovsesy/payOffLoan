/* Aleksandr Movsesyan
     Programming Lab 4
     pl4.cpp
     CS 110A
     Craig Persiko

     This program lets the customer know how long it will take to pay off a loan
at a certain interest rate.
  */

#include <iostream>
#include <cstdlib>
using namespace std;

void user_input ( double& principle_amount, double& interest_rate, double&
payment_amount );
// gets the ammount borrowed the interest rate and how much he wants to pay
// every month and returns it through call-by-reference
// perameters

double pay_off_loan ( double& principle_amount, double interest_rate, double
payment_amount, int& months, double& total_interest );
// does the necessary calculations to check if the payment is greater than the
// interest rate and then if it is calculates the months
// necessary to pay off loan, total interst paid, and returns the final payment

void output ( double final_payment, int months, double total_interest );
// outputs the results of the calculations

void month_calculation ( double& principle_amount, double interest_rate, double
payment_amount, int& months, double& total_interest );
// has the loop for each month

int main()
{

  int months = 0, last;
  double principle_amount, interest_rate, payment_amount, total_interest = 0.0,
last_payment;

  user_input ( principle_amount, interest_rate, payment_amount );

  last_payment = pay_off_loan ( principle_amount, interest_rate, payment_amount,
months, total_interest );

  output ( last_payment, months, total_interest );

  return 0;
}

// gets the ammount borrowed the interest rate and how much he wants to pay
// every month and returns it through call-by-reference
// perameters
void user_input ( double& principle_amount, double& interest_rate, double&
payment_amount )
{

  cout << "\n** Welcome to the Consumer Loan Calculator **\n\n";

  cout << "How much do you want to borrow? $";
  cin >> principle_amount;

  if ( principle_amount <= 0 )
  {
    do
    {
      cout << "You must enter a positive number!\n";
      cout << "How much do you want to borrow? $";
      cin >> principle_amount;
    }while ( principle_amount <= 0 );
  }

  cout << "What is the annual interest rate expressed as a percent? ";
  cin >> interest_rate;

  if ( interest_rate <= 0 )
  {
    do
    {
      cout << "You must enter a positive number!\n";
      cout << "What is the annual interest rate expressed as a percent? ";
      cin >> interest_rate;
    }while ( interest_rate <= 0 );
  }

  cout << "What is the monthly payment amount? $";
  cin >> payment_amount;

  if ( payment_amount <= 0 )
  {
    do
    {
      cout << "You must enter a positive number!\n";
      cout << "What is the monthly payment amount? $";
      cin >> payment_amount;
    }while ( payment_amount <= 0 );
  }
}

// does the necessary calculations to check if the payment is greater than the
// interest rate and then if it is calculates the months
// necessary to pay off loan, total interst paid, and returns the final payment
double pay_off_loan ( double& principle_amount, double interest_rate, double
payment_amount, int& months, double& total_interest )
{

  double year_interest, last_payment, interest;

  year_interest = interest_rate / 1200.0;

  month_calculation ( principle_amount, year_interest, payment_amount, months,
total_interest );

  interest = principle_amount * year_interest;
  principle_amount += interest;
  last_payment = principle_amount;
  total_interest += interest;
  months++;

  return last_payment;
}

// outputs the results of the calculations
void output ( double final_payment, int months, double total_interest )
{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << "Your debt will be paid off after " << months << " months, with a final payment of just $" << final_payment
       << "\nThe total amount of interest you will pay during that time is $" <<
total_interest;
  cout << "\n\n** Don't get overwhelmed with debt! **\n\n";

  int last;
  cin >> last;
  cin >> last;

}

// has the loop for each month
void month_calculation ( double& principle_amount, double interest_rate, double
payment_amount, int& months, double& total_interest )
{
  while (principle_amount > payment_amount)
  {
    double interest;

    interest = principle_amount * interest_rate;
    total_interest += interest;
    if ( interest >= payment_amount )
    {
      cout << "You must make payments of at least $" <<
static_cast<int>(total_interest + 1)
           << "\nBecause your monthly interest is $" <<
static_cast<int>(total_interest);
      cout << "\n\n** Don't get overwhelmed with debt! **\n\n";
      exit (1);
    }
      principle_amount += interest;
      principle_amount -= payment_amount;
      months++;
  }

}
