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

#ifndef GRIP_HPP
#define GRIP_HPP

#include "IWidget.hpp"
#include <X11/Xaw/Porthole.h>
#include "Components.hpp"


class Grip : public IWidget
{
    public:

        Grip(const char*);
        virtual ~Grip();
        void Create(const Widget);
        void AddChild(const IWidget&) ;

    private:

        const char*  name;
        Components childs;
};

#endif
