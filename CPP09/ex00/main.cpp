/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:37:33 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/24 02:14:11 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av){

    if (ac != 2)
        return 1; //mettre message d erreur
    
    return 0;
}


/*
THE IDEA : 
1) verifier si y a un élément en av pas plus pas moin
2) parser les éléments du fichier .txt dans un container map(int, float) YYYYMMDD et le float
    error : float negatif
    error : date impossible (+12 pour le mois)(+ que 20260301) (jour + que 28, 20 ou 31)(data inferieur a la creation du bitoin 20090103)
3) int base = au premier . Que faire si il est deja plus tard que la date du .txt? erreur ?
    while (db_date <= txt_date) base= date;
    db_value * txt_value
*/
/*

You have to create a program which outputs the value of a certain amount of bitcoin
on a certain date.
This program must use a database in csv format which will represent bitcoin price
over time. This database is provided with this subject.
The program will take as input a second database, storing the different prices/dates
to evaluate.
Your program must respect these rules:
• The program name is btc.
• Your program must take a file as an argument.
• Each line in this file must use the following format: "date | value".
• A valid date will always be in the following format: Year-Month-Day.
• A valid value must be either a float or a positive integer, between 0 and 1000.


You must use at least one container in your code to validate this
exercise. You should handle possible errors with an appropriate
error message.

Here is an example of an input.txt file:
$> head input.txt
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648


Your program will use the value in your input file.

Your program should display on the standard output the result of the value multiplied
by the exchange rate according to the date indicated in your database.

If the date used in the input does not exist in your DB then you
must use the closest date contained in your DB. Be careful to use the
lower date and not the upper one.

The following is an example of the program’s use.
$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>




*/