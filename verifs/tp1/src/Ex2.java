/**
 * 
 */

/**
 * @author E129986P
 *
 */
public class Ex2 {

	/**
	 * 
	 */
	public Ex2() {
		
	}
	
	public static void fahr2Cel(double fahrT){
		assert fahrT >= -459.67 : "too low";
		double celT = (fahrT  - 32)*5/9;
		System.out.println(fahrT + " fahr = " + celT + " cel!");
	}
	
	public static void cel2Fahr(double celT){
		assert celT >= -273.15 : "too low";
		double fahrT = celT * 9/5 +32;
		System.out.println( celT + " cel = " + fahrT + " fahr");
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Ex2.cel2Fahr(0);
		//Ex2.cel2Fahr(-275);
		Ex2.cel2Fahr(-273.15);
		
		//Ex2.fahr2Cel(-460);
		Ex2.fahr2Cel(-459.67);

	}

}
