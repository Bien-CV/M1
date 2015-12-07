#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wxprec.h>
#include <wx/wx.h>
#include <vector>
#include "MapIllustrator.h"
#include "System.h"

class System;

class MainFrame: public wxFrame{

	public:
		MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
		virtual ~MainFrame();

		void changePos(int x, int y, std::vector< std::vector<int> > mapRobot);
	private:
		// -------------------------------
		// --------- ATTRIBUTS -----------
		// -------------------------------
		MapIllustrator * _mapIllustr;
		wxBoxSizer* _sizer;
		System* _syst;

		// -------------------------------
		// ---------- EVENTS -------------
		// -------------------------------
		void OnStart(wxCommandEvent& event);
		void OnExit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);
		void OnNina(wxCommandEvent& event);
		
		wxDECLARE_EVENT_TABLE();
};

#endif
