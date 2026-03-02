/***************************************************************
 * Name:      asdsadApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-28
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "asdsadApp.h"

//(*AppHeaders
#include "asdsadMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(asdsadApp);

bool asdsadApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	asdsadFrame* Frame = new asdsadFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
