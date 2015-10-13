import java.util.*;


public class Ex1 {
	private Vector<Integer> pile;
	private int nbElem;
	
	public Ex1(){
		pile = new Vector<Integer>();
		nbElem = 0;
	}
	
	public void push(Integer x){
		assert (nbElem<10) : "full pile can't add";
		pile.add(nbElem, x);
		nbElem++;
			
		
	}
	
	public Integer pop(){
		assert ! pile.isEmpty(): "empty pile, can't pop";
		Integer poped;
		poped= pile.remove(nbElem - 1);
		nbElem--;
		return poped;
	}
	
	public static void main(String[] args) {
		boolean testAssert = false;
		assert testAssert=true ;
		if (testAssert){
			System.out.println("les assertions sont activées");
		}else{
			System.out.println("les assertions ne sont pas activées");
		}
		Ex1 x = new Ex1();
		x.push(45);x.push(45);x.push(45);x.push(45);x.push(45);x.push(45);x.push(45);
		x.push(45);x.push(45);x.push(45);x.push(45);x.push(45);x.push(45);x.push(45);x.push(45);
		
		System.out.println(x.pop());

	}

}
