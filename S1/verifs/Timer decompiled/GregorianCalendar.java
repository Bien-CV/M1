package com.tp2;

//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

public class GregorianCalendar {
    public static final int HOUR = 1;
    public static final int MINUTE = 2;

    public GregorianCalendar() {
        System.out.println("Stub used");
    }

    public int get(int var1) {
        System.out.println("Stub used");
        return var1 == 1?12:(var1 == 2?30:-1);
    }
}

