  /*
  Name: David Amante
  Created: 1 July 2016
  Project: Create a program that calculates the root of a cubic equation assuming delta is > 0.
    Note: Line numbers are intentionally excluded from printing because the user can fix the TeX file in their TeX editor.
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::sqrt;
using std::ofstream;
using std::string;
using std::getline;

int main()
{
  ofstream out;
  string file_name;

  int font_size = 0;

  int p = 6;
  int p_delta_num = 0;
  int p_delta_denom = 27;

  int q = 7;
  int q_delta_num = 0;
  int q_delta_denom = 4;

  int delta_num = 0;
  int delta_denom = 0;

  int delta_add_num = 0;
  int delta_add_denom = 0;
  int delta_sub_num = 0;
  int delta_sub_denom = 0;

  bool not_sure = false;
  char response;


  while(not_sure == false)
  {
    cout << "Enter what you want to name your .tex file: ";
    getline(cin, file_name);

    cout << "Is the name: '" << file_name << ".tex' correct? (Y/N)" << endl;
    while(response != 'Y' && response != 'y' && response != 'N' && response != 'n')
    {
      cout << "Enter 'Y' or 'y' for yes, 'N' or 'n' for no." << endl;
      cin >> response;
    }

    if(response == 'y' || response == 'y')
    {
      not_sure = true;
    }
    else if(response == 'N' || response == 'n')
    {
      //to catch the return from the 'N' or 'n' response
      cin.ignore(1, '\n');
    }
  }

  //open new LaTeX file
  file_name += ".tex";
  out.open(file_name.c_str());

  while(font_size < 10 || font_size > 12)
  {
    cout << "Enter a font size (10, 11, 12): ";
    cin >> font_size;
  }

  cout << "Enter your value of P: ";
  cin >> p;

  cout << "Enter your value of Q: ";
  cin >> q;

  //initialize doc class and LaTeX packages
  cout << "=============================================" << endl;
  cout << "###            Start LaTeX File           ###" << endl;
  cout << "=============================================" << endl;
  cout << "\\documentclass[" << font_size << "]{article}" << endl;
  cout << "\\usepackage{fullpage}" << endl;
  cout << "\\usepackage{amsfonts}" << endl;
  cout << "\\usepackage{graphicx}" << endl;
  cout << endl;

  //begin doc
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

  //define Delta and roots of X
  cout << "  % Begin definitions of Delta and roots of x" << endl;
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
  cout << "        $x = \\sqrt[3]{\\sqrt{\\Delta} + \\frac{Q}{2}} - \\sqrt[3]{\\sqrt{\\Delta} - \\frac{Q}{2}}$," << endl;
  cout << "      \\end{Large}" << endl;
  cout << "      &" << endl;
  cout << "      \\begin{Large}" << endl;
  cout << "        $\\Delta = \\frac{Q^2}{4} + \\frac{P^3}{27}$" << endl;
  cout << "      \\end{Large}" << endl;
  cout << "    \\\\ \\hline" << endl;
  cout << "    \\end{tabular}" << endl;
  cout << "  \\end{center}" << endl << endl;

  //begin cubic equation calculation
  cout << "  % Define P and Q" << endl;
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
  cout << "          \\rightarrow" << endl;

  //q and p delta number initialization to solve for delta
  q_delta_num = q * q;
  p_delta_num = p * p * p;

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

  delta_num = q_delta_num + p_delta_num;
  delta_denom = q_delta_denom;

	cout << "        \\left[ \\Delta = \\frac{" << q_delta_num << "}{" << q_delta_denom << "} + \\frac{" << p_delta_num << "}{" << p_delta_denom << "} \\right]" << endl;
  cout << "          \\rightarrow" << endl;
	cout << "        \\left[ \\Delta = \\frac{" << delta_num << "}{" << delta_denom << "} \\right]" << endl;
  cout << "    $" << endl;
  cout << "    \\end{large}" << endl;
  cout << "  \\end{center}" << endl;

  //check if the delta_numerator and delta_denominator need to be reduced because delta goes through square root
  //put in the values that were acquired from above.
  cout << endl;
  cout << "  \\begin{center}" << endl;
  cout << "    Using the given data of $\\Delta = \\frac{" << delta_num << "}{" << delta_denom << "}$" << endl;
  cout << "  \\end{center}" << endl;
  cout << endl;

  cout << "  \\begin{center}" << endl;
  cout << "    \\begin{large}" << endl;
  cout << "    $$" << endl;
  cout << "      x = \\sqrt[3]{\\sqrt{\\frac{" << delta_num << "}{" << delta_denom << "}} + \\frac{" << q << "}{2}}" << endl;
  cout << "        - \\sqrt[3]{\\sqrt{\\frac{" << delta_num << "}{" << delta_denom << "}} - \\frac{" << q << "}{2}}" << endl;
  cout << "    $$" << endl;

  delta_num = sqrt(delta_num);
  delta_denom = sqrt(delta_denom);
  cout << "    $$" << endl;
  cout << "      x = \\sqrt[3]{\\frac{" << delta_num << "}{" << delta_denom << "}} + \\frac{" << q << "}{2}}" << endl;
  cout << "        - \\sqrt[3]{\\frac{" << delta_num << "}{" << delta_denom << "}} - \\frac{" << q << "}{2}}" << endl;
  cout << "    $$" << endl;

  delta_add_num = delta_num + q;
  delta_add_denom = delta_denom;

  delta_sub_num = delta_num - q;
  delta_sub_denom = delta_denom;

  if(delta_denom == 2)
  {
    cout << "    $$" << endl;
    cout << "      x = \\sqrt[3]{\\frac{" << delta_add_num << "}{" << delta_add_denom << "}}" << endl;
    cout << "        - \\sqrt[3]{\\frac{" << delta_sub_num << "}{" << delta_sub_denom << "}}" << endl;
    cout << "    $$" << endl;
  }

  while(delta_add_num % 2 == 0 && delta_add_denom % 2 == 0)
  {
    delta_add_num /= 2;
    delta_add_denom /= 2;
  }
  while(delta_sub_num % 2 == 0 && delta_sub_denom % 2 == 0)
  {
    delta_sub_num /= 2;
    delta_sub_denom /= 2;
  }

  cout << "    $$" << endl;
  cout << "      x = \\sqrt[3]{\\frac{" << delta_add_num << "}{" << delta_add_denom << "}}" << endl;
  cout << "        - \\sqrt[3]{\\frac{" << delta_sub_num << "}{" << delta_sub_denom << "}}" << endl;
  cout << "    $$" << endl;

  cout << "    $$" << endl;
  if(delta_add_denom == 1)
  {
    cout << "      x = \\sqrt[3]{" << delta_add_num << "}" << endl;
  }
  if(delta_sub_denom == 1)
  {
    cout << "      x = \\sqrt[3]{" << delta_sub_num << "}" << endl;
  }
  cout << "    $$" << endl;

  delta_add_num = cbrt(static_cast<double> (delta_add_num));
  delta_sub_num = cbrt(static_cast<double> (delta_sub_num));
  cout << "    $$" << endl;
  cout << "      x = (" << delta_add_num << ")" << endl;
  cout << "      x = (" << delta_sub_num << ")" << endl;
  cout << "    $$" << endl;

  cout << "    $$" << endl;
  cout << "      x = (" << delta_add_num - delta_sub_num << ")" << endl;
  cout << "    $$" << endl;
  cout << "    \\end{large}" << endl;
  cout << "  \\end{center}" << endl;
  cout << "\\end{document}" << endl;
  cout << "=============================================" << endl;
  cout << "###             End LaTeX File            ###" << endl;
  cout << "=============================================" << endl;
  out.close();
  return 0;
}
