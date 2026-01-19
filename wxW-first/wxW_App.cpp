#include "wxW_firstApp.h"
#include "wxW_firstMain.h"

const wxString appName = "Pierwszy program wxWidgets";

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(appName);
    frame->Show(true);
    return true;
}


