package fr.univnantes.cta.impl;

import fr.univnantes.cta.Airport;



public class AirportImpl implements Airport{
	private String Name;
	
	public AirportImpl(String nom){
		Name = nom;
	}

	public String getName() {
		return Name;
	}

}
