/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1920.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohkim <dohkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:59:52 by dohkim            #+#    #+#             */
/*   Updated: 2020/05/20 15:12:59 by dohkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
#define SWAP(a, b, temp) temp = a; a = b; b = temp;
using namespace std;

void partition(vector<int> &V, int start, int end, int &pivot)
{
	int temp;
	int left, right;
	
	pivot = start;
	left = start;
	right = end;
	while (left < right)
	{
		while (V[left] <= V[pivot] && left < end)
			left++;
		while (V[right] >= V[pivot] && right > start)
			right--;
		if (left < right)
		{
			SWAP(V[left], V[right], temp);
		}
	}
	if (pivot != right)
	{
		SWAP(V[pivot], V[right], temp);
		pivot = right;
	}
}

void quick_sort(vector<int> &V, int start, int end)
{
	int pivot;

	if (start < end)
	{
		partition(V, start, end, pivot);
		if (pivot != start)
			quick_sort(V, start, pivot - 1);
		if (pivot != end)
			quick_sort(V, pivot + 1, end);
	}
}

int binary_search(vector<int> &V, int target)
{
	int start, end;
	int mid;

	start = 0;
	end = V.size() - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (V[mid] == target)
			return (1);
		else if (V[mid] < target)
			start = mid + 1;
		else if (V[mid] > target)
			end = mid - 1;
	}
	return (0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	vector<int> Ns, Ms;
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		Ns.push_back(temp);
	}
	quick_sort(Ns, 0, Ns.size() - 1);
	cin >> M;
	int exist = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		exist = binary_search(Ns, temp);
		Ms.push_back(exist);
		exist = 0;
	}
	for (auto t : Ms)
	{
		cout << t << "\n";
	}
	return (0);
}