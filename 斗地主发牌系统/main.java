import java.util.Scanner;

public class Main {
	public void start(){
		msg("=========================");
		msg("=========春桑欢乐斗地主=======");
		msg("=========================");
		msg("[0]-洗牌");
		msg("[1]-发牌");
	
		CardGame cg = new CardGame();
		enter(cg);
	}
	
	public void enter(CardGame cg){
		Scanner sc = new Scanner(System.in);
		int i = sc.nextInt();
		switch(i){
		case 0:
			cg.shuffle();
			msg("洗牌完成!");
			break;
		case 1:
			cg.sendCard();
			cg.printAllCards();
			break;
		}
		enter(cg);
	}
	
	
	public void msg(String s){
		System.out.println(s);
	}
	
	public static void main(String[] args) {
		new Main().start();
		
		
	}
}
