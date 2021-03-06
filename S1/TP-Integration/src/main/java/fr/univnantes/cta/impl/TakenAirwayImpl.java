package fr.univnantes.cta.impl;

import fr.univnantes.cta.Airway;
import fr.univnantes.cta.CompassDirection;
import fr.univnantes.cta.TakenAirway;



public class TakenAirwayImpl implements TakenAirway{
	private Airway _airway;
	private int _altitude;
	private CompassDirection _compassdirection;
	
	public TakenAirwayImpl(Airway airway, int altitude, CompassDirection dir){
		_airway = airway;
		_altitude = altitude;
		_compassdirection = dir;
	}

	public double distance() {
		return _airway.getDistance();
	}

	public Airway getAirway() {
		return _airway;
	}

	public int getAltitude() {
		return _altitude;
	}

	public CompassDirection getSense() {
		return _compassdirection;
	}

}
