package TimerPackage;







import org.junit.Before;
import org.junit.Test;

import java.util.GregorianCalendar;


import static org.junit.Assert.*;
import static org.mockito.Mockito.*;


public class Test_tp4_Mockito {
	protected Timer tim;
	
	
	@Before
	public void setUp() throws TimerException {
		GregorianCalendar mockedCalendar = mock(GregorianCalendar.class);
		tim = new Timer(1, 0, 0, mockedCalendar);
		when(mockedCalendar.get(anyInt())).thenReturn(0,0,1);
	}
	
	@Test
	public void testSetActive_true(){
		tim.setActive(true);
		assertTrue (tim.active);
	}
	
	@Test
	public void testSetActive_false() throws AssertionError{
		tim.setActive(false);
		assertTrue (!(tim.active));
	}
	
	@Test
	public void testSetActive_ringing(){
		tim.setActive(true); // 0 et 0
		assertTrue (tim.ringing);
	}
	@Test
	public void testSetActive_ringing_1f1(){
		tim.calendar.get(0);//0
		tim.setActive(true);// 0 et 1
		assertTrue (!tim.ringing);
	}
	
	
	

	//org.junit.runner.JUnitCore.main("TimerPackage/Timer");
}
