/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1463_dp1.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohkim <dohkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 21:03:23 by dohkim            #+#    #+#             */
/*   Updated: 2020/04/06 14:26:48 by dohkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

int min(int a, int b, int c)
{
    int min = -1;
    int arr_list[3] = {a, b, c};
    std::vector<int> list;

    for (int i = 0; i < 3; i++)
    {
        if (arr_list[i] != -1)
            list.push_back(arr_list[i]);
    }
    if (list.size() == 0)
        return (-1);
    else
    {
        min = list[0];
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i] < min)
                min = list[i];
        }
    }
    return (min);
}

// int find_min_recur(int num, int *mem)
// {
//     int op1 = -1, op2 = -1, op3 = -1;
//     if (mem[num] != -1)
//     {
//         // std::cout << "return " << num << std::endl;
//         return (mem[num]);
//     }
//     if (num - 1 >= 1)
//         op1 = find_min(num - 1, mem) + 1;
//     if (num % 2 == 0)
//         op2 = find_min(num / 2, mem) + 1;
//     if (num % 3 == 0)
//         op3 = find_min(num / 3, mem) + 1;
//     // std::cout << num << ": " << op1 << ' ' << op2 << ' ' << op3 << std::endl;
//     if (min(op1, op2, op3) != -1)
//         mem[num] = min(op1, op2, op3);
//     return (mem[num]);
// }

int find_min_iter(int num, int *mem)
{
    int op1, op2, op3;

    for (int i = 2; i < num + 1; i++)
    {
        op1 = -1;
        op2 = -1;
        op3 = -1;
        if (i - 1 >= 1)
            op1 = mem[i - 1] + 1;
        if (i % 2 == 0)
            op2 = mem[i / 2] + 1;
        if (i % 3 == 0)
            op3 = mem[i / 3] + 1;
        mem[i] = min(op1, op2, op3);
    }
    return (mem[num]);
}

void    intialize_mem(int *mem, int num)
{
    for (int i = 0; i < num + 1; i++)
    {
        if (i == 1)
            mem[i] = 0;
        else
            mem[i] = -1;
    }
}

int main()
{
    int num;

    std::cin >> num;
    int *mem = new int[num + 1];
    intialize_mem(mem, num);
    std::cout << find_min_iter(num, mem) << std::endl;
    delete[] mem;
    return (0);
}