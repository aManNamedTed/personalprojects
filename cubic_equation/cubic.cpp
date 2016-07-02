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
  int p = 6;
  int q = 7;
  int font_size;
  
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
  cout << "      \\begin{large" << endl;
  cout << "Delta = " << pow(q, 2) << " / " << 4 << " + " << pow(p, 3) << " / " << 27;
  
}
