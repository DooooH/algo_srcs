/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10991_star16.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohkim <dohkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:45:37 by dohkim            #+#    #+#             */
/*   Updated: 2020/04/01 17:33:40 by dohkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    int num;
    
    std::cin >> num;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < (num - 1 - i); j++)
            std::cout << ' ';
        for (int j = 0; j < 2*(i + 1) - 1; j++)
        {
            if (j % 2 == 0)
                std::cout << '*';
            else 
                std::cout << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}