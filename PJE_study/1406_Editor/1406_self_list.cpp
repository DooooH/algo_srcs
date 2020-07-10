/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1406_self_list.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohkim <dohkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 18:10:37 by dohkim            #+#    #+#             */
/*   Updated: 2020/05/18 15:56:42 by dohkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/stdc++.h>
using namespace std;

typedef struct s_node {
	char data;
	struct s_node *prev, *next;
} t_node;

void lst_push_back(t_node *list, char data)
{
	t_node *node;
	t_node *head;

	node = new t_node;
	head = list;
	if (head == NULL)
	{
		node->next = NULL;
		node->prev = NULL;
		node->data = data;
		return ;
	}
	while (head->next != NULL)
	{
		head = head->next;
	}
	node->data = data;
	node->prev = head;
	node->next = NULL;
	head->next = node;
}




int main()
{
	string base;
	int cmd_num;
	char cmd, option;
	list<char> L_base;
	list<char> L_cmd;
	cin >> base >> cmd_num;
	for (int i = 0; i < cmd_num; i++)
	{
		cin >> cmd;
		L_cmd.push_back(cmd);
		if (cmd == 'P')
		{
			cin >> option;
			L_cmd.push_back(option);
		}
	}
	for (auto t: base)
	{
		L_base.push_back(t);
	}
	list<char>::iterator cursor = L_base.end();
	list<char>::iterator t = L_cmd.begin();
	while (t != L_cmd.end())
	{
		switch(*t)
		{
			case 'P':
				++t;
				L_base.insert(cursor, *t); //cursor?
				break ;
			case 'L':
				if (cursor != L_base.begin())
					cursor--;
				break ;
			case 'D':
				if (cursor != L_base.end())
					cursor++;
				break ;
			case 'B':
				if (cursor != L_base.begin())
					cursor = L_base.erase(--cursor);
				break ;
			default :
				;
		}
		t++;
	}
	for (auto t : L_base)
	{
		cout << t;
	}
	return (0);
}
	// list<char>::iterator temp ;
	// temp = L_base.insert(cursor, 'x');
	// cout << *temp << endl;
	// if (cursor == L_base.end())
	// 	cout << "end \n";
	// for (auto t: L_base)
	// {
	// 	cout << t << " ";
	// }

	// cursor++;
	// L_base.insert(cursor, 'x');
	// cout << *cursor << endl;
	// for (auto t: L_base)
	// {
	// 	cout << t << " ";
	// }