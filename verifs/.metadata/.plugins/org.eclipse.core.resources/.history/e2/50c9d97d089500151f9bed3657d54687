package fr.nantes.cta.one;

import fr.nantes.cta.Position;
import fr.nantes.cta.VOR;


public class VORImpl implements VOR {
	private String _nom;
	private Position _position;

	public VORImpl(String name, Position position) {
		_nom      = name;
		_position = position;
	}

	public double distanceTo(VOR other) {
		return (this.getPosition()).distanceTo(other.getPosition());
	}

	public String getName() {
		return this._nom;
	}

	public Position getPosition() {
		return _position;
	}

}
