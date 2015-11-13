package tests;
import static org.mockito.Matchers.anyInt;
import static org.mockito.Mockito.*;
import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import fr.univnantes.cta.CompassDirection;
import fr.univnantes.cta.impl.LatitudeImpl;
import fr.univnantes.cta.impl.LongitudeImpl;
import fr.univnantes.cta.impl.PositionImpl;
import fr.univnantes.cta.impl.VORImpl;

public class VOR_Test {
	protected VORImpl vor;
	protected VORImpl other;
	protected PositionImpl pos1;
	protected PositionImpl pos2;
	
	@Before
	public void setUp() throws Exception {
		pos1 = mock(PositionImpl.class);
		pos2 = mock(PositionImpl.class);
		vor = new VORImpl("str", pos1);
		other = new VORImpl("other", pos2);
		when(pos1.distanceTo(pos2)).thenReturn(0.);
	}


	@Test
	public void testDistanceTo() {
		assertTrue(vor.distanceTo(other)==0.);
	}

	@Test
	public void testGetName() {
		assertTrue(vor.getName().equals("str"));
	}

	@Test
	public void testGetPosition() {
		assertTrue(vor.getPosition()==pos1);
	}

}
