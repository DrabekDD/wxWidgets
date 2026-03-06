/***************************************************************
 * Name:      wwxSApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-04
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wwxSApp.h"

//(*AppHeaders
#include "wwxSMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wwxSApp);

bool wwxSApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wwxSFrame* Frame = new wwxSFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
