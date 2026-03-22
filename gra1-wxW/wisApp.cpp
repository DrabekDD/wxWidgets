#include <wx/wx.h>           // podstawowe elementy wxWidgets
#include <wx/combobox.h>     // kontrolka ComboBox
#include <cstdlib>           // rand(), srand()
#include <ctime>             // time()

class MyFrame : public wxFrame   // klasa głównego okna
{
public:
    MyFrame()                    // konstruktor okna
        : wxFrame(nullptr, wxID_ANY, "Zgadnij liczbe", wxDefaultPosition, wxSize(430, 320)),
          secretNumber(0),       // początkowa tajna liczba
          attempts(0),           // liczba prób na start
          maxAttempts(10),       // domyślna maks. liczba prób
          gameActive(false)      // gra na starcie nie trwa
    {
        std::srand(static_cast<unsigned>(std::time(nullptr))); // inicjalizacja losowości

        wxPanel* panel = new wxPanel(this);                    // panel wewnątrz okna
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);    // główny układ pionowy

        wxBoxSizer* rangeSizer = new wxBoxSizer(wxHORIZONTAL); // układ poziomy dla zakresu

        rangeSizer->Add(new wxStaticText(panel, wxID_ANY, "Od:"), 0, wxALL | wxALIGN_CENTER_VERTICAL, 5); // napis Od:
        fromCtrl = new wxTextCtrl(panel, wxID_ANY, "1");       // pole początkowego zakresu
        rangeSizer->Add(fromCtrl, 1, wxALL, 5);                // dodanie pola do układu

        rangeSizer->Add(new wxStaticText(panel, wxID_ANY, "Do:"), 0, wxALL | wxALIGN_CENTER_VERTICAL, 5); // napis Do:
        toCtrl = new wxTextCtrl(panel, wxID_ANY, "100");       // pole końcowego zakresu
        rangeSizer->Add(toCtrl, 1, wxALL, 5);                  // dodanie pola do układu

        mainSizer->Add(rangeSizer, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 5); // dodanie sekcji zakresu

        mainSizer->Add(new wxStaticText(panel, wxID_ANY, "Poziom:"), 0, wxLEFT | wxRIGHT | wxTOP, 10); // napis Poziom:

        difficultyCtrl = new wxComboBox(                       // lista rozwijana trudności
            panel,                                             // rodzic
            wxID_ANY,                                          // automatyczne ID
            "",                                                // pusty tekst startowy
            wxDefaultPosition,                                 // domyślna pozycja
            wxDefaultSize,                                     // domyślny rozmiar
            0,                                                 // brak elementów na starcie
            nullptr,                                           // brak tablicy elementów
            wxCB_READONLY                                      // tylko wybór z listy
        );

        difficultyCtrl->Append("Latwy (10 prob)");             // dodanie poziomu łatwego
        difficultyCtrl->Append("Sredni (7 prob)");             // dodanie poziomu średniego
        difficultyCtrl->Append("Trudny (5 prob)");             // dodanie poziomu trudnego
        difficultyCtrl->SetSelection(0);                       // domyślnie łatwy

        mainSizer->Add(difficultyCtrl, 0, wxEXPAND | wxALL, 10); // dodanie ComboBox do okna

        mainSizer->Add(new wxStaticText(panel, wxID_ANY, "Twoja liczba:"), 0, wxLEFT | wxRIGHT, 10); // napis pola zgadywania

        guessCtrl = new wxTextCtrl(                            // pole wpisywania liczby
            panel,                                             // rodzic
            wxID_ANY,                                          // automatyczne ID
            "",                                                // pusty tekst początkowy
            wxDefaultPosition,                                 // domyślna pozycja
            wxDefaultSize,                                     // domyślny rozmiar
            wxTE_PROCESS_ENTER                                 // obsługa klawisza Enter
        );

        mainSizer->Add(guessCtrl, 0, wxEXPAND | wxALL, 10);    // dodanie pola do układu

        wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL); // układ poziomy przycisków

        checkBtn = new wxButton(panel, wxID_ANY, "Sprawdz");   // przycisk sprawdzania
        newGameBtn = new wxButton(panel, wxID_ANY, "Nowa gra");// przycisk nowej gry

        buttonSizer->Add(checkBtn, 1, wxALL, 5);               // dodanie przycisku Sprawdz
        buttonSizer->Add(newGameBtn, 1, wxALL, 5);             // dodanie przycisku Nowa gra

        mainSizer->Add(buttonSizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 5); // dodanie przycisków do okna

        attemptsLabel = new wxStaticText(panel, wxID_ANY, "Proby: 0 / 10"); // napis z liczbą prób
        mainSizer->Add(attemptsLabel, 0, wxLEFT | wxRIGHT | wxTOP, 10);     // dodanie napisu

        resultLabel = new wxStaticText(panel, wxID_ANY, "Kliknij 'Nowa gra', aby zaczac."); // komunikat startowy
        mainSizer->Add(resultLabel, 0, wxEXPAND | wxALL, 10);               // dodanie komunikatu

        panel->SetSizer(mainSizer);                           // przypisanie układu do panelu

        checkBtn->Bind(wxEVT_BUTTON, &MyFrame::OnCheck, this);               // kliknięcie Sprawdz
        newGameBtn->Bind(wxEVT_BUTTON, &MyFrame::OnNewGame, this);           // kliknięcie Nowa gra
        difficultyCtrl->Bind(wxEVT_COMBOBOX, &MyFrame::OnDifficultyChanged, this); // zmiana poziomu
        guessCtrl->Bind(wxEVT_TEXT_ENTER, &MyFrame::OnCheck, this);          // Enter w polu liczby

        checkBtn->Enable(false);                              // na starcie blokujemy Sprawdz
        Centre();                                             // wyśrodkowanie okna
    }

private:
    wxTextCtrl* fromCtrl;         // pole Od
    wxTextCtrl* toCtrl;           // pole Do
    wxTextCtrl* guessCtrl;        // pole zgadywania
    wxComboBox* difficultyCtrl;   // lista trudności
    wxButton* checkBtn;           // przycisk Sprawdz
    wxButton* newGameBtn;         // przycisk Nowa gra
    wxStaticText* attemptsLabel;  // etykieta liczby prób
    wxStaticText* resultLabel;    // etykieta z komunikatem

    int secretNumber;             // wylosowana liczba
    int attempts;                 // aktualna liczba prób
    int maxAttempts;              // maksymalna liczba prób
    bool gameActive;              // czy gra aktualnie trwa

    void UpdateAttemptsLabel()    // funkcja odświeżająca napis prób
    {
        attemptsLabel->SetLabel(wxString::Format("Proby: %d / %d", attempts, maxAttempts)); // nowy tekst etykiety
    }

    bool ReadRange(int& from, int& to) // odczyt zakresu z formularza
    {
        long fromVal = 0;         // tymczasowa wartość Od
        long toVal = 0;           // tymczasowa wartość Do

        if (!fromCtrl->GetValue().ToLong(&fromVal) || !toCtrl->GetValue().ToLong(&toVal)) // sprawdzenie konwersji
        {
            wxMessageBox("Podaj poprawne liczby w polach Od i Do.", "Blad", wxOK | wxICON_ERROR); // komunikat błędu
            return false;         // dane niepoprawne
        }

        if (fromVal >= toVal)     // sprawdzenie poprawności zakresu
        {
            wxMessageBox("Pole 'Od' musi byc mniejsze niz 'Do'.", "Blad", wxOK | wxICON_ERROR); // komunikat błędu
            return false;         // zły zakres
        }

        from = static_cast<int>(fromVal); // zapis poprawnej wartości Od
        to = static_cast<int>(toVal);     // zapis poprawnej wartości Do

        return true;               // wszystko poprawne
    }

    void ApplyDifficulty()         // ustawienie poziomu trudności
    {
        int sel = difficultyCtrl->GetSelection(); // pobranie indeksu wybranej opcji

        if (sel == 0)              // jeśli łatwy
            maxAttempts = 10;      // 10 prób
        else if (sel == 1)         // jeśli średni
            maxAttempts = 7;       // 7 prób
        else                       // w przeciwnym razie trudny
            maxAttempts = 5;       // 5 prób

        UpdateAttemptsLabel();     // odświeżenie etykiety prób
    }

    void StartGame()               // rozpoczęcie nowej gry
    {
        int from = 1;              // domyślny początek zakresu
        int to = 100;              // domyślny koniec zakresu

        if (!ReadRange(from, to))  // próba odczytu zakresu
            return;                // przerwanie przy błędzie

        ApplyDifficulty();         // ustawienie trudności

        secretNumber = from + (std::rand() % (to - from + 1)); // losowanie liczby z zakresu
        attempts = 0;              // wyzerowanie prób
        gameActive = true;         // oznaczenie, że gra trwa

        guessCtrl->Clear();        // wyczyszczenie pola zgadywania
        checkBtn->Enable(true);    // włączenie przycisku Sprawdz

        UpdateAttemptsLabel();     // odświeżenie licznika prób
        resultLabel->SetLabel("Gra rozpoczeta. Zgadnij liczbe."); // komunikat dla gracza
        guessCtrl->SetFocus();     // ustawienie kursora w polu zgadywania
    }

    void OnNewGame(wxCommandEvent&) // obsługa kliknięcia Nowa gra
    {
        StartGame();               // rozpoczęcie nowej gry
    }

    void OnDifficultyChanged(wxCommandEvent&) // obsługa zmiany poziomu
    {
        ApplyDifficulty();         // ustawienie nowej trudności

        if (!gameActive)           // jeśli gra jeszcze nie trwa
            resultLabel->SetLabel("Wybrano poziom. Kliknij 'Nowa gra'."); // informacja dla użytkownika
    }

    void OnCheck(wxCommandEvent&)  // obsługa sprawdzania liczby
    {
        if (!gameActive)           // jeśli gra nie została uruchomiona
        {
            wxMessageBox("Najpierw kliknij 'Nowa gra'.", "Informacja", wxOK | wxICON_INFORMATION); // komunikat
            return;                // przerwanie
        }

        long guessLong = 0;        // tymczasowa liczba wpisana przez użytkownika

        if (!guessCtrl->GetValue().ToLong(&guessLong)) // sprawdzenie czy wpis to liczba
        {
            wxMessageBox("Wpisz poprawna liczbe.", "Blad", wxOK | wxICON_ERROR); // komunikat błędu
            return;                // przerwanie
        }

        int guess = static_cast<int>(guessLong); // konwersja na int

        attempts++;                // zwiększenie liczby prób
        UpdateAttemptsLabel();     // odświeżenie etykiety prób

        if (guess == secretNumber) // jeśli użytkownik trafił
        {
            resultLabel->SetLabel(wxString::Format("Brawo! Trafiles w %d probach.", attempts)); // komunikat wygranej
            gameActive = false;    // zakończenie gry
            checkBtn->Enable(false); // wyłączenie przycisku Sprawdz
            return;                // koniec funkcji
        }

        if (attempts >= maxAttempts) // jeśli skończyły się próby
        {
            resultLabel->SetLabel(wxString::Format("Koniec gry. Szukana liczba to %d.", secretNumber)); // komunikat przegranej
            gameActive = false;    // zakończenie gry
            checkBtn->Enable(false); // wyłączenie przycisku Sprawdz
            return;                // koniec funkcji
        }

        if (guess < secretNumber)  // jeśli liczba za mała
            resultLabel->SetLabel("Za malo."); // podpowiedź
        else                       // jeśli liczba za duża
            resultLabel->SetLabel("Za duzo."); // podpowiedź

        guessCtrl->SetFocus();     // powrót kursora do pola
        guessCtrl->SelectAll();    // zaznaczenie całego wpisu
    }
};

class MyApp : public wxApp        // klasa aplikacji
{
public:
    bool OnInit() override        // funkcja startowa programu
    {
        MyFrame* frame = new MyFrame(); // utworzenie głównego okna
        frame->Show(true);              // pokazanie okna
        return true;                    // poprawny start aplikacji
    }
};

wxIMPLEMENT_APP(MyApp);           // uruchomienie aplikacji
