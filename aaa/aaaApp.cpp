/***************************************************************
 * Name:      aaaApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-25
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "aaaApp.h"

//(*AppHeaders
#include "aaaMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(aaaApp);

bool aaaApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	aaaFrame* Frame = new aaaFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
