import org.apache.jena.rdf.model.*;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.rdf.model.Property;
import org.apache.jena.rdf.model.RDFNode;
import org.apache.jena.rdf.model.Resource;
import org.apache.jena.rdf.model.Statement;
import org.apache.jena.rdf.model.StmtIterator;
import org.apache.*;
import org.apache.jena.vocabulary.VCARD;

/**
 * Tutorial 1 creating a simple model
 */

public class TP1 {
	// some definitions
	static String personURI = "http://somewhere/JohnSmith";
	static String fullName = "John Smith";
	static String givenName = "John";
	static String familyName = "Smith";

	public static void main(String args[]) {
		// create an empty model
		Model model = ModelFactory.createDefaultModel();

		// create the resource
		Resource johnSmith = model.createResource(personURI);

		// add the property
		johnSmith.addProperty(VCARD.FN, fullName);
		johnSmith.addProperty(VCARD.N,
				model.createResource().addProperty(VCARD.Given, givenName)
						.addProperty(VCARD.Family, familyName));
		/*
		 * ou bien Resource johnSmith = model.createResource(personURI)
		 * .addProperty(VCARD.FN, fullName);
		 */
		// liste des déclarations dans le modèle
		StmtIterator iter = model.listStatements();

		// affiche l'objet, le prédicat et le sujet de chaque déclaration
		while (iter.hasNext()) {
			Statement stmt = iter.nextStatement(); // obtenir la prochaine
													// déclaration
			Resource subject = stmt.getSubject(); // obtenir le sujet
			Property predicate = stmt.getPredicate(); // obtenir le prédicat
			RDFNode object = stmt.getObject(); // obtenir l'objet

			System.out.print(subject.toString());
			System.out.print(" " + predicate.toString() + " ");
			if (object instanceof Resource) {
				System.out.print(object.toString());
			} else {
				// l'objet est un littéral
				System.out.print(" \"" + object.toString() + "\"");
			}
			System.out.println(" .");
		}
		Resource vcard = model.getResource(personURI);
		String name = vcard.getProperty(VCARD.FN)
                .getString();
		System.out.println(name);
		//model.write(System.out, "N-TRIPLE"/*, "RDF/XML-ABBREV"/*, "Turtle"*/);
		
		
		
		
	}
}
