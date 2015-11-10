package tests;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import fr.univnantes.cta.Airway;
import fr.univnantes.cta.impl.AirwayImpl;
import fr.univnantes.cta.impl.VORImpl;

public class Airway_Test {

	@Before
	public void setUp() throws Exception {
		VORImpl s = new VORImpl("s", null);
		VORImpl st = new VORImpl("st", null);
		AirwayImpl airway = new AirwayImpl(s, st);
	}

	@Test
	public void testAirwayImpl() {
		fail("Not yet implemented");
	}

	@Test
	public void testGetDistance() {
	}

	@Test
	public void testDeparture() {
		fail("Not yet implemented");
	}

	@Test
	public void testArrival() {
		fail("Not yet implemented");
	}

	@Test
	public void testGetVORDepart() {
		fail("Not yet implemented");
	}

	@Test
	public void testGetVORArrive() {
		fail("Not yet implemented");
	}

}
