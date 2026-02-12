/***************************************************************
 * Name:      wxSApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-13
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wxSApp.h"

//(*AppHeaders
#include "wxSMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxSApp);

bool wxSApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxSFrame* Frame = new wxSFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
