package fr.univnantes.cta.impl;

import fr.univnantes.cta.Airplane;
import fr.univnantes.cta.AirplaneOverload;
import fr.univnantes.cta.Airport;
import fr.univnantes.cta.FlightPlan;
import fr.univnantes.cta.IncompatibleAirway;



public class CreateMilitarFlight extends FlightImpl{
	private static final int _poidspassager = 70;
	private static final int _poidsequipement = 100;
	
	
	public CreateMilitarFlight (Airport departure, Airport arrival,
			Airplane plane, FlightPlan fp, int passengers)
			throws IncompatibleAirway, AirplaneOverload {
		super (departure, arrival, plane, fp, passengers);
		if (this.loadingWeight()>plane.getLoading()) throw new AirplaneOverload();  
		//verifie que le poids de charge ne depasse pas la capaciter de chargement de l'avion 
		if (this.getAirplane().getAutonomy()<this.getFlightPlan().distance()) throw new IncompatibleAirway(this.getAirplane().getAutonomy(),this.getFlightPlan().distance());
		//verifie que la distance a parcourir ne depasse pas l'autonomie de l'avion
	}
	
	/**
	 * retourne le poids de chargement dun vol militaire
	 */
	public double loadingWeight(){
		return (this._nbpassagers*(_poidspassager+_poidsequipement));
	}
	
	/**
	 * retourne le poids total d'un vol militaire, avion compris
	 */
	public double totalWeight() {
		return (this.getAirplane().weight())+this._nbpassagers*(_poidspassager+ _poidsequipement);
	}

}
