package tests;


import java.util.GregorianCalendar;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import org.junit.Before;
import org.junit.Test;

import fr.univnantes.cta.CompassDirection;
import fr.univnantes.cta.impl.LatitudeImpl;
import fr.univnantes.cta.impl.LongitudeImpl;
import fr.univnantes.cta.impl.PositionImpl;

public class Position_Test {
	protected  PositionImpl pos;
	protected LatitudeImpl lat;
	protected LongitudeImpl lon;

	@Before
	public void setUp(){
		// on recreer lat et lon car elles ont déja été testées et elles ,ne sont pas trop lourdes
		lat = new LatitudeImpl(0, 0, 0, CompassDirection.NORTH);
		lon = new LongitudeImpl(0, 0, 0, CompassDirection.EAST);
		pos = new PositionImpl(lat, lon);
	}
	

	@Test
	public void testGetLatitude() {
		assertTrue(pos.getLatitude()==lat);
	}

	@Test
	public void testGetLongitude() {
		assertTrue(pos.getLongitude()==lon);
	}

	@Test(expected=UnsupportedOperationException.class)
	public void testDistanceTo() {
		PositionImpl pos2 = new PositionImpl(lat, lon);
		pos.distanceTo(pos2);
	}

}
