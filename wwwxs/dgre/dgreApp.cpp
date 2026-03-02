/***************************************************************
 * Name:      dgreApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2026-02-28
 * Copyright:  ()
 * License:
 **************************************************************/

#include "dgreApp.h"

//(*AppHeaders
#include "dgreMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(dgreApp);

bool dgreApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        dgreFrame* Frame = new dgreFrame(0);
        Frame->Show();
        SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
