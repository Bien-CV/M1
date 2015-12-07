#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "MainFrame.h"

class MainFrame;

class System{
	private:
		MainFrame* _mf;
		std::vector< std::vector<int> > _mapFirstLayer;
		std::vector< std::vector<int> > _mapSecondLayer;
		int _robotPosX; // normally into Robot which is into AI
		int _robotPosY; // normally into Robot which is into AI
		std::vector< std::vector<int> > _robotMap; // normally into Robot which is into AI
		
	public:
		System(MainFrame*);
		virtual ~System();

		void start();

		std::vector< std::vector<int> > getMapFirstLayer();
		std::vector< std::vector<int> > getMapSecondLayer();
		std::vector< std::vector<int> > getRobotMap();
		int getRobotPosX();
		int getRobotPosY();
};

#endif
