#ifndef LINE_EDITOR_H
#define LINE_EDITOR_H

#include <string>
#include <vector>

using std::vector;
using std::string;

void line_editor_menu();
void create_new_file();
void open_new_file();
void write_menu(vector<string>& program, string file_name);
void print_program(vector<string> program);
void insert_text(vector<string>& program);
void append_text(vector<string>& program);
void delete_lines(vector<string>& program);
void write_program(vector<string> program, string file_name);

#endif
