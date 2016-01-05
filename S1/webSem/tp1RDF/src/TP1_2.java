

import java.io.InputStream;

import org.apache.jena.*;

import org.apache.jena.rdf.model.Model;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.util.FileManager;

public class TP1_2 {
	public static void main(String args[]) {
	// créer un modèle vide
	Model model = ModelFactory.createDefaultModel();
	String inputfile = "inputfile";
	// utiliser le FileManager pour trouver le fichier d'entrée
	InputStream in = FileManager.get().open(inputfile);{
		if (in == null) {
			throw new IllegalArgumentException(
					"Fichier: " + inputfile + " non trouvé");
		}

		// lire le fichier RDF/XML
		model.read(in, null);
		 
		// l'écrire sur la sortie standard
		model.write(System.out, "N-TRIPLE");
	}
	}
}