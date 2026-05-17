/***************************************************************
 * Name:      wykresApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-05-17
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wykresApp.h"

//(*AppHeaders
#include "wykresMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wykresApp);

bool wykresApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wykresFrame* Frame = new wykresFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
