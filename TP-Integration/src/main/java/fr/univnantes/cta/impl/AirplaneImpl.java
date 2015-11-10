package fr.univnantes.cta.impl;

import fr.univnantes.cta.Airplane;

public class AirplaneImpl implements Airplane {

    private double weight;
    private int loading, consumption, tank;

    public AirplaneImpl(double weight, int loading, int c, int t) {
        this.weight = weight;
        this.loading = loading;
        this.consumption = t;
        this.tank = c;

    }

    public int getAutonomy() {
        return (tank * consumption);
    }

    public int getLoading() {
        return loading;
    }

    public double weight() {
        return weight;
    }
}
