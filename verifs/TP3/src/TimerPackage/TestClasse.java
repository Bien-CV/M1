package TimerPackage;

import static org.junit.Assert.*;


import java.util.Arrays;
import java.util.Collection;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;

@RunWith( Parameterized.class)public class TestClasse {

	private Timer t;
	private int arg1;
	private int arg2;
	private int arg3;
	
	public TestClasse( int a1, int a2, int a3){
		arg1 = a1;
		arg2 = a2;
		arg3 = a3;

		
	}
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
	}

	@AfterClass
	public static void tearDownAfterClass() throws Exception {
	}

	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}

	@Parameters public static Collection data (){
		Object[][] data = {
				{0,0,0},
				{11,0,0},
				{1,-1,0},
				{1,24,0},
				{1,0,-1},
				{1,0,60}
		};
		return Arrays.asList(data);
	}
	
	/**
	 * test des valeurs invalides
	 * @throws TimerException
	 */
	@Test(expected=TimerException.class)
	public void testTimer() throws TimerException {
		t = new Timer(arg1, arg2, arg3);
		
	}
	/**
	 * test d'une valeur valide
	 * @throws TimerException
	 */
	@Test
	public void testTimer2() throws TimerException {
		Timer t2 = new Timer(1,0,0);
		
	}

	@Test (expected=TimerException.class)
	public void testSelectRing0() throws TimerException {
		Timer t3 = new Timer(1, 0, 0);
		t3.ringing = true;
		t3.selectRing(0);
		
	}
	
	@Test (expected=TimerException.class)
	public void testSelectRing11() throws TimerException {
		Timer t3 = new Timer(1, 0, 0);
		t3.selectRing(11);
		
	}
	@Test
	public void testSelectRingOk() throws TimerException {
		Timer t3 = new Timer(1, 0, 0);
		t3.selectRing(2);
		
	}
/*
	@Test
	public void testAddMin() {
		fail("Not yet implemented");
	}

	@Test
	public void testSetActive() {
		fail("Not yet implemented");
	}*/

}
