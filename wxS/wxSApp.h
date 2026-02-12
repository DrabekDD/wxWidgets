/***************************************************************
 * Name:      wxSApp.h
 * Purpose:   Defines Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-13
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef WXSAPP_H
#define WXSAPP_H

#include <wx/app.h>

class wxSApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WXSAPP_H
