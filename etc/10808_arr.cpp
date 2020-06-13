/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10808_arr.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohkim <dohkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 20:44:42 by dohkim            #+#    #+#             */
/*   Updated: 2020/04/11 21:36:17 by dohkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	int arr['z' + 1];

	// for (int &e : arr)
	// 	e = 0;
	fill(arr, arr + 'z' + 1,  0);
	cin >> S;
	for (int i = 0; i < S.length(); i++)
		arr[S[i]] += 1;
	for (int i = 'a'; i < 'z' + 1; i++)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}