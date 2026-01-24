#pragma once
#include <wx/wx.h>


class MyFrame : public wxFrame
{
public:
    MyFrame(wxWindow* parent, wxWindowID id, const wxString& title,
            const wxPoint& pos, const wxSize& size, long style);
private:
    wxStatusBar* sb = nullptr;
    // tworzymy menu
    // jeden pasek menu
    wxMenuBar* mb;
    // w pasku dwie pozycje
    wxMenu* mFile;
    wxMenu* mHelp;
    // elementy rozwijalne - podmenu do mFile i mHelp
    // pomijamy w wypadku proszczenia przez Appent
    // wxMenuItem* mShowDateTime;
    // wxMenuItem* mShowSystemVersion;
    // wxMenuItem* mClose;
    // wxMenuItem* mAboutProgram;
};
