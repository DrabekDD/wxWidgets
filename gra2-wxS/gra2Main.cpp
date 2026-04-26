/***************************************************************
 * Name:      gra2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-18
 * Copyright: DD ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "gra2Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(gra2Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(gra2Frame)
const long gra2Frame::ID_STATICTEXT3 = wxNewId();
const long gra2Frame::ID_STATICTEXT1 = wxNewId();
const long gra2Frame::ID_TEXT_OD = wxNewId();
const long gra2Frame::ID_STATICTEXT2 = wxNewId();
const long gra2Frame::ID_TEXT_DO = wxNewId();
const long gra2Frame::ID_STATICTEXT4 = wxNewId();
const long gra2Frame::ID_COMBO_POZIOM = wxNewId();
const long gra2Frame::ID_STATICTEXT5 = wxNewId();
const long gra2Frame::ID_TEXT_PROBA = wxNewId();
const long gra2Frame::ID_BUTT_SPRAWDZ = wxNewId();
const long gra2Frame::ID_BUT_NEW_GAME = wxNewId();
const long gra2Frame::ID_LBL_PROBA = wxNewId();
const long gra2Frame::ID_LBL_WYNIK = wxNewId();
const long gra2Frame::ID_RICHTEXTCTRL1 = wxNewId();
const long gra2Frame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(gra2Frame,wxFrame)
    //(*EventTable(gra2Frame)
    //*)
END_EVENT_TABLE()

gra2Frame::gra2Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(gra2Frame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* mainS;

    Create(parent, wxID_ANY, _("ZGADNIJ LICZBE"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(361,450));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(224,200), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    mainS = new wxBoxSizer(wxVERTICAL);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("\nWybierz zakres z jakiego bedzie losowana liczba"), wxDefaultPosition, wxSize(370,36), wxALIGN_LEFT|wxFULL_REPAINT_ON_RESIZE, _T("ID_STATICTEXT3"));
    mainS->Add(StaticText3, 0, wxALL|wxEXPAND, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _(" Od: "), wxPoint(-1,-1), wxSize(31,19), 0, _T("ID_STATICTEXT1"));
    BoxSizer1->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ctrlOd = new wxTextCtrl(Panel1, ID_TEXT_OD, _("0"), wxDefaultPosition, wxSize(70,31), 0, wxDefaultValidator, _T("ID_TEXT_OD"));
    BoxSizer1->Add(ctrlOd, 6, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(9,7,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Do: "), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ctrlDo = new wxTextCtrl(Panel1, ID_TEXT_DO, _("100"), wxDefaultPosition, wxSize(78,31), 0, wxDefaultValidator, _T("ID_TEXT_DO"));
    BoxSizer1->Add(ctrlDo, 6, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    mainS->Add(BoxSizer1, 0, wxALL, 5);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Wybierz poziom"), wxDefaultPosition, wxSize(301,20), wxST_NO_AUTORESIZE|wxALIGN_LEFT|wxBORDER_NONE, _T("ID_STATICTEXT4"));
    mainS->Add(StaticText4, 0, wxALL|wxEXPAND, 5);
    comboPoziom = new wxComboBox(Panel1, ID_COMBO_POZIOM, wxEmptyString, wxDefaultPosition, wxSize(347,37), 0, 0, 0, wxDefaultValidator, _T("ID_COMBO_POZIOM"));
    comboPoziom->SetSelection( comboPoziom->Append(_("prosty (10 prob)")) );
    comboPoziom->Append(_("sredni (7 prob)"));
    comboPoziom->Append(_("trudny (5 prob)"));
    mainS->Add(comboPoziom, 0, wxALL|wxEXPAND, 5);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Podaj twoja liczbe"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    mainS->Add(StaticText5, 0, wxALL|wxEXPAND, 5);
    ctrlProba = new wxTextCtrl(Panel1, ID_TEXT_PROBA, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXT_PROBA"));
    mainS->Add(ctrlProba, 0, wxALL|wxEXPAND, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    butSprawdz = new wxButton(Panel1, ID_BUTT_SPRAWDZ, _("Sprawdz"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTT_SPRAWDZ"));
    butSprawdz->Disable();
    BoxSizer2->Add(butSprawdz, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    butNewGame = new wxButton(Panel1, ID_BUT_NEW_GAME, _("Nowa  gra"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUT_NEW_GAME"));
    BoxSizer2->Add(butNewGame, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    mainS->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
    lblProba = new wxStaticText(Panel1, ID_LBL_PROBA, _("a"), wxDefaultPosition, wxSize(351,22), 0, _T("ID_LBL_PROBA"));
    mainS->Add(lblProba, 0, wxALL|wxEXPAND, 5);
    lblWynik = new wxStaticText(Panel1, ID_LBL_WYNIK, _("b"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_LBL_WYNIK"));
    mainS->Add(lblWynik, 0, wxALL|wxEXPAND, 5);
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    mainS->Add(RichTextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(mainS);
    mainS->Fit(Panel1);
    mainS->SetSizeHints(Panel1);

    Connect(ID_COMBO_POZIOM,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&gra2Frame::OncomboPoziom);
    Connect(ID_TEXT_PROBA,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&gra2Frame::OnSprawdz);
    Connect(ID_BUTT_SPRAWDZ,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gra2Frame::OnSprawdz);
    Connect(ID_BUT_NEW_GAME,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gra2Frame::OnNewGame);
    //*)

    lblWynik->SetLabel("Wybierz poziom i kliknij 'Nowa gra'."); // informacja dla użytkownika
    lblProba->SetLabel(wxString::Format("Proby: %d / %d", proba, maxproba));
    butNewGame->SetFocus();


}

bool gra2Frame::ReadRange(int& fromx, int& toy) {
    long odx = 0;               // tymczasowa wartość Od
    long doy = 0;               // tymczasowa wartość Do
    if (!ctrlOd->GetValue().ToLong(&odx) || !ctrlDo->GetValue().ToLong(&doy)) {
        wxMessageBox("Podaj poprawne liczby w polach Od i Do.", "Blad", wxOK | wxICON_ERROR); // komunikat błędu
        return false;       // dane niepoprawne
    }
    if (odx >= doy){            // sprawdzenie poprawności zakresu
        wxMessageBox("Pole 'Od' musi byc mniejsze niz 'Do'.", "Blad", wxOK | wxICON_ERROR); // komunikat błędu
        return false;       // zły zakres
    }
    fromx = static_cast<int>(odx);      // zapis poprawnej wartości Od
    toy = static_cast<int>(doy);        // zapis poprawnej wartości Do
    return true;                        // wszystko poprawne
}



void gra2Frame::UstawPoziom(){         // ustawienie poziomu trudności
    int sel = comboPoziom->GetSelection(); // pobranie indeksu wybranej opcji
    if (sel == 0) maxproba = 10;
    else if (sel == 1) maxproba = 7;
    else maxproba = 5;
    lblProba->SetLabel(wxString::Format("Proby: %d / %d", proba, maxproba));
    }


gra2Frame::~gra2Frame()
{
    //(*Destroy(gra2Frame)
    //*)
}

void gra2Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void gra2Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}


void gra2Frame::OnNewGame(wxCommandEvent& event)
{
    int fromx = 1;                                                                  // domyślny początek zakresu
    int toy = 100;                                                                  // domyślny koniec zakresu
    // tu sobie napisze jak zmienić zakres
    if (!ReadRange(fromx, toy))                                                     // próba odczytu zakresu
    return;                                                                         // przerwanie przy błędzie
    // tu sobie ustawie poziom trudności czyli zmienną maxproba
    UstawPoziom();                                                                  // ustawienie trudności
    los = fromx + (std::rand() % (toy - fromx + 1));                                // losowanie liczby z zakresu
    proba = 0;                                                                      // wyzerowanie prób
    gameActive = true;                                                              // oznaczenie, że gra trwa
    ctrlProba->Clear();                                                             // wyczyszczenie pola zgadywania
    butSprawdz->Enable(true);                                                       // włączenie przycisku Sprawdz
    comboPoziom->Enable(false);                                                     // wyłączenie combo
    lblProba->SetLabel(wxString::Format("Proby: %d / %d", proba, maxproba));        // odświeżenie licznika prób
    lblWynik->SetLabel("Gra rozpoczeta. Zgadnij liczbe.");                          // komunikat dla gracza
    butSprawdz->SetFocus();                                                         // ustawienie kursora w polu zgadywania

}

void gra2Frame::OncomboPoziom(wxCommandEvent& event)
{
    int sel = comboPoziom->GetSelection();                                          // pobranie indeksu wybranej opcji
    if (sel == 0) maxproba = 10;
    else if (sel == 1) maxproba = 7;
    else maxproba = 5;
    if (!gameActive){                                                               // jeśli gra jeszcze nie trwa
        lblWynik->SetLabel("Wybrano poziom. Kliknij 'Nowa gra'.");
        lblProba->SetLabel(wxString::Format("Proby: %d / %d", proba, maxproba));
    }
    else{
    // właściwie nie wiem co
    };

}

void gra2Frame::OnSprawdz(wxCommandEvent& event)
{

    if (!gameActive){
        wxMessageBox("Najpierw kliknij 'Nowa gra'.", "Informacja", wxOK | wxICON_INFORMATION);
        return;
    }
    long liczaWpisana = 0;                                                                          // liczba wpisana przez użytkownika
    if (!ctrlProba->GetValue().ToLong(&liczaWpisana)) {                                             // sprawdzenie czy wpis to liczba
            wxMessageBox("Wpisz poprawna liczbe.", "Blad", wxOK | wxICON_ERROR);
            return;
    }
    int liczba = static_cast<int>(liczaWpisana);
    proba++;                                                                                        // zwiększenie liczby prób
    lblProba->SetLabel(wxString::Format("Proby: %d / %d", proba, maxproba));
    if (liczba == los) {                                                                            // jeśli użytkownik trafił
        lblWynik->SetLabel(wxString::Format("Brawo! Trafiles w %d probach.", proba));               // komunikat wygranej
        gameActive = false;
        butSprawdz->Enable(false);
        comboPoziom->Enable(true);
        return;
    }
    if (proba >= maxproba) {                                                                        // jeśli skończyły się próby
        lblWynik->SetLabel(wxString::Format("Koniec gry - PRZEGRANA. Szukana liczba to %d.", los));
        gameActive = false;
        butSprawdz->Enable(false);
        comboPoziom->Enable(true);
        return;
    }
    if (liczba < los)                                                                               // jeśli pudło
        lblWynik->SetLabel(wxT("Za mało."));
    else
        lblWynik->SetLabel("Za duzo.");

    ctrlProba->SetFocus();
    ctrlProba->SelectAll();

}



