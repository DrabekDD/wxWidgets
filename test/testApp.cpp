/***************************************************************
 * Name:      testApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-23
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "testApp.h"

//(*AppHeaders
#include "testMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(testApp);

bool testApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	testFrame* Frame = new testFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
