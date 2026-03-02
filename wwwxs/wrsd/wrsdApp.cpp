/***************************************************************
 * Name:      wrsdApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2026-02-28
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "wrsdApp.h"

//(*AppHeaders
#include "wrsdMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wrsdApp);

bool wrsdApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        wrsdFrame* Frame = new wrsdFrame(0);
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
