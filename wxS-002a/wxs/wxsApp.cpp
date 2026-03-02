/***************************************************************
 * Name:      wxsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-28
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxsApp.h"

//(*AppHeaders
#include "wxsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxsApp);

bool wxsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxsFrame* Frame = new wxsFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
