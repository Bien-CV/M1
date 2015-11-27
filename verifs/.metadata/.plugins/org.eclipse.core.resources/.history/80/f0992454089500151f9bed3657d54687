package fr.nantes.cta.one;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Vector;

import fr.nantes.cta.FlightPlan;
import fr.nantes.cta.TakenAirway;



public class FlightPlanImpl implements FlightPlan{
    
	private List<TakenAirway> airwayListModifiable;
    
	private List<TakenAirway> airwayListNonModifiable;
	
	
    public FlightPlanImpl() {
    	airwayListModifiable = new Vector<TakenAirway>();
    	airwayListNonModifiable = Collections.unmodifiableList(airwayListModifiable);
    }

	public void addAirway(TakenAirway a) {
		if (airwayListModifiable.isEmpty()){airwayListModifiable.add(a);}
		else {int dernier = (airwayListModifiable.size()-1);
		    if (((AirwayImpl)(airwayListModifiable.get(dernier).getAirway())).GetVORArrive() != ((AirwayImpl)(a.getAirway())).GetVORDepart())
		        {throw new IllegalArgumentException("Erreur dans le plan de vol : \nun Aeroport de depart ne correspond pas a un aeroport d'arriver precedent");
		        }
		    
		    // verifi si le depart du vol ajouter correspond bien a l'arriver du vol precedent
		    //pour verifier la correspondence des vols
		    
		    airwayListModifiable.add(a);
		  }
		
	}

	public double distance() {
		double total = 0;
		for (TakenAirway ta : airwayListModifiable){
			total = total + ta.distance();						//calcul la distance du plan de vol
		}
		return total;
	}

	public List<TakenAirway> getPath() {
		return airwayListNonModifiable;		//retourne la liste des plan de vols
	}
	
}
