  /*
  Name: David Amante
  Created: 1 July 2016
  Project: Create a program that calculates the root of a cubic equation assuming delta is > 0.
*/

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::pow;

int main()
{
  int font_size = 0;

  int p = 6;
  int p_delta_num = 0;
  int p_delta_denom = 27;

  int q = 7;
  int q_delta_num = 0;
  int q_delta_denom = 4;

  int delta_num = 0;
  int delta_denom = 0;

  while(font_size < 10 || font_size > 12)
  {
    cout << "Enter a font size (10, 11, 12): ";
    cin >> font_size;
  }

  cout << "Enter your value of P: ";
  cin >> p;

  cout << "Enter your value of Q: ";
  cin >> q;

  cout << "\\documentclass[" << font_size << "]{article}" << endl;
  cout << "\\usepackage{fullpage}" << endl;
  cout << "\\usepackage{amsfonts}" << endl;
  cout << "\\usepackage{graphicx}" << endl;
  cout << endl;
  cout << "\\begin{document}" << endl;
  cout << "  \\begin{center}" << endl;
  cout << "    The Cubic Equation is defined as: " << endl;
  cout << "  \\end{center}" << endl;
  cout << endl;
  cout << "  \\begin{Large}" << endl;
  cout << "    \\begin{center}" << endl;
  cout << "      $x^3 + Px = Q$." << endl;
  cout << "    \\end{center}" << endl;
  cout << "  \\end{Large}" << endl;
  cout << endl << endl;
  cout << "  \\begin{center}" << endl;
  cout << "    \\begin{tabular}{|c|c|}" << endl;
  cout << "    \\hline" << endl;
  cout << "      \\begin{large}" << endl;
  cout << "        If its roots are defined by:" << endl;
  cout << "      \\end{large}" << endl;
  cout << "      &" << endl;
  cout << "      \\begin{large}" << endl;
  cout << "        and $\\Delta$ is defined by:" << endl;
  cout << "      \\end{large}" << endl;
  cout << "    \\\\ \\hline" << endl;
  cout << "      \\begin{Large}" << endl;
  cout << "      $x = \\sqrt[3]{\\sqrt{\\Delta} + \frac{Q}{2}} - \\sqrt[3]{\\sqrt{\\Delta} - \frac{Q}{2}}$,"
  cout << "      \\end{Large}" << endl;
  cout << "      &" << endl;
  cout << "      \\begin{Large}" << endl;
  cout << "      $\\Delta = \frac{Q^2}{4} + \frac{P^3}{27}$" << endl;
  cout << "      \\end{Large}" << endl;
  cout << "    \\\\ \\hline" << endl;
  cout << "    \\end{tabular}" << endl;
  cout << "  \\end{center}" << endl;

  cout << "  \\begin{center}" << endl;
  cout << "    Using the given data of P = " << p << "; Q = " << q << endl;
  cout << "  \\end{center}" << endl;

  cout << "  \\begin{center}" << endl;
  cout << "    \\begin{large}" << endl;
  cout << "    $" << endl;
  cout << "      \\displaystyle" << endl;
  cout << "        \\left[ \\Delta = \\frac{" << q << "^2}{4} + \\frac{" << p << "^3}{27} \\right]" << endl;
  cout << "          \\rightarrow" << endl;
  cout << "        \\left[ \\Delta = \\frac{" << q * q << "}{4} + \\frac{" << p * p << "}{27} \\right]" << endl;
  q_delta_num = q * q;
  p_delta_num = p * p * p;

  cout << "          \\rightarrow" << endl;

  //simplify out all %2 and %3
  //simplify q delta factor
  while(q_delta_num % 2 == 0 && q_delta_denom % 2 == 0)
  {
    q_delta_num /= 2;
    q_delta_denom /= 2;
  }
  while(q_delta_num % 3 == 0 && q_delta_denom % 3 == 0)
  {
    q_delta_num /= 3;
    q_delta_denom /= 3;
  }
  cout << q_delta_num << " / " << q_delta_denom << endl;

  //simplify p delta factor
  while(p_delta_num % 2 == 0 && p_delta_denom % 2 == 0)
  {
    p_delta_num /= 2;
    p_delta_denom /= 2;
  }
  while(p_delta_num % 3 == 0 && p_delta_denom % 3 == 0)
  {
    p_delta_num /= 3;
    p_delta_denom /= 3;
  }
  cout << p_delta_num << " / " << p_delta_denom << endl;

  cout << "        \\left[ \\Delta = \\frac{" << q_delta_num << "}{" << q_delta_denom << "} + \\frac{" << p_delta_num << "}{" << p_delta_denom << "} \\right]" << endl;
  cout << "          \\rightarrow" << endl;

  //find common denominator to combine. this is always addition, and always positive because this program is for delta > 0
  //assume that both denominators need to be multiplied to be able to find greatest common denominator
  //it doesn't matter about if they don't need to multiplied because they'll be simplified immediately after
  if(p_delta_denom == q_delta_denom)
  {
    //just skip to the next step
  }
  else
  {
    q_delta_num *=  p_delta_denom;
    q_delta_denom *= p_delta_denom;

    p_delta_num *= q_delta_denom;
    p_delta_denom *= q_delta_denom;
  }
  cout << "Q Fraction: " << q_delta_num << " / " << q_delta_denom << endl;
  cout << "P Fraction: " << p_delta_num << " / " << p_delta_denom << endl;

	cout << "        \\left[ \\Delta = \\frac{" << q_delta_num << "}{" << q_delta_denom << "} + \\frac{" << p_delta_num << "}{" << p_delta_denom << "} \\right]" << endl;
  cout << "          \\rightarrow" << endl;
  delta_num = q_delta_num + p_delta_num;
  delta_denom = q_delta_num;

	cout << "	       \\left[ \\Delta = \\frac{" << delta_num << "}{" << delta_denom << "} \\right]" << endl;
  cout << "    $" << endl;
  cout << "    \\end{large}" << endl;
  cout << "  \\end{center}" << endl;

  //check if the delta_numerator and delta_denominator need to be reduced because delta goes through square root
  //put in the values that were acquired from above.
  cout << "  \\begin{center}" << endl;
  cout << "	   Using the given data of $\\Delta = \\frac{81}{4}$" << endl;
  cout << "  \\end{center}" << endl;

  cout << "  \\begin{center}" << endl;
  cout << "    \\begin{large}" << endl;
  //lines 67-99
  cout << "    \\end{large}" << endl;
  cout << "  \\end{center}" << endl;

  cout << "\\end{document}" << endl;
}
