/***************************************************************
 * Name:      test11App.cpp
 * Purpose:   Code for Application Class
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-04-29
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "test11App.h"

//(*AppHeaders
#include "test11Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(test11App);

bool test11App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	test11Frame* Frame = new test11Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
