package tests;

import static org.junit.Assert.*;

import org.junit.Test;

import fr.univnantes.cta.impl.AirplaneImpl;

public class Airplane_Test {

	@Test
	public void testAirplaneImpl() {
		AirplaneImpl airplane = new AirplaneImpl(0, 0, 0, 0);
		assertNotNull(airplane);
	}

	@Test
	public void testGetAutonomy() {//TODO verifier que c'est bien ce que l'on veut calculer
		AirplaneImpl airplane = new AirplaneImpl(0, 0, 3, 2);
		assertTrue(airplane.getAutonomy()==6);
	}

	@Test
	public void testGetLoading() {
		AirplaneImpl airplane = new AirplaneImpl(0, 1, 0, 0);
		assertTrue(airplane.getLoading()==1);
	}

	@Test
	public void testWeight() {
		AirplaneImpl airplane = new AirplaneImpl(1, 0, 0, 0);
		assertTrue(airplane.weight()==1);
	}

}
