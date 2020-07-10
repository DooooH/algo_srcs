/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2562.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohkim <dohkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:08:09 by dohkim            #+#    #+#             */
/*   Updated: 2020/05/20 15:14:12 by dohkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> input;
	int max, max_idx;
	int temp;

	for (int i = 0; i < 9; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}
	
	max = input[0];}
	max_idx = 0;
	for (int i = 0; i < 9; i++)
	{
		if (input[i] > max)
		{
			max = input[i];
			max_idx = i;
		}
	}
	cout << max << "\n" << max_idx + 1 << "\n";
	return (0);
}