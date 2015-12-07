package tests;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import org.junit.Before;
import org.junit.Test;

import fr.univnantes.cta.CompassDirection;
import fr.univnantes.cta.impl.AirwayImpl;
import fr.univnantes.cta.impl.TakenAirwayImpl;

public class TakenAirway_Test {
	protected TakenAirwayImpl takena;
	protected AirwayImpl airw;

	@Before
	public void setUp() throws Exception {
		airw = mock(AirwayImpl.class);
		takena = new TakenAirwayImpl(airw, 42, CompassDirection.SOUTH);
		when(airw.getDistance()).thenReturn(21.);
	}

	@Test
	public void testDistance() {
		assertTrue(takena.distance()==21.);
	}

	@Test
	public void testGetAirway() {
		assertTrue(takena.getAirway().equals(airw));
	}

	@Test
	public void testGetAltitude() {
		assertTrue(takena.getAltitude()==42);
	}

	@Test
	public void testGetSense() {
		assertTrue(takena.getSense().equals(CompassDirection.SOUTH));
	}

}
