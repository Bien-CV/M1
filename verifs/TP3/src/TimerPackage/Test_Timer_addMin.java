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

@RunWith( Parameterized.class)public class Test_Timer_addMin {
	Timer t;
	private int a1;
	
	public Test_Timer_addMin(int arg1) {
		a1=arg1;
	}

	static int nbmin= 60*27+30;
	
	@Parameters public static Collection data (){
		Object[][] data = {
				{63},
				{0},
				{nbmin}

		};
		return Arrays.asList(data);
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

	@Test /*(expected=TimerException.class) pour le 1er*/
	public void testAddMin() throws TimerException {
		t = new Timer(1,23,59);
		t.addMin(a1);
	}
	@Test(expected=TimerException.class)
	public void testAddMin_1() throws TimerException {
		t = new Timer(1,23,59);
		t.addMin(-1);
	}

}
