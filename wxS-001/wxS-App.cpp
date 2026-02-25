/***************************************************************
 * Name:      wxS001App.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-25
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxS-App.h"

//(*AppHeaders
#include "wxS-Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxS001App);

bool wxS001App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxS001Frame* Frame = new wxS001Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
