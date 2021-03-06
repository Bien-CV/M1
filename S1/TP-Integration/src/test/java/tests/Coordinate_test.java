package tests;

import static org.junit.Assert.*;

import org.junit.Ignore;
import org.junit.Test;

import fr.univnantes.cta.CompassDirection;
import fr.univnantes.cta.impl.CoordinateImpl;

public class Coordinate_test {

	@Test
	public void testCoordinateImpl() {
		CoordinateImpl coord = new CoordinateImpl(0, 0, 0, CompassDirection.EAST);
		assertNotNull(coord);
	}

	@Test
	public void testDirection() {
		CoordinateImpl coord = new CoordinateImpl(0, 0, 0, CompassDirection.EAST);
		assertTrue(coord.direction()==CompassDirection.EAST);
	}

	@Test
	public void testCos() {
		CoordinateImpl coord = new CoordinateImpl(0, 0, 0, CompassDirection.EAST);
		assertTrue(coord.Cos()==1);
	}

	@Test
	public void testSin() {
		CoordinateImpl coord = new CoordinateImpl(0, 0, 0, CompassDirection.EAST);
		assertTrue(coord.Sin()==0);
	}
	@Test
	public void testCosSouth() {
		CoordinateImpl coord = new CoordinateImpl(0, 0, 0, CompassDirection.SOUTH);
		assertTrue(coord.Cos()==1);
	}

	@Test
	public void testSinSouth() {
		CoordinateImpl coord = new CoordinateImpl(0, 0, 0, CompassDirection.WEST);
		assertTrue(coord.Sin()==0);
	}

}
