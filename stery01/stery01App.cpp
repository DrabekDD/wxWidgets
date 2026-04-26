/***************************************************************
 * Name:      stery01App.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-26
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "stery01App.h"

//(*AppHeaders
#include "stery01Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(stery01App);

bool stery01App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	stery01Frame* Frame = new stery01Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
