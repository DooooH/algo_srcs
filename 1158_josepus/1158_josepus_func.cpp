/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1158_josepus_func.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohkim <dohkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:45:20 by dohkim            #+#    #+#             */
/*   Updated: 2020/05/16 23:22:58 by dohkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;
void iter(list<int> &L, list<int>::iterator &t, int K)
{
	for (int i = 1; i < K; i++)
	{
		++t;
		if (t == L.end())
			t = L.begin();
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	list<int> L;
	cin >> N >> K;
	for(int i=1; i<=N; i++)
	{
		L.push_back(i);
	}
	list<int>::iterator t = L.begin();
	cout << "<";
	while (!L.empty())
	{
		iter(L, t, K);
		cout << *t;
		t = L.erase(t);
		if (t == L.end())
			t = L.begin();
		if (!L.empty())
			cout << ", ";	
	}
	cout << ">";
}