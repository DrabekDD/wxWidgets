/***************************************************************
 * Name:      cykloApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-05-14
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "cykloApp.h"

//(*AppHeaders
#include "cykloMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(cykloApp);

bool cykloApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	cykloFrame* Frame = new cykloFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
