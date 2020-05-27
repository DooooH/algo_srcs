/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2741_printN.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohkim <dohkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:29:19 by dohkim            #+#    #+#             */
/*   Updated: 2020/04/06 15:08:56 by dohkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <vector>
// #include <string>
#include <cstdio>

int main()
{
    int num;
    // std::vector<std::string> result;

    scanf("%d", &num);
    for (int i = 1; i < num + 1; i++)
    {
        printf("%d\n", i);
    }
    return(0);
}