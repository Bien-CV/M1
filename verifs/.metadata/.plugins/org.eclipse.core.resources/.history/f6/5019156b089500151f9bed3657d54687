package fr.nantes.cta.one;

import fr.nantes.cta.Airplane;
import fr.nantes.cta.AirplaneOverload;
import fr.nantes.cta.Airport;
import fr.nantes.cta.FlightPlan;
import fr.nantes.cta.IncompatibleAirway;


public class CreateCivilFlight extends FlightImpl{
	private static final int _poidspassager = 70;
	private static final int _poidsbagages= 60;
	
	public CreateCivilFlight (Airport departure, Airport arrival,
			Airplane plane, FlightPlan fp, int passengers)
		    throws IncompatibleAirway, AirplaneOverload {
		super (departure, arrival, plane, fp, passengers);
		if (this.loadingWeight()>plane.getLoading()) throw new AirplaneOverload();
		//verifie que le poids de charge ne depasse pas la capaciter de chargement de l'avion
		if (this.getAirplane().getAutonomy()<this.getFlightPlan().distance()) {
			throw new IncompatibleAirway(this.getAirplane().getAutonomy(),this.getFlightPlan().distance());
			}
		//verifie que la distance a parcourir ne depasse pas l'autonomie de l'avion
	}
	
	/**
	 * retourne le poids de chargement d'un vol civil
	 */
	public double loadingWeight(){
		return (this._nbpassagers*(_poidspassager+_poidsbagages));
	}
	
	/**
	 * retourne le poids total d'un vol civil, avion compris
	 */
	public double totalWeight() {
		return (this.getAirplane().weight())+this._nbpassagers*(_poidspassager+_poidsbagages);
	}
	
}
