package tests;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

import org.junit.Before;
import org.junit.Test;




import fr.univnantes.cta.CompassDirection;
import fr.univnantes.cta.impl.AirwayImpl;
import fr.univnantes.cta.impl.LatitudeImpl;
import fr.univnantes.cta.impl.LongitudeImpl;
import fr.univnantes.cta.impl.PositionImpl;
import fr.univnantes.cta.impl.VORImpl;

public class Airway_Test {
	protected AirwayImpl airway;
	protected VORImpl sta;
	protected VORImpl sto;
	
	@Before
	public void setUp() throws Exception {
		LatitudeImpl latitude = new LatitudeImpl(1, 0, 0, CompassDirection.NORTH);
		LongitudeImpl longitude = new LongitudeImpl(1, 0, 0, CompassDirection.EAST);
		LongitudeImpl longitude2 = new LongitudeImpl(2, 0, 0, CompassDirection.EAST);
		PositionImpl pos1 = new PositionImpl(latitude, longitude);
		PositionImpl pos2 = new PositionImpl(latitude, longitude2);
		sta = new VORImpl("sta", pos1);
		sto = new VORImpl("sto", pos2);
		airway = new AirwayImpl(sta,sto);
	}


	@Test
	public void testGetDistance() {
		assertTrue(airway.getDistance()==sta.distanceTo(sto));
	}

	@Test
	public void testDeparture() {
		assertEquals(airway.GetVORDepart(),(sta.getName()));
	}

	@Test
	public void testArrival() {
		assertEquals(airway.GetVORArrive(),(sto.getName()));
	}

	@Test
	public void testGetVORDepart() {
		assertEquals(airway.GetVORDepart(),("sta"));
	}

	@Test
	public void testGetVORArrive() {
		assertEquals(airway.GetVORArrive(),("sto"));
	}

}
