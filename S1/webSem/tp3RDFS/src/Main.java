import org.apache.jena.query.ResultSet;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Controller ctrl = new Controller();
		ctrl.loadDefaultGraph("graph.tp3.rdf");

		
		System.out.println(ctrl.readQuery("sparql", "q1.rq"));
		// QUESTION 1
		System.out.println("Instances de Flemish :");
		ResultSet results = ctrl.doSelect("q1.rq");
		Controller.showResults(results);
		System.out.println("\n");

		// QUESTION 2
		System.out.println("first name and last name of instances de Flemish :");
		results = ctrl.doSelect("q2.rq");
		Controller.showResults(results);
		System.out.println("\n");

		// QUESTION 3
		ctrl.doUpdate("q3.rq");

		// QUESTION 4a
		System.out.println("first name and last name of instances de Cubist :");
		results = ctrl.doSelect("q4a.rq");
		Controller.showResults(results);
		System.out.println("\n");

		// QUESTION 4b
		System.out.println("first name and last name of instances de Painter :");
		results = ctrl.doSelect("q4b.rq");
		Controller.showResults(results);
		System.out.println("\n");

		// QUESTION 5
		ctrl.enableRDFS(null);

		// QUESTION 6a
		System.out.println("first name and last name of instances de Cubist :");
		results = ctrl.doSelect("q4a.rq");
		Controller.showResults(results);
		System.out.println("\n");

		// QUESTION 6b
		System.out.println("first name and last name of instances de Painter et leurs types:");
		results = ctrl.doSelect("q4b.rq");
		Controller.showResults(results);
		System.out.println("\n");

	}

}
