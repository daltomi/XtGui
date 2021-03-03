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
#ifndef FORMAPANEL_HPP
#define FORMAPANEL_HPP

#include "IWidget.hpp"
#include <X11/Xaw/Form.h>
#include "Components.hpp"

#include <iostream>
using std::cerr;
using std::endl;

class FormPanel : public IWidget
{
    public:

        FormPanel(const char* );
        virtual ~FormPanel();
        void Create(const Widget);
        void AddChild(const IWidget&);

    private:

        Components childs;
        const char*  name;
};

#endif

