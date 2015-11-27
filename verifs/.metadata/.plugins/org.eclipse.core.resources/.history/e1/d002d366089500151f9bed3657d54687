package fr.nantes.cta.one;

import fr.nantes.cta.CompassDirection;
import fr.nantes.cta.Coordinate;



public class CoordinateImpl extends AngleImpl implements Coordinate {
	private int _angle;
	private int _minute;
	private int _seconde;
	private CompassDirection dir;

	public CoordinateImpl (int angle, int minute, int seconde, CompassDirection cd){
		super (angle, minute, seconde);
		_angle = angle;
		_minute = minute;
		_seconde = seconde;
		dir = cd;
	}
	public CompassDirection direction() {
		return dir;
	}
	
	/**
	 * retourne le cosinus d'un angle donnée en degre, minute, seconde
	 * @return
	 */

	public double Cos() {
		if (dir==CompassDirection.SOUTH || dir == CompassDirection.WEST){
		//recalcul du cos	
			return Math.cos(this.Radians());
		}else{
			return cos();
		}
	}
	
	/**
	 * retourne le un angle donnée en degre, minute, seconde en Degre
	 * @return
	 */

	public double Degrees() {
		int sign = 1;
		if (dir==CompassDirection.SOUTH || dir == CompassDirection.WEST){
			sign = -1;
			}
		return sign* (_angle+(_minute+_seconde/60.)/60.);
		}

	public double Radians() {
		return Math.toRadians(this.Degrees());
	}

	public double Sin() {
		if (dir==CompassDirection.SOUTH || dir == CompassDirection.WEST){
		// recalcul su sin	
			return Math.sin(this.Radians());
		}else{
			return sin();
		}
		
	}
	
}
