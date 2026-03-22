/***************************************************************
 * Name:      gra2App.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-18
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "gra2App.h"

//(*AppHeaders
#include "gra2Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(gra2App);

bool gra2App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	gra2Frame* Frame = new gra2Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
