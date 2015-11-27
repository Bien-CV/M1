package fr.nantes.cta.one;

import fr.nantes.cta.Angle;
import fr.nantes.cta.Position;



public class PositionImpl implements Position {
	private LatitudeImpl lati;
	private LongitudeImpl longi;
	private static final double Rayon = 6378.14;		//Rayon de la terre
	
	public PositionImpl(LatitudeImpl latitude, LongitudeImpl longitude) {
		longi = longitude;
		lati  = latitude;
	}

	public double distanceTo(Position other) {
		return Math.acos((this.lati.Cos()) * (this.longi.Cos()) *
				(((LatitudeImpl)other.getLatitude()).Cos()) *
				(((LongitudeImpl)other.getLongitude()).Cos()) +
				(this.lati.Cos())*(this.longi.Sin()) *
				(((LatitudeImpl)other.getLatitude()).Cos()) *
				(((LongitudeImpl)other.getLongitude()).Sin()) +
				(this.lati.Sin()) * (((LatitudeImpl)other.getLatitude()).Sin())) * Rayon;
		
	}

	public Angle getLatitude() {
		return lati;
	}

	public Angle getLongitude() {
		return longi;
	}

}
