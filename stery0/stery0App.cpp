/***************************************************************
 * Name:      stery0App.cpp
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

#include "stery0App.h"
#include "stery0Main.h"

IMPLEMENT_APP(stery0App);

bool stery0App::OnInit()
{
    stery0Frame* frame = new stery0Frame(0L, _("wxWidgets Application Template"));
    
    frame->Show();
    
    return true;
}
