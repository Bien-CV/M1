package controller_package;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;

import org.apache.jena.query.Dataset;
import org.apache.jena.query.Query;
import org.apache.jena.query.QueryExecution;
import org.apache.jena.query.QueryExecutionFactory;
import org.apache.jena.query.QueryFactory;
import org.apache.jena.query.ResultSet;
import org.apache.jena.query.ResultSetFormatter;
import org.apache.jena.rdf.model.Model;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.sparql.core.DatasetImpl;
import org.apache.jena.update.UpdateExecutionFactory;
import org.apache.jena.update.UpdateFactory;
import org.apache.jena.update.UpdateProcessor;
import org.apache.jena.update.UpdateRequest;
import org.apache.jena.util.FileManager;


public class Controller {

	private Dataset dataset;

	/**
	 * Constructeur
	 */
	public Controller() {
		// create an empty dataset
		dataset = new DatasetImpl(ModelFactory.createDefaultModel());
	}

	/**
	 * Constructeur au cas où l'on veut passer un autre type de model exemple un
	 * model inféré 
	 * ex : ctrl2= new ControllerBis(ModelFactory.createRDFSModel(ctrl.getDatas().getDefaultModel()));
	 */
	public Controller(Model model) {
		dataset = new DatasetImpl(model);
	}
	public Dataset getDatas(){
		return dataset;
	}

	public void readingRDF(String filename){

		// Open RDF file
		InputStream in = FileManager.get().open(filename);
		if (in == null) {
		    throw new IllegalArgumentException("File not found");
		}

		// Load file content
		dataset.getDefaultModel().read(in, null);
		//model.write(System.out, "Turtle");
	}

	public String readQuery(String filename){
		try {
            File file = new File(filename);
            FileInputStream inputStream = new FileInputStream(file);
            BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
            StringBuilder data = new StringBuilder();
            String line;

            while ((line = reader.readLine()) != null) {
                data.append(line + "\n");
            }

            inputStream.close();
			return data.toString();
        }
        catch(Exception ex){
            return null;
        }
	}

	public void doSelect(String filename){

		String request = readQuery(filename);
		Query query = QueryFactory.create(request);
		QueryExecution qexec = QueryExecutionFactory.create(query, dataset);
		ResultSet results =  qexec.execSelect();

		// Output query results	
		ResultSetFormatter.out(System.out, results, query);

		// Important - free up resources used running the query
		qexec.close();
	}
	public void doUpdate(String filename){

		String request = readQuery(filename);
		
		UpdateRequest query = UpdateFactory.create(request);
        UpdateProcessor qexec = UpdateExecutionFactory.create(query, dataset);
		qexec.execute();

	}
	public Model getModel(){
		return dataset.getDefaultModel();
	}
	
}
