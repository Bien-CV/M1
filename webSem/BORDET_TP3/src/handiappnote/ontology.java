/**
 * 
 */
package handiappnote;

import controller_package.Controller;

/**
 * @author E129986P
 *
 */
public class ontology {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Controller control = new Controller();
		String filename= "~/HandiAppNote/accessibility-ontology.ttl";
		control.readingRDF(filename);
		
		
	}

}
