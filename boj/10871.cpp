/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10871.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohkim <dohkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:28:57 by dohkim            #+#    #+#             */
/*   Updated: 2020/04/07 15:07:20 by dohkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N, X;

    std::cin >> N;
    int *arr = new int[N];
    std::cin >> X;
    for (int i = 0; i < N; i++)
        std::cin >> arr[i];
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < X)
        {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << "\n";
    delete[] arr;
    return (0);
}
