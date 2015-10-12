package TP3;

import org.apache.jena.query.ResultSet;
import org.apache.jena.rdf.model.ModelFactory;

import controller_package.Controller;


public class Main {
	public static void main(String[] args) {
		Controller ctrl = new Controller();
		ctrl.readingRDF("peintures.rdf");

		
		// QUESTION 1
		System.out.println("1) Instances de Flemish :");
		ctrl.doSelect("sparql/q1.rq");
		System.out.println("\n");

		// QUESTION 2
		System.out.println("2) first name and last name of instances de Flemish :");
		ctrl.doSelect("sparql/q2.rq");
		System.out.println("\n");

		// QUESTION 3
		ctrl.doUpdate("sparql/q3.rq");

		// QUESTION 4a
		System.out.println("4a) first name and last name of instances de Cubist :");
		ctrl.doSelect("sparql/q4a.rq");
		System.out.println("\n");

		// QUESTION 4b
		System.out.println("4b) first name and last name of instances de Painter :");
		ctrl.doSelect("sparql/q4b.rq");
		System.out.println("\n");

		// QUESTION 5
		ctrl= new Controller(ModelFactory.createRDFSModel(ctrl.getDatas().getDefaultModel()));

		// QUESTION 6a
		System.out.println("6a) first name and last name of instances de Cubist :");
		ctrl.doSelect("sparql/q4a.rq");
		System.out.println("\n");

		// QUESTION 6b
		System.out.println("6b) first name and last name of instances de Painter et leurs types:");
		ctrl.doSelect("sparql/q4b.rq");
		System.out.println("\n");

	}

}
