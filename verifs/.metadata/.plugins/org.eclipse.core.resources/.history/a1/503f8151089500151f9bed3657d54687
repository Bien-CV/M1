package fr.nantes.cta.one;

import fr.nantes.cta.Airplane;




public class AirplaneImpl implements Airplane {
	private double _poids;
	private int _capacite, _consomation, _capareservoir;
		
	public AirplaneImpl(double weight, int loading, int consumption, int tank){
		_poids = weight;
		_capacite = loading;
		_consomation = consumption;
		_capareservoir = tank;
		
	}

	public int getAutonomy() {
		return (_capareservoir*_consomation);
	}

	public int getLoading() {
		return _capacite;
	}

	public double weight() {
		return _poids;
	}

}
