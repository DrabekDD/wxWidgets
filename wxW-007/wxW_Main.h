#pragma once
#include <wx/wx.h>

class MyFrame : public wxFrame
{
public:
    MyFrame(wxWindow* parent, wxWindowID id, const wxString& title,
            const wxPoint& pos, const wxSize& size, long style);
private:
    wxMenuBar* mb = nullptr;
    wxMenu* mFile = nullptr;
    wxMenu* mHelp = nullptr;
    wxToolBar* tb = nullptr;
    wxStatusBar* sb = nullptr;
};
