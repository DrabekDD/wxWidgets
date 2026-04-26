/***************************************************************
 * Name:      wxSgrafEuklidesApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-04-26
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxSgrafEuklidesApp.h"

//(*AppHeaders
#include "wxSgrafEuklidesMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxSgrafEuklidesApp);

bool wxSgrafEuklidesApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxSgrafEuklidesFrame* Frame = new wxSgrafEuklidesFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
