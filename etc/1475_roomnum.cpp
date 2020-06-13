/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1475_roomnum.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohkim <dohkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 12:29:57 by dohkim            #+#    #+#             */
/*   Updated: 2020/04/27 15:08:59 by dohkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
#define SIZE 9
using namespace std;
int arr[SIZE] = {0,};
int find_min()
{
	int max = arr[0];

	if (arr[6] % 2 == 1)
			arr[6] += 1;
	arr[6] /= 2;
	for (int i = 0; i < SIZE; i++)
		max = std::max(max, arr[i]);
	return (max);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string n;
	cin >> n;
	for (unsigned int i = 0; i < n.length(); i++)
	{
		if (n[i] == '9')
			arr[6] += 1;
		else
			arr[n[i] - '0'] += 1;
	}
	cout << find_min() << '\n';
	return (0);
}