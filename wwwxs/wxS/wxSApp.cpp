/***************************************************************
 * Name:      wxSApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2026-02-28
 * Copyright:  ()
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
        wxSDialog Dlg(NULL);
        SetTopWindow(&Dlg);
        Dlg.ShowModal();
        wxsOK = false;
    }
    //*)
    return wxsOK;

}
