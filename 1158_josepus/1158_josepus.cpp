/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1158_josepus.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohkim <dohkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:45:20 by dohkim            #+#    #+#             */
/*   Updated: 2020/05/14 23:05:03 by dohkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;
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
		for (int i = 1; i < K; i++)
		{
			++t;
			if (t == L.end())
				t = L.begin();
		}
		cout << *t;
		t = L.erase(t);
		if (t == L.end())
			t = L.begin();
		if (!L.empty())
			cout << ", ";	
	}
	cout << ">";
}