package tests;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import org.junit.Before;
import org.junit.Test;



import fr.univnantes.cta.impl.AirwayImpl;
import fr.univnantes.cta.impl.VORImpl;

public class Airway_Test {
	protected AirwayImpl airway;
	protected VORImpl sta;
	protected VORImpl sto;
	
	@Before
	public void setUp() throws Exception {
		sta = mock(VORImpl.class);
		sto = mock(VORImpl.class);
		airway = new AirwayImpl(sta,sto);
		when(sta.distanceTo(sto)).thenReturn(42.);
		when(sta.getName()).thenReturn("sta");
		when(sto.getName()).thenReturn("sto");
	}


	@Test
	public void testGetDistance() {
		assertTrue(airway.getDistance()==42.);
	}

	@Test
	public void testDeparture() {
		assertTrue(airway.GetVORDepart().equals(sta.getName()));
	}

	@Test
	public void testArrival() {
		assertTrue(airway.GetVORArrive().equals(sto.getName()));
	}

	@Test
	public void testGetVORDepart() {
		assertTrue(airway.GetVORDepart().equals("sta"));
	}

	@Test
	public void testGetVORArrive() {
		assertTrue(airway.GetVORArrive().equals("sto"));
	}

}
