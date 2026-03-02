/***************************************************************
 * Name:      dddddApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-28
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "dddddApp.h"

//(*AppHeaders
#include "dddddMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(dddddApp);

bool dddddApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	dddddFrame* Frame = new dddddFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
