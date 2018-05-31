/*
    Author: David Amante
    Date: 5.29.18
    Goal: Make a dynamic budget program that iterates through monthly cycles
          until debts are paid off.

    Example:
        Monthly Expenses
        ########|Income|Student Loan|Car Payment|Food|Gas
        Month 1:  3200   68000-50     10000-50   145
        Month 2:  3200
        Month 3:  3200
        ...
        Month N:






    gain:
        paychecks monthly = 3200/month
        miscellaneous gains, negligible
        gifts
    loss:   
        student loans = 35,000 total, 50/month until == 0
        car loans     = 10,000 total, 50/month until == 0
        mortgage/rent = 1200/month,. if(mortgage > paycheck/(1/3), careful, over 33% paycheck)
        stocks        = 10/month

    functions
        Add Expense
    trackTheseVars:
        total 
        totalMoneySaved = (budget->gain * .10 / month)

        stepOne = save 1000 dollars for a rainy day fund
        stepTwo = start paying off your debt where you have a higher interst rate first
        stepThree = save up to 3-6 months of expenses
                    put this in terms of monthly amounts
                    1 month: 4000
                    2 months: 8000
                    3 months: 12000
                    etc
                define budget stuff
                    food
                    car
                    insurance
        stepFour = take advantage of tax advantage accounts 401k, ira  
        stepFive = save your age in bonds
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BudgetEntry {
public:
    double monthlyPayment;
    double total;
    string name;
    bool isRecurrent;

    BudgetEntry()
    {
        name = "";
        monthlyPayment = 0;
        total = 0;
        isRecurrent = false;
    }

    BudgetEntry(string s, double mp, double t, bool r)
    {
        name = s;
        monthlyPayment = mp;
        total = t;
        isRecurrent = r;
    }
};

bool checkRepeat();
void menu();
double getMonthlyIncome();

int main()
{
    bool repeat = true;
    double monthlyIncome = getMonthlyIncome();

    while(repeat)
    {
        // menu
        menu();
        // add an expense
        // delete an expense
        // show expenses until month count (< 0)
        // show expenses until all debt paid
        // export to latex
        repeat = checkRepeat();
    }
    return 0;
}



//need to clean input
double getMonthlyIncome() 
{
    double monthlyIncome = 0;
    cout << "Enter your monthly income: ";
    cin >> monthlyIncome;
    return monthlyIncome;
}

void menu()
{
    cout << "        Budget Calculator Program        " << endl;
    cout << "              Version 0.0.1              " << endl;
    cout << "=========================================" << endl;
    cout << "1: Add an expense                        " << endl;
    cout << "2: Delete an expense                     " << endl;
    cout << "3: Show expenses to ith month            " << endl;
    cout << "4: Show expenses until all debt is paid  " << endl;
    cout << "5: Export to LaTeX file                  " << endl;
    cout << "6: Exit                                  " << endl;
}

bool checkRepeat()
{
    char repeatOption = 'n';
    bool repeat = false;

    cout << "Would you like to edit your data? (y/n)" << endl;
    cin >> repeatOption;

    while(repeatOption != 'N' && repeatOption != 'n' &&
          repeatOption != 'Y' && repeatOption != 'y')
    {
        cout << "Would you like to edit your data? (y/n)" << endl;
        cin >> repeatOption;
    }

    if(repeatOption == 'Y' || repeatOption == 'y')
    {
        repeat = true;
    }
    else if(repeatOption == 'N' || repeatOption == 'n')
    {
        repeat = false;
    }

    return repeat;
}