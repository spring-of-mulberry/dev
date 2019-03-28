package com.softeem.card.entity;

import java.util.ArrayList;
import java.util.List;

public class Player {
	//玩家id
	private int id;
	//玩家名称
	private String name;
	//是否为地主
	private boolean boss;
	//牌
	private List<Card> cards = new ArrayList<Card>();
	
	public Player() {
		// TODO Auto-generated constructor stub
	}
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public boolean isBoss() {
		return boss;
	}
	public void setBoss(boolean boss) {
		this.boss = boss;
	}
	public List<Card> getCards() {
		return cards;
	}
	public void setCards(List<Card> cards) {
		this.cards = cards;
	}

	public Player(int id, String name) {
		super();
		this.id = id;
		this.name = name;
	}

	
}
