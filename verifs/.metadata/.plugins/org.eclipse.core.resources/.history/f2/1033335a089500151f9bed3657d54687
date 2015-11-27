package fr.nantes.cta.one;

import fr.nantes.cta.Airway;
import fr.nantes.cta.VOR;


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
