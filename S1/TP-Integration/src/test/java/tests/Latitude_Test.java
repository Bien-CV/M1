package tests;

import static org.junit.Assert.*;

import org.junit.Test;

import fr.univnantes.cta.CompassDirection;
import fr.univnantes.cta.impl.LatitudeImpl;

public class Latitude_Test {

	@Test
	public void testLatitudeImpl() {
		LatitudeImpl lat = new LatitudeImpl(0, 0, 0, CompassDirection.NORTH);
		assertNotNull(lat);
	}
	@Test(expected=IllegalArgumentException.class)
	public void testLatitudeImpl2() {
		LatitudeImpl lat = new LatitudeImpl(0, 0, 0, CompassDirection.EAST);
		
	}
	@Test(expected=IllegalArgumentException.class)
	public void testLatitudeImpl3() {
		LatitudeImpl lat = new LatitudeImpl(100, 0, 0, CompassDirection.NORTH);
		
	}

}
