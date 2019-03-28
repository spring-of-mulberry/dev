import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Random;

import com.softeem.card.entity.Card;
import com.softeem.card.entity.Player;

public class CardGame {
	//花数
	String[] flowers = {"红心","黑桃","方块","梅花"};
	//点数
	String[] nums = {"3","4","5","6","7","8","9","10","J","Q","K","A","2"};
	//大王
	String king = "King";
	//小王
	String queen = "Queen";
	//存储所有的牌
	ArrayList<Card> db = new ArrayList<Card>();
	//声明玩家
	ArrayList<Player> players;
	//玩家索引
	int curNum;
	//发牌索引
	int dbIndex;
	
	public CardGame() {
		players = new ArrayList<Player>();
		players.add( new Player(1,"刘备"));
		players.add( new Player(2,"关羽"));
		players.add( new Player(3,"张飞"));
		//初始化所有牌
			initCards();
//			//洗牌
//			shuffle();
//			//发牌
//			sendCard();
//			//打印
//			printAllCards();
	
	}
	//打印
	public void printAllCards() {
		// TODO Auto-generated method stub
		for(Player p: players){
			sort(p.getCards());
			System.out.println(p.getName()+"->"+p.getCards());
		}
	}

	//初始化54张牌
	public void initCards() {
		for (int i = 0; i < nums.length; i++) {
			for (int j = 0; j < flowers.length; j++) {
				//创建卡片,每次循环获取一张牌（点数，花色，排序）
				Card c = new Card();
				c.setFlower(flowers[j]);
				c.setNum(nums[i]);
				c.setSort(i);
				//存入集合
				db.add(c);
			}
		}
		db.add(new Card(queen,13));
		db.add(new Card(king,14));
	}
	
	//洗牌
	public void shuffle() {
		Collections.shuffle(db);
		Collections.shuffle(db);
		Collections.shuffle(db);
	}
	
	public void sort(List<Card> list) {
		Collections.sort(list);
	}
	//发牌
	public void sendCard() {
		//定地主
		Random r = new Random();
		//随即产生一个索引（0,1,2）
		int index = r.nextInt(players.size());
		//设置为地主
		players.get(index).setBoss(true);
		//发牌
		sendCard2();
		
	}
	public void sendCard2(){
		for(Player p :players){
			p.getCards().clear();
		}
		//
		curNum = 0;
		dbIndex = 0;
		//发牌
		while(dbIndex<(db.size()-3)){
			if(curNum==0){
				players.get(curNum).getCards().add(db.get(dbIndex));
				curNum=1;
			}else if(curNum==1){
				players.get(curNum).getCards().add(db.get(dbIndex));
				curNum=2;
			}else{
				players.get(curNum).getCards().add(db.get(dbIndex));
				curNum=0;	
			}
			dbIndex++;
		}
		for(Player p :players){
			if(p.isBoss()){
				p.getCards().add(db.get(51));
				p.getCards().add(db.get(52));
				p.getCards().add(db.get(53));
				break;
			}
		}
		
	}
	
}
