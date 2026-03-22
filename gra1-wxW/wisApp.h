/***************************************************************
 * Name:      wisApp.h
 * Purpose:   Defines Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-18
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef WISAPP_H
#define WISAPP_H

#include <wx/app.h>

class wisApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WISAPP_H
