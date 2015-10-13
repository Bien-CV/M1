package com.tp2;

//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

public class TimerException extends Exception {
    private static final long serialVersionUID = 1L;
    private String msg;

    public TimerException(String var1) {
        this.msg = var1;
    }

    public String toString() {
        return this.msg + " : " + super.toString();
    }
}

