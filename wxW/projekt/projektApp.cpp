/***************************************************************
 * Name:      projektApp.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-02-09
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "projektApp.h"
#include "projektMain.h"

IMPLEMENT_APP(projektApp);

bool projektApp::OnInit()
{
    projektFrame* frame = new projektFrame(0L, _("wxWidgets Application Template"));
    
    frame->Show();
    
    return true;
}
