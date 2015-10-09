
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Controller ctrl= new Controller();
		ctrl.loadDefaultGraph("graph.tp3.rdf");
		Controller.showResults(ctrl.doSelect("q1.rq"));

	}

}
