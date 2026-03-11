#include "wxW_App.h"
#include "wxW_Main.h"

const wxString appName = "wxWidgets";

wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
    frame = new MyFrame(nullptr, wxID_ANY, appName, wxPoint(200, 150),
                     wxSize(900, 700), wxDEFAULT_FRAME_STYLE | wxRESIZE_BORDER);
    frame->Show();
    return true;
}
