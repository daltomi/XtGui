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
#include "Components.hpp"


////////////////////////
Components::Components() 
////////////////////////
{ 

}


/////////////////////////////////////////////
void Components::add(const IWidget& w) 
/////////////////////////////////////////////
{
    push_back( const_cast<IWidget*>(&w) );
}


/////////////////////////
Components::~Components() 
/////////////////////////
{ 

}


///////////////////////////////////////////////////
void Components::create(const Widget parent)  const
///////////////////////////////////////////////////
{
    for_each(begin(), end(), [&parent](IWidget* ptr){ ptr->Create(parent);});
}


///////////////////////////
void Components::release()
///////////////////////////
{
    for_each(begin(), end(), [](IWidget* ptr){ delete ptr;} );
}



