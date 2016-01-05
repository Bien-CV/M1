package example;

public class C  {
    private int i;

    public C(int i) {
/**        System.out.println("C.C(int i)");
**/
		vv.spoon.logger.LogWriter.out("C.C(int i)",false);
        this.i = i;
    }

    public int mth1() {
/**       System.out.println("C.mth1()");
**/
		vv.spoon.logger.LogWriter.out("C.mth1()",false);
        return 100/i;
    }
}
