#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// This program uses Luhn's Algorithm to determine if the user's input is a vaild credit card number.
// Accepts American Express (AMEX), MasterCard, and Visa credit cards.

int main(void)
{
    long number;
    number = get_long("Number: ");                                      // Prompt user for credit card number

    int n_digits = log10(number) + 1;                                   // Calculate length of input

    // MasterCard?
    if ((((number / 100000000000000) % 10) == 1 || ((number / 100000000000000) % 10) == 2 || ((number / 100000000000000) % 10) == 3
         || ((number / 100000000000000) % 10) == 4 || ((number / 100000000000000) % 10) == 5) && floor(n_digits) == 16
        && ((number / 1000000000000000) % 10) == 5)
    {
        int a = (number / 1000000000000000) % 10;                        // Store first digit of user input
        int b = (number / 100000000000000) % 10;
        int c = (number / 10000000000000) % 10;
        int d = (number / 1000000000000) % 10;
        int e = (number / 100000000000) % 10;
        int f = (number / 10000000000) % 10;
        int g = (number / 1000000000) % 10;
        int h = (number / 100000000) % 10;
        int i = (number / 10000000) % 10;
        int j = (number / 1000000) % 10;
        int k = (number / 100000) % 10;
        int l = (number / 10000) % 10;
        int m = (number / 1000) % 10;
        int n = (number / 100) % 10;
        int o = (number / 10) % 10;
        int p = (number / 1) % 10;                                        // Store last digit of user input

        int o_dub, m_dub, k_dub, i_dub, g_dub, e_dub, c_dub, a_dub;
        // Begin Luhn's Algorithm: double every other digit starting second to last
        o_dub = 2 * o;
        m_dub = 2 * m;
        k_dub = 2 * k;
        i_dub = 2 * i;
        g_dub = 2 * g;
        e_dub = 2 * e;
        c_dub = 2 * c;
        a_dub = 2 * a;

        if (a_dub >= 10)  // If the doubled digits are >= 10 add the digit in the ten's place to the digit in the one's place
        {
            a_dub = 1 + a_dub % 10;
        }
        if (c_dub >= 10)
        {
            c_dub = 1 + c_dub % 10;
        }
        if (e_dub >= 10)
        {
            e_dub = 1 + e_dub % 10;
        }
        if (g_dub >= 10)
        {
            g_dub = 1 + g_dub % 10;
        }
        if (i_dub >= 10)
        {
            i_dub = 1 + i_dub % 10;
        }
        if (k_dub >= 10)
        {
            k_dub = 1 + k_dub % 10;
        }
        if (m_dub >= 10)
        {
            m_dub = 1 + m_dub % 10;
        }
        if (o_dub >= 10)
        {
            o_dub = 1 + o_dub % 10;
        }
        // Add the doubled digit's digits to the digits in the user input that were not doubled
        int sum = a_dub + c_dub + e_dub + g_dub + i_dub + k_dub + m_dub + o_dub + b + d + f + h + j + l + n + p;

        if (sum % 10 == 0) // If the sum's modulo 10 is congruent to 0 >> valid MASTERCARD
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (floor(n_digits) == 16 && ((number / 1000000000000000) % 10) == 4)   // 16-digit Visa?
    {
        int a = (number / 1000000000000000) % 10;                                  // Store first digit of user input
        int b = (number / 100000000000000) % 10;
        int c = (number / 10000000000000) % 10;
        int d = (number / 1000000000000) % 10;
        int e = (number / 100000000000) % 10;
        int f = (number / 10000000000) % 10;
        int g = (number / 1000000000) % 10;
        int h = (number / 100000000) % 10;
        int i = (number / 10000000) % 10;
        int j = (number / 1000000) % 10;
        int k = (number / 100000) % 10;
        int l = (number / 10000) % 10;
        int m = (number / 1000) % 10;
        int n = (number / 100) % 10;
        int o = (number / 10) % 10;
        int p = (number / 1) % 10;                                        // Store last digit of user input

        int o_dub, m_dub, k_dub, i_dub, g_dub, e_dub, c_dub, a_dub;
        // Begin Luhn's Algorithm: double every other digit starting second to last
        o_dub = 2 * o;
        m_dub = 2 * m;
        k_dub = 2 * k;
        i_dub = 2 * i;
        g_dub = 2 * g;
        e_dub = 2 * e;
        c_dub = 2 * c;
        a_dub = 2 * a;

        if (a_dub >= 10)   // If the doubled digits are >= 10 add the digit in the ten's place to the digit in the one's place
        {
            a_dub = 1 + a_dub % 10;
        }
        if (c_dub >= 10)
        {
            c_dub = 1 + c_dub % 10;
        }
        if (e_dub >= 10)
        {
            e_dub = 1 + e_dub % 10;
        }
        if (g_dub >= 10)
        {
            g_dub = 1 + g_dub % 10;
        }
        if (i_dub >= 10)
        {
            i_dub = 1 + i_dub % 10;
        }
        if (k_dub >= 10)
        {
            k_dub = 1 + k_dub % 10;
        }
        if (m_dub >= 10)
        {
            m_dub = 1 + m_dub % 10;
        }
        if (o_dub >= 10)
        {
            o_dub = 1 + o_dub % 10;
        }
        // Add the doubled digit's digits to the digits that were not doubled in the user input
        int sum = a_dub + c_dub + e_dub + g_dub + i_dub + k_dub + m_dub + o_dub + b + d + f + h + j + l + n + p;

        if (sum % 10 == 0) // If the sum's modulo 10 is congruent to 0 >> valid VISA
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (floor(n_digits) == 13 && ((number / 1000000000000) % 10) == 4)    // 13-digit Visa?
    {
        int d = (number / 1000000000000) % 10;                               // Store first digit of user input
        int e = (number / 100000000000) % 10;
        int f = (number / 10000000000) % 10;
        int g = (number / 1000000000) % 10;
        int h = (number / 100000000) % 10;
        int i = (number / 10000000) % 10;
        int j = (number / 1000000) % 10;
        int k = (number / 100000) % 10;
        int l = (number / 10000) % 10;
        int m = (number / 1000) % 10;
        int n = (number / 100) % 10;
        int o = (number / 10) % 10;
        int p = (number / 1) % 10;                                         // Store last digit of user input

        int o_dub, m_dub, k_dub, i_dub, g_dub, e_dub;
        // Begin Luhn's Algorithm: double every other digit starting second to last
        o_dub = 2 * o;
        m_dub = 2 * m;
        k_dub = 2 * k;
        i_dub = 2 * i;
        g_dub = 2 * g;
        e_dub = 2 * e;

        if (e_dub >= 10)   // If the doubled digits are >= 10 add the digit in the ten's place to the digit in the one's place
        {
            e_dub = 1 + e_dub % 10;
        }
        if (g_dub >= 10)
        {
            g_dub = 1 + g_dub % 10;
        }
        if (i_dub >= 10)
        {
            i_dub = 1 + i_dub % 10;
        }
        if (k_dub >= 10)
        {
            k_dub = 1 + k_dub % 10;
        }
        if (m_dub >= 10)
        {
            m_dub = 1 + m_dub % 10;
        }
        if (o_dub >= 10)
        {
            o_dub = 1 + o_dub % 10;
        }
        // Add the digits in the user input that were not doubled to the doubled digit's digits
        int sum = e_dub + g_dub + i_dub + k_dub + m_dub + o_dub + d + f + h + j + l + n + p;

        if (sum % 10 == 0) // If the sum's modulo is congruent to 0 >> valid Visa
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if ((((number / 10000000000000) % 10) == 4 || ((number / 10000000000000) % 10) == 7) && floor(n_digits) == 15
             && ((number / 100000000000000) % 10) == 3) // American Express?
    {
        int b = (number / 100000000000000) % 10;                                // Store first digit of user input
        int c = (number / 10000000000000) % 10;
        int d = (number / 1000000000000) % 10;
        int e = (number / 100000000000) % 10;
        int f = (number / 10000000000) % 10;
        int g = (number / 1000000000) % 10;
        int h = (number / 100000000) % 10;
        int i = (number / 10000000) % 10;
        int j = (number / 1000000) % 10;
        int k = (number / 100000) % 10;
        int l = (number / 10000) % 10;
        int m = (number / 1000) % 10;
        int n = (number / 100) % 10;
        int o = (number / 10) % 10;
        int p = (number / 1) % 10;                                              // Store last digit of user input

        int o_dub, m_dub, k_dub, i_dub, g_dub, e_dub, c_dub;
        // Begin Luhn's Algorithm: double every other digit starting second to last
        o_dub = 2 * o;
        m_dub = 2 * m;
        k_dub = 2 * k;
        i_dub = 2 * i;
        g_dub = 2 * g;
        e_dub = 2 * e;
        c_dub = 2 * c;

        if (c_dub >= 10)  // If the doubled digits are >= 10 add the digit in the ten's place to the digit in the one's place
        {
            c_dub = 1 + c_dub % 10;
        }
        if (e_dub >= 10)
        {
            e_dub = 1 + e_dub % 10;
        }
        if (g_dub >= 10)
        {
            g_dub = 1 + g_dub % 10;
        }
        if (i_dub >= 10)
        {
            i_dub = 1 + i_dub % 10;
        }
        if (k_dub >= 10)
        {
            k_dub = 1 + k_dub % 10;
        }
        if (m_dub >= 10)
        {
            m_dub = 1 + m_dub % 10;
        }
        if (o_dub >= 10)
        {
            o_dub = 1 + o_dub % 10;
        }
        // Add the digits that were not doubled to the doubled digit's digits
        int sum = c_dub + e_dub + g_dub + i_dub + k_dub + m_dub + o_dub + b + d + f + h + j + l + n + p;

        if (sum % 10 == 0) // If the sum's modulo is congruent to 0 >> Vaild AMEX
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}