/***************************************************************
 * Name:      wxSddApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-28
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxSddApp.h"

//(*AppHeaders
#include "wxSddMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxSddApp);

bool wxSddApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxSddFrame* Frame = new wxSddFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
