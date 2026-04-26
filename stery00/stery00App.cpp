/***************************************************************
 * Name:      stery00App.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-26
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "stery00App.h"
#include "stery00Main.h"

IMPLEMENT_APP(stery00App);

bool stery00App::OnInit()
{
    stery00Frame* frame = new stery00Frame(0L, _("wxWidgets Application Template"));
    
    frame->Show();
    
    return true;
}
