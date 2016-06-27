#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int a, b, c;
  int font_size;

  a = 1;
  b = 2;
  c = 3;
  font_size = 11;

  cout << "Quadratic Equation calculator to LaTeX v1.0.0" << endl;

  /*
  cout << "Enter the font pt size you want for your LaTeX doc: ";
  cin >> font_size;

  cout << "Of the form: ax^2 + bx + c" << endl;
  cout << "Enter the value of a: ";
  cin >> a;
  cout << "Enter the value of b: ";
  cin >> b;
  cout << "Enter the value of c: ";
  cin >> c;
  */

  cout << endl;
  cout << "\\documentclass[" << font_size << "]{article}\n";
  cout << "\\usepackage{fullpage}" << endl;
  cout << "\\usepackage{amsfonts}" << endl;
  cout << "\\usepackage{graphicx}" << endl;

  cout << endl;
  cout << "\\begin{document}" << endl;
  cout << " \\begin{center}" << endl;
  cout << "  The Quadratic Equation is defined as:" << endl;
  cout << " \\end{center}" << endl;
  cout << " \\begin{Large}" << endl;
  cout << "  $$x = \\frac{-(" << b << ") \\pm \\sqrt{" << b << "^2 - 4(" << a << ")(" << c << ")}}{2(" << a << ")}" << endl;
  return 0;
}
