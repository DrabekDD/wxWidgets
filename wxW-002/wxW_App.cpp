#include "wxW_App.h"
#include "wxW_Main.h"

const wxString appName = "wxWidgets - modyfikujemy okno";

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

/*
bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(appName);
    frame->Show(true);
    return true;
}

zmiana wywołania w OnInit()

*/
bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(NULL,
                                 wxID_ANY,
                                 appName,
                                 wxPoint(100, 100),
                                 wxSize(1000, 600),
                                 wxCAPTION | wxMINIMIZE_BOX | wxCLOSE_BOX);
    frame->Show(true);
    return true;
}

/*
1) Okno z podręcznika
   Podany styl nie zawiera wxRESIZE_BORDER ani wxMAXIMIZE_BOX, więc
   nie da się swobodnie zmieniać rozmiaru i nie da się minimalizować okna

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(NULL,
                                 wxID_ANY,
                                 appName,
                                 wxPoint(100, 100),
                                 wxSize(1000, 600),
                                 wxCAPTION | wxMINIMIZE_BOX | wxCLOSE_BOX);
    frame->Show(true);
    return true;
}

2)Okno o stałym rozmiarze, bez możliwości zmiany, tylko zamykanie
  "okienko narzędziowe lub dialogowe"

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(
        NULL,
        wxID_ANY,
        "Okno nierozszerzalne",
        wxPoint(50, 50),
        wxSize(640, 480),
        wxCAPTION | wxCLOSE_BOX | wxSYSTEM_MENU
    );

    frame->Show(true);
    return true;
}

3) Okno normalne

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(
        NULL,
        wxID_ANY,
        "Pełne okno aplikacji",
        wxPoint(200, 150),
        wxSize(900, 700),
        wxDEFAULT_FRAME_STYLE | wxRESIZE_BORDER
    );

    frame->Show(true);
    return true;
}

4) Okno dziwne

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(
        NULL,
        wxID_ANY,
        "Dziwne okno (niewidoczny tytul)",
        wxPoint(37, 73),
        wxSize(333, 222),
        wxFRAME_NO_TASKBAR      // nie pokazuj na pasku zadan
        | wxSTAY_ON_TOP         // zawsze na wierzchu
        | wxBORDER_NONE         // bez ramki
    );

    // Dodatkowe "dziwności"
    frame->SetTransparent(170); // 0..255 (dziala na wielu systemach, ale nie zawsze)
    frame->SetBackgroundColour(wxColour(20, 20, 20)); // ciemne tlo
    frame->SetToolTip("To okno nie ma paska tytulu. Zamknij je Alt+F4 :)");

    frame->Show(true);
    frame->Raise();
    return true;
}
*/
