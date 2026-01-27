#pragma once
#include <wx/wx.h>


class MyFrame : public wxFrame
{
public:
    MyFrame(wxWindow* parent, wxWindowID id, const wxString& title,
            const wxPoint& pos, const wxSize& size, long style);
private:
    // konieczne jedynie gdy mamy manualny wskaźnik
    // wxStatusBar* sb = nullptr;
};
