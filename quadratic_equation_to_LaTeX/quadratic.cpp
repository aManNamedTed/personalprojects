/*
  Name: David Amante
  Created: June 27, 2016
  Project: Make a program that:
    -Solves the Quadratic Equation
    -Shows all steps to solving the Quadratic Equation
    -Pushes all calculations to a LaTeX ('.tex') file to push to a PDF through TeX

  Note: All 'quadratic_writeup.*' files are what I used as a reference to complete this program.
*/

#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;

int main()
{
  string version = "v1.0.0";
  int a, b, c;
  int font_size = 0;
  int factor_root;
  int factored_value = 1;
  int factored_value_counter = 0;
  int denominator = 1;
  char imaginary = ' ';
  bool not_sure = false;
  char response;
  string file_name;
  ofstream out;

  cout << "Version: " << version << endl;
  cout << "by David Amante" << endl;
  cout << endl;
  cout << "Quadratic Equation calculator to LaTeX" << endl;

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
    cout << "Choose between the following font sizes (10, 11, 12): ";
    cin >> font_size;
  }

  cout << endl;
  cout << "Of the form: ax^2 + bx + c" << endl;
  cout << "Enter the value of a: ";
  cin >> a;
  cout << "Enter the value of b: ";
  cin >> b;
  cout << "Enter the value of c: ";
  cin >> c;

  cout << "%Quadratic Equation calculator to LaTeX " << version << ", by David Amante" << endl;
  out << "%Quadratic Equation calculator to LaTeX " << version << ", by David Amante" << endl;
  cout << endl;
  cout << "\\documentclass[" << font_size << "pt]{article}\n";
  out << "\\documentclass[" << font_size << "pt]{article}\n";
  cout << "\\usepackage{fullpage}" << endl;
  out << "\\usepackage{fullpage}" << endl;
  cout << "\\usepackage{amsfonts}" << endl;
  out << "\\usepackage{amsfonts}" << endl;
  cout << "\\usepackage{graphicx}" << endl;
  out << "\\usepackage{graphicx}" << endl;

  cout << endl;
  cout << "\\begin{document}" << endl;
  out << "\\begin{document}" << endl;
  cout << "  \\begin{center}" << endl;
  out << "  \\begin{center}" << endl;
  cout << "     The Quadratic Equation is defined as:" << endl;
  out << "     The Quadratic Equation is defined as:" << endl;
  cout << "  \\end{center}" << endl;
  out << "  \\end{center}" << endl;
  cout << "  \\begin{Large}" << endl;
  out << "  \\begin{Large}" << endl;
  cout << "     $$x = \\frac{-(b) \\pm \\sqrt{b^2 - 4(a)(c)}}{2(a)}$$" << endl;
  out << "     $$x = \\frac{-(b) \\pm \\sqrt{b^2 - 4(a)(c)}}{2(a)}$$" << endl;
  cout << "  \\end{Large}" << endl;
  out << "  \\end{Large}" << endl;
  cout << "  \\begin{center}" << endl;
  out << "  \\begin{center}" << endl;
  cout << "     The equation," << endl;
  out << "     The equation," << endl;
  cout << "        \\begin{Large}" << endl;
  out << "        \\begin{Large}" << endl;
  cout << "           $(" << a << ")x^2 + (" << b << ")x + (" << c << ")$" << endl;
  out << "           $(" << a << ")x^2 + (" << b << ")x + (" << c << ")$" << endl;
  cout << "        \\end{Large}" << endl;
  out << "        \\end{Large}" << endl;
  cout << "     \\\\assuming" << endl;
  out << "     \\\\assuming" << endl;
  cout << "        \\begin{Large}" << endl;
  out << "        \\begin{Large}" << endl;
  cout << "           $a = " << a << ", b = " << b << ", c = " << c << "$" << endl;
  out << "           $a = " << a << ", b = " << b << ", c = " << c << "$" << endl;
  cout << "        \\end{Large}" << endl;
  out << "        \\end{Large}" << endl;
  cout << "     \\\\plugged into the quadratic equation is:" << endl;
  out << "     \\\\plugged into the quadratic equation is:" << endl;
  cout << "  \\end{center}" << endl;
  out << "  \\end{center}" << endl;
  cout << "  \\begin{Large}" << endl;
  out << "  \\begin{Large}" << endl;
  cout << "     $$x = \\frac{-(" << b << ") \\pm \\sqrt{(" << b << ")^2 - 4(" << a << ")(" << c << ")}}{2(" << a << ")}$$" << endl;
  out << "     $$x = \\frac{-(" << b << ") \\pm \\sqrt{(" << b << ")^2 - 4(" << a << ")(" << c << ")}}{2(" << a << ")}$$" << endl;
  cout << "  \\end{Large}" << endl;
  out << "  \\end{Large}" << endl;
  cout << "  \\begin{center}" << endl;
  out << "  \\begin{center}" << endl;
  cout << "     Simplified, is:" << endl;
  out << "     Simplified, is:" << endl;
  cout << "  \\end{center}" << endl;
  out << "  \\end{center}" << endl;
  cout << "  \\begin{Large}" << endl;
  out << "  \\begin{Large}" << endl;

  //assigning denom value
  denominator = 2 * a;
  b *= -1;

  cout << "     $$x = \\frac{(" << b << ") \\pm \\sqrt{(" << b * b << ") - (" << 4 * a * c << ")}}{(" << denominator << ")}$$" << endl;
  out << "     $$x = \\frac{(" << b << ") \\pm \\sqrt{(" << b * b << ") - (" << 4 * a * c << ")}}{(" << denominator << ")}$$" << endl;
  cout << "  \\end{Large}" << endl;
  out << "  \\end{Large}" << endl;
  cout << "  \\begin{Large}" << endl;
  out << "  \\begin{Large}" << endl;
  cout << "     $$x = \\frac{(" << b << ") \\pm \\sqrt{(" << ((b * b) - (4 * a * c)) << ")}}{(" << denominator << ")}$$" << endl;
  out << "     $$x = \\frac{(" << b << ") \\pm \\sqrt{(" << ((b * b) - (4 * a * c)) << ")}}{(" << denominator << ")}$$" << endl;
  cout << "  \\end{Large}" << endl;
  out << "  \\end{Large}" << endl;
  cout << "  \\begin{Large}" << endl;
  out << "  \\begin{Large}" << endl;

  factor_root = ((b * b) - (4 * a * c));

  //checks for negative inside root, places i variable outside of radical
  if(factor_root < 0)
  {
    imaginary = 'i';
    cout << "     $$x = \\frac{(" << b << ") \\pm \\sqrt{(" << -1 * factor_root << ")}" << imaginary << "}{(" << denominator << ")}$$" << endl;
    out << "     $$x = \\frac{(" << b << ") \\pm \\sqrt{(" << -1 * factor_root << ")}" << imaginary << "}{(" << denominator << ")}$$" << endl;
    //makes positive for further calculation
    factor_root *= -1;
  }
  else
  {
    cout << "     $$x = \\frac{(" << b << ") \\pm \\sqrt{(" << factor_root << ")}}{(" << denominator << ")}$$" << endl;
    out << "     $$x = \\frac{(" << b << ") \\pm \\sqrt{(" << factor_root << ")}}{(" << denominator << ")}$$" << endl;
  }
  cout << "  \\end{Large}" << endl;
  out << "  \\end{Large}" << endl;

  //check if divisible by 2
  while(factor_root % 2 == 0)
  {
    factor_root /= 2;
    factored_value_counter++;
    if(factored_value_counter == 2)
    {
      factored_value *= 2;
    }
  }

  //if only factored once, reverts to original root value
  if(factored_value_counter == 1)
  {
    factor_root *= 2;
  }

  //initializing factored_value_counter in case there was a carry-over from finding if factor_root is divisible by 2
  factored_value_counter = 0;

  //check if divisible by 3
  while(factor_root % 3 == 0)
  {
    factor_root /= 3;
    factored_value_counter++;
    if(factored_value_counter == 2)
    {
      factored_value *= 3;
    }
  }

  //if only factored once, reverts to original root value
  if(factored_value_counter == 1)
  {
    factor_root *= 3;
  }

  cout << "  \\begin{Large}" << endl;
  out << "  \\begin{Large}" << endl;

  //factored_value is always positive, so no reason for ()s
  cout << "     $$x = \\frac{(" << b << ") \\pm " << factored_value << "\\sqrt{(" << factor_root << ")}" << imaginary << "}{(" << denominator << ")}$$" << endl;
  out << "     $$x = \\frac{(" << b << ") \\pm " << factored_value << "\\sqrt{(" << factor_root << ")}" << imaginary << "}{(" << denominator << ")}$$" << endl;

  cout << "  \\end{Large}" << endl;
  out << "  \\end{Large}" << endl;

  //dividing out all 2's
  while((b % 2 == 0) && (factored_value % 2 == 0) && (denominator % 2 == 0))
  {
    b /= 2;
    factored_value /= 2;
    denominator /= 2;
  }

  //dividing out all 3's
  while((b % 3 == 0) && (factored_value % 3 == 0) && (denominator % 3 == 0))
  {
    b /= 3;
    factored_value /= 3;
    denominator /= 3;
  }

  cout << "  \\begin{Large}" << endl;
  out << "  \\begin{Large}" << endl;
  cout << "     $$x = \\frac{(" << b << ") \\pm \\sqrt{(" << factor_root << ")}" << imaginary << "}{(" << denominator << ")}$$" << endl;
  out << "     $$x = \\frac{(" << b << ") \\pm \\sqrt{(" << factor_root << ")}" << imaginary << "}{(" << denominator << ")}$$" << endl;
  cout << "  \\end{Large}" << endl;
  out << "  \\end{Large}" << endl;

  cout << "  \\begin{center}" << endl;
  out << "  \\begin{center}" << endl;
  cout << "     The roots are:" << endl;
  out << "     The roots are:" << endl;
  cout << "     \\begin{Large}" << endl;
  out << "     \\begin{Large}" << endl;
  cout << "        $x = \\displaystyle \\frac{1}{" << denominator << "}((" << b << ") + \\sqrt{" << factor_root << "}" << imaginary << ")$" << endl;
  out << "        $x = \\displaystyle \\frac{1}{" << denominator << "}((" << b << ") + \\sqrt{" << factor_root << "}" << imaginary << ")$" << endl;
  cout << "     \\end{Large}" << endl;
  out << "     \\end{Large}" << endl;

  cout << "     and" << endl;
  out << "     and" << endl;

  cout << "     \\begin{Large}" << endl;
  out << "     \\begin{Large}" << endl;
  cout << "        $x = \\displaystyle \\frac{1}{" << denominator << "}((" << b << ") - \\sqrt{" << factor_root << "}" << imaginary << ")$" << endl;
  out << "        $x = \\displaystyle \\frac{1}{" << denominator << "}((" << b << ") - \\sqrt{" << factor_root << "}" << imaginary << ")$" << endl;
  cout << "     \\end{Large}" << endl;
  out << "     \\end{Large}" << endl;
  cout << "  \\end{center}" << endl;
  out << "  \\end{center}" << endl;
  cout << "\\end{document}" << endl;
  out << "\\end{document}" << endl;
  out.close();

  return 0;
}
