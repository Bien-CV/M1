package tests;

import static org.junit.Assert.*;

import org.junit.Test;

import fr.univnantes.cta.CompassDirection;
import fr.univnantes.cta.impl.LongitudeImpl;

public class Longitude_Test {

	@Test
	public void testLongitudeImpl() {
		LongitudeImpl lat = new LongitudeImpl(0, 0, 0, fr.univnantes.cta.CompassDirection.EAST);
		assertNotNull(lat);
		
	}
	@Test(expected=IllegalArgumentException.class)
	public void testLongitudeImpl2() {
		LongitudeImpl lat = new LongitudeImpl(0, 0, 0, CompassDirection.NORTH);
		
	}
	@Test(expected=IllegalArgumentException.class)
	public void testLongitudeImpl3() {
		LongitudeImpl lat = new LongitudeImpl(181, 0, 0, CompassDirection.EAST);
		
	}

}
