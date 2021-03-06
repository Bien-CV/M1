package tests;

import static org.junit.Assert.*;

import org.junit.BeforeClass;
import org.junit.Test;

import fr.univnantes.cta.impl.AirplaneImpl;
import fr.univnantes.cta.impl.AirportImpl;

public class Airport_Test {

	@Test
	public void testAirportImpl() {
		AirportImpl airport = new AirportImpl("str");
		assertNotNull(airport);
	}

	@Test
	public void testGetName() {
		AirportImpl airport = new AirportImpl("str");
		assertEquals(airport.getName(),("str"));
	}

}
