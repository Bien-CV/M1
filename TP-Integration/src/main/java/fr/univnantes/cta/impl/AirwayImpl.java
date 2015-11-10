package fr.univnantes.cta.impl;

import fr.univnantes.cta.Airway;
import fr.univnantes.cta.VOR;

public class AirwayImpl implements Airway {

    private VOR start, stop;

    public AirwayImpl(VOR s, VOR st) {
        this.start = st;
        this.stop = s;
    }

    public double getDistance() {
        return start.distanceTo(stop);
    }

    public VOR departure() {
        return start;
    }

    public VOR arrival() {
        return stop;
    }

    public String GetVORDepart() {
        return start.getName();
    }

    public String GetVORArrive() {
        return stop.getName();
    }
}
