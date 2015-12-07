#include "../include/MarcoPolo.h"

wxIMPLEMENT_APP(MarcoPolo);

bool MarcoPolo::OnInit(){
	_frame = new MainFrame(L"Marco Polo", wxPoint(50,50), wxSize(772,512) );
	//  --------------------- ----------
	//	|					| |        |
	//	|					| |        |
	//	|					| |        |
	//	|					| ==========
	//	|					| |        |
	//	|					| |        |
	//	|					| |		   |
	//  --------------------- ----------
	
	// masta : 32*32 de 16*16 --> 512*512
	// mini bas droit : 32*32 de 8*8 ----->	256*256
	// horiz sepa = 4px
	// mini haut droit : 9*9 de 28*28 -----> 252*252
	// vertical sepa = 4px
	

    _frame->SetAutoLayout(true);
	_frame->Show(true);
	return true;
}
