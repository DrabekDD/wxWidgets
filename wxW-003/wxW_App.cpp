#include "wxW_App.h"
#include "wxW_Main.h"

const wxString appName = "wxWidgets - modyfikujemy okno";

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(
        NULL,
        wxID_ANY,
        appName,
        wxPoint(200, 150),
        wxSize(900, 700),
        wxDEFAULT_FRAME_STYLE | wxRESIZE_BORDER
    );

    frame->Show(true);
    return true;
}


