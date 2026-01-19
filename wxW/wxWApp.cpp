/***************************************************************
 * Name:      wxWApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-01-18
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxWApp.h"
#include "wxWMain.h"

IMPLEMENT_APP(wxWApp);

bool wxWApp::OnInit()
{
    wxWFrame* frame = new wxWFrame(0L, _("wxWidgets Application Template"));
    
    frame->Show();
    
    return true;
}
