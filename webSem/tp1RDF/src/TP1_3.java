import org.apache.jena.rdf.model.*;
public class TP1_3 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Model m = ModelFactory.createDefaultModel();
		 String nsA = "http://somewhere/else#";
		 String nsB = "http://nowhere/else#";
		 Resource root = m.createResource( nsA + "root" );
		 Property P = m.createProperty( nsA + "P" );
		 Property Q = m.createProperty( nsB + "Q" );
		 Resource x = m.createResource( nsA + "x" );
		 Resource y = m.createResource( nsA + "y" );
		 Resource z = m.createResource( nsA + "z" );
		 m.add( root, P, x ).add( root, P, y ).add( y, Q, z );
		 System.out.println( "# -- pas de préfixes spéciaux définis" );
		 m.write( System.out );
		 System.out.println( "# -- nsA défini" );
		 m.setNsPrefix( "nsA", nsA );
		 m.write( System.out );
		 System.out.println( "# -- nsA et cat définis" );
		 m.setNsPrefix( "cat", nsB );
		 m.write( System.out );
		 
		 System.out.println("\n-----------------------------------\n");
		 Model m2 = ModelFactory.createDefaultModel();
		 m2.read( "nouveaufichier.rdf" );
		 m2.write( System.out );

	}

}
