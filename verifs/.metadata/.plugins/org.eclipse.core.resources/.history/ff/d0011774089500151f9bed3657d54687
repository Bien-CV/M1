package fr.nantes.cta.one;

import fr.nantes.cta.CompassDirection;



public class LatitudeImpl extends CoordinateImpl{

	public LatitudeImpl(int angle, int minute, int seconde, CompassDirection cd) {
		super(angle, minute, seconde, cd);
		if ((cd != CompassDirection.NORTH) && (cd != CompassDirection.SOUTH)) {
			throw new IllegalArgumentException("mauvaise direction");
		}
		// une latitude est positionner sur Nord Sud
		
		if ((this.degrees() < 0) || (this.degrees() > 90)) {
			throw new IllegalArgumentException("mauvais angle");
		}
		// avec un angle compris entre 0 et 90 degre
		
	}
}
