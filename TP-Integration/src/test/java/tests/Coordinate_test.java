package tests;

import static org.junit.Assert.*;

import org.junit.Ignore;
import org.junit.Test;

import fr.univnantes.cta.impl.CoordinateImpl;

public class Coordinate_test {

	@Test
	public void testCoordinateImpl() {
		CoordinateImpl coord = new CoordinateImpl(0, 0, 0, null);
		assertNotNull(coord);
	}

	@Test(expected=UnsupportedOperationException.class)
	public void testDirection() {
		CoordinateImpl coord = new CoordinateImpl(0, 0, 0, null);
		coord.direction();
	}

	@Test(expected=UnsupportedOperationException.class)
	public void testCos() {
		CoordinateImpl coord = new CoordinateImpl(0, 0, 0, null);
		coord.Cos();
	}

	@Test(expected=UnsupportedOperationException.class)
	public void testSin() {
		CoordinateImpl coord = new CoordinateImpl(0, 0, 0, null);
		coord.Sin();
	}

}
