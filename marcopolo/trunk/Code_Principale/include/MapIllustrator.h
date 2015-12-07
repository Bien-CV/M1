#ifndef MAPILLUSTRATOR_H
#define MAPILLUSTRATOR_H

#include "wx/wx.h"
#include "wx/sizer.h"
#include <vector>
#include <iostream>
 
class MapIllustrator : public wxPanel
{
private:
	// ------------------------------------
	// ------ pixels screen settings ------
	// ------------------------------------
	int _rmsCelluleHeight;
	int _rmsCelluleWidth;
	int _zrsCelluleHeight;
	int _zrsCelluleWidth;
	int _fmsCelluleHeight;
	int _fmsCelluleWidth;
	int _horrizontalSpacerSize;
	int _verticalSpacerSize;
	int _zoomSize;

	wxPoint * _robotPos;
	std::vector< std::vector<int> > _mapFirstLayer;
	std::vector< std::vector<int> > _mapSecondLayer;
	std::vector< std::vector<int> > _robotMap;

	std::vector<wxImage*> _imgsRobotMap;
	std::vector<wxImage*> _imgsZoomMap;
	std::vector<wxImage*> _imgsFullMap;
public:
	
    MapIllustrator(wxFrame* parent, std::vector< std::vector<int> > mapFirstLayer, std::vector< std::vector<int> > mapSecondLayer, std::vector< std::vector<int> > robotMap, wxPoint * robotPos);
	virtual ~MapIllustrator();
    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    void render(wxDC& dc);
	void changePos(int x, int y, std::vector< std::vector<int> > mapRobot);
 
    // some useful events
    /*
     void mouseMoved(wxMouseEvent& event);
     void mouseDown(wxMouseEvent& event);
     void mouseWheelMoved(wxMouseEvent& event);
     void mouseReleased(wxMouseEvent& event);
     void rightClick(wxMouseEvent& event);
     void mouseLeftWindow(wxMouseEvent& event);
     void keyPressed(wxKeyEvent& event);
     void keyReleased(wxKeyEvent& event);
     */
 
    DECLARE_EVENT_TABLE()
};

#endif
