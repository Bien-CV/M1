#include "../include/MainFrame.h"

enum{
	ID_Start = 1,
	ID_Nina = 2
};

wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
	EVT_MENU(ID_Start,	MainFrame::OnStart)
	EVT_MENU(ID_Nina,MainFrame::OnNina)

	EVT_MENU(wxID_EXIT,	MainFrame::OnExit)
	EVT_MENU(wxID_ABOUT,MainFrame::OnAbout)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size): wxFrame(NULL,wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE & ~ (wxRESIZE_BORDER | wxMINIMIZE_BOX | wxMAXIMIZE_BOX)){
	
	// -----------------------------------------------------
	// ---------------- MENUS ------------------------------
	// ------------------------------------------------------

	wxMenu *menuFile = new wxMenu;
	menuFile->Append(ID_Start, L"&Start...\tCtrl-H", L"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);

	wxMenu *menuNina = new wxMenu;
	menuNina->Append(ID_Nina, L"&Nina...\tCtrl-N", L"Menu de Nina");
	
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append( menuFile, L"&File" );
	menuBar->Append( menuHelp, L"&Help" );
	menuBar->Append( menuNina, L"&Nina" );

	SetMenuBar( menuBar );

	//CreateStatusBar();
	//SetStatusText( L"Welcome to wxWidgets!" );

	//Create System
	_syst = new System(this);

	// ----------------------------------------------------
	// ---------------- Init Map Illustrator --------------
	// ------------------- (first Draw) -------------------
	// ----------------------------------------------------
	std::vector < std::vector<int> > vec;
	_sizer = new wxBoxSizer(wxHORIZONTAL);
	_mapIllustr = new MapIllustrator(this,_syst->getMapFirstLayer(),_syst->getMapSecondLayer(),_syst->getRobotMap(),new wxPoint(_syst->getRobotPosX(),_syst->getRobotPosY()));
	_sizer->Add(_mapIllustr, 1, wxEXPAND);
 	SetSizer(_sizer);
}

MainFrame::~MainFrame(){}

void MainFrame::OnExit(wxCommandEvent& event){
	Close ( true );
}

void MainFrame::OnAbout(wxCommandEvent& event){
	wxMessageBox( L"This is a wxWidgets' exploration simulation app", L"About MarcoPolo", wxOK | wxICON_INFORMATION );
}

void MainFrame::OnStart(wxCommandEvent& event){
	_syst->start();
}

void MainFrame::OnNina(wxCommandEvent& event){
	wxMessageBox ( L"Menu de Nina!", L"Coucou", wxOK | wxICON_INFORMATION);
}

void MainFrame::changePos(int x, int y, std::vector< std::vector<int> > mapRobot){
	_mapIllustr->changePos(x,y,mapRobot);
	Refresh();
}
