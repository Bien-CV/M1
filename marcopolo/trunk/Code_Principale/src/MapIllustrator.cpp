#include "../include/MapIllustrator.h"

BEGIN_EVENT_TABLE(MapIllustrator, wxPanel)
// some useful events
/*
 EVT_MOTION(MapIllustrator::mouseMoved)
 EVT_LEFT_DOWN(MapIllustrator::mouseDown)
 EVT_LEFT_UP(MapIllustrator::mouseReleased)
 EVT_RIGHT_DOWN(MapIllustrator::rightClick)
 EVT_LEAVE_WINDOW(MapIllustrator::mouseLeftWindow)
 EVT_KEY_DOWN(MapIllustrator::keyPressed)
 EVT_KEY_UP(MapIllustrator::keyReleased)
 EVT_MOUSEWHEEL(MapIllustrator::mouseWheelMoved)
 */
 
 // catch paint events
 EVT_PAINT(MapIllustrator::paintEvent)
END_EVENT_TABLE()
 
 
// some useful events
/*
 void MapIllustrator::mouseMoved(wxMouseEvent& event) {}
 void MapIllustrator::mouseDown(wxMouseEvent& event) {}
 void MapIllustrator::mouseWheelMoved(wxMouseEvent& event) {}
 void MapIllustrator::mouseReleased(wxMouseEvent& event) {}
 void MapIllustrator::rightClick(wxMouseEvent& event) {}
 void MapIllustrator::mouseLeftWindow(wxMouseEvent& event) {}
 void MapIllustrator::keyPressed(wxKeyEvent& event) {}
 void MapIllustrator::keyReleased(wxKeyEvent& event) {}
 */
 
MapIllustrator::MapIllustrator(wxFrame* parent,std::vector< std::vector<int> > mapFirstLayer, std::vector< std::vector<int> > mapSecondLayer, std::vector< std::vector<int> > robotMap, wxPoint * robotPos) :
wxPanel(parent)
{
	wxInitAllImageHandlers();
	
	_rmsCelluleHeight = 16;
	_rmsCelluleWidth = 16;
	_zrsCelluleHeight = 28;
	_zrsCelluleWidth = 28;
	_fmsCelluleHeight = 8;
	_fmsCelluleWidth = 8;
	_horrizontalSpacerSize = 4;
	_verticalSpacerSize = 4;
	_zoomSize = 9;
	
	_mapFirstLayer = mapFirstLayer;
	_mapSecondLayer = mapSecondLayer;
	_robotMap = robotMap;
	_robotPos = robotPos;

	_imgsRobotMap.push_back(new wxImage(wxString("images/image0.png"),wxBITMAP_TYPE_PNG));
	_imgsRobotMap.push_back(new wxImage(wxString("images/image1.png"),wxBITMAP_TYPE_PNG));
	_imgsRobotMap.push_back(new wxImage(wxString("images/image2.png"),wxBITMAP_TYPE_PNG));
	_imgsRobotMap.push_back(new wxImage(wxString("images/image3.png"),wxBITMAP_TYPE_PNG));
	_imgsRobotMap.push_back(new wxImage(wxString("images/image4.png"),wxBITMAP_TYPE_PNG));

	_imgsZoomMap.push_back(new wxImage(wxString("images/image0.png"),wxBITMAP_TYPE_PNG));
	_imgsZoomMap.push_back(new wxImage(wxString("images/image1.png"),wxBITMAP_TYPE_PNG));
	_imgsZoomMap.push_back(new wxImage(wxString("images/image2.png"),wxBITMAP_TYPE_PNG));
	_imgsZoomMap.push_back(new wxImage(wxString("images/image3.png"),wxBITMAP_TYPE_PNG));
	_imgsZoomMap.push_back(new wxImage(wxString("images/image4.png"),wxBITMAP_TYPE_PNG));

	_imgsFullMap.push_back(new wxImage(wxString("images/image0.png"),wxBITMAP_TYPE_PNG));
	_imgsFullMap.push_back(new wxImage(wxString("images/image1.png"),wxBITMAP_TYPE_PNG));
	_imgsFullMap.push_back(new wxImage(wxString("images/image2.png"),wxBITMAP_TYPE_PNG));
	_imgsFullMap.push_back(new wxImage(wxString("images/image3.png"),wxBITMAP_TYPE_PNG));
	_imgsFullMap.push_back(new wxImage(wxString("images/image4.png"),wxBITMAP_TYPE_PNG));

	int imgsSize = _imgsRobotMap.size();
	for(int i = 0 ; i < imgsSize ; ++i){
		_imgsZoomMap[i]->Rescale(_zrsCelluleWidth,_zrsCelluleHeight,wxIMAGE_QUALITY_HIGH);
		_imgsFullMap[i]->Rescale(_fmsCelluleWidth,_fmsCelluleHeight,wxIMAGE_QUALITY_HIGH);
	}
}
MapIllustrator::~MapIllustrator(){}

/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */
 
void MapIllustrator::paintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    render(dc);
}

/*
 * Alternatively, you can use a clientDC to paint on the panel
 * at any time. Using this generally does not free you from
 * catching paint events, since it is possible that e.g. the window
 * manager throws away your drawing when the window comes to the
 * background, and expects you will redraw it when the window comes
 * back (by sending a paint event).
 *
 * In most cases, this will not be needed at all; simply handling
 * paint events and calling Refresh() when a refresh is needed
 * will do the job.
 */
void MapIllustrator::paintNow()
{
    wxPaintDC dc(this);
    render(dc);
}


void MapIllustrator::changePos(int x, int y, std::vector< std::vector<int> > mapRobot)
{
	_robotPos->x = x;
	_robotPos->y = y;
}
 
/*
 * Here we do the actual rendering. I put it in a separate
 * method so that it can work no matter what type of DC
 * (e.g. wxPaintDC or wxClientDC) is used.
 */
void MapIllustrator::render(wxDC&  dc)
{
	// ------------------------------------------
	// ------------ DRAW ROBOT MAP --------------
	// ------------------------------------------
	int robotMapSizeX = _robotMap.size();
	int robotMapSizeY;
	for(int i = 0; i < robotMapSizeX; ++i){
		robotMapSizeY = _robotMap[i].size();
		for(int j = 0; j < robotMapSizeY; ++j){
			if ( _robotMap[j][i] > 0){
				dc.DrawBitmap(
					*new wxBitmap(*_imgsRobotMap[ _mapFirstLayer[j][i]]),
					_rmsCelluleWidth*i,
					_rmsCelluleHeight*j
				);
				if ( _mapSecondLayer[j][i] > 0){
					dc.DrawBitmap(
						*new wxBitmap(*_imgsRobotMap[ _mapSecondLayer[j][i]]),
						_rmsCelluleWidth*i,
						_rmsCelluleHeight*j
					);
				}
			}else{
				dc.DrawBitmap(
					*new wxBitmap(*_imgsRobotMap[ _robotMap[j][i]]),
					_rmsCelluleWidth*i,
					_rmsCelluleHeight*j
				);
			}
		}
	}
	dc.DrawBitmap(
		*new wxBitmap(*_imgsRobotMap[_imgsZoomMap.size()-1]),
		_rmsCelluleWidth*_robotPos->x,
		_rmsCelluleHeight*_robotPos->y
	);
	// ------------------------------------------
	// ------------- DRAW MAP -------------------
	// ------------------------------------------
	for(int i = 0; i < robotMapSizeX; ++i){
		robotMapSizeY = _robotMap[i].size();
		for(int j = 0; j < robotMapSizeY; ++j){
			dc.DrawBitmap(
				*new wxBitmap(*_imgsFullMap[ _mapFirstLayer[j][i]]),
				robotMapSizeX * _rmsCelluleWidth + _verticalSpacerSize + _fmsCelluleWidth*i,
				_zoomSize * _zrsCelluleHeight + _horrizontalSpacerSize + _fmsCelluleHeight*j
			);
			if ( _mapSecondLayer[j][i] > 0){
				dc.DrawBitmap(
					*new wxBitmap(*_imgsFullMap[ _mapSecondLayer[j][i]]),
					robotMapSizeX * _rmsCelluleWidth + _verticalSpacerSize + _fmsCelluleWidth*i,
					_zoomSize * _zrsCelluleHeight + _horrizontalSpacerSize + _fmsCelluleHeight*j
				);
			}
		}
	}
	dc.DrawBitmap(
		*new wxBitmap(*_imgsFullMap[_imgsZoomMap.size()-1]),
		robotMapSizeX * _rmsCelluleWidth + _verticalSpacerSize + _fmsCelluleWidth*_robotPos->x,
		_zoomSize * _zrsCelluleHeight + _horrizontalSpacerSize + _fmsCelluleHeight*_robotPos->y
	);

	// ------------------------------------------
	// ----------- DRAW ROBOT ZOOM---------------
	// ------------------------------------------
	int startX = _robotPos->x - ((_zoomSize-1)/2);
	int stopX = _robotPos->x + ((_zoomSize-1)/2);
	int startY = _robotPos->y - ((_zoomSize-1)/2);
	int stopY = _robotPos->y + ((_zoomSize-1)/2);
	
	int cptx = 0;
	int cpty = 0;	
	for(int i = startX; i <= stopX; ++i){
		cpty = 0;
		for(int j = startY; j <= stopY; ++j){
			if( i >= 0 && i < robotMapSizeX){
				robotMapSizeY = _robotMap[i].size();
				if( j >= 0 && j < robotMapSizeY){
					dc.DrawBitmap(
						*new wxBitmap(*_imgsZoomMap[ _mapFirstLayer[j][i]]),
						robotMapSizeX * _rmsCelluleWidth + _verticalSpacerSize + _zrsCelluleWidth*cptx,
						_zrsCelluleHeight*cpty
					);
					if ( _mapSecondLayer[j][i] > 0){
						dc.DrawBitmap(
							*new wxBitmap(*_imgsZoomMap[ _mapSecondLayer[j][i]]),
							robotMapSizeX * _rmsCelluleWidth + _verticalSpacerSize + _zrsCelluleWidth*cptx,
							_zrsCelluleHeight*cpty
						);
					}					
				}else{
					dc.DrawBitmap(
							*new wxBitmap(*_imgsZoomMap[0]),
							robotMapSizeX * _rmsCelluleWidth + _verticalSpacerSize + _zrsCelluleWidth*cptx,
							_zrsCelluleHeight*cpty
					);
				}
			}else{
				dc.DrawBitmap(
							*new wxBitmap(*_imgsZoomMap[0]),
							robotMapSizeX * _rmsCelluleWidth + _verticalSpacerSize + _zrsCelluleWidth*cptx,
							_zrsCelluleHeight*cpty
				);
			}
			cpty++;	
		}
		cptx++;
	}
	dc.DrawBitmap(
		*new wxBitmap(*_imgsZoomMap[_imgsZoomMap.size()-1]),
		robotMapSizeX * _rmsCelluleWidth + _verticalSpacerSize + _zrsCelluleWidth*((_zoomSize-1)/2),
		_zrsCelluleHeight*((_zoomSize-1)/2)
	);
	/*
	wxImage * wxImg = new wxImage();
	wxImg->LoadFile(wxString("image") + wxString::Format(wxT("%i"),postPos->x) + wxString(".jpg"),wxBITMAP_TYPE_JPEG);
	wxBitmap * wxBit = new wxBitmap(*wxImg);
	dc.DrawBitmap(*wxBit,50,50);*/

    // draw a line
    //dc.SetPen( wxPen( wxColor(0,0,0), 3 ) ); // black line, 3 pixels thick
    //dc.DrawLine( 300, 100, 700, 300 ); // draw line across the rectangle
}
