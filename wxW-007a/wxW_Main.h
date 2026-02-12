#pragma once
#include <wx/wx.h>

class MyFrame : public wxFrame
{
public:
    MyFrame(wxWindow* parent, wxWindowID id, const wxString& title,
            const wxPoint& pos, const wxSize& size, long style);
private:
    enum{
        ID_SHOW_DATE = wxID_HIGHEST + 1,
        ID_SHOW_OS,
        ID_EXIT,
        ID_ABOUT,
        ID_TOOL_NEW,
        ID_TOOL_OPEN,
        ID_TOOL_SAVE
    };
    // ---- Budowa UI ----
    void CreateMainMenu();
    void CreateMainToolBar();
    void CreateMainStatusBar();
    void BindEvents();
    void UpdateStatusBarGeometry();
    // ---- Handlery ----
    void OnShowDate(wxCommandEvent& event);
    void OnShowOS(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnMove(wxMoveEvent& event);
    void OnSize(wxSizeEvent& event);

    wxMenuBar* mb = nullptr;
    wxMenu* mFile = nullptr;
    wxMenu* mHelp = nullptr;
    wxToolBar* tb = nullptr;
    wxStatusBar* sb = nullptr;
};
