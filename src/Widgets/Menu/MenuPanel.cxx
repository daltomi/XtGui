/* 
XtGui - Copyright (©) 2012,2021 daltomi <daltomi@disroot.org>

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
#include "MenuPanel.hpp"

//////////////////////////////////////////////////////////////
MenuPanel::MenuPanel(const char* _name) : boxPanel( _name ) 
//////////////////////////////////////////////////////////////
{ 

}


////////////////////////
MenuPanel::~MenuPanel()
////////////////////////
{ 
   boxPanel.Release(); 
}


///////////////////////////////////////////
Menu* MenuPanel::AddItem(const char* _name)
///////////////////////////////////////////
{
    Menu* menu = new Menu(_name);
    boxPanel.AddChild(*menu);
    return menu;
}


////////////////////////////////////////////
void MenuPanel::Create(const Widget parent)
////////////////////////////////////////////
{
    boxPanel.Create(parent);
}


