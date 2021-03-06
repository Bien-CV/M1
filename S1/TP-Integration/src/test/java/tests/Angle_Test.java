package tests;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import fr.univnantes.cta.impl.AngleImpl;

public class Angle_Test {
	
	@Test
	public void testAngleImpl() {
		AngleImpl angle = new AngleImpl(0, 0, 0);
		assertNotNull(angle);
	}

	@Test
	public void testCos() {
		AngleImpl angle = new AngleImpl(0, 0, 0);
		assertTrue(angle.cos()==1);
	}

	@Test
	public void testDegrees() {
		AngleImpl angle = new AngleImpl(0, 0, 0);
		assertTrue(angle.degrees()==0);
	}

	@Test
	public void testRadians() {
		AngleImpl angle = new AngleImpl(0, 0, 0);
		assertTrue(angle.radians()==0);
	}

	@Test
	public void testSin() {
		AngleImpl angle = new AngleImpl(0, 0, 0);
		assertTrue(angle.sin()==0);
	}

}
