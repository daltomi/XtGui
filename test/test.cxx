/* 
XtGui -  Copyright (©) 2012,2021 daltomi <daltomi@disroot.org>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or 
(at your option) any later version.

This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
GNU General Public License for more details.

You should have received a copy of the GNU General Public License 
along with this program.  If not, see http://www.gnu.org/licenses/.
*/

#include "Widgets/Label.hpp"
#include "Widgets/Button.hpp"
#include "XtGui.hpp"

#include <ostream>
using std::cout;
using std::endl;

void cb_menu(const char*);
void cb_button(const char*);
void cb_about(const char*);
void cb_exit_program();


XtGui*  gui; 
Label   label("-------XtGui-------\n-------------------");
Button  button("Hide Label", cb_button);
Button  button_all("<<", cb_button);
bool    hide = false;


int main(int argc, char** argv)
{
    const unsigned int width = 400;
    const unsigned int height= 420;

    gui = new XtGui("XTest", argc, argv, width, height);

    gui->Attach(label);
    gui->Attach(button);
    gui->Attach(button_all);

    gui->AddMenu("App");
    gui->AddSubMenu("Quit", cb_menu);

    gui->AddMenu("Edit");
    gui->AddSubMenu("Copy", cb_menu);
    gui->AddSubMenu("Paste", cb_menu);
    gui->AddLineMenu();
    gui->AddSubMenu("Properties...", cb_menu);
    
    gui->AddMenu("Help");
    gui->AddSubMenu("About..", cb_about);
    
    gui->Run(&cb_exit_program);
}


//callback
void cb_menu(const char* name)
{
    const string quit("Quit");

    if(name == quit )
    {
        cb_exit_program();
    }
    else
    {
        string str("Menu Select:\n");
        str += name;
        label.SetText(str.c_str() );
     }
}


//callback
void cb_exit_program()
{
    delete gui;
    exit(0);
}


//callback
void cb_about(const char* title)
{
    const char* label = "XtGui by daltomi@disroot.org";
    const char* button = "Done";

    gui->Message(title,label, button);
}


//callback
void cb_button(const char*)
{
    if(!hide)
    {
        label.Hide();
        button.SetText("Show Label");
    }
    else
    {
        label.Show();
        button.SetText("Hide Label");
    }
    hide = !hide;
}


