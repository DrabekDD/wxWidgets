/***************************************************************
 * Name:      wxWApp.h
 * Purpose:   Defines Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-01-18
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef WXWAPP_H
#define WXWAPP_H

#include <wx/app.h>

class wxWApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WXWAPP_H
