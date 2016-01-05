package com.tp2;

//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

public class Timer {
    protected int ring;
    protected int hour;
    protected int min;
    protected boolean active;
    protected boolean ringing;

    public Timer(int var1, int var2, int var3) throws TimerException {
        if(var2 < 0) {
            throw new TimerException("bad hour: inf value");
        } else if(var2 > 23) {
            throw new TimerException("bad hour: sup value");
        } else if(var3 < 0) {
            throw new TimerException("bad min: inf value");
        } else if(var3 > 59) {
            throw new TimerException("bad min: sup value");
        } else if(var1 >= 1 && var1 <= 10) {
            this.ring = var1;
            this.hour = var2;
            this.min = var3;
            this.active = false;
            this.ringing = false;
        } else {
            throw new TimerException("bad ring: out of limits");
        }
    }

    public void selectRing(int var1) throws TimerException {
        if(this.ringing) {
            throw new TimerException("timer is ringing...");
        } else if(var1 >= 1 && var1 <= 10) {
            this.ring = var1;
        } else {
            throw new TimerException("bad ring: out of limits");
        }
    }

    public void addMin(int var1) throws TimerException {
        int var2 = 0;
        boolean var3 = false;
        boolean var4 = false;
        if(var1 < 0) {
            throw new TimerException("bad min: inf value");
        } else {
            while(var1 > 59) {
                ++var2;
                var1 -= 60;
            }

            int var5 = this.min + var1;
            if(var5 > 59) {
                ++var2;
                var5 -= 60;
            }

            int var6;
            for(var6 = this.hour + var2; var6 > 23; var6 -= 24) {
                ;
            }

            this.hour = var6;
            this.min = var5;
        }
    }

    protected void setActive(boolean var1) {
        this.active = var1;
        if(this.active) {
            GregorianCalendar var2 = new GregorianCalendar();
            if(this.hour == var2.get(1) && this.min == var2.get(2)) {
                this.ringing = true;
            }
        }

    }

    public boolean equals(Object var1) {
        return var1 != null && var1 instanceof Timer?this.ring == ((Timer)var1).ring && this.hour == ((Timer)var1).hour && this.min == ((Timer)var1).min && this.active == ((Timer)var1).active && this.ringing == ((Timer)var1).ringing:false;
    }

    public String toString() {
        String var1 = "";
        var1 = var1 + this.hour + ":" + this.min;
        if(this.active) {
            var1 = var1 + "  (active";
            if(this.ringing) {
                var1 = var1 + ":ringing";
            }

            var1 = var1 + ")";
        }

        return var1;
    }

    public static void main(String[] var0) {
        try {
            Timer var1 = new Timer(3, 12, 30);
            var1.setActive(true);
            System.out.println(var1);
            var1.addMin(55);
            System.out.println(var1);
            GregorianCalendar var2 = new GregorianCalendar();
            System.out.println(var2.get(1));
        } catch (TimerException var3) {
            System.out.println(var3);
        }

    }
}

