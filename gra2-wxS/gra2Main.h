/***************************************************************
 * Name:      gra2Main.h
 * Purpose:   Defines Application Frame
 * Author:    DD (kyczbard@gmail.com)
 * Created:   2026-03-18
 * Copyright: DD ()
 * License:
 **************************************************************/

#ifndef GRA2MAIN_H
#define GRA2MAIN_H

//(*Headers(gra2Frame)
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class gra2Frame: public wxFrame
{
    public:

        gra2Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~gra2Frame();

    private:

        //(*Handlers(gra2Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnNewGame(wxCommandEvent& event);
        void OncomboPoziom(wxCommandEvent& event);
        void OnSprawdz(wxCommandEvent& event);
        //*)

        //(*Identifiers(gra2Frame)
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT1;
        static const long ID_TEXT_OD;
        static const long ID_STATICTEXT2;
        static const long ID_TEXT_DO;
        static const long ID_STATICTEXT4;
        static const long ID_COMBO_POZIOM;
        static const long ID_STATICTEXT5;
        static const long ID_TEXT_PROBA;
        static const long ID_BUTT_SPRAWDZ;
        static const long ID_BUT_NEW_GAME;
        static const long ID_LBL_PROBA;
        static const long ID_LBL_WYNIK;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(gra2Frame)
        wxButton* butNewGame;
        wxButton* butSprawdz;
        wxComboBox* comboPoziom;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* lblProba;
        wxStaticText* lblWynik;
        wxTextCtrl* ctrlDo;
        wxTextCtrl* ctrlOd;
        wxTextCtrl* ctrlProba;
        //*)

        bool ReadRange(int& fromx, int& toy);
        void UstawPoziom();

        int proba=0;                 // aktualna liczba prób
        int maxproba=10;              // maksymalna liczba prób
        int los;                   // wylosowana liczba
        bool gameActive;           // czy gra aktualnie trwa

        DECLARE_EVENT_TABLE()
};

#endif // GRA2MAIN_H
