
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
#ifndef BOXPANEL_HPP
#define BOXPANEL_HPP

#include "IWidget.hpp"
#include <X11/Xaw/Box.h>
#include "Components.hpp"

#include <string>
using std::string;


class BoxPanel : public IWidget
{
    public:

        BoxPanel(const char*);
        virtual ~BoxPanel();
        void Create(const Widget);
        void AddChild(const IWidget&) ;
        void Release();

    private:

        const char* name;
        Components childs;
};

#endif
