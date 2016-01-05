package fr.univnantes.cta.impl;

import fr.univnantes.cta.Airway;
import fr.univnantes.cta.VOR;

//TODO il faudra penser a enlever des mocks la ou ils ne sont pas necessaire: ex airwway mock de vor
public class AirwayImpl implements Airway{
	private VOR _depart, _arriver;
	
	public AirwayImpl(VOR start, VOR stop){
		_depart = start;
		_arriver = stop;
	}

	public double getDistance() {
		return _depart.distanceTo(_arriver);
	}
	
	public String GetVORDepart(){
		return _depart.getName();		
	}
	 public String GetVORArrive(){
		 return _arriver.getName();
	 }

}
