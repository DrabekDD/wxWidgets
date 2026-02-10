#pragma once
#include <wx/wx.h>


class MyFrame : public wxFrame
{
public:
    MyFrame(wxWindow* parent, wxWindowID id, const wxString& title,
            const wxPoint& pos, const wxSize& size, long style);
private:
    wxStatusBar* sb = nullptr;
    // jeden pasek menu
    wxMenuBar* mb = nullptr;
    // w pasku dwie pozycje
    wxMenu* mFile = nullptr;
    wxMenu* mHelp = nullptr;

    void CreateMyToolbar();
    wxToolBar* tb = nullptr;
};
