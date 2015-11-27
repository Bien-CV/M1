package fr.univnantes.cta.impl;

import fr.univnantes.cta.CompassDirection;



public class LongitudeImpl extends CoordinateImpl{

	public LongitudeImpl(int angle, int minute, int seconde, CompassDirection cd) {
		super(angle, minute, seconde, cd);
		if ((cd != CompassDirection.EAST) && (cd != CompassDirection.WEST)) {
			throw new IllegalArgumentException("mauvaise direction");
		}
		// une longitude est positionner sur Est Ouest
		
		if ((this.degrees() < 0) || (this.degrees() > 180)){
			throw new IllegalArgumentException("mauvais angle");
		}
		// avec un angle compris entre 0 et 180 degre
		
	}
}
