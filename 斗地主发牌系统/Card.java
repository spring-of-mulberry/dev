package com.softeem.card.entity;

/*
 * 牌类
 */
public class Card implements Comparable<Card> {
	//id
	private int id;
	//花色
	private String flower;
	//点数
	private String num;
	//排序号
	private int sort;
	

	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getFlower() {
		return flower;
	}
	public void setFlower(String flower) {
		this.flower = flower;
	}
	public String getNum() {
		return num;
	}
	public void setNum(String num) {
		this.num = num;
	}
	public int getSort() {
		return sort;
	}
	public void setSort(int sort) {
		this.sort = sort;
	}
	
	public String toString(){
		return num+"-"+flower;
	}

	public Card() {
		super();
	}
	public Card(String num, int sort) {
		super();
		this.num = num;
		this.sort = sort;
	}
	
	public int compareTo(Card o) {

		return this.sort-o.sort;
	}
}
