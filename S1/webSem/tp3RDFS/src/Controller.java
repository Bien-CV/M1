

import org.apache.jena.rdf.model.*;
import org.apache.jena.sparql.core.DatasetImpl;
import org.apache.jena.update.*;
import org.apache.jena.util.FileManager;
import org.apache.jena.query.* ;

import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;


public class Controller {

    private Dataset dataset;

    /**
     * Constructeur
     */
    public Controller() {
        // create an empty dataset
        this.dataset = new DatasetImpl(ModelFactory.createDefaultModel());
    }

    /**
     * Lit une requête dans un fichier et la renvoie sous forme de chaîne
     * @param directory String Répertoire dans lequel chercher le fichier
     * @param filename String Fichier contenant la requête à extraire
     * @return String La requête SPARQL formée à partir du fichier
     */
    public String readQuery(String directory, String filename) {
        List<String> lines = null;
        String query = "";

        try {
            // On récupère le contenu du fichier
            lines = Files.readAllLines(Paths.get(directory, filename), StandardCharsets.UTF_8);
        } catch (IOException e) {
            e.printStackTrace();
        }

        // on forme la requête depuis le fichier
        for(String l: lines) {
            query += " " + l;
        }

        return query;
    }

    /**
     * Charge les données depuis un fichier RDF dans le graphe par défaut
     * @param filename String Fichier contenant le graphe au format RDF/XML
     */
    public void loadDefaultGraph(String filename) {

        // use the FileManager to find the input file
        InputStream in = FileManager.get().open(filename);
        if (in == null) {
            throw new IllegalArgumentException("File: " + filename + " not found");
        }

        // read the RDF/XML file
        this.dataset.getDefaultModel().read(in, null);
    }

    /**
     * Charge les données depuis un fichier RDF dans un graphe nommé
     * @param filename String Fichier contenant le graphe au format RDF/XML
     */
    public void loadNamedGraph(String uri, String filename) {

        // use the FileManager to find the input file
        InputStream in = FileManager.get().open(filename);
        if (in == null) {
            throw new IllegalArgumentException("File: " + filename + " not found");
        }

        // read the RDF/XML file
        this.dataset.addNamedModel(uri, ModelFactory.createDefaultModel().read(in, null));
    }

    /**
     * Charge la requête de type SELECT contenue dans un fichier et l'exécute
     * @param filename String Fichier contenant la requête
     * @return ResultSet Les résultats de la requête
     */
    public ResultSet doSelect(String filename) {
        ResultSet results = null;

        // on crée la requête
        Query query = QueryFactory.create(this.readQuery("sparql", filename)) ;
        try {
            // on exécute la requête
            QueryExecution qexec = QueryExecutionFactory.create(query, this.dataset);
            results = qexec.execSelect() ;
        } catch(Exception e) {
            System.err.println(e.getMessage());
        }

        // on renvoie les résultats
        return results;
    }

    /**
     * Charge la requête de type UPDATE/DELETE contenue dans un fichier et l'exécute
     * @param filename String Fichier contenant la requête
     * @return
     */
    public void doUpdate(String filename) {
        ResultSet results = null;

        // on crée la requête
        UpdateRequest query = UpdateFactory.create(this.readQuery("sparql", filename)) ;

        try {
            // on exécute la requête
            UpdateProcessor qexec = UpdateExecutionFactory.create(query, this.dataset);
            qexec.execute();
        } catch(Exception e) {
            System.err.println(e.getMessage());
        }
    }

    /**
     * Méthode activant l'inférence sur un graphe nommé ou par défaut
     * @param uri String|null L'uri du graphe cible, ou null si on veut cibler le graphe par défaut
     */
    public void enableRDFS(String uri) {
        InfModel new_model = null;

        // si on cible le graphe par défaut
        if(uri == null) {
            // on récupère le graphe par défaut et on active l'inférence
            new_model = ModelFactory.createRDFSModel(this.dataset.getDefaultModel());

            // on met à jour le graphe par défaut
            this.dataset.setDefaultModel(new_model);
        } else { //sinon, on cible un graphe nommé
            // on récupère le graphe nommé et on active l'inférence
            new_model = ModelFactory.createRDFSModel(this.dataset.getNamedModel(uri));

            // on met à jour le graphe nommé
            this.dataset.replaceNamedModel(uri, new_model);
        }
    }

    /**
     * Méthode affichant les résultats issue d'un ResultSet
      * @param results ResultSet Les résultats à afficher
     */
    public static void showResults(ResultSet results) {
        QuerySolution soln = null;

        for ( ; results.hasNext() ; ) {
            soln = results.nextSolution() ;
            System.out.println(soln.toString());
        }
    }

}
