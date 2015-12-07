#ifndef MARCOPOLO_H
#define MARCOPOLO_H

#include <wx/wxprec.h>
#include <wx/sizer.h>
#include <wx/wx.h>
#include "MainFrame.h"

class MarcoPolo:public wxApp{
private:
	MainFrame * _frame;

public:
	virtual bool OnInit();
};

#endif
