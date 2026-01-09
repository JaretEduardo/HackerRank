using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;



class Result
{
    public static int findSmallestMissingPositive(List<int> orderNumbers)
    {
        int n = orderNumbers.Count;
        int i = 0;
        
        while (i < n)
        {
            int numeroActual = orderNumbers[i];
            
            int indiceCorrecto = numeroActual - 1;
            
            if (numeroActual > 0 && numeroActual <= n && orderNumbers[indiceCorrecto] != numeroActual)
            {
                orderNumbers[i] = orderNumbers[indiceCorrecto];
                
                orderNumbers[indiceCorrecto] = numeroActual;
            }
            else
            {
                i++;
            }
        }
        
        for (int j = 0; j < n; j++)
        {
            if (orderNumbers[j] != j + 1)
            {
                return j + 1;
            }
        }
        
        return n + 1;
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        int orderNumbersCount = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> orderNumbers = new List<int>();

        for (int i = 0; i < orderNumbersCount; i++)
        {
            int orderNumbersItem = Convert.ToInt32(Console.ReadLine().Trim());
            orderNumbers.Add(orderNumbersItem);
        }

        int result = Result.findSmallestMissingPositive(orderNumbers);

        Console.WriteLine(result);
    }
}
