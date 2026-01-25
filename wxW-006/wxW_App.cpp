#include "wxW_App.h"
#include "wxW_Main.h"

const wxString appName = "wxW - tworzymy menu";
//(*AppHeaders
#include <wx/image.h>
//*)

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	//(*AppInitialize
	bool wxsOK = true;
	wxInitAllImageHandlers();
	//*)
	return wxsOK;

    MyFrame* frame = new MyFrame(NULL, wxID_ANY, appName, wxPoint(200, 150),
        wxSize(900, 700), wxDEFAULT_FRAME_STYLE | wxRESIZE_BORDER
    );
    frame->Show(true);
    return true;
}


